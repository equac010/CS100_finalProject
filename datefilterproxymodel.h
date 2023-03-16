#ifndef DATEFILTERPROXYMODEL_H
#define DATEFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QDate>

class DateFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit DateFilterProxyModel(QObject *parent = nullptr);
    QDate filterStartDate() const {return startDate;}
    void setFilterStartDate(QDate date);
    QDate filterEndDate() const {return endDate;}
    void setFilterEndDate(QDate date);

    bool filterAcceptsRow(int row, const QModelIndex &sourceParent) const;

private:
    QDate startDate;
    QDate endDate;
    bool dateInRange(QDate date) const;
};

#endif // DATEFILTERPROXYMODEL_H
