#ifndef SQUAREWIDGET_H
#define SQUAREWIDGET_H

#include <QWidget>

namespace Ui {
class SquareWidget;
}

class SquareWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SquareWidget(QWidget *parent = 0);
    ~SquareWidget();

private:
    Ui::SquareWidget *ui;
};

#endif // SQUAREWIDGET_H
