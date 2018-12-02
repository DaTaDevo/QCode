/********************************************************************************
** Form generated from reading UI file 'trianglewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLEWIDGET_H
#define UI_TRIANGLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TriangleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *triangleType;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *spinBoxAB;
    QLabel *label_4;
    QDoubleSpinBox *spinBoxA;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxBC;
    QLabel *label_5;
    QDoubleSpinBox *spinBoxB;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *spinBoxAC;
    QLabel *label_6;
    QDoubleSpinBox *spinBoxC;

    void setupUi(QWidget *TriangleWidget)
    {
        if (TriangleWidget->objectName().isEmpty())
            TriangleWidget->setObjectName(QStringLiteral("TriangleWidget"));
        TriangleWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(TriangleWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        triangleType = new QComboBox(TriangleWidget);
        triangleType->setObjectName(QStringLiteral("triangleType"));

        verticalLayout->addWidget(triangleType);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(TriangleWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBoxAB = new QDoubleSpinBox(TriangleWidget);
        spinBoxAB->setObjectName(QStringLiteral("spinBoxAB"));

        horizontalLayout->addWidget(spinBoxAB);

        label_4 = new QLabel(TriangleWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        spinBoxA = new QDoubleSpinBox(TriangleWidget);
        spinBoxA->setObjectName(QStringLiteral("spinBoxA"));

        horizontalLayout->addWidget(spinBoxA);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(TriangleWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        spinBoxBC = new QDoubleSpinBox(TriangleWidget);
        spinBoxBC->setObjectName(QStringLiteral("spinBoxBC"));

        horizontalLayout_3->addWidget(spinBoxBC);

        label_5 = new QLabel(TriangleWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        spinBoxB = new QDoubleSpinBox(TriangleWidget);
        spinBoxB->setObjectName(QStringLiteral("spinBoxB"));

        horizontalLayout_3->addWidget(spinBoxB);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(TriangleWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBoxAC = new QDoubleSpinBox(TriangleWidget);
        spinBoxAC->setObjectName(QStringLiteral("spinBoxAC"));

        horizontalLayout_2->addWidget(spinBoxAC);

        label_6 = new QLabel(TriangleWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        spinBoxC = new QDoubleSpinBox(TriangleWidget);
        spinBoxC->setObjectName(QStringLiteral("spinBoxC"));

        horizontalLayout_2->addWidget(spinBoxC);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(TriangleWidget);

        QMetaObject::connectSlotsByName(TriangleWidget);
    } // setupUi

    void retranslateUi(QWidget *TriangleWidget)
    {
        TriangleWidget->setWindowTitle(QApplication::translate("TriangleWidget", "Form", nullptr));
        label->setText(QApplication::translate("TriangleWidget", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260 \320\220\320\222:", nullptr));
        label_4->setText(QApplication::translate("TriangleWidget", "\320\243\320\263\320\276\320\273 \320\220", nullptr));
        label_2->setText(QApplication::translate("TriangleWidget", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260 \320\222\320\241:", nullptr));
        label_5->setText(QApplication::translate("TriangleWidget", "\320\243\320\263\320\276\320\273 \320\222", nullptr));
        label_3->setText(QApplication::translate("TriangleWidget", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\320\275\320\270\320\272\320\260 \320\220\320\241:", nullptr));
        label_6->setText(QApplication::translate("TriangleWidget", "\320\243\320\263\320\276\320\273 \320\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriangleWidget: public Ui_TriangleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLEWIDGET_H
