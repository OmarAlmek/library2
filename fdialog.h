#ifndef FDIALOG_H
#define FDIALOG_H
#include <QDialog>
namespace Ui {
class FDialog;
}

class FDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FDialog (QString iDs, int accbal, QWidget *parent = nullptr);
    ~FDialog();

private slots:
    void on_pushButton_recharge_clicked();

    void on_pushButton_purchasedbooks_clicked();

    void on_pushButton_purchsebook_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::FDialog *ui;
    QString booknames[7]= {"Phyics 1", "Physics 2", "Psychology", "Arabic", "How to train your dragon", "C++ introduction", "The theif and the dogs"};
    int bookprices[7]= {200, 500, 1000, 300, 2000, 1500, 700};
    QString *books = new QString [10];
    int count;

};

#endif // FDIALOG_H
