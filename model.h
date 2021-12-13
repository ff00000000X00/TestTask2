#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "objects.h"
#include <memory>


class Model : public QObject
{
    Q_OBJECT
private:
    std::unique_ptr<BaseObject> modelObject;
public:
    Model(QObject *parent = nullptr);
    ~Model();
};
#endif // MODEL_H
