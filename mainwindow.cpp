#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDoubleValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->lineEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::clearInput()
{
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_Clear_clicked()
{
    clearInput();
    operation.clear();
}

void MainWindow::on_pushButton_Num1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}


void MainWindow::on_pushButton_Num2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}


void MainWindow::on_pushButton_Num3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}


void MainWindow::on_pushButton_Num4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}


void MainWindow::on_pushButton_Num5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}


void MainWindow::on_pushButton_Num6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}


void MainWindow::on_pushButton_Num7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}


void MainWindow::on_pushButton_Num8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}


void MainWindow::on_pushButton_Num9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}


void MainWindow::on_pushButton_Num0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}


void MainWindow::on_pushButton_Dot_clicked()
{
    QString text = ui->lineEdit->text();

    if(!text.contains(".")){
        ui->lineEdit->setText(ui->lineEdit->text()+".");
    }
}


void MainWindow::on_pushButton_Sub_clicked()
{
    firstNum = ui->lineEdit->text().toDouble();
    operation = "-";
    ui->labelFirstNum->setText("First Number: " + QString::number(firstNum));
    clearInput();
}


void MainWindow::on_pushButton_Mul_clicked()
{
    firstNum = ui->lineEdit->text().toDouble();
    operation = "*";
    ui->labelFirstNum->setText("First Number: " + QString::number(firstNum));
    clearInput();
}


void MainWindow::on_pushButton_Div_clicked()
{
    firstNum = ui->lineEdit->text().toDouble();
    operation = "/";
    ui->labelFirstNum->setText("First Number: " + QString::number(firstNum));
    clearInput();
}

void MainWindow::on_pushButton_Sum_clicked()
{
    firstNum = ui->lineEdit->text().toDouble();
    operation = "+";
    ui->labelFirstNum->setText("First Number: " + QString::number(firstNum));
    clearInput();
}

    void MainWindow::on_pushButton_Eql_clicked()
    {
        double secondNum = ui->lineEdit->text().toDouble();
        double result = 0 ;

        if (operation == "+") result  = firstNum + secondNum;
        else if (operation == "-") result = firstNum + secondNum;
        else if (operation == "*") result = firstNum * secondNum;
        else if (operation == "/" && secondNum != 0) result = firstNum / secondNum;

        ui->lineEdit->setText(QString::number(result));
        ui->labelFirstNum->clear();
    }

    void MainWindow::on_pushButton_ChangeSig_clicked()
    {
        QString currentText = ui->lineEdit->text();

        if (currentText.isEmpty()) {
            ui->lineEdit->setText("-");
            return;
        }

        if (currentText == "-") {
            ui->lineEdit->clear();
            return;
        }

        bool isNegative = currentText.startsWith('-');
        QString numberPart = isNegative ? currentText.mid(1) : currentText;

        if (isNegative) {
            ui->lineEdit->setText(numberPart);
        } else {
            ui->lineEdit->setText("-"+numberPart);
        }

    }






