#ifndef CALCULATION_H
#define CALCULATION_H

#include <QString>

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

    QString getDisplayText() const;
    QString getStatusText() const;

private:
    double firstNum;
    QString operation;
    QString currentInput;
    bool waitingForSecondNumber;

    void updateDisplay();
};

#endif // CALCULATION_H
