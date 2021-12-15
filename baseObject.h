#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <QString>
#include <QVariant>


class BasicObject
{
    QVariant baseValue;
public:
    BasicObject(const QVariant& eVal);
    QVariant data();
    void setVal(const QVariant& eVal);
};

#endif // BASEOBJECT_H
