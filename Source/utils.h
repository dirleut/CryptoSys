/*
  ==============================================================================

    crypto.h
    Created: 4 Nov 2019 11:51:03am
    Author:  Кирилл Фокин

  ==============================================================================
*/
#include "MainComponent.h"
#pragma once

BigInteger modulo(BigInteger base, BigInteger exp, BigInteger modulus);

void encrypt(std::string &message);

std::string binaryToHex(const std::string &str);

bool checkAndAddNextUTF8Bytes(std::stringstream &ss, std::string &symb, int n);
std::string binaryToUTF8(const std::string &bitstr);

std::string hexToBinary(const std::string &hexstr);
std::string UTF8ToBinary(const std::string &utf8str);

bool isHex(const std::string &str);
bool isBinary(const std::string &str);

BigInteger fromBinString(const std::string &binstr);
std::string fromBigInt(const BigInteger &bn);
