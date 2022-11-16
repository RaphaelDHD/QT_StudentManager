#include "TP3_GestionEtu.h"
#include "promotion.h"

TP3_GestionEtu::TP3_GestionEtu(Promotion* prom,QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    listView = new ViewList(prom,ui.listWidget);
    listForm = new ViewForms(prom, ui.lineEdit_add_firstname, ui.lineEdit_add_lastname, ui.lineEdit_add_number, ui.lineEdit_add_BAC, ui.lineEdit_add_department, ui.lineEdit_remove_number);
    pieChartView = new ViewPieChart(prom, ui.groupBox_department);
    prom->addObserver(listView);
    prom->addObserver(listForm);
    prom->addObserver(pieChartView);
    connect(ui.pushButton_delete_list , &QPushButton::pressed , listView, &ViewList::remove);
    connect(ui.pushButton_addStudent, &QPushButton::pressed, listForm, &ViewForms::add);
    connect(ui.pushButton_delete_number, &QPushButton::pressed, listForm, &ViewForms::del);
    // connect vers le bouton et mettre en 3eme parametre parent du bouton, fonction listView::remove



}
