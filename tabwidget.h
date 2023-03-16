#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "QtCore/qitemselectionmodel.h"
#include "foodtablemodel.h"

class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    TabWidget(QWidget* parent = nullptr);
    void readFromFile(const QString &fileName);
    void writeToFile(const QString &fileName);

public slots:
    void showAddFoodDialog();
    void addFoodEntry(const QString &foodName);
    void editEntry();
    void removeEntry();

signals:
    void selectionChanged (const QItemSelection &selected);

private:
    void setupTabs();

    FoodTableModel *table;
};

#endif // TABWIDGET_H
