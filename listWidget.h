#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QGridlayout>
#include <QPushButton>
class SearchBox : public QLineEdit
{
    Q_OBJECT
public:
    SearchBox(QWidget* parent);
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event) override;
};
class SearchWidget : public QWidget
{
public:
    SearchWidget(QWidget* parent);

    void setButtonChat();
    void setButtonAddress();
private:
    SearchBox* _search;
    QPushButton* _any;

    QGridLayout* _layout;
};

class ListWidget : public QWidget
{
public:
    ListWidget(QWidget* parent);
private:
    SearchWidget* _sw;
};
