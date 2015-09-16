#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QtAlgorithms>
#include <time.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void mousePressEvent(QMouseEvent *e);
    bool check();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    int mas[9];
    bool first;
    bool endgame;
};

#endif // WIDGET_H
