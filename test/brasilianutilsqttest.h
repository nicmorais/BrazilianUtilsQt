#ifndef BRASILIANUTILSQTTEST_H
#define BRASILIANUTILSQTTEST_H

#include <QObject>

class BrasilianUtilsQtTest : public QObject
{
    Q_OBJECT

private slots:
    void testIsValidCpf_data();
    void testIsValidCpf();

    void testIsValidCnpj_data();
    void testIsValidCnpj();

    void testParseCurrency_data();
    void testParseCurrency();

    void testIsValidBoleto_data();
    void testIsValidBoleto();

    void testCapitalize_data();
    void testCapitalize();

    void testGenerateCpf();
};

#endif // BRASILIANUTILSQTTEST_H
