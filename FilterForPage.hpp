#pragma once

#include <QSortFilterProxyModel>

class FilterForPage : public QSortFilterProxyModel
{
    Q_OBJECT

  public:
    void setPage(int p);

  protected:
    bool filterAcceptsRow(int source_row,
                          const QModelIndex &source_parent) const override;

  private:
    int m_row{ 0 };
};
