#include "hangman1.h"
#include "ui_hangman1.h"
hangman1::hangman1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::hangman1)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->view->setScene(scene);
    getWord(); // initializes the word from the file
    int wordLeng = word.length();
    for(int i = 0; i < wordLeng; i++)
        displayedWord += "_"; // initially all the displayed characters in the word are spaces
    ui->label->setText(displayedWord);
    spaceCount = wordLeng;
    labelsVisibility(0); // all labels above the buttons are not visible initially
    player = new QMediaPlayer(); // initialize the player for playing music in the rest of the code
}

hangman1::~hangman1() {
    delete ui;
    delete scene;
    delete player;
}

// action when clicking the buttons
void hangman1::on_A_clicked() {
    checkLetter(ui->A->text()); // we search and check the letter with its text as the input
    ui->A->setVisible(0); // right or wrong, the button becomes disabled (i.e. you can't click it)
    // we do this by making the button disappear, and making the corresponding label appear
    ui->label_A->setVisible(1);
}

void hangman1::on_B_clicked() {
    checkLetter(ui->B->text());
    ui->B->setVisible(0);
    ui->label_B->setVisible(1);
}

void hangman1::on_C_clicked() {
    checkLetter(ui->C->text());
    ui->C->setVisible(0);
    ui->label_C->setVisible(1);
}

void hangman1::on_D_clicked() {
    checkLetter(ui->D->text());
    ui->D->setVisible(0);
    ui->label_D->setVisible(1);
}

void hangman1::on_E_clicked() {
    checkLetter(ui->E->text());
    ui->E->setVisible(0);
    ui->label_E->setVisible(1);
}

void hangman1::on_F_clicked() {
    checkLetter(ui->F->text());
    ui->F->setVisible(0);
    ui->label_F->setVisible(1);
}

void hangman1::on_G_clicked() {
    checkLetter(ui->G->text());
    ui->G->setVisible(0);
    ui->label_G->setVisible(1);
}

void hangman1::on_H_clicked() {
    checkLetter(ui->H->text());
    ui->H->setVisible(0);
    ui->label_H->setVisible(1);
}

void hangman1::on_I_clicked() {
    checkLetter(ui->I->text());
    ui->I->setVisible(0);
    ui->label_I->setVisible(1);
}

void hangman1::on_J_clicked() {
    checkLetter(ui->J->text());
    ui->J->setVisible(0);
    ui->label_J->setVisible(1);
}

void hangman1::on_K_clicked() {
    checkLetter(ui->K->text());
    ui->K->setVisible(0);
    ui->label_K->setVisible(1);
}

void hangman1::on_L_clicked() {
    checkLetter(ui->L->text());
    ui->L->setVisible(0);
    ui->label_L->setVisible(1);
}

void hangman1::on_M_clicked() {
    checkLetter(ui->M->text());
    ui->M->setVisible(0);
    ui->label_M->setVisible(1);
}

void hangman1::on_N_clicked() {
    checkLetter(ui->N->text());
    ui->N->setVisible(0);
    ui->label_N->setVisible(1);
}

void hangman1::on_O_clicked() {
    checkLetter(ui->O->text());
    ui->O->setVisible(0);
    ui->label_O->setVisible(1);
}

void hangman1::on_P_clicked() {
    checkLetter(ui->P->text());
    ui->P->setVisible(0);
    ui->label_P->setVisible(1);
}

void hangman1::on_Q_clicked() {
    checkLetter(ui->Q->text());
    ui->Q->setVisible(0);
    ui->label_Q->setVisible(1);
}

void hangman1::on_R_clicked() {
    checkLetter(ui->R->text());
    ui->R->setVisible(0);
    ui->label_R->setVisible(1);
}

void hangman1::on_S_clicked() {
    checkLetter(ui->S->text());
    ui->S->setVisible(0);
    ui->label_S->setVisible(1);
}

