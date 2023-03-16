#include "tabwidget.h"
#include "QtWidgets/qheaderview.h"
#include "QtWidgets/qtableview.h"
#include "addfooddialog.h"
#include "datefilterproxymodel.h"
#include <QSortFilterProxyModel>

TabWidget::TabWidget(QWidget *parent):
    QTabWidget(parent)
{
    auto proxyModel = new DateFilterProxyModel(this);
    proxyModel->setSourceModel(table);
    proxyModel->setFilterStartDate(QDate(QDate::currentDate()));
    proxyModel->setFilterEndDate(QDate(QDate::currentDate()));

    //I'm setting up the tableView in this code rather than the ui file since I don't know otherwise how to reference it and set its properties
    auto tableView = new QTableView();

    tableView->setModel(proxyModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &TabWidget::selectionChanged);
}

void TabWidget::readFromFile(const QString &fileName)
{

}

void TabWidget::writeToFile(const QString &fileName)
{

}

void TabWidget::showAddFoodDialog()
{
    AddFoodDialog dialog;
    if (dialog.exec()) {
        addFoodEntry()
    }
}

void TabWidget::addFoodEntry(const QString &foodName)
{

}

void TabWidget::editEntry()
{

}

void TabWidget::removeEntry()
{

}

void TabWidget::setupTabs()
{

}
