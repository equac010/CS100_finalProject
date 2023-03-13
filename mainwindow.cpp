#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./inputform.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();
    series->append("Protein", 40);
    series->append("Fat", 25);
    series->append("Carbs", 35);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Daily Macros");

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(ui->frame);

    //Attempt
//    //![1]
//        QPieSeries *series = new QPieSeries();
//        series->append("Jane", 1);
//        series->append("Joe", 2);
//        series->append("Andy", 3);
//        series->append("Barbara", 4);
//        series->append("Axel", 5);
//    //![1]

//    //![2]
//        QPieSlice *slice = series->slices().at(1);
//        slice->setExploded();
//        slice->setLabelVisible();
//        slice->setPen(QPen(Qt::darkGreen, 2));
//        slice->setBrush(Qt::green);
//    //![2]

//    //![3]
//        QChart *chart = new QChart();
//        chart->addSeries(series);
//        chart->setTitle("Simple piechart example");
//        chart->legend()->hide();
//    //![3]

//    //![4]
//        QChartView *chartView = new QChartView(chart);
//        chartView->setRenderHint(QPainter::Antialiasing);
//    //![4]

//    //![5]
//        QMainWindow window;
//        window.setCentralWidget(chartView);
//        window.resize(400, 300);
//        window.show();

//    }

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

