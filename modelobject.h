#ifndef MODELOBJECT_H
#define MODELOBJECT_H
#include "baseObject.h"
#include <QVector>
#include <QMap>


class ModelObject
{
private:
    QString objectName;
    QMap<QString,BasicObject> modObj;
public:
    ModelObject(const QString& eName);

    void addValue(const QString& key,const QVariant& val);

    QString name();
    QString key(const int& key);


    QVariant data(const QString& key) ;
    QVariant data(const int& key) ;

};

#endif // MODELOBJECT_H
