#include "name.h"
name::name()
{

}
name::~name(){
    delete index1;
}
QString name::getName(){
    return index1->getUser();
}
