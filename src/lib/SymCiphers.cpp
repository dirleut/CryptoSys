#include "SymCiphers.h"
#include <algorithm>

bool isEnglish(const std::string &str) {
  return str.size() > 0 &&
    str.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", 0) == std::string::npos;
}

void caesar(std::string& msg, short shift)
{
    if (msg.length() == 0) {
        return;
    }

    msg.erase(remove_if(msg.begin(), msg.end(), isspace), msg.end());
    
    for (size_t i=0; i < msg.length(); ++i) {
        msg[i] = std::toupper(msg[i]);
        msg[i] = char(int(msg[i] + shift - 65) % ENG_ALPHABET_SIZE + 65);
    }
}
