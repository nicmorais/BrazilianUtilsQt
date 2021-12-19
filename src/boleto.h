#ifndef BOLETO_H
#define BOLETO_H

#include <QString>

class Boleto
{
public:
    Boleto();

    static bool isValidBoleto(QString code);

    static bool isValidBoletoBancario(QString code);

    static bool isValidBoletoBancarioDigitableLine(QString code);

    static bool isValidBoletoBancarioBarcode(QString code);

    static bool isValidBoletoArrecadacao(QString code);

    static bool isValidBoletoArrecadacaoDigitableLine(QString code);

    static bool isValidBoletoArrecadacaoBarcode(QString code);

    static QString convertToBoletoBancarioBarcode(QString code);

    static QString convertToBoletoArrecadacaoBarcode(QString code);
};

class Block
{
public:
    Block(QString number, QString checkDigit){
        this->number = number;
        this->checkDigit = checkDigit;
    }

    QString number;
    QString checkDigit;
};

#endif // BOLETO_H
