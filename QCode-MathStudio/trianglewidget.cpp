#include "trianglewidget.h"
#include "ui_trianglewidget.h"

#include <QComboBox>
#include <QSpinBox>
#include <QPixmap>


TriangleWidget::TriangleWidget(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::TriangleWidget)
{
    ui->setupUi(this);

    // список  разновидностей треугольников
    hashFlag[TypeTriangle::arbitraryTriangle] = "Произвольный";
    hashFlag[TypeTriangle::isoscelesTriangle] = "Равнобедренный";
    hashFlag[TypeTriangle::rightTriangle] = "Прямоугольный";

    // заполняет comboBox, типами треугольников
    ui->triangleType->insertItem(TypeTriangle::arbitraryTriangle, hashFlag.value(TypeTriangle::arbitraryTriangle));
    ui->triangleType->insertItem(TypeTriangle::isoscelesTriangle, hashFlag.value(TypeTriangle::isoscelesTriangle));
    ui->triangleType->insertItem(TypeTriangle::rightTriangle, hashFlag.value(TypeTriangle::rightTriangle));

    // получаем данные из spinBox
    startTask(ui->triangleType->currentIndex());

    // связываем сигналы с слотами
    connect(ui->spinBoxAB, SIGNAL(valueChanged(double)), this, SLOT(upAB(double)));
    connect(ui->spinBoxBC, SIGNAL(valueChanged(double)), this, SLOT(upBC(double)));
    connect(ui->spinBoxAC, SIGNAL(valueChanged(double)), this, SLOT(upAC(double)));

    // запускаем перерасчет каждый раз как изменили тип треугольника
    connect(ui->triangleType, SIGNAL(activated(int)), this, SLOT(startTask(int)));

    QPixmap pixmap("://triangle");
    ui->labelImg->setPixmap(pixmap);
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
    result.a = ui->spinBoxA->value();
    result.b = ui->spinBoxB->value();
    result.c = ui->spinBoxC->value();


    // заносим входищие данные
    tmpData.inData = &result;

    // получаем ответ
    //tmpData = myMath::ForwardTriangleSide(result);


    //тут нужно воспользоваться switch
  switch (numTask) {
 case TypeTriangle::arbitraryTriangle :
  {
         tmpData = myMath::SaerchPartiesTriangle(result);
         break;
  }
  case TypeTriangle::isoscelesTriangle :
  {

      myMath::SaerchPartiesTriangle(result); break;
  }
  case TypeTriangle ::rightTriangle :
  {

      myMath::SearchAnglesTriangle(result); break;
  }
    default:
        break;
  }
       // Тут код связаный с решением задач прямогольных треугольников
      // по такому принципу поступаешь со всеми видами треугольников

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
