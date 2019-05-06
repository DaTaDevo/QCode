#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_contact.h"
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include <QTextStream>

void MainWindow::update_or_filling_list()
{
    ui->listContact->clear();
    QVector<QString> strings;

    QFile f("database.txt");
    f.open(QIODevice::ReadOnly);
    QTextStream read(&f);
    while(!read.atEnd())
    {
        QString line = read.readLine();
        strings.push_back(line);
    }
    f.close();

    for(int i=0;i<strings.size();i++ )
    {
        ui->listContact->addItem(strings.at(i));
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->but_delete->hide();
    update_or_filling_list();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
     Add_Contact  acc;
     acc.setModal(true);
     acc.exec();
     update_or_filling_list();
     ui->but_delete->hide();
}

void MainWindow::on_but_delete_clicked()
{
    QMessageBox::StandardButton del  = QMessageBox::question(this,"Delete","Do you really want to delete this contact"+(ui->listContact->currentItem()->text()),QMessageBox::Ok | QMessageBox::No);

    if(del == QMessageBox::Yes)
    {
        PhoneBook var;
       QString string_of_contact = ui->listContact->currentItem()->text();
       string string_of_contact_std = string_of_contact.toStdString();
       var.delete_Contact(string_of_contact_std);
       update_or_filling_list();
    }
    else
    {

    }
}
