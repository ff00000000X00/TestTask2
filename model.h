#ifndef MODEL_H
#define MODEL_H
#include <QAbstractTableModel>
#include "modelobject.h"

class Model : public QAbstractTableModel
{
    Q_OBJECT   
private:
    QList<ModelObject*> iModelObject;
    QList<QString> keys;
    void setKeys();
public:
    Model(QList<ModelObject*>& eModelObjects,QObject *parent = nullptr);
    ~Model();
protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;


};
#endif // MODEL_H
