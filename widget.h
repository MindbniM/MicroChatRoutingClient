#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "functionWidget.h"
#include "listWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    static Widget& GetInstance();
private:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    FunWidget* windowLeft;
    ListWidget* windowMid;
    QWidget* windowRight;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
