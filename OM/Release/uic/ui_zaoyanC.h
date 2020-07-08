/********************************************************************************
** Form generated from reading UI file 'zaoyanC.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZAOYANC_H
#define UI_ZAOYANC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_zaoyanC
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QDialog *zaoyanC)
    {
        if (zaoyanC->objectName().isEmpty())
            zaoyanC->setObjectName(QString::fromUtf8("zaoyanC"));
        zaoyanC->resize(342, 300);
        groupBox = new QGroupBox(zaoyanC);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 221));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(224, 30, 81, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(224, 180, 81, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(24, 100, 81, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 100, 81, 23));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(24, 30, 81, 23));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(24, 170, 81, 23));

        retranslateUi(zaoyanC);
        QObject::connect(pushButton_6, SIGNAL(clicked()), zaoyanC, SLOT(Relay4Pressed()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), zaoyanC, SLOT(Relay4Released()));
        QObject::connect(pushButton_3, SIGNAL(pressed()), zaoyanC, SLOT(Relay27Pressed()));
        QObject::connect(pushButton_3, SIGNAL(released()), zaoyanC, SLOT(Relay27Released()));
        QObject::connect(pushButton_4, SIGNAL(pressed()), zaoyanC, SLOT(Relay28Pressed()));
        QObject::connect(pushButton_4, SIGNAL(released()), zaoyanC, SLOT(Relay28Released()));
        QObject::connect(pushButton_2, SIGNAL(pressed()), zaoyanC, SLOT(Relay5Pressed()));
        QObject::connect(pushButton_2, SIGNAL(released()), zaoyanC, SLOT(Relay5Released()));
        QObject::connect(pushButton, SIGNAL(pressed()), zaoyanC, SLOT(Relay6Pressed()));
        QObject::connect(pushButton, SIGNAL(released()), zaoyanC, SLOT(Relay6Released()));

        QMetaObject::connectSlotsByName(zaoyanC);
    } // setupUi

    void retranslateUi(QDialog *zaoyanC)
    {
        zaoyanC->setWindowTitle(QCoreApplication::translate("zaoyanC", "\345\207\277\345\262\251", nullptr));
        groupBox->setTitle(QCoreApplication::translate("zaoyanC", "\345\207\277\345\262\251\344\275\215\347\275\256\345\276\256\350\260\203", nullptr));
        pushButton->setText(QCoreApplication::translate("zaoyanC", "\345\207\277\345\262\251\346\234\272\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("zaoyanC", "\345\207\277\345\262\251\346\234\272\345\220\216\351\200\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("zaoyanC", "\345\267\246\347\247\273", nullptr));
        pushButton_4->setText(QCoreApplication::translate("zaoyanC", "\345\217\263\347\247\273", nullptr));
        pushButton_6->setText(QCoreApplication::translate("zaoyanC", "\345\220\257\345\212\250\346\227\213\350\275\254\345\206\262\345\207\273", nullptr));
        pushButton_7->setText(QCoreApplication::translate("zaoyanC", "\345\201\234\346\255\242\346\227\213\350\275\254\345\206\262\345\207\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zaoyanC: public Ui_zaoyanC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZAOYANC_H
