#include "functionWidget.h"
FunWidget::FunWidget(QWidget* parent,Widget* root):QWidget(parent),_root(root)
{
    this->setFixedWidth(50);
    this->setStyleSheet("background-color: rgb(46, 46, 46);");
    QVBoxLayout* layout=new QVBoxLayout(this);
    layout->setSpacing(20);
    layout->setContentsMargins(0,50,0,0);
    _user=new QPushButton(this);
    _chat=new QPushButton(this);
    _addressBook=new QPushButton(this);

    setFunIconUser("D:/QTCode/MicroChatRoutingClient/Icon/测试.png");
    setFunIcon(_chat,":/Fun/Icon/chat_activate.png");
    setFunIcon(_addressBook,":/Fun/Icon/address.png");

    layout->addWidget(_user,1,Qt::AlignTop|Qt::AlignHCenter);
    layout->addWidget(_chat,1,Qt::AlignTop|Qt::AlignHCenter);
    layout->addWidget(_addressBook,1,Qt::AlignTop|Qt::AlignHCenter);

    layout->addStretch(20);


}
void FunWidget::setFunIconUser(const QString& filename)
{
    QIcon chatIcon(filename);
    _user->setIcon(chatIcon);
    _user->setFixedSize(40,40);
    _user->setIconSize(QSize(40,40));
    _user->setStyleSheet(R"(
        QPushButton {
            border: none;
            background-color: transparent;
        }
        QPushButton:hover {
            background-color: rgba(255, 255, 255, 0.1); /* 可选的悬停效果 */
        }
    )");
}
void FunWidget::setFunIcon(QPushButton* button,const QString& filename)
{
    QIcon chatIcon(filename);
    button->setIcon(chatIcon);
    button->setFixedSize(32, 32);
    button->setIconSize(QSize(24, 24));

    button->setStyleSheet(R"(
        QPushButton {
            border: none;
            background-color: transparent;
        }
        QPushButton:hover {
            background-color: rgba(255, 255, 255, 0.1); /* 可选的悬停效果 */
        }
    )");
}
void FunWidget::initSignalSlot()
{
    connect(_user,&QPushButton::clicked,this,&FunWidget::userTable);
    connect(_chat,&QPushButton::clicked,this,&FunWidget::switchChatTable);
    connect(_addressBook,&QPushButton::clicked,this,&FunWidget::switchAddressTable);
}
void FunWidget::switchChatTable()
{
    _activate=Activate::CHAT;
    _chat->setIcon(QIcon(":/Fun/Icon/chat_activate.png"));
    _addressBook->setIcon(QIcon(":/Fun/Icon/address.png"));
    _root->windowMid;
}
void FunWidget::switchAddressTable()
{
    _activate=Activate::ADDRESSBOOK;
    _chat->setIcon(QIcon(":/Fun/Icon/chat.png"));
    _addressBook->setIcon(QIcon(":/Fun/Icon/address.png"));
}
void FunWidget::userTable()
{}
