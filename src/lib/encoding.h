#pragma once
#include <string>

bool binaryToHex(std::string &str);
bool binaryToUTF8(std::string &bitstr);

bool hexToBinary(std::string &hexstr);
bool UTF8ToBinary(std::string &utf8str);

bool isHex(const std::string &str);
bool isBinary(const std::string &str);
