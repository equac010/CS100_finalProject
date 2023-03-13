#include "inputform.h"
#include "ui_inputform.h"

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
    close();
}

void InputForm::on_cancelButton_clicked(QAbstractButton *button){
    close();

}


void InputForm::on_doubleSpinBox_Qty_valueChanged(double qtyInput){}

void InputForm::on_spinBo_caal_valueChanged(int calInput){}

void InputForm::on_doubleSpinBox_protein_valueChanged(double proteinInput){}

void InputForm::on_doubleSpinBox_fat_valueChanged(double fatInput){}

void InputForm::on_doubleSpinBox_carbs_valueChanged(double carbInput){}

void InputForm::on_textName_objectNameChanged(const QString &foodName){}



