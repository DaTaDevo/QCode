/********************************************************************************
** Form generated from reading UI file 'squarewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQUAREWIDGET_H
#define UI_SQUAREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SquareWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *SquareWidget)
    {
        if (SquareWidget->objectName().isEmpty())
            SquareWidget->setObjectName(QStringLiteral("SquareWidget"));
        SquareWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(SquareWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(SquareWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        retranslateUi(SquareWidget);

        QMetaObject::connectSlotsByName(SquareWidget);
    } // setupUi

    void retranslateUi(QWidget *SquareWidget)
    {
        SquareWidget->setWindowTitle(QApplication::translate("SquareWidget", "Form", nullptr));
        label->setText(QApplication::translate("SquareWidget", "                          COMING SOON!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SquareWidget: public Ui_SquareWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQUAREWIDGET_H
