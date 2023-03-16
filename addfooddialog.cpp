#include "addfooddialog.h"
#include "ui_addfooddialog.h"

AddFoodDialog::AddFoodDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFoodDialog)
{
    ui->setupUi(this);
}

AddFoodDialog::~AddFoodDialog()
{
    delete ui;
}
