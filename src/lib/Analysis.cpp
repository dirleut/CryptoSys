#include "Analysis.h"
#include "SymCiphers.h"

#include <algorithm>
#include <math.h>

double calculatePirsonTest(const std::string& text)
{
    std::map<char, uint32_t> letters;
    for (size_t i = 0; i < text.size(); ++i)
    {
        ++letters[text[i]];
    }
    
    double chi_squared = 0.0;
    for (auto it = letters.begin(); it != letters.end(); ++it)
    {
        double iteration = (it->second - (text.size() * english_frequencies[it->first]))
            * (it->second - (text.size() * english_frequencies[it->first]))
            / (text.size() * english_frequencies[it->first]);

        chi_squared += iteration;
    }
    return chi_squared;
}

double calculateCoincidenceIndex(std::string text) {
    std::map<char, double> letters;

    for (size_t i = 0; i < text.size(); ++i)
    {
        if (letters.find(text[i]) == letters.end()) {
            letters[text[i]] = 1;
        } else {
            ++letters[text[i]];
        }
    }

    double frequencies_sum = 0.0;
    for (auto it = letters.begin(); it != letters.end(); ++it)
    {
        frequencies_sum += it->second * (it->second - 1);
    }

    frequencies_sum /= text.size() * (text.size() - 1);
    return frequencies_sum;
}

uint8_t findCaesarCiperKey(const std::string& msg)
{
    if (calculatePirsonTest(msg) < pirson_border &&
        calculatePirsonTest(msg) > 0)
    {
        return 0;
    }

    std::vector<double> pirson_criteria;
    for (size_t i = 0; i < LAT_ALPHABET_SIZE; ++i)
    {
        std::string text_to_check = msg;
        caesar(text_to_check, LAT_ALPHABET_SIZE - i);
        pirson_criteria.push_back(calculatePirsonTest(text_to_check));
    }

    std::vector<double> differencies;
    for (const auto& criterium : pirson_criteria)
    {
        differencies.push_back(fabs(criterium - (pirson_border / 2)));
    }

    double minimum = differencies[0];
    size_t index_min;
    for (size_t i = 0; i < differencies.size(); ++i)
    {
        if (differencies[i] < minimum) {
            minimum = differencies[i];
            index_min = i;
        }
    }

    return index_min;
}

// TODO провести больше тестирования
std::string findVigenereCipherKey(const std::string& msg)
{
    double frequencies_sum = calculateCoincidenceIndex(msg);
    if (frequencies_sum >= english_coincidence_index - error &&
        frequencies_sum <= english_coincidence_index + error)
    {
        return "";
    }

    std::vector<double> indexis;

    for (size_t i = 2; i < msg.size(); ++i)
    {
        std::string text_to_check = "";

        for (size_t j = 0; j < msg.size(); j += i)
        {
            text_to_check += msg[j];
        }

        if (text_to_check.size() < 100) {
            break;
        }

        double index = calculateCoincidenceIndex(text_to_check);
        indexis.push_back(index);
    }

    std::vector<double> differencies;
    for (const auto& index : indexis)
    {
        differencies.push_back(fabs(index - english_coincidence_index));
    }

    double minimum = differencies[0];
    int index_min;
    for (size_t i = 0; i < differencies.size(); ++i)
    {
        if (differencies[i] < minimum) {
            minimum = differencies[i];
            index_min = i;
        }
    }

    size_t key_length = index_min + 2;
    std::vector<std::string> textes(key_length);

    for (size_t i = 0; i < key_length; ++i)
    {
        for (size_t j = i; j < msg.size(); j += key_length)
        {
            textes[i] += msg[j];
        }
    }

    std::vector<int> key_in_numbers;
    for (const auto& text : textes)
    {
        key_in_numbers.push_back(findCaesarCiperKey(text));
    }

    std::string result_key;
    for (const auto& letter : key_in_numbers)
    {
        result_key += char(letter + 65);
    }
    return result_key;
}

std::vector<long long> combination(long long N, long long K)
{
    std::vector<long long> combinations;
    std::string bitmask(K, 1);
    bitmask.resize(N, 0);

    do {
        for (size_t i = 0; i < N; ++i)
        {
            if (bitmask[i]) {
                combinations.push_back(i);
            }
        }
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return combinations;
}

std::set<long long> findPossibleScytaleKeys(const std::string& msg)
{
    std::set<long long> text_size_multipliers;
    std::vector<long long> factors = factorize(msg.size());

    for (int k = 1; k <= factors.size(); ++k)
    {
        auto comb = combination(factors.size(), k);
        for (size_t i = 0; i < comb.size(); i += k)
        {
            long long multiplier = 1;
            for (size_t j = i; j < i + k; ++j)
            {
                multiplier *= factors[comb[j]];
            }
            text_size_multipliers.insert(multiplier);
        }
    }
    return  text_size_multipliers;
}

std::vector<long long> factorize(long long number)
{
    std::vector<long long> factors;
    // Попробуем сначала числа 2, 3, 5
    for (int divisor : {2, 3, 5}) {
        while (number % divisor == 0) {
            factors.push_back(divisor);
            number /= divisor;
        }
    }

    // Перебираем числа 5,7,11,13,17,19,23...
    int increments[8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long divisor = 7; divisor * divisor <= number; divisor += increments[i++]) {
        while (number % divisor == 0) {
            factors.push_back(divisor);
            number /= divisor;
        }
        if (i == 8)
            i = 0;
    }
    if (number > 1) {
        factors.push_back(number);
    }
    return factors;
}


