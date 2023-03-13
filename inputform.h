#ifndef INPUTFORM_H
#define INPUTFORM_H

#include "QtWidgets/qabstractbutton.h"
#include <QDialog>
#include <QString>
namespace Ui {
class InputForm;
}

class InputForm : public QDialog
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = nullptr);
    ~InputForm();
    QString foodName;

private slots:
    void on_saveButton_clicked(QAbstractButton *button);

    void on_cancelButton_clicked(QAbstractButton *button);


    void on_doubleSpinBox_Qty_valueChanged(double qtyInput);

    void on_spinBo_caal_valueChanged(int calInput);

    void on_doubleSpinBox_protein_valueChanged(double proteinInput);

    void on_doubleSpinBox_fat_valueChanged(double fatInput);

    void on_doubleSpinBox_carbs_valueChanged(double carbInput);

    void on_textName_objectNameChanged(const QString &foodName);

private:
    Ui::InputForm *ui;
};

#endif // INPUTFORM_H
