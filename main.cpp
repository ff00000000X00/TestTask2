#include "model.h"
#include "modelobject.h"
#include <QTableView>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<ModelObject*> list;

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



    Model mod(list);


    QTableView TV;
    TV.setModel(&mod);

    TV.show();


    return a.exec();
}
