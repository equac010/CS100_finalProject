#ifndef INPUTFORM_H
#define INPUTFORM_H

#include "QtWidgets/qabstractbutton.h"
#include <QDialog>
#include <QString>

#include "food.h"
#include "meal.h"
#include "nutrition.h"
#include <vector>
#include <iterator>

namespace Ui {
class InputForm;
}

class InputForm : public QDialog
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = nullptr);
    ~InputForm();

    QString foodName;
    int quantity = 0;
    Nutrition n;

    int calories = 0;
    int protein = 0;
    int fat = 0;
    int carbs = 0;

    //std::vector<Food> foods = {};

    //Meal m(foods);


private slots:
    void on_saveButton_clicked(QAbstractButton *button);

    void on_cancelButton_clicked(QAbstractButton *button);


    void on_doubleSpinBox_Qty_valueChanged(double qtyInput);

    void on_spinBo_caal_valueChanged(int calInput);

    void on_doubleSpinBox_protein_valueChanged(double proteinInput);

    void on_doubleSpinBox_fat_valueChanged(double fatInput);

    void on_doubleSpinBox_carbs_valueChanged(double carbInput);




private:
    Ui::InputForm *ui;
};

#endif // INPUTFORM_H
