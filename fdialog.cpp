#include "fdialog.h"
#include "ui_fdialog.h"

FDialog::FDialog(QString iDs, int accbal, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FDialog)
{
    ui->setupUi(this);

    for(int i=0; i < 7; i++){
        ui->comboBox->addItem(booknames[i]);
    }
    ui->label_id->setText(iDs);
    ui->label_balance->setText(QString::number(accbal));


}

FDialog::~FDialog()
{
    delete ui;
}


void FDialog::on_pushButton_recharge_clicked()
{
    if(!(ui->lineEdit->text().toInt() < 0))
        ui->label_balance->setText(QString::number(ui->lineEdit->text().toInt()+ ui->label_balance->text().toInt()));

      ui->lineEdit->setText("");}


void FDialog::on_pushButton_purchasedbooks_clicked()
{

}


void FDialog::on_pushButton_purchsebook_clicked()
{
    if(ui->label_balance->text().toInt() < ui->label_bookprice->text().toInt()){
        ui->label_bookprice->setText("balance needs to be recharged");
    return;}
  ui->label_balance->setText(QString::number((ui->label_balance->text().toInt())- (ui->label_bookprice->text().toInt())));

}


void FDialog::on_comboBox_activated(int index)
{
    ui->label_bookprice->setText(QString::number(bookprices[ui->comboBox->currentIndex()]));
}

