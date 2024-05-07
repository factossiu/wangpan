#ifndef PROTOCOL_H
#define PROTOCOL_H
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<QWidget>
typedef unsigned int uint;
#define REGIST_OK "regist ok"
#define REGIST_FAILED "regist failed :name existed"
#define LOGIN_OK "login ok"
#define LOGIN_FAILED "login failed"
#define SEARCH_USER_NO "no such people"
#define SEARCH_USER_ONLINE "online"
#define SEARCH_USER_OFFLINE "offline"

#define UNKNOW_ERROR "unknow error"
#define EXISTED_FRINEND "friend exist"
#define ADD_FRIEND_OFFLINE "usr offline"
#define ADD_FRIEND_NOEXIST "usr not exist"

#define DEL_FRIEND_OK "delete friend ok"

#define DIR_NOT_EXIST "cur dir not exist"
#define DIR_NAME_EXIST "file name exist"
#define CREATE_DIR_OK "create dir ok"

#define DEL_DIR_OK "delete dir ok"
#define DEL_DIR_FAILURED "delete dir failured : is file"

#define RENAME_FILE_OK "rename ok"
#define RENAME_FILE_FAILURED "rename FAILURED"

#define ENTER_DIR_FAILURED "enter dir failured: is file"
#define ENTER_DIR_FAILURED "enter dir failured: is file"

#define UPLOAD_FILE_OK "upload file ok"
#define UPLOAD_FILE_FAILURED "upload file failured"

#define DEL_FILE_OK "delete file ok"
#define DEL_FILE_FAILURED "delete FILE failured : is Dir"

#define MOVE_FILE_OK "MOVE file ok"
#define MOVE_FILE_FAILURED "MOVE FILE failured : is reguler file"
#define COMMON_ERROR "operate failed:system is busy"
enum ENUM_MSG_TYPE{
    ENUM_MSG_TYPE_MIN = 0,
    ENUM_MSG_TYPE_REGIST_REQUEST,
    ENUM_MSG_TYPE_REGIST_RESPOND,
    ENUM_MSG_TYPE_LOGIN_REQUEST,
    ENUM_MSG_TYPE_LOGIN_RESPOND,
    ENUM_MSG_TYPE_ALL_ONLINE_REQUEST, //在线用户
    ENUM_MSG_TYPE_ALL_ONLINE_RESPOND,
    ENUM_MSG_TYPE_SEARCH_USER_REQUEST,
    ENUM_MSG_TYPE_SEARCH_USER_RESPOND,
    ENUM_MSG_TYPE_ADD_FRIEND_REQUEST,//添加好友
    ENUM_MSG_TYPE_ADD_FRIEND_RESPOND,
    ENUM_MSG_TYPE_ADD_FRIEND_AGGREE, //同意\拒绝添加好友
    ENUM_MSG_TYPE_ADD_FRIEND_REFUSE,
    ENUM_MSG_TYPE_FLUSG_REQUEST,    //刷新好友
    ENUM_MSG_TYPE_FLUSH_RESPOND,
    ENUM_MSG_TYPE_DEL_REQUEST,//删除好友
    ENUM_MSG_TYPE_DEL_RESPOND,
    ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST,//私聊
    ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND,

    ENUM_MSG_TYPE_GROUP_CHAT_REQUEST,//群聊
    ENUM_MSG_TYPE_GROUP_CHAT_RESPOND,

    ENUM_MSG_TYPE_CREATE_DIR_REQUEST,//创建文件
    ENUM_MSG_TYPE_CREATE_DIR_RESPOND,

    ENUM_MSG_TYPE_FLUSH_FILE_REQUEST,//刷新查看文件
    ENUM_MSG_TYPE_FLUSH_FILE_RESPOND,

    ENUM_MSG_TYPE_DEL_DIR_REQUEST,//删除目录
    ENUM_MSG_TYPE_DEL_DIR_RESPOND,

    ENUM_MSG_TYPE_RENAME_FILE_REQUEST,//重命名文件
    ENUM_MSG_TYPE_RENAME_FILE_RESPOND,

    ENUM_MSG_TYPE_ENTER_FILE_REQUEST,//进入文件夹
    ENUM_MSG_TYPE_ENTER_FILE_RESPOND,

    ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST,//上传文件夹
    ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND,

    ENUM_MSG_TYPE_DEL_FILE_REQUEST, //删除文件
    ENUM_MSG_TYPE_DEL_FILE_RESPOND,

    ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST,//下载请求
    ENUM_MSG_TPYE_DOWNLOAD_FILE_RESPOND,

    ENUM_MSG_TYPE_SHARE_FILE_REQUEST, //共享恢复
    ENUM_MSG_TYPE_SHARE_FILE_RESPOND,
    ENUM_MSG_TYPE_SHARE_FILE_NOTE,
        ENUM_MSG_TYPE_SHARE_FILE_NOTE_RESPOND,

    ENUM_MSG_TYPE_MOVE_FILE_REQUEST,//移动文件
    ENUM_MSG_TYPE_MOVE_FILE_RESPOND,
    /*  ENUM_MSG_TYPE_REGIST_REQUEST,
    ENUM_MSG_TYPE_REGIST_RESPOND,
    ENUM_MSG_TYPE_REGIST_REQUEST,
    ENUM_MSG_TYPE_REGIST_RESPOND,
    ENUM_MSG_TYPE_REGIST_REQUEST,
    ENUM_MSG_TYPE_REGIST_RESPOND,*/
    ENUM_MSG_TYPE_MAX_MAX = 0x00ffffff
};

struct FileInfo{
    char caFileName[32]; //文件名字
    int iFileType;//文件类型
};

struct PDU
{
    uint uiPDULen; //总的协议数据单元长度
    uint uiMsgType; //消息类型
    char caData[128];
    uint uiMsgLen;//实际消息长度
    int caMsg[];//实际消息
};
PDU *mkPDU(uint uiMsgLen);

#endif // PROTOCOL_H
