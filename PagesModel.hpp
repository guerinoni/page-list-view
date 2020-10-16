#pragma once

#include "FilterForPage.hpp"
#include "ItemsModel.hpp"

#include <memory>

class PagesModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int currentPage READ currentPage WRITE setCurrentPage NOTIFY
                   currentPageChanged)

    Q_PROPERTY(QSortFilterProxyModel *itemsForPage READ itemsForPage NOTIFY
                   itemsForPageChanged)

  public:
    explicit PagesModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;

    int currentPage() const noexcept;
    void setCurrentPage(int value);

    QSortFilterProxyModel *itemsForPage();

    void setTotalItems(int number);

  signals:
    void currentPageChanged();
    void itemsForPageChanged();

  private:
    std::unique_ptr<ItemsModel> m_itemsModel;
    int m_currentPage{ 0 };
    FilterForPage m_itemsForPage;

    void createModelForPage();
};
