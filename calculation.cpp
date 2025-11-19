#include "calculation.h"
#include <qdebug.h>

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

//scobli
void Calculation::saveContext()
{
    savedNumbers.push(firstNum);
    savedOperations.push(operation);
}

void Calculation::restoreContext()
{
    if (!savedNumbers.isEmpty() && !savedOperations.isEmpty()) {
        firstNum = savedNumbers.pop();
        operation = savedOperations.pop();
    }
}

void Calculation::pressLPar()
{
    CalcContext ctx;
    ctx.firstNum = firstNum;
    ctx.operation = operation;
    ctx.currentInput = currentInput;
    ctx.waitingForSecondNumber = waitingForSecondNumber;

    /*qDebug() << "SAVE: firstNum=" << ctx.firstNum
             << ", op=" << ctx.operation
             << ", input=" << ctx.currentInput;  */

    contextStack.push(ctx);

    firstNum = 0.0;
    operation = "";
    currentInput = "";
    waitingForSecondNumber = false;
}

void Calculation::pressRPar()
{
    if (contextStack.isEmpty()) {
            currentInput = "Ошибка: лишняя )";
            updateDisplay();

            firstNum = 0.0;
            operation = "";
            waitingForSecondNumber = false;
            return;
    }

    if (currentInput.isEmpty()) {
        currentInput = "Ошибка: пустые ()";
        updateDisplay();
        contextStack.pop();
        return;
    }

    pressEquals();  //Выражение внутри скобок


    CalcContext ctx = contextStack.pop();


    // Операция внешнего поля
    if (!currentInput.startsWith("Error")) {
        double innerResult = currentInput.toDouble();
        double outerResult = 0.0;
        QString errorMessage;

        if (ctx.operation == "+") {
            outerResult = ctx.firstNum + innerResult;
        } else if (ctx.operation == "-") {
            outerResult = ctx.firstNum - innerResult;
        } else if (ctx.operation == "*") {
            if (std::abs(ctx.firstNum) > 1e150 || std::abs(innerResult) > 1e150) {
                errorMessage = "Error: Overflow";
            } else {
                outerResult = ctx.firstNum * innerResult;
            }
        } else if (ctx.operation == "/") {
            if (innerResult == 0.0) {
                errorMessage = "Division by zero";
            } else {
                outerResult = ctx.firstNum / innerResult;
            }
        }

        if (errorMessage.isEmpty()) {
            currentInput = QString::number(outerResult);
            // Сохраняем результат как новое firstNum для последующих операций
            firstNum = outerResult;
            operation = "";  // Операция применена
            waitingForSecondNumber = false;
        } else {
            currentInput = errorMessage;
            operation = "";
        }
    } else {
        //При ошибке внутри скобок
        operation = "";
    }

    updateDisplay();
}

/* 111 Код касательно скобок выше и сохранение контекста до/внутри скобок для вычислений будем придумывать что в скобках будет 1число
пока без вложенных скобок, рекурсия, пока не до конца осознал как сделать оценку для операций и скобок, наверное через токены и веса... наверное..
тогда он сможет еще и думать так что бы в стек запиливать много операций и он сам решал где * важнее +-))
*/



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
    // Заглушка - как будто если добавлять функции придется даже использовать)
}
