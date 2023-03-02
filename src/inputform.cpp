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

void InputForm::on_buttonBox_clicked(QAbstractButton *button)
{
    close();
}

