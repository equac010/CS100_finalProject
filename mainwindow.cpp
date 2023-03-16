#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addfooddialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mealInputButton_clicked()
{
    AddFoodDialog addDialog;
    addDialog.exec();
}


void MainWindow::on_deleteButton_clicked()
{

}

