#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // selecionando a musica a tocar
    ui->setupUi(this);
    sound = new QSound(".//music.wav");

    // Dimensoes da tela do player
    this-> resize(640,480);
    playbutton = new QPushButton(this);
    playbutton->setText("Play");
    int buttonx =640*80/100;
    int buttony =200;

    // A posicao do botao play
    playbutton->setGeometry(buttonx,buttony,70,40);
    playbutton->show();

    // titulo
    this->setWindowTitle("Player");

    // A posicao do botao stop
    stopbutton= new QPushButton(this);
    int buttonxx=640*60/100;
    int buttonxy=200;
    stopbutton->setGeometry(buttonxx,buttonxy,70,40);
    stopbutton->setText("Stop");
    stopbutton->show();

    status=new QLabel(this);
    int atx=640*50/100;
    int aty=100;
    status->setGeometry(atx,aty,100,10);
    status-> show();

    //conectando o butão a funcao designada
    connect(playbutton,SIGNAL(clicked()),this,SLOT(play()));
    connect(playbutton,SIGNAL(clicked()),this,SLOT(stop()));
    timer_raplay = new QTimer();
    connect(timer_raplay,SIGNAL(timeout()),this,SLOT(replay()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::play(){
    timer_raplay->start(2000);

}
void Widget::stop(){
    timer_raplay->stop();
}
void Widget::replay(){
    sound->play();
}
