#pragma once

#include <QAbstractListModel>

class ItemsModel : public QAbstractListModel
{
    Q_OBJECT

  public:
    explicit ItemsModel(int total, QObject *parent = nullptr);

    enum Rolez { Name = Qt::UserRole + 1 };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void createItems(int number);

  private:
    QVector<QString> m_items;
};
