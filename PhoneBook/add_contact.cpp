#include "add_contact.h"
#include "ui_add_contact.h"
#include <QMessageBox>

Add_Contact::Add_Contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Contact)
{
    ui->setupUi(this);
}

Add_Contact::~Add_Contact()
{
    delete ui;
}

void Add_Contact::on_pushButton_clicked()
{
    PhoneBook var;
    QString qName = ui->set_name->text();
    QString qNumber = ui->set_number->text();
    string name  = qName.toStdString();
    string number  = qNumber.toStdString();
    var.save_To_DataBase(name,number);
    QMessageBox ::information(this,"Information","Your contact successfuly saved");
    hide();
}
