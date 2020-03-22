#include "SymCiphers.h"
#include <algorithm>

// TODO точки, запятые, дефисы и перенос строк
// TODO вынести все проверки
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