void hangman1::on_T_clicked() {
    checkLetter(ui->T->text());
    ui->T->setVisible(0);
    ui->label_T->setVisible(1);
}

void hangman1::on_U_clicked() {
    checkLetter(ui->U->text());
    ui->U->setVisible(0);
    ui->label_U->setVisible(1);
}

void hangman1::on_V_clicked() {
    checkLetter(ui->V->text());
    ui->V->setVisible(0);
    ui->label_V->setVisible(1);
}

void hangman1::on_W_clicked() {
    checkLetter(ui->W->text());
    ui->W->setVisible(0);
    ui->label_W->setVisible(1);
}

void hangman1::on_X_clicked() {
    checkLetter(ui->X->text());
    ui->X->setVisible(0);
    ui->label_X->setVisible(1);
}

void hangman1::on_Y_clicked() {
    checkLetter(ui->Y->text());
    ui->Y->setVisible(0);
    ui->label_Y->setVisible(1);
}

void hangman1::on_Z_clicked() {
    checkLetter(ui->Z->text());
    ui->Z->setVisible(0);
    ui->label_Z->setVisible(1);
}

void hangman1::checkLetter(const QString& letter) {
    string s_letter = letter.toStdString(); // converting the letter into a string for interacting with characters
    char letter1 = s_letter[0]; // we take the first letter since we only worry about one letter
    char letter2; // the letter that we get check letter1 with
    int tempo; // for checking uppercases and lowercases
    bool found = false; // for checking if a letter is found
    int length = word.length();
    for (int i = 0; i < length && spaceCount; i++) { // if the spaceCount is 0, we break out of the for loop
       letter2 = word[i];
       if (letter2 >= 'a' && letter2 <= 'z') { // if it's lowercase, make it uppercase
            tempo = letter2;
            tempo += 'A';
            tempo -= 'a';
            letter2 = tempo;
        }
        if(letter1 == letter2) {
            displayedWord[i] = word[i]; // displaying the letter that was found on the screen
            spaceCount--;
            if (!found) {
                // put the directory of the music with the same name when cloning the project
                player->setMedia(QUrl("C:/Users/AUC/Desktop/Spring 2021/CS2 Lab/QT Projects/Assignment 2 CS2 Lab again/Assignment-2-CS2-Lab/esm_5_wickets_sound_fx_arcade_casino_kids_mobile_app.mp3"));
                player->play();
            }
            found = true;
        }
    }
    if (!spaceCount) winning(); // if there are no spaces, then the user/player wins
    ui->label->setText(displayedWord); // display after the change
    if (!found) wrongLetter();
}

void hangman1::buttonsVisibility(const bool& b) {
    ui->A->setVisible(b);
    ui->B->setVisible(b);
    ui->C->setVisible(b);
    ui->D->setVisible(b);
    ui->E->setVisible(b);
    ui->F->setVisible(b);
    ui->G->setVisible(b);
    ui->H->setVisible(b);
    ui->I->setVisible(b);
    ui->J->setVisible(b);
    ui->K->setVisible(b);
    ui->L->setVisible(b);
    ui->M->setVisible(b);
    ui->N->setVisible(b);
    ui->O->setVisible(b);
    ui->P->setVisible(b);
    ui->Q->setVisible(b);
    ui->R->setVisible(b);
    ui->S->setVisible(b);
    ui->T->setVisible(b);
    ui->U->setVisible(b);
    ui->V->setVisible(b);
    ui->W->setVisible(b);
    ui->X->setVisible(b);
    ui->Y->setVisible(b);
    ui->Z->setVisible(b);
}

