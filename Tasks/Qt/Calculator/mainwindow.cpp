#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QDebug>
#include <QKeyEvent>
#include <QScriptEngine>
#include <QtCore/qmath.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(270, 401);
    this->setWindowTitle("Calculator");
    //setWindowFlags( Qt::CustomizeWindowHint );

    for(int i=0; i < ui->gridLayout->rowCount(); i++) {
        for(int j=0; j < ui->gridLayout->columnCount(); j++) {
             if(i == 4 && j == 0) continue;
             connect(qobject_cast<QPushButton *>(ui->gridLayout->itemAtPosition(i, j)->widget()), &QPushButton::clicked, this, &MainWindow::onClicked );
        }
     }
}

void MainWindow::onClicked() {
    if(!isKeyPressed) {
        clicked_btn = qobject_cast<QPushButton *>(sender())->text();
    }
    isKeyPressed = false;

    if (clicked_btn == "+" || clicked_btn == "-" || clicked_btn == "×" || clicked_btn == "÷") {
         arithmetic();
    } else if (clicked_btn == "=") {
         equals();
    } else if (clicked_btn == ".") {
         point();
    } else if (clicked_btn == "(" || clicked_btn == ")") {
         bracket();
    } else if (clicked_btn == "CE") {
         clean();
    } else if(clicked_btn == "1/x") {
         inverse();
    } else if (clicked_btn == "√") {
         root();
    } else if (clicked_btn == "←") {
         back();
    } else if (clicked_btn == " x²") {
         square();
    } else if (clicked_btn == "±") {
         sign();
    } else {
         numbers();
    }

    if(exp_process.length() > 24) {
        ui->label_arrows->setText("«");
    } else {
        ui->label_arrows->setText("");
    }

    ui->label_process->setText(exp_process);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    clicked_btn = event->text();
    isKeyPressed = true;
    onClicked();
}

void MainWindow::numbers() {
    if(allowNumber) {
        if(theNumber == "0") {
            if(clicked_btn != "0") {
                theNumber = clicked_btn;
                exp_process.replace(exp_process.length()-1, 1, clicked_btn);
            }
        } else {
            theNumber += clicked_btn;
            exp_process += clicked_btn;
        }
        allowArith = true;
        isNegative = false;
        allowOpenBracket = false;
        allowCloseBracket = true;
    }
    arithAfterOpenBracket = true;
}



void MainWindow::equals() {

    exp_result += theNumber;
    theNumber = "";

    if(exp_result.length() != 0) {
        QString lastChar = exp_result.at(exp_result.length()-1);
        if(lastChar == "+" || lastChar == "-") {
            exp_result += "0";
        } else if(lastChar == "*" || lastChar == "/") {
            exp_result += "1";
        } else {
            exp_process += ")";
        }

        QScriptEngine expression;
        result = expression.evaluate(exp_result).toNumber();

        exp_result = QString::number(result);

        if(exp_result == "inf") {
            ui->label_result->setText("Infinit");
        } else if (exp_result == "NaN") {
            ui->label_result->setText("NaN");
        } else {
            ui->label_result->setText(exp_result);
        }
        exp_process = "";
    }
}

void MainWindow::arithmetic() {   // + - * /
    if(arithAfterOpenBracket) {
        allowNumber = true;

        if(exp_result == "" && theNumber == "") {
            exp_process = "0";
        }
        exp_result += theNumber;
        theNumber = "";

        if(!allowArith) {
            exp_result.remove(exp_result.length()-1, 1);
            exp_process.remove(exp_process.length()-1, 1);
        }

        exp_process += clicked_btn;
        if(clicked_btn == "÷") {
            exp_result += "/";
        } else if(clicked_btn == "×") {
            exp_result += "*";
        } else {
            exp_result += clicked_btn;
        }

        allowArith = false;
        allowOpenBracket = true;
        allowCloseBracket = false;
    }
}

void MainWindow::bracket() {
    allowArith = true;

    if(clicked_btn == ")") {
        if(allowCloseBracket && bracketsCount != 0) {
            exp_result += theNumber;
            exp_result += clicked_btn;
            exp_process += clicked_btn;
            theNumber = "";
            allowNumber = false;
            bracketsCount--;
        }
    } else {
        if(allowOpenBracket) {
            arithAfterOpenBracket = false;
            exp_process += clicked_btn;
            exp_result += clicked_btn;
            bracketsCount++;
        }
    }
}

