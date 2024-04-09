#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void highlightCombination();

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button8_clicked();

    void on_button9_clicked();

private:
    Ui::MainWindow *ui;

    QIcon xIcon;
    QIcon oIcon;
    QIcon xWinIcon;
    QIcon oWinIcon;

    void drawSymbol(QPushButton *button); // Draws "X" or "O" symbol according to current turn
    void UIcheckWin(); // UI caller for the game logic checkWin()
    void endGame(bool draw); // Called when win condition is met, blocks interaction with buttons and
                             // pops a window up asking if the user wants to retry or quit
    void retry(); // Resets everything needed to start a new game

    QPushButton* getButtonWithIndex(int index); // Returns a button according to its index
};
#endif // MAINWINDOW_H
