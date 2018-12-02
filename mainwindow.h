#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QStackedWidget>
#include <QMainWindow>
#include <QHash>

#include "trianglewidget.h"
#include "squarewidget.h"
#include "basewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum Tasks {
        taskTriangle, // 0
        taskKvadrat, // 1
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void upWidget(int taskNum);
    void upWidget(QListWidgetItem *current, QListWidgetItem *previous);
    void sendMsgConsole(myMath::Triangle data);
private:
    Ui::MainWindow *ui;
    //  таблица задач
    QHash<int, QWidget*> hashTask;
    QStackedWidget *stackedWgt;
};

#endif // MAINWINDOW_H
