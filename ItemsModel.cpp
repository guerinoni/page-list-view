#include "ItemsModel.hpp"

ItemsModel::ItemsModel(int total, QObject *parent) : QAbstractListModel(parent)
{
    for (auto i = 0; i < total; ++i) {
        m_items.push_back(QString::number(i));
    }
}

int ItemsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_items.size();
}

QVariant ItemsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    if (role == Rolez::Name) {
        return m_items.at(index.row());
    }

    return {};
}

QHash<int, QByteArray> ItemsModel::roleNames() const
{
    return { { Rolez::Name, "nameRole" } };
}
