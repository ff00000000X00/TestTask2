#include "model.h"

Model::Model(const QList<Model::pObject> &modelObjects, QObject *parent)
{

}

Model::~Model()
{
}

int Model::rowCount(const QModelIndex &parent) const
{

}

int Model::columnCount(const QModelIndex &parent) const
{
    return iModelObject.size();
}

