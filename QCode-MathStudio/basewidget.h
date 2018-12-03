#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>

#include "mainmath.h"

// Это базовый класс(класс интерфейса) он используется
// для того чтобы в дальнейшем можно было маштабировать приложение
// а также вынести общюю логику

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(QWidget *parent = 0);

signals:
    void signalResult(const myMath::Triangle&);
public slots:
    void startTask(int numTask);
};

#endif // BASEWIDGET_H
