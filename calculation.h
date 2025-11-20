#ifndef CALCULATION_H
#define CALCULATION_H

#include <QString>
#include <QStack>


struct CalcContext {
    double firstNum;
    QString operation;
    QString currentInput;
    bool waitingForSecondNumber;
};


class Calculation
{
public:
    Calculation();

    void pressDigit(const QString& digit);
    void pressOperation(const QString& op);
    void pressEquals();
    void pressClear();
    void pressChangeSign();
    void pressDecimalPoint();

    void pressLPar();
    void pressRPar();

    void pressSqrt();
    void pressAbs();
    void pressLog();

    QString getDisplayText() const;
    QString getStatusText() const;

private:
    double firstNum;
    QString operation;
    QString currentInput;
    bool waitingForSecondNumber;

    //scobki
    QStack<double> savedNumbers;
    QStack<QString> savedOperations;
    QStack<CalcContext> contextStack;

    enum MathOp {
        Normal,
        Sqrt,
        Abs,
        Pow,
        Log
    };
    MathOp mathOp = Normal;

    void saveContext();
    void restoreContext();

    void updateDisplay();

};

#endif // CALCULATION_H
