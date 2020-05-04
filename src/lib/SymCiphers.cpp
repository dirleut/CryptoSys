#include "SymCiphers.h"
#include <algorithm>
#include <map>

// TODO точки, запятые, дефисы и перенос строк
// TODO вынести все проверки

std::map<char, double> english_frequencies = {
    {'A', 0.086}, {'B', 0.014}, {'C', 0.028}, {'D', 0.028},
    {'E', 0.130}, {'F', 0.029}, {'G', 0.010}, {'H', 0.053},
    {'I', 0.063}, {'J', 0.011}, {'K', 0.004}, {'L', 0.034},
    {'M', 0.055}, {'N', 0.061}, {'O', 0.070}, {'P', 0.030},
    {'Q', 0.001}, {'R', 0.065}, {'S', 0.061}, {'T', 0.105},
    {'U', 0.025}, {'V', 0.009}, {'W', 0.005}, {'X', 0.002},
    {'Y', 0.020}, {'Z', 0.001}
};

bool isLatin(const std::string &str) {
  return str.size() > 0 &&
    str.find_first_not_of("*-_,.!? 0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0) == std::string::npos;
}

void leaveLettersOnly(std::string& content) {
    if (content.length() == 0) {
        return;
    }
    content.erase(remove_if(content.begin(), content.end(), ispunct), content.end());
    content.erase(remove_if(content.begin(), content.end(), isspace), content.end());
    for (size_t i = 0; i < content.length(); ++i) {
        content[i] = std::toupper(content[i]);
    }
}

void caesar(std::string& msg, short shift) {
    for (size_t i = 0; i < msg.length(); ++i) {
        msg[i] = std::toupper(msg[i]);
        msg[i] = char(int(msg[i] + shift - 65) % LAT_ALPHABET_SIZE + 65);
    }
}

void vigenere(std::string& msg, std::string& key, bool encrypt) {
    key.erase(remove_if(key.begin(), key.end(), isspace), key.end());
    for (size_t i = 0; i < key.length(); ++i) {
        key[i] = std::toupper(key[i]);
    }

    for (size_t i = 0, j = 0; i < msg.length(); ++i) {
        if (encrypt) {
            msg[i] = char(int(msg[i] + key[j++]) % LAT_ALPHABET_SIZE + 65);
        } else {
            msg[i] = char(int(msg[i] - key[j++] + LAT_ALPHABET_SIZE) % LAT_ALPHABET_SIZE + 65);
        }
        if (j == key.length()) {
            j = 0;
        }
    }
}

std::string scytale(const std::string& msg, short shift)
{
    char* result = (char*)calloc(1, msg.length() + 1);
    for (int i = 0; i < shift; ++i)
    {
        for(int j = i; j < msg.length(); j += shift)
        {
            result[strlen(result)] = msg[j];
        }
    }
    return std::string(result);
}

// Критерий Пирсона
bool isPlainEnglishText(const std::string& text)
{
    double border = 37.65;

    std::map<char, double> letters;
    for (size_t i = 0; i < text.size(); ++i)
    {
        if (letters.find(text[i]) == letters.end()) {
            letters[text[i]] = 1;
        } else {
            ++letters[text[i]];
        }
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
