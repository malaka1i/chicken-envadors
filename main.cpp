#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
// #include "health_score.h"
// #include <QMediaPlayer>
    int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // ******* Create the Scene ********
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // *******  Create the Player ********

    // QGraphicsPixmapItem * pixmap2 = new QGraphicsPixmapItem();
    // QPixmap Pixmap2(":/new/prefix1/ship.png");
    // Pixmap2.scaled(80, 80);

    Player * rect = new Player(scene);
    // rect->setPixmap(Pixmap2);
    // rect->setPixmap(QPixmap(":/new/prefix1/ship.png"));
    // rect->setPixmap(QPixmap(":/new/prefix1/ship.png").scaled(80, 80));
    scene->addItem(rect);
    //rect -> setPixmap(pixmap2);
    rect -> setPos(10, 450);
    // *******  Create the View ********

    view->setScene(scene);
    view->show();
    // *******  Setting the foucs to the Player ********
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    rect->setPos(view->width()/2, view->height()- rect->y() + 330);

    // *******   Assign scene to the view   ***************

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),rect,SLOT(createEnemy()));
    time->start(2000);


    //score
    // health_score* score = rect->get_score();
    // scene -> addItem(score);

    // health_score* health = rect->get_health();
    // health-> setPos(health->x(),health->y()+25);
    // scene -> addItem(health);
    // qDebug() << "HEY THERE";
    // //sound
    // // QMediaPlayer* bullet = new QMediaPlayer();
    // // bullet->setMedia(":/sounds/laser sound.mp3");
    // // bullet -> play();

    return a.exec();
}
