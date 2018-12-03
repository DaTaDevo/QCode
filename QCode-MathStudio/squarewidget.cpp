#include "squarewidget.h"
#include "ui_squarewidget.h"

SquareWidget::SquareWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SquareWidget)
{
    ui->setupUi(this);
}

SquareWidget::~SquareWidget()
{
    delete ui;
}
