#include "brazilianutilsqt.h"
#include "boleto.h"
#include "boleto.cpp"
#include <QRandomGenerator>

BrazilianUtilsQt::BrazilianUtilsQt()
{

}

bool BrazilianUtilsQt::isValidCpf(QString cpf){
    cpf = cpf.remove(".").remove("-");

    if(cpf.length() != 11){
        return false;
    }

    for(int i = 1; i < 9; i++){
        if(cpf == QString::number(i).repeated(11)){
            return false;
        }
    }

    int sum = 0;
    int j = 0;

    for(int i = 10; i > 1; i--){
        sum += cpf.mid(j, 1).toInt() * i;
        j++;
    }

    int remainder = (sum * 10 % 11);
    remainder = remainder == 10 ? 0 : remainder;

    if(cpf.mid(9, 1).toInt() != remainder){
        return false;
    }

    sum = 0;
    j = 0;

    for(int i = 11; i > 1; i--){
        sum += cpf.mid(j, 1).toInt() * i;
        j++;
    }

    remainder = (sum * 10 % 11);
    remainder = remainder == 10 ? 0 : remainder;

    if(cpf.mid(10, 1).toInt() != remainder){
        return false;
    }

    return true;
}

bool BrazilianUtilsQt::isValidCnpj(QString cnpj){
    cnpj = cnpj.remove(".").remove("-").remove("/");

    if(cnpj.length() != 14){
        return false;
    }

    for(int i = 0; i < 9; i++){
        if(cnpj == QString::number(i).repeated(14)){
            return false;
        }
    }

    QList<int> numbers;

    numbers<<5<<4<<3<<2<<9<<8<<7<<6<<5<<4<<3<<2;

    int sum = 0;
    int j = 0;

    for(int i : numbers){
        sum += cnpj.mid(j, 1).toInt() * i;
        j++;
    }

    int digit = sum % 11;

    if(digit < 2){
        digit = 0;
    }else{
        digit = 11 - digit;
    }

    if(cnpj.mid(12, 1).toInt() != digit){
        return false;
    }

    numbers.push_front(6);

    sum = 0;
    j = 0;

    for(int i : numbers){
        sum += cnpj.mid(j, 1).toInt() * i;
        j++;
    }

    digit = sum % 11;

    if(digit < 2){
        digit = 0;
    }else{
        digit = 11 - digit;
    }

    if(cnpj.mid(13, 1).toInt() != digit){
        return false;
    }

    return true;
}

double BrazilianUtilsQt::parseCurrency(QString amount){
    amount = amount.remove("R").remove("$").remove(".").replace(",", ".");

    return amount.toDouble();
}

bool BrazilianUtilsQt::isValidBoleto(QString code){
    return Boleto::isValidBoleto(code);
}

QString BrazilianUtilsQt::capitalize(QString text){
    QStringList textList = text.split(" ");

    for(QString &word : textList){
        if(isAcronym(word)){
            word = word.toUpper();
        }else if(isPreposition(word)){
            word = word.toLower();
        }else{
            word = word.mid(0, 1).toUpper() + word.mid(1);
        }
    }
    return textList.join(' ');
}

QString BrazilianUtilsQt::generateCpf(){
    QString cpf = QString::number(QRandomGenerator::global()->generate());

    if(cpf.length() < 9){
        cpf = cpf += cpf.mid(0, 9 - cpf.length());

    }

    int sum = 0;
    int j = 0;

    for(int i = 10; i > 1; i--){
        sum += cpf.mid(j, 1).toInt() * i;
        j++;
    }

    int checkDigit = sum * 10 % 11;
    checkDigit = checkDigit == 10 ? 0 : checkDigit;

    cpf = cpf.mid(0, 9) + QString::number(checkDigit);

    sum = 0;
    j = 0;

    for(int i = 11; i > 1; i--){
        sum += cpf.mid(j, 1).toInt() * i;
        j++;
    }

    checkDigit = sum * 10 % 11;
    checkDigit = checkDigit == 10 ? 0 : checkDigit;

    cpf += QString::number(checkDigit);

    return cpf;
}

bool BrazilianUtilsQt::isPreposition(QString string){
    QStringList prepositions;
    prepositions <<"a"<<"com"<<"da"<<"das"<<"de"<<"do"<<"dos"<<"e"<<"em"<<"na"<<"nas"<<"no"<<"nos"<<"o"<<"por"<<"sem";

    return prepositions.indexOf(string.toLower()) != -1;
}

bool BrazilianUtilsQt::isAcronym(QString string){
    QStringList acronyms;
    acronyms << "cia" << "cnpj" << "cpf" << "mei" << "epp" << "ltda" << "me" << "rg" << "eireli" << "s/a" << "sa" << "s.a";

    return acronyms.indexOf(string.toLower()) != -1;
}
