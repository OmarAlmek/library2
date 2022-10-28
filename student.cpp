#include "student.h"
#include "ui_student.h"
Student::Student(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Student)
{
    ui->setupUi(this);
}

Student::~Student()
{
    delete ui;
}


void Student::on_pushButton_signin_clicked()
{
    for (int i=0; i<100; i++){
        if(ui->lineEdit_name->text()== names[i] && ui->lineEdit_password_2->text()== passwords[i]){
            ui->label_unknown->setText("Signing in");
            ui->label_id->setText(iDs[i]);
            ui->label_balance->setText(QString::number(accbal[i]));
            FDialog fdialog(iDs[i], accbal[i]);
            fdialog.setModal(true);
            fdialog.exec();
            return;
        }
        else if(ui->lineEdit_name->text()== names[i] && ui->lineEdit_password_2->text()!= passwords[i]){
            ui->label_unknown->setText("incorrect password");
            return;
        }
        else ui->label_unknown->setText("incorrect username");
}
}
