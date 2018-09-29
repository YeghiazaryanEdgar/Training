#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
     void onClicked();
     void numbers();
     void arithmetic();
     void equals();
     void point();
     void clean();
     void bracket();
     void sign();
     void back();
     void root();
     void inverse();
     void square();
     void keyPressEvent(QKeyEvent *);
private:
     Ui::MainWindow *ui;
     QString exp_result;
     QString exp_process;
     QString clicked_btn;
     QString theNumber = "";
     bool isNegative = false;
     bool isKeyPressed = false;
     bool allowArith = true;
     bool allowNumber = true;
     bool allowOpenBracket = true;
     bool allowCloseBracket = false;
     bool arithAfterOpenBracket = true;
     double result = 0;
     int bracketsCount = 0;
};

#endif // MAINWINDOW_H
