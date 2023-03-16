#include "addfooddialog.h"
#include "ui_addfooddialog.h"

AddFoodDialog::AddFoodDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFoodDialog)
{
    ui->setupUi(this);
    connect(ui->saveButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(ui->cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Food"));
}

AddFoodDialog::~AddFoodDialog()
{
    delete ui;
}

QString AddFoodDialog::name()
{
    return ui->nameLine->text();
}

double AddFoodDialog::servings()
{
    return ui->doubleSpinBox_serving->value();
}

int AddFoodDialog::calPerServing()
{
    return ui->spinBox_cal->value();
}

int AddFoodDialog::proteinPerServing()
{
    return ui->doubleSpinBox_protein->value();
}

int AddFoodDialog::carbPerServing()
{
    return ui->doubleSpinBox_carbs->value();
}

int AddFoodDialog::fatPerServing()
{
    return ui->doubleSpinBox_fat->value();
}
