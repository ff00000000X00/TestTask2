#ifndef MODEL_H
#define MODEL_H
#include <QAbstractTableModel>
#include "modelobject.h"
#include <memory>


class Model : public QAbstractTableModel
{
    Q_OBJECT   
private:
    mutable int i= -1;
    QList<ModelObject*> iModelObject;
public:
    Model(QList<ModelObject*>& eModelObjects,QObject *parent = nullptr);
    ~Model();
protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool insertRows (int row, int count, const QModelIndex& parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex())override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex())override;

};
#endif // MODEL_H
