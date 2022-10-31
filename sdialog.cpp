#include "sdialog.h"
#include "ui_sdialog.h"

SDialog::SDialog(QString *purchasedbooks, int c, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SDialog)
{
    ui->setupUi(this);
    for (int i=0; i <c; i++){
        ui->textEdit->append(purchasedbooks[i]);
        ui->textEdit->setReadOnly(true);}
}

SDialog::~SDialog()
{
    delete ui;
}
