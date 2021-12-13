#include "objects.h"

BaseObject::BaseObject(const QString& eName)
    :iName(eName)
{}


/*
 * *****************************************************************
 */

StrObject::StrObject(const QString &eName, const std::map<QString,QString>& eData)
    :BaseObject(eName)
    ,iData(eData)
{}

void StrObject::setData(const std::map<QString, QString>& eData)
{
    iData = eData;
}

/*
 * *****************************************************************
 */

IntObject::IntObject(const QString &eName, const std::map<QString,int>& eData)
    :BaseObject(eName)
    ,iData(eData)
{}

void IntObject::setData(const std::map<QString, int> &eData)
{
    iData = eData;
}
/*
 * *****************************************************************
 */
DoubleObject::DoubleObject(const QString &eName, const std::map<QString,double>& eData)
    :BaseObject(eName)
    ,iData(eData)
{}

void DoubleObject::setData(const std::map<QString, double> &eData)
{
    iData = eData;
}
