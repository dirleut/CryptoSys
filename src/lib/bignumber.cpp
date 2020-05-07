#include "bignumber.h"
// TODO написать тесты
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

std::string fromBigInt(const BigInteger &bn) {
    std::string binstr;
    for(int i = bn.getHighestBit(); i >=0 ; --i){
        binstr += (bn[i]) ? '1' : '0';
    }
    return binstr;
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
