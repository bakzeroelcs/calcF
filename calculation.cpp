#include "calculation.h"

Calculation::Calculation()
    : firstNum(0.0),
    operation(""),
    currentInput(""),
    waitingForSecondNumber(false)
{
}

void Calculation::pressDigit(const QString& digit)
{
    if (waitingForSecondNumber) {
        currentInput = digit;
        waitingForSecondNumber = false;
    } else {
        currentInput += digit;
    }
    updateDisplay();
}

void Calculation::pressDecimalPoint()
{
    if (!currentInput.contains('.')) {
        if (currentInput.isEmpty()) {
            currentInput = "0.";
        } else {
            currentInput += ".";
        }
        updateDisplay();
    }
}

void Calculation::pressOperation(const QString& op)
{
    if (!currentInput.isEmpty()) {
        firstNum = currentInput.toDouble();
        operation = op.trimmed();
        waitingForSecondNumber = true;
    }
}

void Calculation::pressEquals()
{
    if (operation.isEmpty()) {
        return;
    }

    double secondNum;
    if (waitingForSecondNumber) {
        // если ну лень второе число придумывать
        secondNum = firstNum;
    } else if (currentInput.isEmpty()) {
        secondNum = 0.0;
    } else {
        bool ok;
        secondNum = currentInput.toDouble(&ok);
        if (!ok) {
            currentInput = "Error";
            updateDisplay();
            return;
        }
    }

    double result = 0.0;
    QString errorMessage;

    if (operation == "+") {
        result = firstNum + secondNum;
    } else if (operation == "-") {
        result = firstNum - secondNum;
    } else if (operation == "x") {
        if (std::abs(firstNum) > 1e150 || std::abs(secondNum) > 1e150) {
            errorMessage = "FULLBAK";
        } else {
            result = firstNum * secondNum;
        }
    } else if (operation == "/") {
        if (secondNum == 0.0) {
            errorMessage = "Div on ZEro";
        } else {
            result = firstNum / secondNum;
        }
    } else {
        errorMessage = "Unknown operation: '" + operation + "'";
    }

    if (errorMessage.isEmpty()) {
        currentInput = QString::number(result);
        firstNum = 0.0; // просто чтоб красиво было, очистить лейбел от последнего действия
        operation = "";
        waitingForSecondNumber = false;
    } else {
        currentInput = errorMessage;
    }

    waitingForSecondNumber = false;
    updateDisplay();
}

void Calculation::pressClear()
{
    currentInput = "";
    firstNum = 0.0;
    operation = "";
    waitingForSecondNumber = false;
    updateDisplay();
}

void Calculation::pressChangeSign()
{
    if (!currentInput.isEmpty() && currentInput != "0") {
        if (currentInput.startsWith('-')) {
            currentInput = currentInput.mid(1);
        } else {
            currentInput = '-' + currentInput;
        }
        updateDisplay();
    }
}

QString Calculation::getDisplayText() const
{
    if (currentInput.startsWith("Error")) {
        return currentInput;
    }
    return currentInput.isEmpty() ? "0" : currentInput;
}

QString Calculation::getStatusText() const
{
    if (operation.isEmpty()) {
        return "";
    }
    return "First Number: " + QString::number(firstNum) + " " + operation;
}

void Calculation::updateDisplay()
{
    // Заглушка — обновление происходит через геттеры
}
