#pragma once
#include <JuceHeader.h>

BigInteger modulo(BigInteger base, BigInteger exp, BigInteger modulus);
BigInteger fromBinString(const std::string &binstr);
std::string fromBigInt(const BigInteger &bn);

