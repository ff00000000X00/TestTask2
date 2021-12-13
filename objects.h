#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <QString>
#include <map>

/*
 * Я думал над тем, чтобы сделать класс шаблонным,
 * но в итоге отказался от этой мысли, т.к. условия были довольно четкие
 * А при создание шаблонного класса их можно было бы обойти
 */


class BaseObject
{
private:
    const QString iName;
public:
protected:
    BaseObject(const QString& eName);
    virtual ~BaseObject(){};
    virtual void setData(std::map<QString,QString>) = 0;
    virtual void setData(std::map<QString,int>) = 0;
    virtual void setData(std::map<QString,double>) = 0;
};

class StrObject:public BaseObject
{
private:
    std::map<QString,QString> iData;
    QString iStrVal;
public:
    StrObject(const QString& eName,const std::map<QString,QString>& eData);
    void setData(std::map<QString,QString>) override;
};

class IntObject:public BaseObject
{
private:
    std::map<QString,int> iData;
    int iIntVal;
public:
    IntObject(const QString& eName,const std::map<QString,int>& eData);
    void setData(std::map<QString,int>) override;
};

class DoubleObject:public BaseObject
{
private:
    std::map<QString,double> iData;
    double iDoubleVal;
public:
    DoubleObject(const QString& eName,const std::map<QString,double>& eData);
    void setData(std::map<QString,double>) override;
};

#endif // BASEOBJECT_H
