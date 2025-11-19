#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QDebug"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    //dog
    connect(ui->pushButton_Num0, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num1, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num2, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num3, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num4, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num5, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num6, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num7, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num8, &QPushButton::clicked, this, &MainWindow::onDigitClicked);
    connect(ui->pushButton_Num9, &QPushButton::clicked, this, &MainWindow::onDigitClicked);

    //op
    connect(ui->pushButton_Sum, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(ui->pushButton_Sub, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(ui->pushButton_Mul, &QPushButton::clicked, this, &MainWindow::onOperationClicked);
    connect(ui->pushButton_Div, &QPushButton::clicked, this, &MainWindow::onOperationClicked);


    //mods
    connect(ui->pushButton_Eql, &QPushButton::clicked, this, &MainWindow::onEqualsClicked);
    connect(ui->pushButton_Clear, &QPushButton::clicked, this, &MainWindow::onClearClicked);
    connect(ui->pushButton_ChangeSig, &QPushButton::clicked, this, &MainWindow::onChangeSignClicked);
    connect(ui->pushButton_Dot, &QPushButton::clicked, this, &MainWindow::onDecimalPointClicked);
}


void MainWindow::updateUI()
{
    ui->lineEdit->setText(calculation.getDisplayText());
    ui->labelFirstNum->setText(calculation.getStatusText());


    qDebug() << "Dis:" << calculation.getDisplayText();
}
void MainWindow::onDigitClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();
    calculation.pressDigit(digit);
    updateUI();
}

void MainWindow::onOperationClicked()
{
    QString op = qobject_cast<QPushButton*>(sender())->text();
    calculation.pressOperation(op);
    updateUI();
}

void MainWindow::onEqualsClicked()
{
    calculation.pressEquals();
    updateUI();
}

void MainWindow::onClearClicked()
{
    calculation.pressClear();
    updateUI();
}

void MainWindow::onChangeSignClicked()
{
    calculation.pressChangeSign();
    updateUI();
}

void MainWindow::onDecimalPointClicked()
{
    calculation.pressDecimalPoint();
    updateUI();
}
