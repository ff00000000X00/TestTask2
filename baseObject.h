#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <QString>
#include <QVariant>


class BasicObject
{
    QVariant baseValue;
public:
    BasicObject(const QVariant& eVal);
    virtual QVariant data();
    virtual void setVal(const QVariant& eVal);
};

class StrObject:public BasicObject
{
    QString iVal;
public:
    StrObject(const QString& eVal);;
    QVariant data() override;
    void setVal(const QVariant& eVal) override;
};

class BoolObject:public BasicObject
{
    bool iVal;
public:
    BoolObject(const bool& eVal);
    QVariant data() override;
    void setVal(const QVariant& eVal) override;
};

class DoubleObject:public BasicObject
{
    double iVal;
public:
    DoubleObject(const double& eVal);
    QVariant data() override;
    void setVal(const QVariant& eVal) override;
};


#endif // BASEOBJECT_H
