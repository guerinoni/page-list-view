#include "FilterForPage.hpp"

void FilterForPage::setPage(int p)
{
    m_row = p;
    invalidate();
}

bool FilterForPage::filterAcceptsRow(int source_row,
                                     const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent)
    const auto min = 9 * m_row;
    const auto max = min + 9;
    return source_row >= min && source_row < max;
}
