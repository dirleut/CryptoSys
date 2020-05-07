// TODO написать тесты
#include "encoding.h"
#include <bitset>

static const char* _hexCharToBin(char c) {
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

bool binaryToHex(std::string &str) {
    if (!isBinary(str)) {
        return false;
    }
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
    str = result;
    return true;
}

bool hexToBinary(std::string &hexstr) {
    if (!isHex(hexstr)) {
        return false;
    }
    std::string bin;
    for(unsigned i = 0; i != hexstr.length(); ++i)
       bin += _hexCharToBin(hexstr[i]);
    hexstr = bin;
    return true;
}

static bool _checkAndAddNextUTF8Bytes(std::stringstream &ss, std::string &symb, int n) {
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

bool binaryToUTF8(std::string &bitstr) {
    if (!isBinary(bitstr)) {
        return false;
    }
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
            if(!_checkAndAddNextUTF8Bytes(ss, symb, 1)) {
                return false;
            }
        }
        else if(checkByte.find("1110") == 0) {
            symb += char(byte.to_ulong());
            if(!_checkAndAddNextUTF8Bytes(ss, symb, 2)) {
                return false;
            }
        }
        else if(checkByte.find("11110") == 0) {
            symb += char(byte.to_ulong());
            if(!_checkAndAddNextUTF8Bytes(ss, symb, 3)) {
                return false;
            }
        }
        else
            return false;
        outstr += symb;
    }
    bitstr = outstr;
    return true;
}

// TODO чтобы false тоже возвращала
bool UTF8ToBinary(std::string &utf8str) {
    std::string outstr;
    for (std::size_t i = 0; i < utf8str.size(); ++i) {
        outstr += std::bitset<8>(utf8str.c_str()[i]).to_string();
    }
    utf8str = outstr;
    return true;
}

bool isBinary(const std::string &str) {
    return str.size() > 0 &&
    str.find_first_not_of("01", 0) == std::string::npos;
}

bool isHex(const std::string &str) {
  return str.size() > 0 &&
    str.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos;
}

