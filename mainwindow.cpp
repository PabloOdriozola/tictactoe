#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"


// Buttons' indexes
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2
#define BUTTON4 3
#define BUTTON5 4
#define BUTTON6 5
#define BUTTON7 6
#define BUTTON8 7
#define BUTTON9 8

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    // Loading images on pixmaps and setting them inside icons
    QPixmap xPixmap("/home/vboxuser/Desktop/Projects/tictactoe/images/X.png");
    QPixmap oPixmap("/home/vboxuser/Desktop/Projects/tictactoe/images/O.png");
    QPixmap xWinPixmap("/home/vboxuser/Desktop/Projects/tictactoe/images/Xwin.png");
    QPixmap oWinPixmap("/home/vboxuser/Desktop/Projects/tictactoe/images/Owin.png");
    xIcon = QIcon(xPixmap);
    oIcon = QIcon(oPixmap);
    xWinIcon = QIcon(xWinPixmap);
    oWinIcon = QIcon(oWinPixmap);

    setFixedSize(400, 400);
    ui->setupUi(this);
    initGame(); // Initialize game logic

}

MainWindow::~MainWindow()
{
    delete ui;
}

QPushButton* MainWindow::getButtonWithIndex(int index) {
    QPushButton *button = NULL;
    switch(index) {
        case BUTTON1:
            button = ui->button1;
            break;
        case BUTTON2:
            button = ui->button2;
            break;
        case BUTTON3:
            button = ui->button3;
            break;
        case BUTTON4:
            button = ui->button4;
            break;
        case BUTTON5:
            button = ui->button5;
            break;
        case BUTTON6:
            button = ui->button6;
            break;
        case BUTTON7:
            button = ui->button7;
            break;
        case BUTTON8:
            button = ui->button8;
            break;
        case BUTTON9:
            button = ui->button9;
            break;
    }
        return button;
}

void MainWindow::highlightCombination() {
    QPushButton *win1 = getButtonWithIndex(winnerCombo[0]);
    QPushButton *win2 = getButtonWithIndex(winnerCombo[1]);
    QPushButton *win3 = getButtonWithIndex(winnerCombo[2]);

    // "Turn" winning combo into red to highlight it
    if (!turn) {
        win1->setIcon(QIcon(xWinIcon));
        win2->setIcon(QIcon(xWinIcon));
        win3->setIcon(QIcon(xWinIcon));
    } else {
        win1->setIcon(QIcon(oWinIcon));
        win2->setIcon(QIcon(oWinIcon));
        win3->setIcon(QIcon(oWinIcon));
    }
}

void MainWindow::retry() {
    for (auto button : ui->centralwidget->findChildren<QPushButton*>()) {
        button->blockSignals(false); // Make buttons clickable again
        button->setIcon(QIcon()); // Erase all symbols
    }
    restartGame(); // Restart game logic as well

}

void MainWindow::endGame(bool draw) {
    // Deactivate all buttons
    for (auto button : ui->centralwidget->findChildren<QPushButton*>()) {
        button->blockSignals(true);
    }

    // Show a new window informing about the result and asking for a new game
    QMessageBox::StandardButton reply;

    if (draw) { // Check if it's a draw or if any player won
        reply = QMessageBox::question(this, "Game over", "It's a draw! Retry?",
                                      QMessageBox::Yes|QMessageBox::No);
    } else {
        reply = QMessageBox::question(this, "Game over", "Well played! Retry?",
                                    QMessageBox::Yes|QMessageBox::No);
    }

    QMessageBox *msgBox = this->findChild<QMessageBox *>();
    if (msgBox) {
        msgBox->setFixedSize(1000, 200); // Set size for reply window
    }

    if (reply == QMessageBox::Yes) {
        retry(); // Restart game
    } else {
        qApp->quit(); // Close app
    }
}

void MainWindow::UIcheckWin() {
    if (checkWin()) {
        highlightCombination();
        endGame(false);
    } else if (turnNum > 9) { // If it's last possible move and doesn't mean a victory, it's a draw
        endGame(true);
    }
}

void MainWindow::drawSymbol(QPushButton *button) {
    if (turn) { // If player X clicked draw X
        button->setIcon(QIcon(xIcon));
    } else { // Player O
        button->setIcon(QIcon(oIcon));
    }
    button->setIconSize(QSize(button->width()+10,button->height())); // Set size in both cases

    button->blockSignals(true); // Once pressed make the button unclickable
}

void MainWindow::on_button1_clicked()
{
    drawSymbol(ui->button1); // Draw symbol on corresponding button
    playTurn(BUTTON1); // Call game logic function
    UIcheckWin(); // Check if this turn translates into victory
}


void MainWindow::on_button2_clicked()
{
    drawSymbol(ui->button2);
    playTurn(BUTTON2);
    UIcheckWin();
}


void MainWindow::on_button3_clicked()
{
    drawSymbol(ui->button3);
    playTurn(BUTTON3);
    UIcheckWin();
}


void MainWindow::on_button4_clicked()
{
    drawSymbol(ui->button4);
    playTurn(BUTTON4);
    UIcheckWin();
}


void MainWindow::on_button5_clicked()
{
    drawSymbol(ui->button5);
    playTurn(BUTTON5);
    UIcheckWin();
}


void MainWindow::on_button6_clicked()
{
    drawSymbol(ui->button6);
    playTurn(BUTTON6);
    UIcheckWin();
}


void MainWindow::on_button7_clicked()
{
    drawSymbol(ui->button7);
    playTurn(BUTTON7);
    UIcheckWin();
}


void MainWindow::on_button8_clicked()
{
    drawSymbol(ui->button8);
    playTurn(BUTTON8);
    UIcheckWin();
}


void MainWindow::on_button9_clicked()
{
    drawSymbol(ui->button9);
    playTurn(BUTTON9);
    UIcheckWin();
}

