#include <QtGui/QApplication>
#include "litescreengui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    litescreengui w;
    w.show();
    
    return a.exec();
}
