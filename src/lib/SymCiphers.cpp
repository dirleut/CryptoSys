#include "SymCiphers.h"
#include <algorithm>
#include <map>

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

void vigenere(std::string& msg, std::string& key, Operation op) {
    key.erase(remove_if(key.begin(), key.end(), isspace), key.end());
    for (size_t i = 0; i < key.length(); ++i) {
        key[i] = std::toupper(key[i]);
    }

    for (size_t i = 0, j = 0; i < msg.length(); ++i) {
        if (op == ENCRYPT) {
            msg[i] = char(int(msg[i] + key[j++]) % LAT_ALPHABET_SIZE + 65);
        } else if (op == DECRYPT){
            msg[i] = char(int(msg[i] - key[j++] + LAT_ALPHABET_SIZE) % LAT_ALPHABET_SIZE + 65);
        }
        if (j == key.length()) {
            j = 0;
        }
    }
}

void scytale(std::string& msg, short shift, Operation op)
{
    // Добавим спец. символы в конец при зашифровании
    if (op == ENCRYPT) {
        for (size_t i = 0; i < msg.length() % shift; ++i) {
            msg += SPEC_CHAR;
        }
    }

    char* chars = (char*)calloc(1, msg.length() + 1);
    for (int i = 0; i < shift; ++i) {
        for(int j = i; j < msg.length(); j += shift) {
            chars[strlen(chars)] = msg[j];
        }
    }

    msg = std::string(chars);

    // Удалим спец. символы в конеце при расшифровании
    if (op == DECRYPT) {
        for (size_t i = 0; i < shift; ++i) {
            if (msg.back() == SPEC_CHAR) {
                msg = msg.substr(0, msg.size() - 1);
            }
        }
    }
}
