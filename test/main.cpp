#include <QTest>

#include "brasilianutilsqttest.h"

int main( int argc, char* argv[] ) {
    QCoreApplication app( argc, argv );

    BrasilianUtilsQtTest brasilianUtilsQtTest;

    return QTest::qExec( &brasilianUtilsQtTest, argc, argv );
}
