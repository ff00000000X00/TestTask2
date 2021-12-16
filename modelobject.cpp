#include "modelobject.h"

ModelObject::ModelObject(const QString &eName)
    :objectName(eName)
{}

void ModelObject::addValue(const QString &key, const QVariant & val)
{
    modObj.insert(key,val);
}

QString ModelObject::name()
{
    return objectName;
}

QString ModelObject::key(const int &key)
{
    if(key>=0 || key<=modObj.size())
    {
        return (modObj.begin()+key).key();
    }
    return QString();
}

QList<QString> ModelObject::keys()
{
    return modObj.keys();
}

QVariant ModelObject::data(const QString& key)
{
   if(modObj.contains(key))
   {
       auto val = modObj.find(key);
       if(val!=modObj.end())
           return val.value();
   }
   return QVariant();
}

QVariant ModelObject::data(const int &key)
{
    if(key<0 || key>=modObj.size())
    {
        return QVariant();
    }
    else
    return (modObj.begin()+key).value();
}


/*
void ModelObject::setVal(const QVariant &eVal)
{
    baseValue = eVal;
}
*/



