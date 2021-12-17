#include "model.h"


void Model::setKeys()
{
    for(auto val:iModelObject)
    {
        keys<<val->keys();
        keys.removeDuplicates();
    }
}

Model::Model(QList<ModelObject*> &modelObjects, QObject *parent)
    :QAbstractTableModel(parent)
    ,iModelObject(modelObjects)
{setKeys();}

Model::~Model()
{}

int Model::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    if(iTransposed)
        return keys.size();
    else
        return iModelObject.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    if(iTransposed)
        return iModelObject.size();
    else
        return keys.size();
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
        if(iTransposed)
            return iModelObject.at(index.column())->data(keys.at(index.row()));
        else
            return iModelObject.at(index.row())->data(keys.at(index.column()));
    }
    return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole){
        return QVariant();}

    if(iTransposed){
        return (orientation == Qt::Horizontal)?
                    iModelObject.at(section)->name():
                    keys.at(section);
        }
    else
    {
        return (orientation == Qt::Vertical)?
                    iModelObject.at(section)->name():
                    keys.at(section);
    }
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role)
{
   if(index.isValid()&&role == Qt::EditRole)
    {
        iModelObject.at(index.column())->setData(keys.at(index.row()),value);
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

void Model::slotObjectToString(const QItemSelectionModel *model)
{
    for (auto iVal:model->selectedIndexes())
    {
        auto val = data(iVal, Qt::EditRole);
        setData(iVal,val.toString(),Qt::EditRole);
    }
}

void Model::slotObjectToDouble(const QItemSelectionModel *model)
{
    for (auto iVal:model->selectedIndexes())
    {
        auto val = data(iVal, Qt::EditRole);
        setData(iVal,val.toDouble(),Qt::EditRole);
    }

}

void Model::slotObjectToBool(const QItemSelectionModel *model)
{

    for (auto iVal:model->selectedIndexes())
    {
        auto val = data(iVal, Qt::EditRole);
        setData(iVal,val.toBool(),Qt::EditRole);
    }
}

void Model::slotTranspose()
{
    iTransposed = !iTransposed;
    this->headerDataChanged(Qt::Horizontal,0,iModelObject.size());
    this->headerDataChanged(Qt::Vertical,0,keys.size());
}
