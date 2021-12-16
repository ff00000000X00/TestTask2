#include "modelobject.h"

ModelObject::ModelObject(const QString &eName)
    :objectName(eName)
{}

QString ModelObject::name()const noexcept
{
    return objectName;
}

QString ModelObject::key(const int &key)const noexcept
{
    if(key>=0 || key<=modObj.size())
    {
        return (modObj.begin()+key).key();
    }
    return QString();
}

void ModelObject::addValue(const QString &key, const QVariant & val)
{
    modObj.insert(key,val);
}

QList<QString> ModelObject::keys()const noexcept
{
    return modObj.keys();
}

void ModelObject::setData(const QString &key, const QVariant& eVal) noexcept
{
    if(modObj.contains(key))
    {
        auto val = modObj.find(key);
        if(val!=modObj.end())
            val.value() = eVal;
    }
}

QVariant ModelObject::data(const QString& key)const noexcept
{
   if(modObj.contains(key))
   {
       auto val = modObj.find(key);
       if(val!=modObj.end())
           return val.value();
   }
   return QVariant();
}

QVariant ModelObject::data(const int &key)const noexcept
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



