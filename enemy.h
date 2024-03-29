#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include "player.h"
#include "ui_game_over.h"
#include"game_over.h"
// #include"main.cpp"
// #include <QMediaPlayer>


class Player;
class Enemy: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT
    // QMediaPlayer* gameoversound;
    Player* rect;
public:
    Enemy(Player* p);

public slots:
    void move();
    void collide();
};

#endif // ENEMY_H
