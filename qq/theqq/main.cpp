#include "widget.h"

#include <QApplication>
#include"usersql.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    usersql user;
    w.show();
    return a.exec();
}
