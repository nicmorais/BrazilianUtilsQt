#include "boleto.h"
#include "modulo.h"
#include "modulo.cpp"
#include <QVector>
#include <QDebug>

Boleto::Boleto()
{

}

bool Boleto::isValidBoleto(QString code){
    if(code.mid(0, 1).toInt() == 8){
        return isValidBoletoArrecadacao(code);
    }
    return isValidBoletoBancario(code);

    return true;
}

bool Boleto::isValidBoletoBancario(QString code){
    if(code.length() == 44) {
        return isValidBoletoBancarioBarcode(code);
    }else if(code.length() == 47){
        return isValidBoletoBancarioDigitableLine(code);
    }else{
        return false;
    }
}

bool Boleto::isValidBoletoBancarioDigitableLine(QString code){
    code = code.remove(" ").remove(".");

    if(code.mid(0, 9) == code.mid(9, 1)){
        return false;
    }

    if(code.mid(10, 10) == code.mid(20, 1)){
        return false;
    }

    if(code.mid(21, 10) == code.mid(31, 1)){
        return false;
    }

    QVector<Block> blocks;
    blocks.append(Block(code.mid(0, 9), code.mid(9, 1)));
    blocks.append(Block(code.mid(10, 10), code.mid(20, 1)));
    blocks.append(Block(code.mid(21, 10), code.mid(31, 1)));

    for(int i = 0; i < blocks.length(); i++){
        if(blocks[i].checkDigit.toInt() != Modulo::modulo10(blocks[i].number)){
            return false;
        }
    }

    return isValidBoletoBancarioBarcode(convertToBoletoBancarioBarcode(code));

}

bool Boleto::isValidBoletoBancarioBarcode(QString code){
    code = code.remove(" ").remove(".");

    int checkDigit = code.mid(4, 1).toInt();

    QString block = code.mid(0, 4) + code.mid(5, 44);

    return Modulo::modulo11Bancario(block) == checkDigit;
}

bool Boleto::isValidBoletoArrecadacao(QString code){
    if(code.length() == 44){
        return isValidBoletoArrecadacaoBarcode(code);
    }else if(code.length() == 48){
        return isValidBoletoArrecadacaoDigitableLine(code);
    }else{
        return false;
    }
}

bool Boleto::isValidBoletoArrecadacaoBarcode(QString code){
    int currencyCode = code.mid(2, 1).toInt();

    int checkDigit = code.mid(3, 1).toInt();

    QString block = code.mid(3, 2) + code.mid(4, 1);
    auto mod = &Modulo::modulo10;

    if(currencyCode == 8 || currencyCode || 9){
        mod = &Modulo::modulo11Arrecadacao;
    }else{
        return false;
    }

    return mod(block) == checkDigit;
}

bool Boleto::isValidBoletoArrecadacaoDigitableLine(QString code){
    return true;
}

QString Boleto::convertToBoletoBancarioBarcode(QString code){
    QString barcode;
    barcode += code.mid(0, 3);
    barcode += code.mid(3, 1);
    barcode += code.mid(32, 1);
    barcode += code.mid(33, 4);
    barcode += code.mid(37, 10);
    barcode += code.mid(4, 5);
    barcode += code.mid(10, 10);
    barcode += code.mid(21, 10);

    return barcode;
}

QString Boleto::convertToBoletoArrecadacaoBarcode(QString code){
    QString barcode;
    for(int i = 0; i < 4; i++){
        int start = (11 * i) + i;
        barcode += code.mid(start, 11);
    }
    return barcode;
}
