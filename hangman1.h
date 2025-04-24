#ifndef HANGMAN1_H
#define HANGMAN1_H
#include <QMediaPlayer>
#include<fstream>
#include<iostream>
#include <QDebug>
#include <QColorDialog>
#include<string>
#include <QMainWindow>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include<QTimer>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class hangman1; }
QT_END_NAMESPACE

class hangman1 : public QMainWindow
{
    Q_OBJECT

public:
    void getWord(); // initializing the word chosen from the file
    hangman1(QWidget *parent = nullptr);
    void wrongLetter(); // what happens when the user/player chooses a wrong letter
    void drawShape(); // draws the shape when the user chooses a wrong letter, called inside the "wrongLetter" function
    // Note that we've added labels above the letters, one for each letter for a specific purpose
    void labelsVisibility(const bool&); // changes the visibility of the buttons' labels in the program
    void buttonsVisibility(const bool&); // change the visibility of the buttons in the program (according to input)
    void checkLetter(const QString&); // searches for the letter and sees if it's a right one
    void losing(); // what happens when the user loses
    void close(); // sequence of ending the program
    void winning(); // what happens when the user wins
    ~hangman1();

private slots:
    void on_A_clicked();
    void on_B_clicked();
    void on_C_clicked();
    void on_D_clicked();
    void on_E_clicked();
    void on_F_clicked();
    void on_G_clicked();
    void on_H_clicked();
    void on_I_clicked();
    void on_J_clicked();
    void on_K_clicked();
    void on_L_clicked();
    void on_M_clicked();
    void on_N_clicked();
    void on_O_clicked();
    void on_P_clicked();
    void on_Q_clicked();
    void on_R_clicked();
    void on_S_clicked();
    void on_T_clicked();
    void on_U_clicked();
    void on_V_clicked();
    void on_W_clicked();
    void on_X_clicked();
    void on_Y_clicked();
    void on_Z_clicked();
private:
    Ui::hangman1 *ui;
    string word; // for manipulation
    QString displayedWord; // what is displayed on the screen
    QGraphicsScene* scene;
    QGraphicsEllipseItem* ellipse;
    QGraphicsLineItem* Line;
    int mistakesNum = 0; // number of mistakes the user/player made
    int spaceCount = 0; // number of spaces remaining in the displayed word
    QMediaPlayer* player; // = new QMediaplayer(); for playing music
};
#endif // HANGMAN1_H
