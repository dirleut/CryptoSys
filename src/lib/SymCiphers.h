#pragma once
#include <string>

const uint8_t ENG_ALPHABET_SIZE = 26;
bool isEnglish(const std::string &str);

void caesar(std::string& msg, short shift);
