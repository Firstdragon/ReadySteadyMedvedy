#include "field.h"
#include "ui_field.h"

field::field(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::field)
{
    points=0;
    ui->setupUi(this);
    QObject::connect(ui->exit, SIGNAL(clicked()), this , SLOT(close()));
    QObject::connect(ui->clear, SIGNAL(clicked()), this , SLOT(clearst()));
    scene = new QGraphicsScene(ui->graphicsView);
    setfield();

}

void field::setfield()
{
    ui->score->display(points);
    QPen pen1(Qt::black);
    QBrush b(Qt::yellow);
    x=0;
    y=50;
    scene->addEllipse(x,y,300,300,pen1,b);
    b.setColor(Qt::red);
    scene->addEllipse(x+25,y+25,250,250,pen1,b);
    b.setColor(Qt::green);
    scene->addEllipse(x+50,y+50,200,200,pen1,b);
    b.setColor(Qt::blue);
    scene->addEllipse(x+75,y+75,150,150,pen1,b);
    b.setColor(Qt::magenta);
    scene->addEllipse(x+100,y+100,100,100,pen1,b);
    b.setColor(Qt::cyan);
    scene->addEllipse(x+125,y+125,50,50,pen1,b);
    ui->graphicsView->setSceneRect(0,50,300,300);
    ui->graphicsView->setScene(scene);
}


void field::mousePressEvent(QMouseEvent *me)
{
    int c=me->x();
    int v=me->y();
    QPen pen1(Qt::black);
    QBrush b(Qt::black);
    scene->addEllipse(c-118,v-22,6,6,pen1,b);
    int cx=abs((c-188))^2;
    int vx=abs((v-22))^2;
    if (cx+vx<625)
    {
        points+=10;
        ui->score->display(points);
    }

    ui->graphicsView->setScene(scene);
}

void field::clearst()
{
    qDeleteAll(scene->items());
    ui->graphicsView->setScene(scene);
    points=0;
    setfield();
}

field::~field()
{
    delete ui;
}
