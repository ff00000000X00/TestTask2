#include "baseObject.h"

BasicObject::BasicObject(const QVariant &eVal)
    :baseValue(eVal)
{}

QVariant BasicObject::data()
{
    return  baseValue;
}

void BasicObject::setVal(const QVariant &eVal)
{
    baseValue = eVal;
}
