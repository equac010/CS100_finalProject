#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      tabWidget(new TabWidget)

{
    setCentralWidget(tabWidget);
    setWindowTitle(tr("Calorie Tracker App"));
}

MainWindow::~MainWindow()
{

}


