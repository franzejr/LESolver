#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleSpinBox>
#include <QGridLayout>
#include "lesolver.h"
#include <QWidget>
#include <QLabel>
#include <string>
#include "linearsystem.h"
#include "matrix.h"
#include "cramer.h"
#include <QString>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connects
    connect(ui->solveButton,SIGNAL(clicked()),this,SLOT(solveLinearEquation()));
    connect(ui->clearButton,SIGNAL(clicked()),ui->historyText,SLOT(clear()));

    //Putting the UI Elements
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    coeficientsMatrix[i][j] = new QDoubleSpinBox();
                    ui->gridLayout->addWidget(coeficientsMatrix[i][j],i,2*j);

                    switch(j){
                    case 0:
                        ui->gridLayout->addWidget(new QLabel("x"),i,(2*j)+1);
                        break;
                    case 1:
                        ui->gridLayout->addWidget(new QLabel("y"),i,(2*j)+1);
                        break;
                    case 2:
                        ui->gridLayout->addWidget(new QLabel("z     = "),i,(2*j)+1);
                        break;
                    }

                    }

            }

            for(int i = 0; i < 3; i++){
                indMatrix[i] = new QDoubleSpinBox();
                ui->gridLayout->addWidget(indMatrix[i],i,8);
            }
            //Adding Cramer Method to ComboBox
            this->ui->methods->insertItem(1,"Cramer");


}

void MainWindow::preencherMatrizes(LinearSystem* system){

    //Pegando os dados da matriz dos coeficietes
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            system->coefficients->setElement(i,j,coeficientsMatrix[i][j]->value() );
            }
    }

    //Pegando os dados da matriz dos termos independentes
    for(int i = 0; i < 3; i++){
        system->independentsTerms->setElement(i,0,indMatrix[i]->value());
    }

}


void MainWindow::solveLinearEquation(){

    //Creating the Linear System
    LinearSystem* system = new LinearSystem(3,3);

    this->preencherMatrizes(system);

    double* answers;
    //Chamando para resolver o sistema
    Cramer* cramer = new Cramer(system);
    answers = cramer->execute(system);


    std::cout<<answers[1];

    QString valores = "";
    valores.append("X = ");
    valores.append(QString::number(answers[0]));
    valores.append("\nY = ");
    valores.append(QString::number(answers[1]));
    valores.append("\nZ = ");
    valores.append(QString::number(answers[2]));
    valores.append("\n");

    ui->historyText->setText(valores);

}

MainWindow::~MainWindow()
{
    delete ui;
}
