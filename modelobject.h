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

    QString name() const noexcept;
    QString key(const int& key) const noexcept;
    QList<QString> keys() const noexcept;


    void addValue(const QString &key, const QVariant & val);
    void setData (const QString& key, const QVariant &val)noexcept;
    QVariant data(const QString& key) const noexcept;
    QVariant data(const int& key) const noexcept;

};

#endif // MODELOBJECT_H
