#ifndef MODULO_H
#define MODULO_H

#include <QString>

class Modulo
{
public:
    Modulo();

    static int modulo10(QString block);

    static int modulo11Bancario(QString block);

    static int modulo11Arrecadacao(QString block);
};

#endif // MODULO_H
