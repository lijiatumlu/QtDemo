#include "logiclayer.h"

#include <QDebug>
#include "login.h"

UserInfo *LogicLayer::m_userInfo = new UserInfo;
List_FriendInfo *LogicLayer::m_friendInfoList = new List_FriendInfo;

LogicLayer::LogicLayer(QObject *parent) :
    QObject(parent)
{
    m_login = new Login();
    m_register = new Register;
    m_connectServer = new ConnectServer(this);
    m_formAddFriend = new AddFriend();
    m_friendList = new FriendList;
    m_userInfoForm = new UserInfoForm();

    connect(m_login, SIGNAL(signalRedister()),
            this, SLOT(slotRedister()));
    connect(m_register, SIGNAL(signalRedisterAsk(QString,QString)),
            m_connectServer, SLOT(slotRedisterAsk(QString,QString)));
    connect(m_login, SIGNAL(signalConnectServer(QString,QString)),
            m_connectServer, SLOT(slotConnectServer(QString,QString)));

    m_login->show();
}

LogicLayer::~LogicLayer()
{
    delete m_login;
    delete m_connectServer;
    delete m_friendList;
}

void LogicLayer::slotUserLoginSuccess(UserInfo *info)
{
    m_login->hide();

    m_friendList->initUserInfo(info);
    m_friendList->show();

    connect(m_friendList, SIGNAL(signalClickUserInfo(UserInfo*)),
            this, SLOT(slotClickUserInfo(UserInfo*)));
    connect(m_friendList, SIGNAL(signalFindFriend()),
            this, SLOT(slotFindFriend()));
}

void LogicLayer::slotClickUserInfo(UserInfo *info)
{
    m_userInfoForm->show();
    m_userInfoForm->updateUserInfoToForm(info);
}

void LogicLayer::slotRedister()
{
    m_register->show();
    m_login->hide();
}

void LogicLayer::slotUserRegisterSuccess(UserInfo *info)
{
    m_register->hide();
    m_login->setIDPassword(info->getUID(), info->getPassword());
    m_login->show();
}

void LogicLayer::slotFindFriend()
{
    connect(m_formAddFriend, SIGNAL(signalFindFriend(QString)),
            m_connectServer, SLOT(slotFindFriend(QString)));
    connect(m_formAddFriend, SIGNAL(signalAddFriend(QString)),
            m_connectServer, SLOT(slotAddFriend(QString)));
    m_formAddFriend->show();
}

void LogicLayer::slotUserFindFriendSuccess(UserInfo *info)
{
    m_formAddFriend->updateSearchResult(info);
}

void LogicLayer::slotUpdateFriendList()
{
    m_friendList->updateFriendList();
}
