#include "tabwidget.h"
#include "QtWidgets/qgridlayout.h"
#include "QtWidgets/qheaderview.h"
#include "QtWidgets/qpushbutton.h"
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
    auto dailyTableView = new QTableView();

    dailyTableView->setModel(proxyModel);
    dailyTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    dailyTableView->horizontalHeader()->setStretchLastSection(true);
    dailyTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    dailyTableView->setSelectionMode(QAbstractItemView::SingleSelection);

    auto addFoodButton = new QPushButton(tr("Add Food"));
    auto gridLayout = new QGridLayout;
    gridLayout->addWidget(addFoodButton);
    gridLayout->addWidget(dailyTableView);




    connect(dailyTableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &TabWidget::selectionChanged);
    connect(addFoodButton, &QAbstractButton::clicked, this, &TabWidget::showAddFoodDialog);
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
        addFoodEntry(dialog.name(), dialog.servings(), dialog.calPerServing(), dialog.proteinPerServing(), dialog.carbPerServing(), dialog.fatPerServing());
    }
}

void TabWidget::addFoodEntry(const QString &foodName, const double servings, const int calPerServing, const int proteinPerServing, const int carbPerServing, const int fatPerServing)
{
    QList<QVariant> listOfParameters = {foodName, servings, calPerServing, proteinPerServing, carbPerServing, fatPerServing, QDateTime::currentDateTime()};
    table->insertRows(0, 1, QModelIndex());
    QModelIndex index = table->index(0,0, QModelIndex());
    for (int i = 0; i < 7; ++i) {
        index = table->index(0, i, QModelIndex());
        table->setData(index, listOfParameters[i], Qt::EditRole);
    }
}

/*
void TabWidget::editEntry()
{

}

void TabWidget::removeEntry()
{

}
*/

void TabWidget::setupTabs()
{

}
