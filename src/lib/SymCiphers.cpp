#include "SymCiphers.h"
#include <algorithm>
#include <map>

#include <iostream>

std::map<char, double> english_frequencies = {
    {'A', 0.086}, {'B', 0.014}, {'C', 0.028}, {'D', 0.028},
    {'E', 0.130}, {'F', 0.029}, {'G', 0.010}, {'H', 0.053},
    {'I', 0.063}, {'J', 0.011}, {'K', 0.004}, {'L', 0.034},
    {'M', 0.055}, {'N', 0.061}, {'O', 0.070}, {'P', 0.030},
    {'Q', 0.001}, {'R', 0.065}, {'S', 0.061}, {'T', 0.105},
    {'U', 0.025}, {'V', 0.009}, {'W', 0.005}, {'X', 0.002},
    {'Y', 0.020}, {'Z', 0.001}
};

// TODO точки, запятые, дефисы и перенос строк
// TODO вынести все проверки
bool isLatin(const std::string &str) {
  return str.size() > 0 &&
    str.find_first_not_of("*:'-_,.!? 0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0) == std::string::npos;
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
    double border = 44.3;
    /*
    std::map<char, uint32_t> letters = {
        {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0},
        {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0},
        {'I', 0}, {'J', 0}, {'K', 0}, {'L', 0},
        {'M', 0}, {'N', 0}, {'O', 0}, {'P', 0},
        {'Q', 0}, {'R', 0}, {'S', 0}, {'T', 0},
        {'U', 0}, {'V', 0}, {'W', 0}, {'X', 0},
        {'Y', 0}, {'Z', 0}
    };
    */
    std::map<char, uint32_t> letters;
    for (size_t i = 0; i < text.size(); ++i)
    {
        ++letters[text[i]];
    }
    for (auto it = letters.begin(); it != letters.end(); ++it)
    {
        std::cout << it->first << "->" << it->second << std::endl;
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
