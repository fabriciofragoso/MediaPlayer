#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtMultimedia/QSound>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QSound *sound;
    QPushButton *stopbutton;
    QPushButton *playbutton;
    QLabel *status;
    QTimer *timer_raplay;
private slots:
    void play();
    void stop();
    void replay();
};

#endif // WIDGET_H
