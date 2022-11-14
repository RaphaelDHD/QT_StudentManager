#include "TP3_GestionEtu.h"
#include "promotion.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* prom,QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    listView = new ViewList(prom,ui.listWidget);
    /*connect(ui., &QAction::triggered , ViewList, ViewList::remove);*/
    // connect vers le bouton et mettre en 3eme parametre parent du bouton, fonction listView::remove

}
