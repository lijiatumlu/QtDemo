#ifndef LOGICLAYER_H
#define LOGICLAYER_H

#include <QObject>
#include <QTimer>

#include "connectserver.h"
#include "friendlist.h"
#include "userinfoform.h"
#include "register.h"
#include "addfriend.h"
#include "friendinfo.h"

class Login;

class LogicLayer : public QObject
{
    Q_OBJECT

public slots:
    void slotUserLoginSuccess(UserInfo *info);
    void slotUserRegisterSuccess(UserInfo *info);
    void slotUserFindFriendSuccess(UserInfo *info);

    void slotClickUserInfo(UserInfo *info);
    void slotRedister();
    void slotFindFriend();
//    void slotAddFriend(QString uid);
    void slotUpdateFriendList();

public:
    explicit LogicLayer(QObject *parent = 0);
    ~LogicLayer();

    static UserInfo *m_userInfo;
    static List_FriendInfo *m_friendInfoList;

private:
    Login *m_login;
    Register *m_register;
    ConnectServer *m_connectServer;

    FriendList *m_friendList;
    AddFriend *m_formAddFriend;
    UserInfoForm *m_userInfoForm;
};

#endif // LOGICLAYER_H
