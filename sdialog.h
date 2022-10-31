#ifndef SDIALOG_H
#define SDIALOG_H

#include <QDialog>

namespace Ui {
class SDialog;
}

class SDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SDialog(QString *purchasedbooks, int count, QWidget *parent = nullptr);
    ~SDialog();

private:
    Ui::SDialog *ui;
};

#endif // SDIALOG_H
