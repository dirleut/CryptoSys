#include "SymCiphers.h"
#include <algorithm>

// TODO точки, запятые, дефисы и перенос строк
// TODO вынести все проверки
bool isLatin(const std::string &str) {
  return str.size() > 0 &&
    str.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0) == std::string::npos;
}

void caesar(std::string& msg, short shift) {
    if (msg.length() == 0) {
        return;
    }

    msg.erase(remove_if(msg.begin(), msg.end(), isspace), msg.end());
    
    for (size_t i = 0; i < msg.length(); ++i) {
        msg[i] = std::toupper(msg[i]);
        msg[i] = char(int(msg[i] + shift - 65) % ENG_ALPHABET_SIZE + 65);
    }
}

void vigenere(std::string& msg, std::string& key, bool encrypt) {
    if (msg.length() == 0) {
        return;
    }
    msg.erase(remove_if(msg.begin(), msg.end(), isspace), msg.end());
    key.erase(remove_if(key.begin(), key.end(), isspace), key.end());
    for (size_t i = 0; i < key.length(); ++i) {
        key[i] = std::toupper(key[i]);
    }

    for (size_t i = 0, j = 0; i < msg.length(); ++i) {
        msg[i] = std::toupper(msg[i]);
        if (encrypt) {
            msg[i] = char(int(msg[i] + key[j++]) % ENG_ALPHABET_SIZE + 65);
        } else {
            msg[i] = char(int(msg[i] - key[j++] + ENG_ALPHABET_SIZE) % ENG_ALPHABET_SIZE + 65);
        }
        if (j == key.length()) {
            j = 0;
        }
    }
}
