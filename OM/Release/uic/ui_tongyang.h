/********************************************************************************
** Form generated from reading UI file 'tongyang.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TONGYANG_H
#define UI_TONGYANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_tongyang
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *okButton;

    void setupUi(QDialog *tongyang)
    {
        if (tongyang->objectName().isEmpty())
            tongyang->setObjectName(QString::fromUtf8("tongyang"));
        tongyang->resize(342, 300);
        groupBox = new QGroupBox(tongyang);
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
        okButton = new QPushButton(tongyang);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(10, 240, 321, 51));

        retranslateUi(tongyang);
        QObject::connect(okButton, SIGNAL(clicked()), tongyang, SLOT(okbutton()));

        QMetaObject::connectSlotsByName(tongyang);
    } // setupUi

    void retranslateUi(QDialog *tongyang)
    {
        tongyang->setWindowTitle(QCoreApplication::translate("tongyang", "\351\200\232\346\260\247", nullptr));
        groupBox->setTitle(QCoreApplication::translate("tongyang", "\351\200\232\346\260\247\344\275\215\347\275\256\345\276\256\350\260\203", nullptr));
        pushButton->setText(QCoreApplication::translate("tongyang", "\345\211\215\350\277\233", nullptr));
        pushButton_2->setText(QCoreApplication::translate("tongyang", "\345\220\216\351\200\200", nullptr));
        pushButton_3->setText(QCoreApplication::translate("tongyang", "\345\267\246\347\247\273", nullptr));
        pushButton_4->setText(QCoreApplication::translate("tongyang", "\345\217\263\347\247\273", nullptr));
        okButton->setText(QCoreApplication::translate("tongyang", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tongyang: public Ui_tongyang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TONGYANG_H
