#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"


// Buttons' indexes
#define BUTTON1 1
#define BUTTON2 2
#define BUTTON3 3
#define BUTTON4 4
#define BUTTON5 5
#define BUTTON6 6
#define BUTTON7 7
#define BUTTON8 8
#define BUTTON9 9

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(400, 450);
    ui->setupUi(this);
    initGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawSymbol(QPushButton *button) {
    if (turn == true) { // If player X clicked draw X
        button->setIcon(QIcon("/home/vboxuser/Desktop/Projects/tictactoe/images/X.png"));
        button->setIconSize(QSize(button->width()+10,button->height()));
    } else {
        button->setIcon(QIcon("/home/vboxuser/Desktop/Projects/tictactoe/images/O.png"));
        button->setIconSize(QSize(button->width()+10,button->height()));
    }

    //button->setIconSize(QSize(0,0)); // Disable the button so that it can be clicked only once
    button->setStyleSheet("QPushButton:pressed { border: none; }");
    button->setEnabled(false);
}

void MainWindow::on_button1_clicked()
{
    drawSymbol(ui->button1);
    playTurn(BUTTON1);
}


void MainWindow::on_button2_clicked()
{
    drawSymbol(ui->button2);
    playTurn(BUTTON2);
}


void MainWindow::on_button3_clicked()
{
    drawSymbol(ui->button3);
    playTurn(BUTTON3);
}


void MainWindow::on_button4_clicked()
{
    drawSymbol(ui->button4);
    playTurn(BUTTON4);
}


void MainWindow::on_button5_clicked()
{
    drawSymbol(ui->button5);
    playTurn(BUTTON5);
}


void MainWindow::on_button6_clicked()
{
    drawSymbol(ui->button6);
    playTurn(BUTTON6);
}


void MainWindow::on_button7_clicked()
{
    drawSymbol(ui->button7);
    playTurn(BUTTON7);
}


void MainWindow::on_button8_clicked()
{
    drawSymbol(ui->button8);
    playTurn(BUTTON8);
}


void MainWindow::on_button9_clicked()
{
    drawSymbol(ui->button9);
    playTurn(BUTTON9);
}

