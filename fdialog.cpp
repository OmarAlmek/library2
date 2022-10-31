#include "fdialog.h"
#include "sdialog.h"
#include "ui_fdialog.h"

FDialog::FDialog( QString iDs, int accbal, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FDialog)
{
    ui->setupUi(this);

    for(int i=0; i < 7; i++){
        if(i ==0){
            ui->comboBox->addItem("");}
       else ui->comboBox->addItem(booknames[i]);
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
    if((ui->lineEdit->text().toInt() < 0)){
             ui->label_negamount->setText("Please enter positive value to add to your balance");
    }

    else ui->label_balance->setText(QString::number(ui->lineEdit->text().toInt()+ ui->label_balance->text().toInt()));

      ui->lineEdit->setText("");
}


void FDialog::on_pushButton_purchasedbooks_clicked()
{
    SDialog sdialog(books, count);
    sdialog.setModal(true);
    sdialog.exec();
}


void FDialog::on_pushButton_purchsebook_clicked()
{
    if(ui->comboBox->itemText(ui->comboBox->currentIndex()) == ""){
        ui->label_bookmessage->setText("Please select a book to buy");
        return;
    }
    if(ui->label_balance->text().toInt() < ui->label_bookprice->text().toInt()){
        ui->label_bookmessage->setText("balance needs to be recharged");
    return;}
 else{
        books[count]= ui->comboBox->itemText(ui->comboBox->currentIndex());
        count++;
     ui->label_bookmessage->setText("book Purchased!");
     ui->label_balance->setText(QString::number((ui->label_balance->text().toInt())- (ui->label_bookprice->text().toInt())));
     return;
}}


void FDialog::on_comboBox_activated(int index)
{
    ui->label_bookprice->setText(QString::number(bookprices[index]));
}

