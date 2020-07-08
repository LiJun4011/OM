/********************************************************************************
** Form generated from reading UI file 'ZNmozu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZNMOZU_H
#define UI_ZNMOZU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ZNmozu
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *okButton;

    void setupUi(QDialog *ZNmozu)
    {
        if (ZNmozu->objectName().isEmpty())
            ZNmozu->setObjectName(QString::fromUtf8("ZNmozu"));
        ZNmozu->resize(342, 300);
        groupBox = new QGroupBox(ZNmozu);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 221));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 50, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 130, 75, 23));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 321, 221));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 50, 75, 23));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 130, 75, 23));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 90, 75, 23));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(220, 90, 75, 23));
        okButton = new QPushButton(ZNmozu);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(10, 240, 321, 51));

        retranslateUi(ZNmozu);
        QObject::connect(okButton, SIGNAL(clicked()), ZNmozu, SLOT(okbutton()));
        QObject::connect(pushButton_4, SIGNAL(pressed()), ZNmozu, SLOT(Relay7Pressed()));
        QObject::connect(pushButton_4, SIGNAL(released()), ZNmozu, SLOT(Relay7Released()));
        QObject::connect(pushButton_3, SIGNAL(pressed()), ZNmozu, SLOT(Relay8Pressed()));
        QObject::connect(pushButton_3, SIGNAL(released()), ZNmozu, SLOT(Relay8Released()));
        QObject::connect(pushButton_5, SIGNAL(pressed()), ZNmozu, SLOT(Relay29Pressed()));
        QObject::connect(pushButton_5, SIGNAL(released()), ZNmozu, SLOT(Relay29Released()));
        QObject::connect(pushButton_6, SIGNAL(pressed()), ZNmozu, SLOT(Relay30Pressed()));
        QObject::connect(pushButton_6, SIGNAL(released()), ZNmozu, SLOT(Relay30Released()));

        QMetaObject::connectSlotsByName(ZNmozu);
    } // setupUi

    void retranslateUi(QDialog *ZNmozu)
    {
        ZNmozu->setWindowTitle(QCoreApplication::translate("ZNmozu", "\345\207\277\345\262\251\346\263\245\347\202\256\346\250\241\347\273\204", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ZNmozu", "\345\207\277\345\262\251\346\263\245\347\202\256\346\250\241\347\273\204\345\210\260\344\275\215\350\260\203\346\225\264", nullptr));
        pushButton->setText(QCoreApplication::translate("ZNmozu", "\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ZNmozu", "\345\220\216\351\200\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ZNmozu", "\345\207\277\345\262\251\346\263\245\347\202\256\346\250\241\347\273\204\345\210\260\344\275\215\350\260\203\346\225\264", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ZNmozu", "\346\250\241\347\273\204\345\211\215\350\277\233", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ZNmozu", "\346\250\241\347\273\204\345\220\216\351\200\200", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ZNmozu", "\346\235\276\345\274\200\346\250\241\347\273\204", nullptr));
        pushButton_6->setText(QCoreApplication::translate("ZNmozu", "\345\215\241\346\255\273\346\250\241\347\273\204", nullptr));
        okButton->setText(QCoreApplication::translate("ZNmozu", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZNmozu: public Ui_ZNmozu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZNMOZU_H
