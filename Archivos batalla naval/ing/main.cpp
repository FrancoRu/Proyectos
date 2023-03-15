#include "GUI/inicio.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    a.setStyle("fusion");
    inicio w;
    w.show();
    return a.exec();
}
