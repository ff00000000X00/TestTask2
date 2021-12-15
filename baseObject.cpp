#include "baseObject.h"

BasicObject::BasicObject(const QVariant &eVal)
    :baseValue(eVal)
{}

QVariant BasicObject::data()
{
    return  QVariant();
}

void BasicObject::setVal(const QVariant &eVal)
{
    baseValue = eVal;
}
//
StrObject::StrObject(const QString &eVal)
    :BasicObject(eVal)
{}

QVariant StrObject::data()
{
    return iVal;
}

void StrObject::setVal(const QVariant &eVal)
{
    iVal = eVal.toString();
}
//


BoolObject::BoolObject(const bool &eVal)
    :BasicObject(eVal)
{}

QVariant BoolObject::data()
{
    return iVal;
}

void BoolObject::setVal(const QVariant &eVal)
{
    iVal = eVal.toBool();
}

//
DoubleObject::DoubleObject(const double &eVal)
    :BasicObject(eVal)
{}

QVariant DoubleObject::data()
{
    return iVal;
}

void DoubleObject::setVal(const QVariant &eVal)
{
    iVal = eVal.toDouble();
}
