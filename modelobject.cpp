#include "modelobject.h"

ModelObject::ModelObject(const QString &eName)
    :objectName(eName)
{}

void ModelObject::addValue(const QString &key, BasicObject *bo)
{
    modObj.insert(key,bo);
}

void ModelObject::addValue(const QString &key, const QString & strVal)
{
    BasicObject* baseVal = new StrObject(strVal);
    addValue(key,baseVal);
}

void ModelObject::addValue(const QString &key, const bool &boolVal)
{
    BasicObject* baseVal = new BoolObject(boolVal);
    addValue(key,baseVal);
}

void ModelObject::addValue(const QString &key, const double &doubleVal)
{
    BasicObject* baseVal = new DoubleObject(doubleVal);
    addValue(key,baseVal);
}

QVariant ModelObject::data(const QString& key) const
{
   if(modObj.contains(key))
   {
       auto val = modObj.find(key);
       if(val!=modObj.end())
           return val.value()->data();
   }
   return QVariant();
}

QVariant ModelObject::data(const int &key) const
{
    if(key>=0 || key<=modObj.size())
    {
        return (modObj.begin()+key).value()->data();
    }
    return QVariant();
}




