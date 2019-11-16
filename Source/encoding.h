/*
  ==============================================================================

    encoding.h
    Created: 4 Nov 2019 11:51:03am
    Author:  Кирилл Фокин

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

bool binaryToHex(std::string &str);
bool binaryToUTF8(std::string &bitstr);

bool hexToBinary(std::string &hexstr);
bool UTF8ToBinary(std::string &utf8str);

bool isHex(const std::string &str);
bool isBinary(const std::string &str);
