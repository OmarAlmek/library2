#ifndef STUDENT_H
#define STUDENT_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Student; }
QT_END_NAMESPACE

class Student : public QMainWindow
{
    Q_OBJECT

public:
    Student(QWidget *parent = nullptr);
    ~Student();

private slots:
    void on_pushButton_signin_clicked();

private:
    Ui::Student *ui;
    QString names[100] = {"Mohammed", "Omar", "Ali", "Youssef", "Rodaina"};
    QString passwords[100]= {"12345", "qwer", "lolol", "abc", "54321"};
    QString iDs[100]= {"90001", "90010", "90100", "91000", "90002"};
    int accbal [100]= {1000, 500, 200, 600, 3000};
};
#endif // STUDENT_H
