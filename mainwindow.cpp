#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // хеш таблица которая хранит указатели на виджеты задач
    hashTask[Tasks::taskTriangle]  = new TriangleWidget;
    hashTask[Tasks::taskKvadrat] = new SquareWidget;

    // заполняем stekWidget
    // здесь заполняем stekWidget, виджетами задач
    // позже можно будет этот процесс автоматизировать
    stackedWgt = new QStackedWidget;
    stackedWgt->addWidget(hashTask.value(Tasks::taskTriangle));
    stackedWgt->addWidget(hashTask.value(Tasks::taskKvadrat));

    ui->mainLayout->addWidget(stackedWgt, 1);

    // заполняем список задач
    ui->listTask->addItem("Triangle");
    ui->listTask->addItem("Kvadrat");

    // соединяем наш список задач со слотом быбора виджета задачи
    connect(ui->listTask, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)), this, SLOT(upWidget(QListWidgetItem*, QListWidgetItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// переключаем на нужный нам виджет, зависит от того что пользователь выбрал из списка
void MainWindow::upWidget(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current) {
            current = previous;
    }
    stackedWgt->setCurrentIndex(ui->listTask->row(current));
    BaseWidget *wgt = qobject_cast<BaseWidget*>(stackedWgt->currentWidget());
    connect(wgt, SIGNAL(signalResult(myMath::Triangle)), this, SLOT(sendMsgConsole(myMath::Triangle)));
}

// здесь вы выводи все информацию в консоль
void MainWindow::sendMsgConsole(myMath::Triangle data)
{
    // вывод ошибок
    if(data.err) {
        ui->mathConsole->setTextColor(QColor(Qt::red));
        if (data.strError == "") {
            ui->mathConsole->append("[ERROR]: \"Нет описания ошибки\" \n");
        } else {
            ui->mathConsole->append("[ERROR]: " + QString::fromUtf8(data.strError.c_str()) + "\n");
        }
        ui->mathConsole->setTextColor(QColor(Qt::black));
    }

    // вывод входящей информации
    ui->mathConsole->setTextColor(QColor(Qt::darkMagenta));
    ui->mathConsole->append("[IN]: \n"
                             "AB: " + QString::number(data.inData->ab) + "\n" +
                             "BC: " + QString::number(data.inData->bc) + "\n" +
                             "AC: " + QString::number(data.inData->ac) + "\n");
    ui->mathConsole->setTextColor(QColor(Qt::black));

    // вывод полученных результатов можно тож автоматизировать со временем
    ui->mathConsole->setTextColor(QColor(Qt::blue));
    ui->mathConsole->append("[OUT]: \n"
                             "AB: " + QString::number(data.ab) + "\n" +
                             "BC: " + QString::number(data.bc) + "\n" +
                             "AC: " + QString::number(data.ac) + "\n");
    ui->mathConsole->setTextColor(QColor(Qt::black));

    // вывод сообщений
    if (data.msg != "") {
        ui->mathConsole->setTextColor(QColor(Qt::green));
        ui->mathConsole->append("[MESSAGE]: " + QString::fromUtf8(data.msg.c_str()) + "\n");
        ui->mathConsole->setTextColor(QColor(Qt::black));
    }
}
