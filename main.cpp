#include <QApplication>

#include "logiclayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LogicLayer login;

    return app.exec();
}
