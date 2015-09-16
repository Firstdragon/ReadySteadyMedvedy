#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QtAlgorithms>

namespace Ui {
class field;
}

class field : public QWidget
{
    Q_OBJECT

public:
    explicit field(QWidget *parent = 0);
     ~field();
    void mousePressEvent(QMouseEvent *me);
    void setfield();
public slots:
    void clearst();

private:
    Ui::field *ui;
    QGraphicsScene *scene;
    int x;
    int y;
    int points;
};

#endif // FIELD_H
