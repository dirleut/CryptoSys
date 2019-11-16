/*
  ==============================================================================

    crypto.cpp
    Created: 4 Nov 2019 11:51:03am
    Author:  Кирилл Фокин

  ==============================================================================
*/
#include "utils.h"

BigInteger modulo(BigInteger base, BigInteger exp, BigInteger modulus) {
    BigInteger x=1, y = base;
    while (exp > 0) {
        if (exp % 2 == 1) {
            x = (x*y) % modulus; // multiplying with base
        }
        y = (y*y) % modulus; // squaring the base
        exp /= 2;
    }
    return x % modulus;
}

const char* _hexCharToBin(char c) {
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return "0000";
    }
}

std::string binaryToHex(const std::string &str) {
    std::string bitstr = str;
    // TODO обработка ошибок
    if(bitstr.size() % 4 != 0) {
        int lim = 4 - (bitstr.size() % 4);
        for(int i = 0; i < lim ; ++i){
            bitstr.insert(0, "0");
        }
    }
    std::string result;
    int charcount = bitstr.size() / 4;

    for(size_t i = 0; i < charcount; ++i) {
        std::bitset<4> bs(bitstr);
        unsigned n = bs.to_ulong();

        std::stringstream ss;
        ss << std::hex << n;
        result += ss.str();
        bitstr.erase(0, 4);
    }
    return result;
}

std::string hexToBinary(const std::string &hexstr) {
    std::string bin;
    for(unsigned i = 0; i != hexstr.length(); ++i)
       bin += _hexCharToBin(hexstr[i]);
    return bin;
}

bool checkAndAddNextUTF8Bytes(std::stringstream &ss, std::string &symb, int n) {
    std::string result;
    for(int i = 0; i < n; ++i) {
        std::bitset<8> nextByte;
        ss >> nextByte;
        if(nextByte.to_string().find("10") == 0) {
            result += char(nextByte.to_ulong());
        } else {
            return false;
        }
    }
    symb += result;
    return true;
}

std::string binaryToUTF8(const std::string &bitstr) {
    std::stringstream ss(bitstr);
    std::string outstr;
    
    while (ss.good()) {
        std::string symb;
        std::bitset<8> byte;
        ss >> byte;
        
        std::string checkByte = byte.to_string();
        if(checkByte.find("0") == 0) {
            outstr += char(byte.to_ulong());
        }
        else if(checkByte.find("110") == 0) {
            symb += char(byte.to_ulong());
            if(!checkAndAddNextUTF8Bytes(ss, symb, 1)) {
                return "";
            }
        }
        else if(checkByte.find("1110") == 0) {
            symb += char(byte.to_ulong());
            if(!checkAndAddNextUTF8Bytes(ss, symb, 2)) {
                return "";
            }
        }
        else if(checkByte.find("11110") == 0) {
            symb += char(byte.to_ulong());
            if(!checkAndAddNextUTF8Bytes(ss, symb, 3)) {
                return "";
            }
        }
        else
            return "";
        outstr += symb;
        //outstr += char(bits.to_ulong());
        //std::cout << outstr << std::endl;
    }
    return outstr;
}

std::string UTF8ToBinary(const std::string &utf8str) {
    std::string outstr;
    for (std::size_t i = 0; i < utf8str.size(); ++i)
    {
        outstr += std::bitset<8>(utf8str.c_str()[i]).to_string();
    }
    return outstr;
}

bool isBinary(const std::string &str) {
    return str.size() > 0 &&
    str.find_first_not_of("01", 0) == std::string::npos;
}

bool isHex(const std::string &str) {
  return str.size() > 0 &&
    str.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos;
}

BigInteger fromBinString(const std::string &binstr) {
    BigInteger bn;
    for(int i = 0; i < binstr.size() ; ++i) {
        if(binstr[i] == '1'){
            bn.setBit(binstr.size() - 1 - i);
        }
    }
    return bn;
}

std::string fromBigInt(const BigInteger &bn) {
    std::string binstr;
    for(int i = bn.getHighestBit(); i >=0 ; --i){
        binstr += (bn[i]) ? '1' : '0';
    }
    return binstr;
}

