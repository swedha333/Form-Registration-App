#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QRegularExpression>
#include <QValidator>
#include <QRegularExpressionMatch>
#include <QRegularExpressionValidator>
#include<QMessageBox>

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


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::information(this,"Sudherson-212218205058","Submitted");

}

void MainWindow::on_lineEdit_returnPressed()
{
    if(ui->lineEdit->text().length()>200)
        QMessageBox::information(this,"Sudherson-212218205058","More than 50 words in Area of Interest");

}

void MainWindow::on_lineEdit_2_returnPressed()
{
    QRegularExpression sh("^[a-zA-Z0-9+_.-]+@[a-zA-Z0-9.-]+$");
    QRegularExpressionMatch match = sh.match(ui->lineEdit_2->text());
    bool hasMatch=match.hasMatch();
    if(!hasMatch)
    {
       QMessageBox::information(this,"Sudherson-212218205058","EmailID is invalid");
    }

}


void MainWindow::on_pushButton_clicked()
{
    foreach(QLineEdit* widget, findChildren<QLineEdit*>())
    {
        widget->clear();
    }
}
