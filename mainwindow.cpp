#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./inputform.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    QPieSeries *series = new QPieSeries();
    series->append("Protein", 40);
    series->append("Fat", 25);
    series->append("Carbs", 35);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Daily Macros");

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->frame);
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mealInputButton_clicked()
{
    InputForm inputForm;
    inputForm.exec();
}

