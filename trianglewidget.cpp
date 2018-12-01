#include "trianglewidget.h"
#include "ui_trianglewidget.h"

#include <QComboBox>
#include <QSpinBox>
#include <QDebug>

TriangleWidget::TriangleWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::TriangleWidget)
{
    ui->setupUi(this);

    // список  разновидностей треугольников
    hashFlag[TypeTriangle::equilateralTriangle] = "Прямоугольный";
    hashFlag[TypeTriangle::isoscelesTriangle] = "Ровностороний";
    hashFlag[TypeTriangle::orthogonalTriangle] = "Ровнобедренный";

    // заполняет comboBox, типами треугольников
    ui->triangleType->insertItem(TypeTriangle::equilateralTriangle, hashFlag.value(TypeTriangle::equilateralTriangle));
    ui->triangleType->insertItem(TypeTriangle::isoscelesTriangle, hashFlag.value(TypeTriangle::isoscelesTriangle));
    ui->triangleType->insertItem(TypeTriangle::orthogonalTriangle, hashFlag.value(TypeTriangle::orthogonalTriangle));

    // получаем данные из spinBox
    startTask(ui->triangleType->currentIndex());

    // связываем сигналы с слотами
    connect(ui->spinBoxAB, SIGNAL(valueChanged(double)), this, SLOT(upAB(double)));
    connect(ui->spinBoxBC, SIGNAL(valueChanged(double)), this, SLOT(upBC(double)));
    connect(ui->spinBoxAC, SIGNAL(valueChanged(double)), this, SLOT(upAC(double)));

    // запускаем перерасчет каждый раз как изменили тип треугольника
    connect(ui->triangleType, SIGNAL(activated(int)), this, SLOT(startTask(int)));
}

TriangleWidget::~TriangleWidget()
{
    delete ui;
}

// В качестве аргумента получает тип выбраного треугольника
void TriangleWidget::startTask(int numTask)
{
    myMath::Triangle tmpData;

    // в сообщение добавляем тип выбранного треугольника
    tmpData.msg += hashFlag.value(numTask).toStdString();

    // получаем входящие данные
    result.ab = ui->spinBoxAB->value();
    result.bc = ui->spinBoxBC->value();
    result.ac = ui->spinBoxAC->value();

    // заносим входищие данные
    tmpData.inData = &result;

    // получаем ответ
    tmpData = myMath::ForwardTriangleSide(result);

    //тут нужно воспользоваться switch
//    switch (numTask) {
//    case TypeTriangle::equilateralTriangle: {
        // Тут код связаный с решением задач прямогольных треугольников
        // по такому принципу поступаешь со всеми видами треугольников
//    }
//    default:
//        break;
//    }

    // вызываем сигнал об окончании решения задачи
    emit signalResult(tmpData);
}

void TriangleWidget::upAB(double ab)
{
    result.ab = ab;
    startTask(ui->triangleType->currentIndex());
}

void TriangleWidget::upBC(double ac)
{
    result.ac = ac;
    startTask(ui->triangleType->currentIndex());
}

void TriangleWidget::upAC(double ac)
{
    result.ac = ac;
    startTask(ui->triangleType->currentIndex());
}
