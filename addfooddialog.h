#ifndef ADDFOODDIALOG_H
#define ADDFOODDIALOG_H

#include <QDialog>

namespace Ui {
class AddFoodDialog;
}

class AddFoodDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFoodDialog(QWidget *parent = nullptr);
    ~AddFoodDialog();

private:
    Ui::AddFoodDialog *ui;
};

#endif // ADDFOODDIALOG_H
