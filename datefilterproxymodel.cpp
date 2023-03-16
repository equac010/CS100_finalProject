#include "datefilterproxymodel.h"

DateFilterProxyModel::DateFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel{parent}
{

}

void DateFilterProxyModel::setFilterStartDate(QDate date)
{
    startDate = date;
    QSortFilterProxyModel::invalidateFilter();
}

void DateFilterProxyModel::setFilterEndDate(QDate date)
{
    endDate = date;
    QSortFilterProxyModel::invalidateFilter();
}

bool DateFilterProxyModel::filterAcceptsRow(int row, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(row,6,sourceParent);

    return dateInRange(sourceModel()->data(index).toDate());
}

bool DateFilterProxyModel::dateInRange(QDate date) const
{
    return (!startDate.isValid() || date > startDate) && (!endDate.isValid() || date < endDate);
}
