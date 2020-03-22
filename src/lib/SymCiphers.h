#pragma once
#include <string>

const uint8_t LAT_ALPHABET_SIZE = 26;
const char SPEC_CHAR = '0';

bool isLatin(const std::string &str);
void leaveLettersOnly(std::string& content);

void caesar(std::string& msg, short shift);
void vigenere(std::string& msg, std::string& key, bool encrypt);
std::string scytale(const std::string& msg, short shift);