void MainWindow::root() {
   if(isNegative) {
       clean();
       ui->label_result->setText("Error");
   } else {
       if(exp_result == "" && theNumber != "") {
           theNumber = QString::number(qSqrt(theNumber.toDouble()));
           ui->label_result->setText(theNumber);
       } else if(exp_result != "" && exp_process == "") {  // RESULT
           exp_result = QString::number(qSqrt(exp_result.toDouble()));
           ui->label_result->setText(exp_result);
       } else if (exp_result == "" && exp_process == "") {
           ui->label_result->setText("0");
       } else if (theNumber == "") {

       } else {
           exp_process.remove(exp_process.length() - theNumber.length(), theNumber.length());
           theNumber = QString::number(qSqrt(theNumber.toDouble()));
           exp_process += theNumber;
       }
   }
}

void MainWindow::sign() {
    exp_process.remove(exp_process.length() - theNumber.length(), theNumber.length());
    if(exp_process == "" && exp_result != "") {    // RESULT
        if (exp_result.toDouble() < 0) {
            isNegative = true;
        }
        if(isNegative) {
            exp_result = exp_result.remove(0, 1);
            isNegative = false;
        } else {
            exp_result = "-" + exp_result;
            isNegative = true;
        }
        ui->label_result->setText(exp_result);
    } else if (theNumber == "") {

    } else {
        if(isNegative) {
            theNumber = theNumber.mid(2, theNumber.length()-3);
            isNegative = false;
        } else {
            theNumber = "(-" + theNumber + ")";
            isNegative = true;
        }
    }
    exp_process += theNumber;
}

void MainWindow::square() {
    if(isNegative) {
        sign();
    }
    if(exp_result == "" && theNumber != "") {
        theNumber = QString::number(theNumber.toDouble() * theNumber.toDouble());
        ui->label_result->setText(theNumber);
        exp_process = "";
    } else if(exp_result == "" && exp_process == "") {
        ui->label_result->setText("0");
    } else if (exp_result != "" && exp_process == "") {
        exp_result = QString::number(exp_result.toDouble() * exp_result.toDouble());
        ui->label_result->setText(exp_result);
    } else if (theNumber == "") {
    } else {
        exp_process = exp_process.remove(exp_process.length() - theNumber.length(), theNumber.length());
        theNumber = QString::number(theNumber.toDouble() * theNumber.toDouble());
        exp_process += theNumber;
        allowNumber = false;
    }
}

void MainWindow::inverse() {
      if(exp_result != "" && exp_process == "") {
          if(exp_result == "0") {
              ui->label_result->setText("Infinity");
          } else {
              exp_result = QString::number(1/exp_result.toDouble());
              ui->label_result->setText(exp_result);
          }
      } else if(exp_result == "" && exp_process != "") {
          if(isNegative) {
               theNumber = theNumber.mid(2, theNumber.length()-3);
               theNumber = QString::number(1/theNumber.toDouble());
               exp_result = "-" + theNumber;
          } else {
               theNumber = QString::number(1/theNumber.toDouble());
               exp_result = theNumber;
          }
          ui->label_result->setText(exp_result);
          exp_process = "";
      } else if (theNumber == ""){

      } else {
          if(theNumber == "") {
              ui->label_result->setText("NaN");
          } else if(theNumber == "0") {
              clean();
              ui->label_result->setText("Infinity");
          } else {
              exp_process.remove(exp_process.length() - theNumber.length(), theNumber.length());
              if(isNegative) {
                   theNumber = theNumber.mid(2, theNumber.length()-3);
                   theNumber = QString::number(1/theNumber.toDouble());
                   theNumber = "(-" + theNumber + ")";
              } else {
                  theNumber = QString::number(1/theNumber.toDouble());
              }
              exp_process += theNumber;
          }
      }
}

void MainWindow::point() {
    if(theNumber == "") {
        exp_process += "0";
        theNumber += "0";
    }
    if(!theNumber.contains(".")) {
        exp_process += clicked_btn;
        theNumber += clicked_btn;
    }
}

void MainWindow::back() {
    if(theNumber != "") {
        theNumber.remove(theNumber.length()-1, 1);
        exp_process.remove(exp_process.length()-1, 1);
    }
}

void MainWindow::clean() {
    exp_process = "";
    exp_result  = "";
    theNumber = "";
    isNegative = false;
    result = 0;
    allowArith = true;
    ui->label_result->setText("0");
    allowNumber = true;
    isKeyPressed = false;
    allowOpenBracket = true;
    allowCloseBracket = false;
    bracketsCount = 0;
    arithAfterOpenBracket = true;
}

MainWindow::~MainWindow() {
    delete ui;
}


