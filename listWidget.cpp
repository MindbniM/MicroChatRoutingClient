#include "listWidget.h"
SearchBox::SearchBox(QWidget* parent):QLineEdit(parent)
{
    this->setFixedHeight(25);
    this->setPlaceholderText("搜索");
    this->setStyleSheet("QLineEdit { border-radius: 5px; background-color: rgb(226, 226, 226); padding-left: 5px;}");
    this->setClearButtonEnabled(true);
    this->addAction(QIcon(":/Fun/Icon/search.png"),QLineEdit::LeadingPosition);
}
void SearchBox::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QLineEdit::mousePressEvent(event);
}
SearchWidget::SearchWidget(QWidget* parent):QWidget(parent)
{
    _search=new SearchBox(this);
    _layout=new QGridLayout(this);
    _any=new QPushButton(this);
    _layout->setContentsMargins(0, 0, 0, 0);
    this->setFixedSize(QSize(250,60));
    this->setStyleSheet("background-color: rgb(247, 247, 247);");
    QWidget* spacer1 = new QWidget(this);
    spacer1->setFixedWidth(5);
    QWidget* spacer2 = new QWidget(this);
    spacer2->setFixedWidth(5);
    QWidget* spacer3 = new QWidget(this);
    spacer3->setFixedWidth(5);

    _layout->addWidget(spacer1, 0, 0);
    _layout->addWidget(_search, 0, 1);
    _layout->addWidget(spacer2, 0, 2);
    _layout->addWidget(_any,0,3);
    _layout->addWidget(spacer3, 0, 4);

    setButtonChat();
}
void SearchWidget::setButtonChat()
{
    _any->setIcon(QIcon(":/Fun/Icon/addChat.png"));
    _any->setFixedSize(QSize(25,25));
    _any->setIconSize(QSize(20,20));
    _any->setStyleSheet(R"(
        QPushButton {
            border: none;
            background-color: rgb(226, 226, 226);
        }
        QPushButton:hover {
            background-color: rgba(226, 226, 226, 0.7); /* 可选的悬停效果 */
        }
    )");
}
void SearchWidget::setButtonAddress()
{
    _any->setIcon(QIcon(":/Fun/Icon/addAddress.png"));
    _any->setFixedSize(QSize(25,25));
    _any->setIconSize(QSize(20,20));
    _any->setStyleSheet(R"(
        QPushButton {
            border: none;
            background-color: transparent;
        }
        QPushButton:hover {
            background-color: rgba(255, 255, 255, 0.1); /* 可选的悬停效果 */
        }
    )");
}
ListWidget::ListWidget(QWidget* parent):QWidget(parent)
{
    _sw=new SearchWidget(this);
    this->setFixedWidth(250);
    this->setStyleSheet("background-color: rgb(230, 230, 230);");

    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(_sw,0,Qt::AlignTop);


    //layout->addWidget(sessionFriendArea, 1, 0, 1, 3);
}
