#ifndef GROUP_H
#define GROUP_H
#include<QWidget>

class group
{
public:
    group();
    void setGroup(int group);
    void setName(QString name);
    int getGroup();
    QString getName();
    int group1;
    QString name;
};

#endif // GROUP_H
