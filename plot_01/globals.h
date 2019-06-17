#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QList>
struct Placeplot
{
    //int ID;
    QString name;
    float x;
    float y;
    QList<int> value;
};

struct Transitionplot
{
    //int ID;
    QString name;
    float x;
    float y;
    QList<int> value;
};

class globals
{
public:
    globals();
    ~globals();
public:
    static QList<struct Placeplot> placeList;
    static QList<struct Transitionplot> transitionList;
};



#endif // GLOBALS_H
