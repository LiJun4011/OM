/********************************************************************************
** Form generated from reading UI file 'zaoyan.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZAOYAN_H
#define UI_ZAOYAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_zaoyan
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *okButton;

    void setupUi(QDialog *zaoyan)
    {
        if (zaoyan->objectName().isEmpty())
            zaoyan->setObjectName(QString::fromUtf8("zaoyan"));
        zaoyan->resize(342, 300);
        groupBox = new QGroupBox(zaoyan);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 221));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 30, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 170, 75, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 100, 75, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 100, 75, 23));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(220, 170, 75, 23));
        okButton = new QPushButton(zaoyan);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(10, 240, 321, 51));

        retranslateUi(zaoyan);
        QObject::connect(okButton, SIGNAL(clicked()), zaoyan, SLOT(okbutton()));
        QObject::connect(pushButton, SIGNAL(pressed()), zaoyan, SLOT(Relay3Pressed()));
        QObject::connect(pushButton, SIGNAL(released()), zaoyan, SLOT(Relay3Released()));
        QObject::connect(pushButton_2, SIGNAL(pressed()), zaoyan, SLOT(Relay2Pressed()));
        QObject::connect(pushButton_2, SIGNAL(released()), zaoyan, SLOT(Relay2Released()));
        QObject::connect(pushButton_4, SIGNAL(pressed()), zaoyan, SLOT(Relay28Pressed()));
        QObject::connect(pushButton_4, SIGNAL(released()), zaoyan, SLOT(Relay28Released()));
        QObject::connect(pushButton_3, SIGNAL(pressed()), zaoyan, SLOT(Relay27Pressed()));
        QObject::connect(pushButton_3, SIGNAL(released()), zaoyan, SLOT(Relay27Released()));
        QObject::connect(pushButton_5, SIGNAL(pressed()), zaoyan, SLOT(Relay31Pressed()));
        QObject::connect(pushButton_5, SIGNAL(released()), zaoyan, SLOT(Relay31Released()));

        QMetaObject::connectSlotsByName(zaoyan);
    } // setupUi

    void retranslateUi(QDialog *zaoyan)
    {
        zaoyan->setWindowTitle(QCoreApplication::translate("zaoyan", "\346\225\264\350\275\246", nullptr));
        groupBox->setTitle(QCoreApplication::translate("zaoyan", "\346\225\264\350\275\246\344\275\215\347\275\256\345\276\256\350\260\203", nullptr));
        pushButton->setText(QCoreApplication::translate("zaoyan", "\346\225\264\350\275\246\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("zaoyan", "\346\225\264\350\275\246\345\220\216\351\200\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("zaoyan", "\346\225\264\350\275\246\345\267\246\347\247\273", nullptr));
        pushButton_4->setText(QCoreApplication::translate("zaoyan", "\346\225\264\350\275\246\345\217\263\347\247\273", nullptr));
        pushButton_5->setText(QCoreApplication::translate("zaoyan", "\346\212\261\347\264\247\350\275\250\351\201\223", nullptr));
        okButton->setText(QCoreApplication::translate("zaoyan", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zaoyan: public Ui_zaoyan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZAOYAN_H
