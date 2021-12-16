#include "model.h"
#include "modelobject.h"
#include <QTableView>
#include <QApplication>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QAction>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<ModelObject*> list;
    QWidget centralWidget;
    centralWidget.resize(300,400);

    ModelObject* obj1 = new ModelObject("Object 1");
    list.append(obj1);
    ModelObject* obj2 = new ModelObject("Object 2");
    list.append(obj2);

    obj1->setData("SKEY_1","SVAL_1");
    obj1->setData("SKEY_2","SVAL_2");
    obj1->setData("SKEY_3","SVAL_3");
    obj1->setData("SKEY_4","SVAL_4");

    obj2->setData("IVAL_1", 1.11);
    obj2->setData("IVAL_2", 2.22);
    obj2->setData("IVAL_3", 3.33);
    obj2->setData("IVAL_4", 4.44);
    obj2->setData("SKEY_4", 2.44);
    obj2->setData("SKEY_2", 5.44);

    Model* mod = new Model(list);

    QTableView* TV = new QTableView;
    TV->setModel(mod);

    QMenu* cMenu = new QMenu("&Change format to");
    QMenuBar* mBar = new QMenuBar();
    mBar->addMenu(cMenu);
    auto indexes = TV->selectionModel()->selectedIndexes();

    cMenu->addAction("Q&String",[&mod, &TV](){mod->slotObjectToString(TV->selectionModel());});
    cMenu->addAction("&Double",[&mod, &TV](){mod->slotObjectToDouble(TV->selectionModel());});
    cMenu->addAction("&Bool",[&mod, &TV](){mod->slotObjectToBool(TV->selectionModel());});

    QVBoxLayout* box = new QVBoxLayout;
    box->addWidget(mBar);
    box->addWidget(TV);
    centralWidget.setLayout(box);
    centralWidget.show();

    return a.exec();
}
