#include "modulo.h"

#include <cmath>

Modulo::Modulo()
{

}

int Modulo::modulo10(QString block){
    std::reverse(block.begin(), block.end());
    int acc = 0;

    for(int i = 0; i < block.length(); i++){
        int sum = block.mid(i, 1).toInt() * (((i + 1) % 2) + 1);
        sum = (sum > 9 ? std::trunc(sum/10) + (sum % 10) : sum);
        acc += sum;
    }
    return (std::ceil((double) acc / 10) * 10) - acc;
}

int Modulo::modulo11Bancario(QString block){
    std::reverse(block.begin(), block.end());

    int multiplier = 2;
    int acc = 0;
    for(int i = 0; i < block.length(); i++){
        int sum = block.mid(i, 1).toInt() * multiplier;
        multiplier = multiplier == 9 ? 2 : multiplier + 1;
        acc += sum;
    }

    int checkDigit = 11 - acc % 11;
    if(checkDigit == 0 || checkDigit == 10 || checkDigit == 11){
        return 1;
    }
    return checkDigit;
}

int Modulo::modulo11Arrecadacao(QString block){
    std::reverse(block.begin(), block.end());

    int multiplier = 2;
    int acc = 0;
    for(int i = 0; i < block.length(); i++){
        int sum = block.mid(i, 1).toInt() * multiplier;
        multiplier = multiplier == 9 ? 2 : multiplier + 1;
        acc += sum;
    }

    int remainder = acc % 11;

    if(remainder == 0 || remainder == 1){
        return 0;
    }else if(remainder == 10){
        return 1;
    }else{
        int checkDigit = 11 - remainder;
        return checkDigit;
    }

}
