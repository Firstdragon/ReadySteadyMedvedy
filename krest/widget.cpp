#include "widget.h"
#include "ui_widget.h"
#include <Windows.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
QWidget(parent),
ui(new Ui::Widget)
{
    first=0;
    for (int i=0; i<9; i++)
        {
            mas[i]=0;
        }
    endgame=0;
    ui->setupUi(this);
    QObject::connect(ui->exitButton, SIGNAL(clicked()), this , SLOT(close()));
    scene = new QGraphicsScene(ui->graphicsView);
    QPen pen1(Qt::black);
    scene->addLine(0,-100,0,140,pen1);
    scene->addLine(-80,-100,-80,140,pen1);
    scene->addLine(-160,-20,80,-20,pen1);
    scene->addLine(-160,60,80,60,pen1);
    ui->graphicsView->setScene(scene);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (endgame==0)
    {
        srand( time( 0 ) );
        int c=e->x();
        int v=e->y();
        QPen pen(Qt::black);
        bool hod=0;
        if (first==1)
        {
            if ((c-205<-80)&(c-205>-160)&(v-130<-20)&(v-130>-100))
            {
                if (mas[0]==0)
                {
                    scene->addLine(-140,-80,-100,-40,pen);
                    scene->addLine(-100,-80,-140,-40,pen);
                    mas[0]=1;
                    hod=1;
                }
            }
            if ((c-205>-80)&(c-205<0)&(v-130>-20)&(v-130<60))
            {
                if (mas[1]==0)
                {
                    scene->addLine(-60,0,-20,40,pen);
                    scene->addLine(-20,0,-60,40,pen);
                    mas[1]=1; hod=1;
                }
            }
            if ((c-205>-80)&(c-205<0)&(v-130<140)&(v-130>60))
            {
                if (mas[2]==0)
                {
                    scene->addLine(-60,80,-20,120,pen);
                    scene->addLine(-20,80,-60,120,pen);
                    mas[2]=1; hod=1;
                }
            }
            if ((c-205<-80)&(c-205>-160)&(v-130>-20)&(v-130<60))
            {
                if (mas[3]==0)
                {
                    scene->addLine(-140,0,-100,40,pen);
                    scene->addLine(-100,0,-140,40,pen);
                    mas[3]=1; hod=1;
                }
            }
            if ((c-205<-80)&(c-205>-160)&(v-130<140)&(v-130>60))
            {
                if (mas[4]==0)
                {
                    scene->addLine(-140,80,-100,120,pen);
                    scene->addLine(-100,80,-140,120,pen);
                    mas[4]=1; hod=1;
                }
            }
            if ((c-205>-80)&(c-205<0)&(v-130<-20)&(v-130>-100))
            {
                if (mas[5]==0)
                {
                    scene->addLine(-60,-80,-20,-40,pen);
                    scene->addLine(-20,-80,-60,-40,pen);
                    mas[5]=1; hod=1;
                }
            }
            if ((c-205<80)&(c-205>0)&(v-130<-20)&(v-130>-100))
            {
                if (mas[6]==0)
                {
                    scene->addLine(20,-80,60,-40,pen);
                    scene->addLine(60,-80,20,-40,pen);
                    mas[6]=1; hod=1;
                }
            }
            if ((c-205<80)&(c-205>0)&(v-130>-20)&(v-130<60))
            {
                if (mas[7]==0)
                {
                    scene->addLine(20,0,60,40,pen);
                    scene->addLine(60,0,20,40,pen);
                    mas[7]=1; hod=1;
                }
            }
            if ((c-205<80)&(c-205>0)&(v-130>60)&(v-130<140))
            {
                if (mas[8]==0)
                {
                    scene->addLine(20,80,60,120,pen);
                    scene->addLine(60,80,20,120,pen);
                    mas[8]=1; hod=1;
                }
            }
            bool end=1;
            if (check()==true)
            {
                QMessageBox::information(0, "Result", "You won!");
                endgame=1;
                return ;
            }
            for (int i=0; i<9; i++)
            {
                if (mas[i]==0)
                {
                    end=0;
                }
            }
            if (end==1)
            {
                QMessageBox::information(0, "Result", "Draw!");
                return ;
            }
        }
        else
        {
            first=1;
            hod=1;
        }
        if (hod==1)
        {
            hod=0;
            while (hod==0)
        {
        int pos= rand() % 9;
        QBrush b1(Qt::white);
        if (pos==0)
        {
            if (mas[0]==0)
            {
               scene->addEllipse(-140,-80,40,40,pen,b1);
                mas[0]=2;
                hod=1;
            }
        }
        if (pos==1)
        {
            if (mas[1]==0)
            {
                scene->addEllipse(-60,0,40,40,pen,b1);
                mas[1]=2; hod=1;
            }
        }
        if (pos==2)
        {
            if (mas[2]==0)
            {
                scene->addEllipse(-60,80,40,40,pen,b1);
                mas[2]=2; hod=1;
            }
        }
        if (pos==3)
        {
            if (mas[3]==0)
            {
                scene->addEllipse(-140,0,40,40,pen,b1);
                mas[3]=2; hod=1;
            }
        }
        if (pos==4)
        {
            if (mas[4]==0)
            {
                scene->addEllipse(-140,80,40,40,pen,b1);
                mas[4]=2; hod=1;
            }
        }
        if (pos==5)
        {
            if (mas[5]==0)
            {
                scene->addEllipse(-60,-80,40,40,pen,b1);
                mas[5]=2; hod=1;
            }
        }
        if (pos==6)
        {
            if (mas[6]==0)
            {
                scene->addEllipse(20,-80,40,40,pen,b1);
                mas[6]=2; hod=1;
            }
        }
        if (pos==7)
        {
            if (mas[7]==0)
            {
                scene->addEllipse(20,0,40,40,pen,b1);
                mas[7]=2; hod=1;
            }
        }
        if (pos==8)
        {
            if (mas[8]==0)
            {
                scene->addEllipse(20,80,40,40,pen,b1);
                mas[8]=2; hod=1;
            }
        }
        bool end=1;
        if (check()==true)
        {
            QMessageBox::information(0, "Result", "You lost!");
            endgame=1;
            return ;
        }
        for (int i=0; i<9; i++)
        {
            if (mas[i]==0)
            {
                end=0;
            }
        }
        if (end==1)
        {
            QMessageBox::information(0, "Result", "Draw!");
            return ;
        }
    }
}
}
}


bool Widget::check()
{

if ((mas[0]==mas[1])&(mas[0]==mas[8])&(mas[0]!=0))
{ return true; }
if ((mas[0]==mas[5])&(mas[0]==mas[6])&(mas[6]!=0))
{ return true; }
if ((mas[3]==mas[1])&(mas[3]==mas[7])&(mas[7]!=0))
{ return true; }
if ((mas[4]==mas[2])&(mas[4]==mas[8])&(mas[8]!=0))
{ return true; }
if ((mas[4]==mas[1])&(mas[4]==mas[6])&(mas[6]!=0))
{ return true; }
if ((mas[5]==mas[1])&(mas[5]==mas[2])&(mas[2]!=0))
{ return true; }
if ((mas[6]==mas[7])&(mas[6]==mas[8])&(mas[8]!=0))
{ return true; }
if ((mas[0]==mas[3])&(mas[0]==mas[4])&(mas[0]!=0))
{ return true; }
return false;
}

Widget::~Widget()
{
delete ui;
}



void Widget::on_pushButton_clicked()
{
    first=1;
}
