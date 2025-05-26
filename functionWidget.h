#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
class FunWidget : public QWidget
{
public:
    FunWidget(QWidget* parent);
private:
    QPushButton* _user;
    QPushButton* _chat;
    QPushButton* _addressBook;
};


