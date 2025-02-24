#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state = 1;
    number1 = " ";
    number2 = " ";
    resetLines();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clickedNumberHandler()
{

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name:" << name;


    if(state == 1)
    {
        number1 += name.at(1);
        ui->Num1->setText(number1);
    }
    else
    {
        number2 += name.at(1);
        ui->Num2->setText(number2);
    }
    qDebug()<<"number 1 = "<< number1<<Qt::endl;
    qDebug()<<"number 2 = "<< number2<<Qt::endl;
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name:" << name;
    if(name == "clear")
    {
        state = 1;
        number1 = "";
        number2 = "";
        resetLines();
    }
    else // if(name == enter)
    {
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();
        qDebug()<<"number 1 = "<< n1 << " and number 2 = "<<n2 <<Qt::endl;

        switch(operand) {
          case 0:
            result = n1+n2;
            break;
          case 1:
            result = n1-n2;
            break;
          case 2:
            result = n1*n2;
            break;
          case 3:
            result = n1/n2;
            break;

          default:
            qDebug()<<"Not correct"<<Qt::endl;
        }
        ui->Result->setText(QString::number(result));
    }

}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name:" << name;
    if(name == "add")
    {
        operand = 0;
    }
    else if(name == "sub")
    {
        operand = 1;
    }
    else if(name == "mul")
    {
        operand = 2;
    }
    else if(name == "div")
    {
        operand = 3;
    }
    state = 2;
    qDebug()<<"operand = "<< operand << Qt::endl;

}

void MainWindow::resetLines()
{
    ui->Num1->clear();
    ui->Num2->clear();
    ui->Result->clear();
}



void MainWindow::on_N1_clicked()
{
    clickedNumberHandler();
}


void MainWindow::on_N2_clicked()
{
    clickedNumberHandler();
}


void MainWindow::on_N3_clicked()
{
   clickedNumberHandler();
}


void MainWindow::on_N4_clicked()
{
     clickedNumberHandler();
}


void MainWindow::on_N5_clicked()
{
    clickedNumberHandler();
}


void MainWindow::on_N6_clicked()
{
    clickedNumberHandler();
}


void MainWindow::on_N7_clicked()
{
    clickedNumberHandler();
}


void MainWindow::on_N8_clicked()
{
     clickedNumberHandler();
}


void MainWindow::on_N9_clicked()
{
    clickedNumberHandler();
}


void MainWindow::on_N0_clicked()
{
     clickedNumberHandler();
}


void MainWindow::on_add_clicked()
{
    addSubMulDivClickHandler();
}


void MainWindow::on_sub_clicked()
{
    addSubMulDivClickHandler();
}


void MainWindow::on_mul_clicked()
{
    addSubMulDivClickHandler();
}


void MainWindow::on_div_clicked()
{
    addSubMulDivClickHandler();
}


void MainWindow::on_clear_clicked()
{
    clearAndEnterClickHandler();
}


void MainWindow::on_enter_clicked()
{
    clearAndEnterClickHandler();
}


