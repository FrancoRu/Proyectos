<<<<<<< HEAD
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
=======
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
>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
