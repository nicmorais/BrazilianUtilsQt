#include "brasilianutilsqttest.h"

#include <QTest>

#include "../src/brazilianutilsqt.h"

void BrasilianUtilsQtTest::testIsValidCpf_data() {
    QTest::addColumn<QString>("cpf");
    QTest::addColumn<bool>("isValid");

    QTest::newRow("111.111.111-11") << QString("111.111.111-11") << false;
    QTest::newRow("58745612311") << QString("58745612311") << false;
    QTest::newRow("012.345.678-90") << QString("012.345.678-90") << true;
    QTest::newRow("524.584.544-02") << QString("524.584.544-02") << true;
    QTest::newRow("52458454402") << QString("52458454402") << true;
}

void BrasilianUtilsQtTest::testIsValidCpf() {
    QFETCH(QString, cpf);
    QFETCH(bool, isValid);

    bool result = BrazilianUtilsQt::isValidCpf(cpf);

    QCOMPARE(result, isValid);
}

void BrasilianUtilsQtTest::testIsValidCnpj_data() {
    QTest::addColumn<QString>("cnpj");
    QTest::addColumn<bool>("isValid");

    QTest::newRow("68.718.934/0001-05") << QString("68.718.934/0001-05") << true;
    QTest::newRow("68718934000105") << QString("68718934000105") << true;
    QTest::newRow("12.123.123/0001-01") << QString("12.123.123/0001-01") << false;
    QTest::newRow("12123123000101") << QString("12123123000101") << false;
}

void BrasilianUtilsQtTest::testIsValidCnpj() {
    QFETCH(QString, cnpj);
    QFETCH(bool, isValid);

    bool result = BrazilianUtilsQt::isValidCnpj(cnpj);

    QCOMPARE(result, isValid);
}

void BrasilianUtilsQtTest::testParseCurrency_data() {
    QTest::addColumn<QString>("amount");
    QTest::addColumn<double>("value");

    QTest::newRow("R$ 4.547,25") << QString("R$ 4.547,25") << 4547.25;
    QTest::newRow("R$9.695.874,33") << QString("R$9.695.874,33") << 9695874.33;
}

void BrasilianUtilsQtTest::testParseCurrency() {
    QFETCH(QString, amount);
    QFETCH(double, value);

    double result = BrazilianUtilsQt::parseCurrency(amount);

    QCOMPARE(result, value);
}

void BrasilianUtilsQtTest::testIsValidBoleto_data() {
    QTest::addColumn<QString>("boleto");
    QTest::addColumn<bool>("isValid");

    QTest::newRow("Test 01") << QString("23793.38128 60007.827136 95000.063305 9 75520000370000") << true;
    QTest::newRow("Test 02") << QString("23793381286000782713695000063305975520000370000") << true;
    QTest::newRow("Test 03") << QString("836200000005 667800481000 180975657313 001589636081") << true;
    QTest::newRow("Test 04") << QString("536200000005 667800481000 180975657313 001589636081") << false;
    QTest::newRow("Test 05") << QString("001933737000000144816060680935031") << false;
    QTest::newRow("Test 06") << QString("84890000000404201622018060519042958603411122") << true;
    QTest::newRow("Test 07") << QString("85890000460-9 52460179160-5 60759305086-5 83148300001-0") << true;
}

void BrasilianUtilsQtTest::testIsValidBoleto() {
    QFETCH(QString, boleto);
    QFETCH(bool, isValid);

    QSKIP("Validar como esta função aceita o código de barras");

    bool result = BrazilianUtilsQt::isValidBoleto(boleto);

    QCOMPARE(result, isValid);
}

void BrasilianUtilsQtTest::testCapitalize_data() {
    QTest::addColumn<QString>("original");
    QTest::addColumn<QString>("expected");

    QTest::newRow("banco do brasil s.a.") << QString("banco do brasil s.a.") << QString("Banco do Brasil S.a.");
    QTest::newRow("teste da funcionalidade com um texto") << QString("teste da funcionalidade com um texto")
                                                          << QString("Teste da Funcionalidade com Um Texto");
}

void BrasilianUtilsQtTest::testCapitalize() {
    QFETCH(QString, original);
    QFETCH(QString, expected);

    QString result = BrazilianUtilsQt::capitalize(original);

    QCOMPARE(result, expected);
}

void BrasilianUtilsQtTest::testGenerateCpf() {
    QString generated = BrazilianUtilsQt::generateCpf();
    QVERIFY(BrazilianUtilsQt::isValidCpf(generated));
}
