#include "foodtablemodel.h"
#include "food.h"
#include <QDateTime>

FoodTableModel::FoodTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant FoodTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Name");
        case 1:
            return tr("Servings");
        case 2:
            return tr("Calories");
        case 3:
            return tr("Carbs");
        case 4:
            return tr("Fat");
        case 5:
            return tr("Protein");
        case 6:
            return tr("Date");
        default:
            break;
        }
    }
    return QVariant();
}

bool FoodTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }

    return false;
}


int FoodTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return listOfFoods.size();
    }

    return 0;
}

int FoodTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 7; // Name, Servings, Calories, Carbs, Fat, Protein, QDateTime
    }
    return 0;
}

QVariant FoodTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= listOfFoods.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &pair = listOfFoods.at(index.row());

        switch(index.column()) {
        case 0:
            return pair.first.getName();
            break;
        case 1:
            return pair.first.getServings();
            break;
        case 2:
            return pair.first.getCalPerServing();
            break;
        case 3:
            return pair.first.getCarbsPerServing();
            break;
        case 4:
            return pair.first.getFatPerServing();
            break;
        case 5:
            return pair.first.getProteinPerServing();
            break;
        case 6:
            return pair.second.date();
            break;
        default:
            break;
        }

    }
    return QVariant();
}

bool FoodTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto foodDate = listOfFoods.value(row);

        switch (index.column()) {
        case 0:
            foodDate.first.setName(value.toString());
            break;

        case 1:
            foodDate.first.setServings(value.toInt());
            break;
        case 2:
            foodDate.first.setCalPerServing(value.toInt());
            break;
        case 3:
            foodDate.first.setCarbsPerServing(value.toInt());
            break;
        case 4:
            foodDate.first.setFatPerServing(value.toInt());
            break;
        case 5:
            foodDate.first.setProteinPerServing(value.toInt());
        case 6:
            //Date cannot be set manually for a food entry
        default:
            return false;

        }
        listOfFoods.replace(row, foodDate);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

Qt::ItemFlags FoodTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool FoodTableModel::insertRows(int position, int rows, const QModelIndex &parent)
{

    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) {
        QPair<Food, QDateTime> defaultFood(Food(), QDateTime::currentDateTime());
        listOfFoods.insert(position, defaultFood);
    }


    endInsertRows();
    return true;
}

bool FoodTableModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        listOfFoods.removeAt(position);
    endRemoveRows();
    return true;
}

const QList<QPair<Food, QDateTime> > &FoodTableModel::getFoodList() const
{
    return listOfFoods;
}
