#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT

public:
    Model(QWidget *parent = nullptr);
    ~Model();
};
#endif // MODEL_H
