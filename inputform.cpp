#include "inputform.h"
#include "ui_inputform.h"
#include "food.h"
#include "meal.h"

#include <iostream>

InputForm::InputForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputForm)
{
    ui->setupUi(this);
}

InputForm::~InputForm()
{
    delete ui;
}

void InputForm::on_saveButton_clicked(QAbstractButton *button){
    QString foodName = ui->textName->toPlainText();


    std::cout << foodName.toStdString() << std::endl;
    std::cout << quantity << std::endl;
    std::cout << calories << std::endl;
    std::cout << protein << std::endl;
    std::cout << fat << std::endl;
    std::cout << carbs << std::endl;





    //m.addFood(Food(foodName,quantity,n));
    close();
}

void InputForm::on_cancelButton_clicked(QAbstractButton *button){
    close();
}



void InputForm::on_doubleSpinBox_Qty_valueChanged(double qtyInput){
    quantity = qtyInput;
}

void InputForm::on_spinBo_caal_valueChanged(int calInput){
    calories = calInput;
}

void InputForm::on_doubleSpinBox_protein_valueChanged(double proteinInput){
    protein = proteinInput;
}

void InputForm::on_doubleSpinBox_fat_valueChanged(double fatInput){
    fat=fatInput;
}

void InputForm::on_doubleSpinBox_carbs_valueChanged(double carbInput){
    carbs = carbInput;
}




