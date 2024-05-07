#include "group.h"

group::group()
{

}
void group::setGroup(int group){
    this->group1 = group;
}
void group::setName(QString name){
    this->name = name;
}
int group::getGroup(){
    return group1;
}
QString group::getName(){
    return name;
}
