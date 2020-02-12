/*
  ==============================================================================

    bignumber.h
    Created: 16 Nov 2019 11:09:19pm

  ==============================================================================
*/
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

BigInteger modulo(BigInteger base, BigInteger exp, BigInteger modulus);
BigInteger fromBinString(const std::string &binstr);
std::string fromBigInt(const BigInteger &bn);

