#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
class Widget;
class FunWidget : public QWidget
{
public:
    FunWidget(QWidget* parent,Widget* root);
private:
    void setFunIcon(QPushButton*button,const QString& filename);
    void setFunIconUser(const QString& filename);
    void initSignalSlot();
    void switchChatTable();
    void switchAddressTable();
    void userTable();
private:
    enum class Activate
    {
        CHAT,
        ADDRESSBOOK
    };
private:
    Widget* _root;
    QPushButton* _user;
    QPushButton* _chat;
    QPushButton* _addressBook;

    Activate _activate=Activate::CHAT;
};


