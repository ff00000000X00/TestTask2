#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <QString>
#include <map>

/*
 * Я думал над тем, чтобы сделать класс шаблонным,
 * но в итоге отказался от этой мысли, т.к. условия были довольно четкие
 * А при создание шаблонного класса их можно было бы обойти
 *
 * И да, тут 4 класса в одном хедере, я понимаю что плохо, сделал нарочно, чтоб не раздувать
 * проект файлами с микроклассами. Одно другого не лучше, конечно.
 */


class BaseObject
{
private:
    const QString iName;
public:
protected:
    BaseObject(const QString& eName);
    virtual ~BaseObject(){};
    virtual void setData(const std::map<QString,QString>&) = 0;
    virtual void setData(const std::map<QString,int>&) = 0;
    virtual void setData(const std::map<QString,double>&) = 0;
};
/*
 * *****************************************************************
 */

class StrObject:public BaseObject
{
private:
    std::map<QString,QString> iData;
public:
    StrObject(const QString& eName,const std::map<QString,QString>& eData);
    void setData(const std::map<QString,QString>&eData) override;
};
/*
 * *****************************************************************
 */

class IntObject:public BaseObject
{
private:
    std::map<QString,int> iData;
public:
    IntObject(const QString& eName,const std::map<QString,int>& eData);
    void setData(const std::map<QString,int>& eData) override;
};
/*
 * *****************************************************************
 */
class DoubleObject:public BaseObject
{
private:
    std::map<QString,double> iData;
public:
    DoubleObject(const QString& eName,const std::map<QString,double>& eData);
    void setData(const std::map<QString,double>& eData) override;
};

#endif // BASEOBJECT_H
