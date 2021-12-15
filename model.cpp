#include "model.h"

Model::Model(QList<ModelObject*> &modelObjects, QObject *parent)
    :QAbstractTableModel(parent)
    ,iModelObject(modelObjects)
{}

Model::~Model()
{}

int Model::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return 4;
}

int Model::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return iModelObject.size();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    if(index.column() < 0 || index.column() >= columnCount())
        return QVariant();
    if(index.row() < 0 || index.row() >= rowCount())
        return QVariant();
    if (role == Qt::DisplayRole || role==Qt::EditRole)
    {
       return iModelObject.at(index.column())->data(index.row());
    }
    return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
  i++;
    if(role != Qt::DisplayRole){
        return QVariant();}

        return (orientation == Qt::Horizontal)?
                    iModelObject.at(section)->name():
                    iModelObject.at(i)->key(section);

}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if(index.isValid()&&role == Qt::EditRole)
    {
        iModelObject.at(index.column())->data(index.row()).setValue(value);
        emit dataChanged(index,index);
        return true;
    }

    return false;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    return index.isValid()?(flags | Qt::ItemIsEditable):flags;

}

bool Model::insertRows(int row, int count, const QModelIndex &parent)
{

}

bool Model::removeRows(int row, int count, const QModelIndex &parent)
{

}

bool Model::insertColumns(int column, int count, const QModelIndex &parent)
{

}

bool Model::removeColumns(int column, int count, const QModelIndex &parent)
{

}

