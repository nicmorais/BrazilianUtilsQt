#ifndef BRAZILIANUTILSQT_H
#define BRAZILIANUTILSQT_H
#include <QString>

class BrazilianUtilsQt
{
public:
    BrazilianUtilsQt();

    static bool isValidCpf(QString cpf);

    static bool isValidCnpj(QString cnpj);

    static double parseCurrency(QString amount);

    static bool isValidBoleto(QString code);

    static QString capitalize(QString text);

    static QString generateCpf();

private:
    static bool isAcronym(QString string);

    static bool isPreposition(QString string);

};

#endif // BRAZILIANUTILSQT_H
