#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>
#include "matrix.h"
#include "linearsystem.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void preencherMatrizes(LinearSystem* system);
    ~MainWindow();

private:
    QDoubleSpinBox* coeficientsMatrix[3][3];
    QDoubleSpinBox* indMatrix[3];
    Ui::MainWindow *ui;


private slots:
    void solveLinearEquation();
};

#endif // MAINWINDOW_H
