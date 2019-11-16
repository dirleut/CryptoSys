/*
  ==============================================================================

    utils.h
    Created: 4 Nov 2019 11:51:03am
    Author:  Кирилл Фокин

  ==============================================================================
*/
#include "MainComponent.h"
#pragma once

bool binaryToHex(std::string &str);
bool binaryToUTF8(std::string &bitstr);

bool hexToBinary(std::string &hexstr);
bool UTF8ToBinary(std::string &utf8str);

bool isHex(const std::string &str);
bool isBinary(const std::string &str);

BigInteger modulo(BigInteger base, BigInteger exp, BigInteger modulus);
BigInteger fromBinString(const std::string &binstr);
std::string fromBigInt(const BigInteger &bn);
