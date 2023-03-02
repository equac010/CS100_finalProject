#ifndef INPUTFORM_H
#define INPUTFORM_H

#include "QtWidgets/qabstractbutton.h"
#include <QDialog>

namespace Ui {
class InputForm;
}

class InputForm : public QDialog
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = nullptr);
    ~InputForm();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::InputForm *ui;
};

#endif // INPUTFORM_H
