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

    void setValue(const QString& key,BasicObject* bo);
    void setValue(const QString& key,QString strVal);
    void setValue(const QString& key,bool   boolVal);
    void setValue(const QString& key,double doubleVal);

};

#endif // MODELOBJECT_H
