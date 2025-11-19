
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculation.h"  // Теперь используем Calculation

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDigitClicked();
    void onOperationClicked();
    void onEqualsClicked();
    void onClearClicked();
    void onChangeSignClicked();
    void onDecimalPointClicked();

    void onLParClicked();
    void onRParClicked();
private:
    Ui::MainWindow *ui;
    Calculation calculation;  // Экземпляр класса Calculation

    void setupConnections();
    void updateUI();
};

#endif // MAINWINDOW_H
