#ifndef TRIANGLEWIDGET_H
#define TRIANGLEWIDGET_H

#include <QHash>
#include <QWidget>

#include "mainmath.h"
#include "basewidget.h"

namespace Ui {
class TriangleWidget;
}


class TriangleWidget : public BaseWidget
{
    Q_OBJECT

    enum TypeTriangle {
        versatileTriangle, /// ровностороний
        isoscelesTriangle, /// равнобедренный
        rightTriangle, /// прямоугольный
    };

public:
    explicit TriangleWidget(QWidget *parent = 0);
    ~TriangleWidget();

protected slots:
    void startTask(int numTask);

// этот сигнал определен в базовом виджете
//signals:
//    void signalResult(const myMath::Triangle);

private:
    Ui::TriangleWidget *ui;
    myMath::Triangle result;
    int taskFlag = 0;
    QHash<int, QString> hashFlag;

private slots:
    // вызаваются при смене соотвецтвующей стороны
    void upAB(double ab);
    void upBC(double bc);
    void upAC(double ac);
    // вызывается при смене типа трегольника
    //void setTypeTriangle(int type);
};

#endif // TRIANGLEWIDGET_H
