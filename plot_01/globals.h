#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QList>
#include <QPushButton>

struct Placeplot
{
    //int ID;
    QString name;
    float x;
    float y;
    float yExpand;
    QList<int> value;
    QPushButton *ExpandButton;
    bool isPushuButton;
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
