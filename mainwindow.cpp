#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"SamathmikaK 212218205044","Successfully Submitted!!");
}


void MainWindow::on_lineEdit_6_returnPressed()
{
    if(ui->lineEdit_6->text().length()>20)
           QMessageBox::information(this,"SamathmikaK 212218205044","Size exceeded!");
}

void MainWindow::on_lineEdit_3_returnPressed()
{
    QRegularExpression re("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    QRegularExpressionMatch match = re.match(ui->lineEdit_3->text());
    bool hasMatch = match.hasMatch();
    if (!hasMatch)
    {
       QMessageBox::information(this,"SamathmikaK 212218205044","Invalid Format");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    foreach(QLineEdit* widget, findChildren<QLineEdit*>())
    {
        widget->clear();
    }
}
