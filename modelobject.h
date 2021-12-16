#ifndef MODELOBJECT_H
#define MODELOBJECT_H
#include <QVariant>
#include <QVector>
#include <QMap>


class ModelObject
{
private:
    QString objectName;
    QMap<QString,QVariant> modObj;
public:
    ModelObject(const QString& eName);

    void addValue(const QString& key,const QVariant& val);
    //void setVal(const QVariant& eVal);

    QString name();
    QString key(const int& key);
    QList<QString> keys();



    QVariant data(const QString& key) ;
    QVariant data(const int& key) ;

};

#endif // MODELOBJECT_H
