#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>
#include <qdir.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    QString s = QDir::currentPath() + "/../data/promoDUT.csv";
    Promotion* promo = new Promotion(s);
    promo->read_list();

    // Create Interface
    TP3_GestionEtu w(promo);
    w.show();


    return a.exec();
}
