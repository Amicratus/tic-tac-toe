#include "xo.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>

XO::XO(QWidget *parent): QWidget(parent)
{
    create();
    turn1 = 0;
    QPushButton *restart = new QPushButton("Restart");
    restart -> setFont(QFont("Bauhaus 93", 15));
    restart -> setMinimumSize(100, 100);
    connect(restart, &QPushButton::clicked, this, &XO::Restart);

    QGridLayout *table = new QGridLayout;
    table -> setSpacing(10);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            QPushButton * box = new QPushButton;
            box -> setText("");
            box -> setFont(QFont("Bauhaus 93", 30));
            box -> setStyleSheet("background-color: white");
            box -> setFixedSize(180, 150);
            connect(box, &QPushButton::clicked, this, &XO::Move);
            list << box;
            table -> addWidget(box, i + 1, j);
        }
    }

    table -> addWidget(restart, 4, 0, 1, 3);
    turn = new QLabel("PLAYER 1");
    origin = turn -> text();
    turn -> setFont(QFont("Bauhaus 93", 20));
    table -> addWidget(turn, 0, 1);
    label = new QLabel("");
    label -> setFont(QFont("Bauhaus 93", 30));
    table -> addWidget(label, 5, 0, 1, 3);

    setLayout(table);
}

void XO:: Move(){
    QPushButton *button = (QPushButton*)sender();
    QString t = button -> text();
    QString sign = turn -> text();
        if(t == "" && label -> text() == ""){
            turn1++;
            if(sign == "PLAYER 1"){
                button -> setText("X");
                turn -> setText("PLAYER 2");
                if(turn1 > 4){
                    if(Check() == 1){
                        label -> setText("PLAYER 1 WIN");

                    }
                }
            }
            else{
                button -> setText("O");
                turn -> setText("PLAYER 1");
                if(turn1 > 4){
                    if(Check() == 1){
                        label -> setText("PLAYER 2 WIN");
                    }
                }
            }
        }
        if(turn1 == 9 && Check() == 0)
            label -> setText("DRAW");
}

void XO:: Restart(){
    for(int i = 0; i < 9; i++){
            list[i] -> setText("");
    }
    if(origin == "PLAYER 1"){
        turn -> setText("PLAYER 2");
        origin = turn -> text();
    }
    else{
        turn -> setText("PLAYER 1");
        origin = turn -> text();
    }
    label -> setText("");
    turn1 = 0;
}

bool XO:: Check(){
    QString pos1 = list[0] -> text();
    QString pos2 = list[4] -> text();
    QString pos3 = list[8] -> text();
    if(pos2 != ""){
        for(int i = 1; i < 5; i++){
            if((pos2 == list[4 - i] -> text()) && (pos2 == list[4 + i] -> text())){
                return 1;
            }
        }
    }
    if(pos1 != ""){
        if((pos1 == list[1] -> text() && pos1 == list[2] -> text()) || (pos1 == list[3] -> text() && pos1 == list[6] -> text()))
            return 1;
    }
    if(pos3 != ""){
        if((pos3 == list[7] -> text() && pos3 == list[6] -> text()) || (pos3 == list[5] -> text() && pos3 == list[2] -> text()))
            return 1;
    }

    return 0;
}



void XO::create(){
    setWindowTitle("Крестики Нолики");
    setMinimumSize(600, 800);
    setMaximumSize(600, 800);
    setStyleSheet("background-color: white");
}

