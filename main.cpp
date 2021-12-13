#include "model.h"
#include "objects.h"

std::map<QString,QString> b;

BaseObject* a = new StrObject("asdas",b);

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    return a.exec();
}
