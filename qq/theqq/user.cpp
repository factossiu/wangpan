#include "user.h"
user::user(){

}
void user::setAccount(QString account){
    this->account = account;
}
void user::setIcon(QString icon){
    this->icon =icon;
}
void user::setPassword(QString password){
    this->password = password;
}
QString user::getAccount(){
    return this->account;
}
QString user::getPassword(){
    return this->password;
}
QString user::getIcon(){
    return this->icon;
}
void user::setSign(QString sign){
    this->sign = sign;
}
QString user::getSign(){
    return this->sign;
}
QString user::getLv(){
    return this->lv;
}
int user::getGroup(){
    return this->group;
}
int user::getId(){
    return this->id;
}
void user::setLv(QString lv){
    this->lv = lv;
}
void user::setGroup(int group)
{
    this->group = group;
}
void user::setId(int id){
    this->id = id;
}
