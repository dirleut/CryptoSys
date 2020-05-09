#include "Analysis.h"
#include "SymCiphers.h"

// Критерий Пирсона
bool isPlainEnglishText(const std::string& text)
{
    double border = 44.3;
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

    return chi_squared < border && chi_squared > 0;
}

int findCaesarCiperKey(const std::string& msg)
{
    if (isPlainEnglishText(msg)) {
        return 0;
    }

    int possible_key = 1;
    for (; possible_key < LAT_ALPHABET_SIZE; ++possible_key)
    {
        std::string text_to_check = msg;
        caesar(text_to_check, LAT_ALPHABET_SIZE - possible_key);
        if (isPlainEnglishText(text_to_check)) {
            break;
        }
    }
    return possible_key;
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


