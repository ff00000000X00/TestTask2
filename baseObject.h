#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <QString>

/*
 * Сначала хотел через полиморфизм, сделать базовый класс, наследовать классы для
 * строчных, логичесских и численных объектов, и везде воткнуть по мэпу,
 * потом через шаблоны, но когда выяснилось, что разные типы значнений должны
 * храниться в одном объекте, ничего лучше придумать не смог
 */

class BasicObject
{
public:
    BasicObject();
};

class StrObject:public BasicObject
{
    QString iVal;
public:
    StrObject(const QString& eVal);
    QString getVal();
    void setVal(const QString& eVal);
};

class BoolObject:public BasicObject
{
    bool iVal;
public:
    BoolObject(const bool& eVal);
    bool getVal();
    void setVal(const bool& eVal);
};

class DoubleObject:public BasicObject
{
    double iVal;
public:
    DoubleObject(const double& eVal);
    double getVal();
    void setVal(const double& eVal);
};


#endif // BASEOBJECT_H
