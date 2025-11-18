#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void clearInput();
    double getValue();
    ~MainWindow();

private slots:
    void on_pushButton_Num1_clicked();

    void on_pushButton_Clear_clicked();

    void on_pushButton_Num2_clicked();

    void on_pushButton_Num3_clicked();

    void on_pushButton_Num4_clicked();

    void on_pushButton_Num5_clicked();

    void on_pushButton_Num6_clicked();

    void on_pushButton_Num7_clicked();

    void on_pushButton_Num8_clicked();

    void on_pushButton_Num9_clicked();

    void on_pushButton_Num0_clicked();

    void on_pushButton_Dot_clicked();

    void on_pushButton_Sum_clicked();

    void on_pushButton_Sub_clicked();

    void on_pushButton_Mul_clicked();

    void on_pushButton_Div_clicked();

    void on_pushButton_Eql_clicked();


private:
    Ui::MainWindow *ui;


    double firstNum = 0;
    double secondNum = 0;
    QString operation;


};
#endif // MAINWINDOW_H
