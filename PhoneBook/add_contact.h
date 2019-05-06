#ifndef ADD_CONTACT_H
#define ADD_CONTACT_H

#include <QDialog>
#include "phonebook.h"

namespace Ui {
class Add_Contact;
}

class Add_Contact : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Contact(QWidget *parent = nullptr);
   ~Add_Contact();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_Contact *ui;
};

#endif // ADD_CONTACT_H