void hangman1::labelsVisibility(const bool& b) {
    ui->label_A->setVisible(b);
    ui->label_B->setVisible(b);
    ui->label_C->setVisible(b);
    ui->label_D->setVisible(b);
    ui->label_E->setVisible(b);
    ui->label_F->setVisible(b);
    ui->label_G->setVisible(b);
    ui->label_H->setVisible(b);
    ui->label_I->setVisible(b);
    ui->label_J->setVisible(b);
    ui->label_K->setVisible(b);
    ui->label_L->setVisible(b);
    ui->label_M->setVisible(b);
    ui->label_N->setVisible(b);
    ui->label_O->setVisible(b);
    ui->label_P->setVisible(b);
    ui->label_Q->setVisible(b);
    ui->label_R->setVisible(b);
    ui->label_S->setVisible(b);
    ui->label_T->setVisible(b);
    ui->label_U->setVisible(b);
    ui->label_V->setVisible(b);
    ui->label_W->setVisible(b);
    ui->label_X->setVisible(b);
    ui->label_Y->setVisible(b);
    ui->label_Z->setVisible(b);
}

void hangman1::close() {
    buttonsVisibility(0);
    labelsVisibility(1);
}

void hangman1::losing() {
    QColor color = "red";
    ui->status->setText("<font color='red'>You lost!</font>");
    close();
    player->setMedia(QUrl("C:/Users/AUC/Desktop/Spring 2021/CS2 Lab/QT Projects/Assignment 2 CS2 Lab again/Assignment-2-CS2-Lab/esm_8_bit_game_over_1_arcade_80s_simple_alert_notification_game.mp3"));
    player->play();
}


void hangman1::winning() {
    QColor color = "green";
    ui->status->setText("<font color='green'>You won!</font>");
    close();
    player->setMedia(QUrl("C:/Users/AUC/Desktop/Spring 2021/CS2 Lab/QT Projects/Assignment 2 CS2 Lab again/Assignment-2-CS2-Lab/sound_ex_machina_Applause,+Clapping,+Crowd+Ambience.mp3"));
    player->play();
}

void hangman1::drawShape() {
    QBrush RedBrush(Qt::red);
    QPen Blackpen(Qt::black);
    Blackpen.setWidth(6);
    switch (mistakesNum) {
    case 1:
        ellipse = scene->addEllipse(-50, -50, 100, 100, Blackpen, RedBrush);
        break;
    case 2:
        Line = scene->addLine(0, 55, 0, 250, Blackpen);
        break;
    case 3:
        Line = scene->addLine(0, 100, 100, 150, Blackpen);
        break;
    case 4:
        Line = scene->addLine(0, 100, -100, 150, Blackpen);
        break;
    case 5:
        Line = scene->addLine(0, 250,-100, 300, Blackpen);
        break;
    case 6:
        Line = scene->addLine(0, 250, 100, 300, Blackpen);
        break;
    case 7:
        Line = scene->addLine(-200, -100, -200, 300, Blackpen);
        break;
    case 8:
        Line = scene->addLine(-200, -100, 0, -100, Blackpen);
        break;
    case 9:
        Line = scene->addLine(0, -100, 0, -50, Blackpen);
        losing();
        break;
    }
}

void hangman1::wrongLetter() {
    mistakesNum++;
    drawShape();
    if (mistakesNum != 9) {
        player->setMedia(QUrl("C:/Users/AUC/Desktop/Spring 2021/CS2 Lab/QT Projects/Assignment 2 CS2 Lab again/Assignment-2-CS2-Lab/app_alert_tone_remove_delete_002.mp3")); // or give it the address
        player->play();
    }
}

void hangman1::getWord() {
    srand(time(0));
    int number;
    ifstream wordsFile;
    wordsFile.open("C:/Users/AUC/Desktop/Spring 2021/CS2 Lab/QT Projects/Assignment 2 CS2 Lab again/Assignment-2-CS2-Lab/Words.txt");
    // put the directory of the file of input that you want for input
    wordsFile >> number;
    // note that the format of the file includes having a number of words that you are going to have for input
    // and then the words that the program chooses randomly from
    int randomNumber = rand() % number;
    for (int i = 0; i < number; i++) {
        wordsFile >> word;
        if (i == randomNumber) break;
    }
}
