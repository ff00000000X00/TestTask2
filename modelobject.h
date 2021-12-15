#ifndef MODELOBJECT_H
#define MODELOBJECT_H
#include "baseObject.h"
#include <QVector>
#include <QMap>


class ModelObject
{
private:
    QString objectName;
    QMap<QString,BasicObject*> modObj;
public:
    ModelObject(const QString& eName);

    void addValue(const QString& key,BasicObject* bo);
    void addValue(const QString& key,const QString & strVal);
    void addValue(const QString& key,const bool &   boolVal);
    void addValue(const QString& key,const double & doubleVal);


    QVariant data(const QString& key) const;
    QVariant data(const int& key) const;

};

#endif // MODELOBJECT_H
