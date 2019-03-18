#ifndef RODENT_H
#define RODENT_H

#include <QString>
#include <QDebug>

class Rodent
{
     int maxLifeSpan = 1000; // in days
protected:
    double weight =1.0; //gramm
    // Maximum weigth is 250 gramm

    int age=0; //age in days
    QString name;

public:
    Rodent();
    Rodent(QString name); // Constructor
   ~Rodent(); // Destructor
    // get and set name
    QString getName() {return name;}
    int getAge(){return age;}
    void setName(QString newName) {name = newName;}

    double getWeight() {return weight;}

    // Add function - get Info, return QString with all information

    void feed(double food); // Feed rodent with some gramm of food
    virtual bool lifeDay(); // spend one day of life, return false is rodent die.
};


class Mouse: public Rodent{
public:
    Mouse(QString name); // Constructor
    void addTwoGrams();
    bool lifeDay();
};

class Hamster: public Rodent{
public:
    Hamster(QString name);
    void addTwoDays();
    bool lifeDay();
};

#endif // RODENT_H
