#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("ChatMsgRoute");

    windowLeft=new FunWidget(this);
    windowMid=new ListWidget(this);
    windowRight=new QWidget();

    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    windowRight->setMaximumWidth(900);

    windowRight->setStyleSheet("background-color: rgb(245, 245, 245);");
    layout->addWidget(windowLeft);
    layout->addWidget(windowMid);
    layout->addWidget(windowRight);

}
Widget& Widget::GetInstance()
{
    static Widget s_w;
    return s_w;
}

Widget::~Widget()
{
    delete ui;
}
