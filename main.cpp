#include <QCoreApplication>
#include <QDebug>
#include <QGlobal.h>
#include <QTime>

#include "rodent.h"

#include <random>


using namespace std;

int main(int argc, char *argv[])
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    QCoreApplication a(argc, argv);

    // создание экземпляра класса Mouse
    Mouse mouse("Jerry");
    qDebug()<< mouse.getName();
    qDebug()<< "Mouse weigth: " <<  mouse.getWeight();

    //пока мышь жива, кормим ее, и иногда используем суперспособность
    while(mouse.lifeDay())
    {
        qDebug()<< "Mouse weigth: " <<  mouse.getWeight();
        // генерация кол-ва корма мыши, не больше 50% ее веса
        float feed =0.1+ static_cast <float> (qrand()) / (static_cast <float> (RAND_MAX/(mouse.getWeight()/2)-0.1));
        //qDebug()<<feed<<endl;
        mouse.feed(feed);

        if (qrand()%5==2) mouse.addTwoGrams();
    }

    qDebug()<<mouse.getName()<<" lived "<<mouse.getAge()<<" days"<<endl;
    system("pause");

    // создание экземпляра класса Hamster
    Hamster hamster("Cooper");
    qDebug()<< hamster.getName();
    qDebug()<< "Hamster weigth: " <<  hamster.getWeight();

    //пока хомяк жив, кормим его, и иногда используем суперспособность
    while(hamster.lifeDay())
    {
        qDebug()<< "Hamster weigth: " <<  hamster.getWeight();
        // генерация кол-ва корма хомяка, не больше 50% его веса
        float feed =0.1+ static_cast <float> (qrand()) / (static_cast <float> (RAND_MAX/(hamster.getWeight()/2)-0.1));
        //qDebug()<<feed<<endl;
        hamster.feed(feed);

        if (qrand()%4==2) hamster.addTwoDays();
    }

    qDebug()<<hamster.getName()<<" lived "<<hamster.getAge()<<" days"<<endl;
    return a.exec();
}
