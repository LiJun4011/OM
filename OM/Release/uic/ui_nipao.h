/********************************************************************************
** Form generated from reading UI file 'nipao.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIPAO_H
#define UI_NIPAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_nipao
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *nipao)
    {
        if (nipao->objectName().isEmpty())
            nipao->setObjectName(QString::fromUtf8("nipao"));
        nipao->resize(342, 300);
        groupBox = new QGroupBox(nipao);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 241));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 91, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 30, 75, 23));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 180, 75, 23));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(210, 180, 75, 23));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 110, 75, 23));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(210, 110, 75, 23));

        retranslateUi(nipao);
        QObject::connect(pushButton, SIGNAL(pressed()), nipao, SLOT(Relay9Pressed()));
        QObject::connect(pushButton, SIGNAL(released()), nipao, SLOT(Relay9Released()));
        QObject::connect(pushButton_2, SIGNAL(pressed()), nipao, SLOT(Relay10Pressed()));
        QObject::connect(pushButton_2, SIGNAL(released()), nipao, SLOT(Relay9Released()));
        QObject::connect(pushButton_5, SIGNAL(pressed()), nipao, SLOT(Relay11Pressed()));
        QObject::connect(pushButton_5, SIGNAL(released()), nipao, SLOT(Relay11Released()));
        QObject::connect(pushButton_6, SIGNAL(pressed()), nipao, SLOT(Relay12Pressed()));
        QObject::connect(pushButton_6, SIGNAL(released()), nipao, SLOT(Relay12Released()));
        QObject::connect(pushButton_3, SIGNAL(pressed()), nipao, SLOT(Relay27Pressed()));
        QObject::connect(pushButton_3, SIGNAL(released()), nipao, SLOT(Relay27Released()));
        QObject::connect(pushButton_4, SIGNAL(pressed()), nipao, SLOT(Relay28Pressed()));
        QObject::connect(pushButton_4, SIGNAL(released()), nipao, SLOT(Relay28Released()));

        QMetaObject::connectSlotsByName(nipao);
    } // setupUi

    void retranslateUi(QDialog *nipao)
    {
        nipao->setWindowTitle(QCoreApplication::translate("nipao", "\346\263\245\347\202\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("nipao", "\346\263\245\347\202\256\344\275\215\347\275\256\345\276\256\350\260\203", nullptr));
        pushButton->setText(QCoreApplication::translate("nipao", "\346\263\245\347\202\256\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("nipao", "\346\263\245\347\202\256\345\220\216\351\200\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("nipao", "\345\267\246\347\247\273", nullptr));
        pushButton_4->setText(QCoreApplication::translate("nipao", "\345\217\263\347\247\273", nullptr));
        pushButton_5->setText(QCoreApplication::translate("nipao", "\346\214\244\346\263\245", nullptr));
        pushButton_6->setText(QCoreApplication::translate("nipao", "\345\241\253\346\263\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nipao: public Ui_nipao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIPAO_H
