#include "Bignumber.h"

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
