#include "functionWidget.h"
FunWidget::FunWidget(QWidget* parent):QWidget(parent)
{
    this->setFixedWidth(50);
    this->setStyleSheet("background-color: rgb(46, 46, 46);");
    QHBoxLayout* layout=new QHBoxLayout(this);
    _chat=new QPushButton(this);

    QIcon chatIcon(":/Fun/Icon/chat.png");
    _chat->setIcon(chatIcon);
    _chat->setFixedSize(32, 32);
    _chat->setIconSize(QSize(24, 24));

    _chat->setStyleSheet(R"(
        QPushButton {
            border: none;
            background-color: transparent;
        }
        QPushButton:hover {
            background-color: rgba(255, 255, 255, 0.1); /* 可选的悬停效果 */
        }
    )");

    layout->addWidget(_chat);
}
