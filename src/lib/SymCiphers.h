#pragma once
#include <string>

const uint8_t ENG_ALPHABET_SIZE = 26;
bool isLatin(const std::string &str);

void caesar(std::string& msg, short shift);
void vigenere(std::string& msg, std::string& key, bool encrypt);
