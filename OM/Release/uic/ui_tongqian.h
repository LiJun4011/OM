/********************************************************************************
** Form generated from reading UI file 'tongqian.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONGQIAN_H
#define UI_TONGQIAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_tongqian
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButtonRC20;
    QPushButton *pushButtonRC25;
    QPushButton *pushButtonRC26;
    QPushButton *pushButtonRC17;
    QPushButton *pushButtonRC22;
    QPushButton *pushButtonRC21;
    QPushButton *pushButtonRC19;
    QPushButton *pushButtonRC23;
    QPushButton *pushButtonRC24;
    QPushButton *pushButtonRC18;

    void setupUi(QDialog *tongqian)
    {
        if (tongqian->objectName().isEmpty())
            tongqian->setObjectName(QString::fromUtf8("tongqian"));
        tongqian->resize(342, 288);
        groupBox = new QGroupBox(tongqian);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 261));
        pushButtonRC20 = new QPushButton(groupBox);
        pushButtonRC20->setObjectName(QString::fromUtf8("pushButtonRC20"));
        pushButtonRC20->setGeometry(QRect(40, 120, 91, 23));
        pushButtonRC25 = new QPushButton(groupBox);
        pushButtonRC25->setObjectName(QString::fromUtf8("pushButtonRC25"));
        pushButtonRC25->setGeometry(QRect(20, 170, 131, 23));
        pushButtonRC26 = new QPushButton(groupBox);
        pushButtonRC26->setObjectName(QString::fromUtf8("pushButtonRC26"));
        pushButtonRC26->setGeometry(QRect(170, 170, 131, 23));
        pushButtonRC17 = new QPushButton(groupBox);
        pushButtonRC17->setObjectName(QString::fromUtf8("pushButtonRC17"));
        pushButtonRC17->setGeometry(QRect(200, 210, 91, 23));
        pushButtonRC22 = new QPushButton(groupBox);
        pushButtonRC22->setObjectName(QString::fromUtf8("pushButtonRC22"));
        pushButtonRC22->setGeometry(QRect(10, 80, 141, 23));
        pushButtonRC21 = new QPushButton(groupBox);
        pushButtonRC21->setObjectName(QString::fromUtf8("pushButtonRC21"));
        pushButtonRC21->setGeometry(QRect(170, 80, 141, 23));
        pushButtonRC19 = new QPushButton(groupBox);
        pushButtonRC19->setObjectName(QString::fromUtf8("pushButtonRC19"));
        pushButtonRC19->setGeometry(QRect(190, 120, 91, 23));
        pushButtonRC23 = new QPushButton(groupBox);
        pushButtonRC23->setObjectName(QString::fromUtf8("pushButtonRC23"));
        pushButtonRC23->setGeometry(QRect(30, 30, 81, 23));
        pushButtonRC24 = new QPushButton(groupBox);
        pushButtonRC24->setObjectName(QString::fromUtf8("pushButtonRC24"));
        pushButtonRC24->setGeometry(QRect(190, 30, 81, 23));
        pushButtonRC18 = new QPushButton(groupBox);
        pushButtonRC18->setObjectName(QString::fromUtf8("pushButtonRC18"));
        pushButtonRC18->setGeometry(QRect(40, 210, 91, 23));

        retranslateUi(tongqian);
        QObject::connect(pushButtonRC23, SIGNAL(pressed()), tongqian, SLOT(Relay23Pressed()));
        QObject::connect(pushButtonRC23, SIGNAL(released()), tongqian, SLOT(Relay23Released()));
        QObject::connect(pushButtonRC24, SIGNAL(pressed()), tongqian, SLOT(Relay24Pressed()));
        QObject::connect(pushButtonRC24, SIGNAL(released()), tongqian, SLOT(Relay24Released()));
        QObject::connect(pushButtonRC22, SIGNAL(pressed()), tongqian, SLOT(Relay22Pressed()));
        QObject::connect(pushButtonRC22, SIGNAL(released()), tongqian, SLOT(Relay22Released()));
        QObject::connect(pushButtonRC21, SIGNAL(pressed()), tongqian, SLOT(Relay21Pressed()));
        QObject::connect(pushButtonRC21, SIGNAL(released()), tongqian, SLOT(Relay21Released()));
        QObject::connect(pushButtonRC20, SIGNAL(pressed()), tongqian, SLOT(Relay20Pressed()));
        QObject::connect(pushButtonRC20, SIGNAL(released()), tongqian, SLOT(Relay20Released()));
        QObject::connect(pushButtonRC19, SIGNAL(pressed()), tongqian, SLOT(Relay19Pressed()));
        QObject::connect(pushButtonRC19, SIGNAL(released()), tongqian, SLOT(Relay19Released()));
        QObject::connect(pushButtonRC25, SIGNAL(pressed()), tongqian, SLOT(Relay25Pressed()));
        QObject::connect(pushButtonRC25, SIGNAL(released()), tongqian, SLOT(Relay25Released()));
        QObject::connect(pushButtonRC26, SIGNAL(pressed()), tongqian, SLOT(Relay26Pressed()));
        QObject::connect(pushButtonRC26, SIGNAL(released()), tongqian, SLOT(Relay26Released()));
        QObject::connect(pushButtonRC18, SIGNAL(pressed()), tongqian, SLOT(Relay18Pressed()));
        QObject::connect(pushButtonRC18, SIGNAL(released()), tongqian, SLOT(Relay18Released()));
        QObject::connect(pushButtonRC17, SIGNAL(pressed()), tongqian, SLOT(Relay17Pressed()));
        QObject::connect(pushButtonRC17, SIGNAL(released()), tongqian, SLOT(Relay17Released()));

        QMetaObject::connectSlotsByName(tongqian);
    } // setupUi

    void retranslateUi(QDialog *tongqian)
    {
        tongqian->setWindowTitle(QCoreApplication::translate("tongqian", "\346\215\205\351\222\216", nullptr));
        groupBox->setTitle(QCoreApplication::translate("tongqian", "\346\215\205\351\222\216\346\216\247\345\210\266", nullptr));
        pushButtonRC20->setText(QCoreApplication::translate("tongqian", "20\346\215\205\351\222\216\351\251\254\350\276\276\345\211\215\350\277\233", nullptr));
        pushButtonRC25->setText(QCoreApplication::translate("tongqian", "25\346\215\205\351\222\216\346\250\241\347\273\204\351\251\254\350\276\276\345\211\215\350\277\233", nullptr));
        pushButtonRC26->setText(QCoreApplication::translate("tongqian", "26\346\215\205\351\222\216\346\250\241\347\273\204\351\251\254\350\276\276\345\220\216\351\200\200", nullptr));
        pushButtonRC17->setText(QCoreApplication::translate("tongqian", "17\346\215\205\351\222\216\346\262\271\347\274\270\345\220\216\351\200\200", nullptr));
        pushButtonRC22->setText(QCoreApplication::translate("tongqian", "22\346\215\205\351\222\216\351\251\254\350\276\276\345\220\216\351\200\200\346\235\276\351\222\216", nullptr));
        pushButtonRC21->setText(QCoreApplication::translate("tongqian", "21\346\215\205\351\222\216\351\251\254\350\276\276\345\211\215\350\277\233\345\244\271\351\222\216", nullptr));
        pushButtonRC19->setText(QCoreApplication::translate("tongqian", "19\346\215\205\351\222\216\351\251\254\350\276\276\345\220\216\351\200\200", nullptr));
        pushButtonRC23->setText(QCoreApplication::translate("tongqian", "23\346\215\205\351\222\216\346\262\271\347\274\270\346\235\276", nullptr));
        pushButtonRC24->setText(QCoreApplication::translate("tongqian", "24\346\215\205\351\222\216\346\262\271\347\274\270\347\264\247", nullptr));
        pushButtonRC18->setText(QCoreApplication::translate("tongqian", "18\346\215\205\351\222\216\346\262\271\347\274\270\345\211\215\350\277\233", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tongqian: public Ui_tongqian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONGQIAN_H
