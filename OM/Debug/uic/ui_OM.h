/********************************************************************************
** Form generated from reading UI file 'OM.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OM_H
#define UI_OM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OMClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_10;
    QLabel *label_display1;
    QLabel *label_4;
    QLineEdit *lineEdit_HouZuoLi;
    QLabel *label_9;
    QLineEdit *lineEdit_ShuiPing;
    QPushButton *pushButton_3;
    QPushButton *pushButton_11;
    QToolBox *toolBox;
    QWidget *page_4;
    QPushButton *pushButtonRC1;
    QPushButton *pushButtonRC13;
    QPushButton *pushButtonRC13_2;
    QPushButton *pushButtonRC1_2;
    QPushButton *pushButtonRC32;
    QPushButton *pushButtonRC31;
    QPushButton *pushButtonRC26_2;
    QPushButton *pushButtonRC28;
    QPushButton *pushButtonRC3;
    QPushButton *pushButtonRC2;
    QPushButton *pushButtonRC30;
    QPushButton *pushButtonRC7;
    QPushButton *pushButtonRC29;
    QPushButton *pushButtonRC8;
    QWidget *page;
    QPushButton *pushButtonRC4_2;
    QPushButton *pushButtonRC5;
    QPushButton *pushButtonRC4;
    QPushButton *pushButtonRC6;
    QWidget *page_2;
    QPushButton *pushButtonRC19;
    QPushButton *pushButtonRC21;
    QPushButton *pushButtonRC22;
    QPushButton *pushButtonRC26;
    QPushButton *pushButtonRC25;
    QPushButton *pushButtonRC24;
    QPushButton *pushButtonRC17;
    QPushButton *pushButtonRC23;
    QPushButton *pushButtonRC18;
    QPushButton *pushButtonRC20;
    QPushButton *pushButtonRC23_2;
    QPushButton *pushButtonRC20_2;
    QPushButton *pushButtonRC20_3;
    QWidget *page_3;
    QPushButton *pushButtonRC10;
    QPushButton *pushButtonRC9;
    QPushButton *pushButtonRC12;
    QPushButton *pushButtonRC11;
    QWidget *page_5;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QPushButton *openPore;
    QPushButton *holeStart;
    QPushButton *holeStop;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *steelStop;
    QPushButton *dropSteel;
    QPushButton *steelStart;
    QPushButton *clipTight;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QPushButton *blockMud;
    QPushButton *mudStop;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *OMClass)
    {
        if (OMClass->objectName().isEmpty())
            OMClass->setObjectName(QString::fromUtf8("OMClass"));
        OMClass->resize(800, 600);
        OMClass->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(170, 255, 255);"));
        centralWidget = new QWidget(OMClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 450, 461, 141));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(480, 450, 141, 141));
        pushButton_10->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:5px groove black;\n"
"	border-radius:50px;\n"
"	padding:5px 4px;\n"
"	color:white;\n"
"	font: 57 14pt \"Adobe Myungjo Std M\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:5px groove black;\n"
"	border-radius:50px;\n"
"	padding:5px 4px;\n"
"	font: 57 14pt \"Adobe Myungjo Std M\";\n"
"}"));
        label_display1 = new QLabel(centralWidget);
        label_display1->setObjectName(QString::fromUtf8("label_display1"));
        label_display1->setGeometry(QRect(10, 10, 611, 431));
        label_display1->setStyleSheet(QString::fromUtf8("background-color:rgb(198, 180, 60);\n"
""));
        label_display1->setScaledContents(true);
        label_display1->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(630, 540, 71, 20));
        lineEdit_HouZuoLi = new QLineEdit(centralWidget);
        lineEdit_HouZuoLi->setObjectName(QString::fromUtf8("lineEdit_HouZuoLi"));
        lineEdit_HouZuoLi->setEnabled(false);
        lineEdit_HouZuoLi->setGeometry(QRect(720, 540, 71, 20));
        lineEdit_HouZuoLi->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(630, 570, 71, 20));
        lineEdit_ShuiPing = new QLineEdit(centralWidget);
        lineEdit_ShuiPing->setObjectName(QString::fromUtf8("lineEdit_ShuiPing"));
        lineEdit_ShuiPing->setEnabled(false);
        lineEdit_ShuiPing->setGeometry(QRect(720, 570, 71, 20));
        lineEdit_ShuiPing->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(630, 510, 71, 23));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(720, 510, 71, 23));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(630, 10, 161, 491));
        toolBox->setSizeIncrement(QSize(0, 0));
        toolBox->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(198, 198, 98);\n"
"border:1px groove rgb(255, 100, 100);\n"
"border-radius:5px;"));
        toolBox->setFrameShadow(QFrame::Sunken);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        page_4->setGeometry(QRect(0, 0, 157, 357));
        pushButtonRC1 = new QPushButton(page_4);
        pushButtonRC1->setObjectName(QString::fromUtf8("pushButtonRC1"));
        pushButtonRC1->setGeometry(QRect(10, 30, 65, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("SimSun-ExtB"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(7);
        pushButtonRC1->setFont(font);
        pushButtonRC1->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC13 = new QPushButton(page_4);
        pushButtonRC13->setObjectName(QString::fromUtf8("pushButtonRC13"));
        pushButtonRC13->setGeometry(QRect(80, 70, 65, 35));
        pushButtonRC13->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC13_2 = new QPushButton(page_4);
        pushButtonRC13_2->setObjectName(QString::fromUtf8("pushButtonRC13_2"));
        pushButtonRC13_2->setGeometry(QRect(80, 30, 65, 35));
        pushButtonRC13_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC1_2 = new QPushButton(page_4);
        pushButtonRC1_2->setObjectName(QString::fromUtf8("pushButtonRC1_2"));
        pushButtonRC1_2->setGeometry(QRect(10, 70, 65, 35));
        pushButtonRC1_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC32 = new QPushButton(page_4);
        pushButtonRC32->setObjectName(QString::fromUtf8("pushButtonRC32"));
        pushButtonRC32->setGeometry(QRect(10, 110, 65, 35));
        pushButtonRC32->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC31 = new QPushButton(page_4);
        pushButtonRC31->setObjectName(QString::fromUtf8("pushButtonRC31"));
        pushButtonRC31->setGeometry(QRect(80, 110, 65, 35));
        pushButtonRC31->setFont(font);
        pushButtonRC31->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC26_2 = new QPushButton(page_4);
        pushButtonRC26_2->setObjectName(QString::fromUtf8("pushButtonRC26_2"));
        pushButtonRC26_2->setGeometry(QRect(10, 190, 65, 35));
        pushButtonRC26_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC28 = new QPushButton(page_4);
        pushButtonRC28->setObjectName(QString::fromUtf8("pushButtonRC28"));
        pushButtonRC28->setGeometry(QRect(80, 190, 65, 35));
        pushButtonRC28->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC3 = new QPushButton(page_4);
        pushButtonRC3->setObjectName(QString::fromUtf8("pushButtonRC3"));
        pushButtonRC3->setGeometry(QRect(50, 150, 65, 35));
        pushButtonRC3->setFont(font);
        pushButtonRC3->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC2 = new QPushButton(page_4);
        pushButtonRC2->setObjectName(QString::fromUtf8("pushButtonRC2"));
        pushButtonRC2->setGeometry(QRect(50, 230, 65, 35));
        pushButtonRC2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC30 = new QPushButton(page_4);
        pushButtonRC30->setObjectName(QString::fromUtf8("pushButtonRC30"));
        pushButtonRC30->setGeometry(QRect(80, 310, 65, 35));
        pushButtonRC30->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC7 = new QPushButton(page_4);
        pushButtonRC7->setObjectName(QString::fromUtf8("pushButtonRC7"));
        pushButtonRC7->setGeometry(QRect(80, 270, 65, 35));
        pushButtonRC7->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC29 = new QPushButton(page_4);
        pushButtonRC29->setObjectName(QString::fromUtf8("pushButtonRC29"));
        pushButtonRC29->setGeometry(QRect(10, 310, 65, 35));
        pushButtonRC29->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	font: 57 9pt \"SimSun-ExtB\";\n"
"}"));
        pushButtonRC8 = new QPushButton(page_4);
        pushButtonRC8->setObjectName(QString::fromUtf8("pushButtonRC8"));
        pushButtonRC8->setGeometry(QRect(10, 270, 65, 35));
        pushButtonRC8->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        toolBox->addItem(page_4, QString::fromUtf8("\346\225\264\350\275\246\347\247\273\345\212\250"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 157, 357));
        pushButtonRC4_2 = new QPushButton(page);
        pushButtonRC4_2->setObjectName(QString::fromUtf8("pushButtonRC4_2"));
        pushButtonRC4_2->setGeometry(QRect(80, 30, 65, 35));
        pushButtonRC4_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC5 = new QPushButton(page);
        pushButtonRC5->setObjectName(QString::fromUtf8("pushButtonRC5"));
        pushButtonRC5->setGeometry(QRect(10, 80, 65, 35));
        pushButtonRC5->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC4 = new QPushButton(page);
        pushButtonRC4->setObjectName(QString::fromUtf8("pushButtonRC4"));
        pushButtonRC4->setGeometry(QRect(10, 30, 65, 35));
        pushButtonRC4->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC6 = new QPushButton(page);
        pushButtonRC6->setObjectName(QString::fromUtf8("pushButtonRC6"));
        pushButtonRC6->setGeometry(QRect(80, 80, 65, 35));
        pushButtonRC6->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        toolBox->addItem(page, QString::fromUtf8("\345\274\200\345\255\224"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 157, 357));
        pushButtonRC19 = new QPushButton(page_2);
        pushButtonRC19->setObjectName(QString::fromUtf8("pushButtonRC19"));
        pushButtonRC19->setGeometry(QRect(10, 60, 65, 35));
        pushButtonRC19->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC21 = new QPushButton(page_2);
        pushButtonRC21->setObjectName(QString::fromUtf8("pushButtonRC21"));
        pushButtonRC21->setGeometry(QRect(80, 60, 65, 35));
        pushButtonRC21->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC22 = new QPushButton(page_2);
        pushButtonRC22->setObjectName(QString::fromUtf8("pushButtonRC22"));
        pushButtonRC22->setGeometry(QRect(80, 20, 65, 35));
        pushButtonRC22->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC26 = new QPushButton(page_2);
        pushButtonRC26->setObjectName(QString::fromUtf8("pushButtonRC26"));
        pushButtonRC26->setGeometry(QRect(80, 140, 65, 35));
        pushButtonRC26->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC25 = new QPushButton(page_2);
        pushButtonRC25->setObjectName(QString::fromUtf8("pushButtonRC25"));
        pushButtonRC25->setGeometry(QRect(80, 100, 65, 35));
        pushButtonRC25->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC24 = new QPushButton(page_2);
        pushButtonRC24->setObjectName(QString::fromUtf8("pushButtonRC24"));
        pushButtonRC24->setGeometry(QRect(10, 180, 65, 35));
        pushButtonRC24->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC17 = new QPushButton(page_2);
        pushButtonRC17->setObjectName(QString::fromUtf8("pushButtonRC17"));
        pushButtonRC17->setGeometry(QRect(10, 140, 65, 35));
        pushButtonRC17->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC23 = new QPushButton(page_2);
        pushButtonRC23->setObjectName(QString::fromUtf8("pushButtonRC23"));
        pushButtonRC23->setGeometry(QRect(80, 180, 65, 35));
        pushButtonRC23->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC18 = new QPushButton(page_2);
        pushButtonRC18->setObjectName(QString::fromUtf8("pushButtonRC18"));
        pushButtonRC18->setGeometry(QRect(10, 100, 65, 35));
        pushButtonRC18->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC20 = new QPushButton(page_2);
        pushButtonRC20->setObjectName(QString::fromUtf8("pushButtonRC20"));
        pushButtonRC20->setGeometry(QRect(10, 20, 65, 35));
        pushButtonRC20->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC23_2 = new QPushButton(page_2);
        pushButtonRC23_2->setObjectName(QString::fromUtf8("pushButtonRC23_2"));
        pushButtonRC23_2->setGeometry(QRect(50, 220, 65, 35));
        pushButtonRC23_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC20_2 = new QPushButton(page_2);
        pushButtonRC20_2->setObjectName(QString::fromUtf8("pushButtonRC20_2"));
        pushButtonRC20_2->setGeometry(QRect(10, 320, 65, 35));
        pushButtonRC20_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC20_3 = new QPushButton(page_2);
        pushButtonRC20_3->setObjectName(QString::fromUtf8("pushButtonRC20_3"));
        pushButtonRC20_3->setGeometry(QRect(80, 320, 65, 35));
        pushButtonRC20_3->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        toolBox->addItem(page_2, QString::fromUtf8("\346\215\205\351\222\216/\351\200\232\346\260\247"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 157, 357));
        pushButtonRC10 = new QPushButton(page_3);
        pushButtonRC10->setObjectName(QString::fromUtf8("pushButtonRC10"));
        pushButtonRC10->setGeometry(QRect(80, 20, 65, 35));
        pushButtonRC10->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC9 = new QPushButton(page_3);
        pushButtonRC9->setObjectName(QString::fromUtf8("pushButtonRC9"));
        pushButtonRC9->setGeometry(QRect(10, 20, 65, 35));
        pushButtonRC9->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC12 = new QPushButton(page_3);
        pushButtonRC12->setObjectName(QString::fromUtf8("pushButtonRC12"));
        pushButtonRC12->setGeometry(QRect(80, 70, 65, 35));
        pushButtonRC12->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        pushButtonRC11 = new QPushButton(page_3);
        pushButtonRC11->setObjectName(QString::fromUtf8("pushButtonRC11"));
        pushButtonRC11->setGeometry(QRect(10, 70, 65, 35));
        pushButtonRC11->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        toolBox->addItem(page_3, QString::fromUtf8("\345\240\265\346\263\245"));
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 157, 357));
        verticalLayout = new QVBoxLayout(page_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(page_5);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        openPore = new QPushButton(groupBox);
        openPore->setObjectName(QString::fromUtf8("openPore"));
        openPore->setGeometry(QRect(10, 20, 51, 21));
        openPore->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        holeStart = new QPushButton(groupBox);
        holeStart->setObjectName(QString::fromUtf8("holeStart"));
        holeStart->setGeometry(QRect(70, 20, 51, 23));
        holeStart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        holeStop = new QPushButton(groupBox);
        holeStop->setObjectName(QString::fromUtf8("holeStop"));
        holeStop->setGeometry(QRect(10, 70, 101, 23));
        holeStop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));

        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(page_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 20, 131, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        steelStop = new QPushButton(widget);
        steelStop->setObjectName(QString::fromUtf8("steelStop"));
        steelStop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));

        gridLayout->addWidget(steelStop, 1, 1, 1, 1);

        dropSteel = new QPushButton(widget);
        dropSteel->setObjectName(QString::fromUtf8("dropSteel"));
        dropSteel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));

        gridLayout->addWidget(dropSteel, 0, 0, 1, 1);

        steelStart = new QPushButton(widget);
        steelStart->setObjectName(QString::fromUtf8("steelStart"));
        steelStart->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));

        gridLayout->addWidget(steelStart, 1, 0, 1, 1);

        clipTight = new QPushButton(widget);
        clipTight->setObjectName(QString::fromUtf8("clipTight"));
        clipTight->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));

        gridLayout->addWidget(clipTight, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        groupBox_3 = new QGroupBox(page_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(52, 52, 52);\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"	color:white;\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:gray;\n"
"	border:3px groove black;\n"
"	border-radius:5px;\n"
"}"));
        blockMud = new QPushButton(groupBox_3);
        blockMud->setObjectName(QString::fromUtf8("blockMud"));
        blockMud->setGeometry(QRect(20, 20, 101, 23));
        mudStop = new QPushButton(groupBox_3);
        mudStop->setObjectName(QString::fromUtf8("mudStop"));
        mudStop->setGeometry(QRect(20, 60, 101, 23));

        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        toolBox->addItem(page_5, QString::fromUtf8("\350\207\252\345\212\250\346\223\215\344\275\234"));
        OMClass->setCentralWidget(centralWidget);

        retranslateUi(OMClass);
        QObject::connect(pushButton_3, SIGNAL(clicked()), OMClass, SLOT(OnOpencvStart()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), OMClass, SLOT(OnOpencvEnd()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), OMClass, SLOT(showmyRC()));
        QObject::connect(pushButtonRC1, SIGNAL(clicked()), OMClass, SLOT(Relay1Pressed()));
        QObject::connect(pushButtonRC1_2, SIGNAL(clicked()), OMClass, SLOT(Relay1Released()));
        QObject::connect(pushButtonRC13, SIGNAL(clicked()), OMClass, SLOT(Relay13Released()));
        QObject::connect(pushButtonRC13_2, SIGNAL(clicked()), OMClass, SLOT(Relay13Pressed()));
        QObject::connect(pushButtonRC32, SIGNAL(pressed()), OMClass, SLOT(Relay32Pressed()));
        QObject::connect(pushButtonRC32, SIGNAL(released()), OMClass, SLOT(Relay32Released()));
        QObject::connect(pushButtonRC31, SIGNAL(pressed()), OMClass, SLOT(Relay31Pressed()));
        QObject::connect(pushButtonRC31, SIGNAL(released()), OMClass, SLOT(Relay31Released()));
        QObject::connect(pushButtonRC3, SIGNAL(pressed()), OMClass, SLOT(Relay3Pressed()));
        QObject::connect(pushButtonRC3, SIGNAL(released()), OMClass, SLOT(Relay3Released()));
        QObject::connect(pushButtonRC26_2, SIGNAL(pressed()), OMClass, SLOT(Relay27Pressed()));
        QObject::connect(pushButtonRC26_2, SIGNAL(released()), OMClass, SLOT(Relay27Released()));
        QObject::connect(pushButtonRC28, SIGNAL(pressed()), OMClass, SLOT(Relay28Pressed()));
        QObject::connect(pushButtonRC28, SIGNAL(released()), OMClass, SLOT(Relay28Released()));
        QObject::connect(pushButtonRC2, SIGNAL(pressed()), OMClass, SLOT(Relay2Pressed()));
        QObject::connect(pushButtonRC2, SIGNAL(released()), OMClass, SLOT(Relay2Released()));
        QObject::connect(pushButtonRC8, SIGNAL(pressed()), OMClass, SLOT(Relay8Pressed()));
        QObject::connect(pushButtonRC8, SIGNAL(released()), OMClass, SLOT(Relay8Released()));
        QObject::connect(pushButtonRC7, SIGNAL(pressed()), OMClass, SLOT(Relay7Pressed()));
        QObject::connect(pushButtonRC7, SIGNAL(released()), OMClass, SLOT(Relay7Released()));
        QObject::connect(pushButtonRC29, SIGNAL(pressed()), OMClass, SLOT(Relay29Pressed()));
        QObject::connect(pushButtonRC29, SIGNAL(released()), OMClass, SLOT(Relay29Released()));
        QObject::connect(pushButtonRC30, SIGNAL(pressed()), OMClass, SLOT(Relay30Pressed()));
        QObject::connect(pushButtonRC30, SIGNAL(released()), OMClass, SLOT(Relay30Released()));
        QObject::connect(pushButtonRC4, SIGNAL(clicked()), OMClass, SLOT(Relay4Pressed()));
        QObject::connect(pushButtonRC4_2, SIGNAL(clicked()), OMClass, SLOT(Relay4Released()));
        QObject::connect(pushButtonRC6, SIGNAL(pressed()), OMClass, SLOT(Relay6Pressed()));
        QObject::connect(pushButtonRC6, SIGNAL(released()), OMClass, SLOT(Relay6Released()));
        QObject::connect(pushButtonRC5, SIGNAL(pressed()), OMClass, SLOT(Relay5Pressed()));
        QObject::connect(pushButtonRC5, SIGNAL(released()), OMClass, SLOT(Relay5Released()));
        QObject::connect(pushButtonRC19, SIGNAL(pressed()), OMClass, SLOT(Relay19Pressed()));
        QObject::connect(pushButtonRC19, SIGNAL(released()), OMClass, SLOT(Relay19Released()));
        QObject::connect(pushButtonRC20, SIGNAL(pressed()), OMClass, SLOT(Relay20Pressed()));
        QObject::connect(pushButtonRC20, SIGNAL(released()), OMClass, SLOT(Relay20Released()));
        QObject::connect(pushButtonRC21, SIGNAL(pressed()), OMClass, SLOT(Relay21Pressed()));
        QObject::connect(pushButtonRC22, SIGNAL(pressed()), OMClass, SLOT(Relay22Pressed()));
        QObject::connect(pushButtonRC21, SIGNAL(released()), OMClass, SLOT(Relay21Released()));
        QObject::connect(pushButtonRC22, SIGNAL(released()), OMClass, SLOT(Relay22Released()));
        QObject::connect(pushButtonRC17, SIGNAL(pressed()), OMClass, SLOT(Relay17Pressed()));
        QObject::connect(pushButtonRC17, SIGNAL(released()), OMClass, SLOT(Relay17Released()));
        QObject::connect(pushButtonRC18, SIGNAL(pressed()), OMClass, SLOT(Relay18Pressed()));
        QObject::connect(pushButtonRC18, SIGNAL(released()), OMClass, SLOT(Relay18Released()));
        QObject::connect(pushButtonRC25, SIGNAL(pressed()), OMClass, SLOT(Relay25Pressed()));
        QObject::connect(pushButtonRC25, SIGNAL(released()), OMClass, SLOT(Relay25Released()));
        QObject::connect(pushButtonRC26, SIGNAL(pressed()), OMClass, SLOT(Relay26Pressed()));
        QObject::connect(pushButtonRC26, SIGNAL(released()), OMClass, SLOT(Relay26Released()));
        QObject::connect(pushButtonRC23, SIGNAL(pressed()), OMClass, SLOT(Relay23Pressed()));
        QObject::connect(pushButtonRC23, SIGNAL(released()), OMClass, SLOT(Relay23Released()));
        QObject::connect(pushButtonRC24, SIGNAL(pressed()), OMClass, SLOT(Relay24Pressed()));
        QObject::connect(pushButtonRC24, SIGNAL(released()), OMClass, SLOT(Relay24Released()));
        QObject::connect(pushButtonRC23_2, SIGNAL(pressed()), OMClass, SLOT(Relay14Pressed()));
        QObject::connect(pushButtonRC23_2, SIGNAL(released()), OMClass, SLOT(Relay14Released()));
        QObject::connect(pushButtonRC9, SIGNAL(pressed()), OMClass, SLOT(Relay9Pressed()));
        QObject::connect(pushButtonRC9, SIGNAL(released()), OMClass, SLOT(Relay9Released()));
        QObject::connect(pushButtonRC10, SIGNAL(pressed()), OMClass, SLOT(Relay10Pressed()));
        QObject::connect(pushButtonRC10, SIGNAL(released()), OMClass, SLOT(Relay10Released()));
        QObject::connect(pushButtonRC11, SIGNAL(pressed()), OMClass, SLOT(Relay11Pressed()));
        QObject::connect(pushButtonRC11, SIGNAL(released()), OMClass, SLOT(Relay11Released()));
        QObject::connect(pushButtonRC12, SIGNAL(pressed()), OMClass, SLOT(Relay12Pressed()));
        QObject::connect(pushButtonRC12, SIGNAL(released()), OMClass, SLOT(Relay12Released()));
        QObject::connect(toolBox, SIGNAL(currentChanged(int)), OMClass, SLOT(getChanged(int)));
        QObject::connect(pushButtonRC20_2, SIGNAL(clicked()), OMClass, SLOT(WFStart()));
        QObject::connect(pushButtonRC20_3, SIGNAL(clicked()), OMClass, SLOT(WFStop()));
        QObject::connect(openPore, SIGNAL(clicked()), OMClass, SLOT(OpenPore()));
        QObject::connect(holeStart, SIGNAL(clicked()), OMClass, SLOT(StartHole()));
        QObject::connect(holeStop, SIGNAL(clicked()), OMClass, SLOT(StopHole()));
        QObject::connect(dropSteel, SIGNAL(clicked()), OMClass, SLOT(DropSteel()));
        QObject::connect(clipTight, SIGNAL(clicked()), OMClass, SLOT(ClipSteel()));
        QObject::connect(steelStart, SIGNAL(clicked()), OMClass, SLOT(StartSteel()));
        QObject::connect(steelStop, SIGNAL(clicked()), OMClass, SLOT(StopSteel()));
        QObject::connect(blockMud, SIGNAL(clicked()), OMClass, SLOT(BlockMud()));
        QObject::connect(mudStop, SIGNAL(clicked()), OMClass, SLOT(StopMud()));

        toolBox->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(OMClass);
    } // setupUi

    void retranslateUi(QMainWindow *OMClass)
    {
        OMClass->setWindowTitle(QCoreApplication::translate("OMClass", "\350\207\252\345\212\250\345\274\200\347\202\211\346\234\2722020.03.30", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("OMClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_10->setText(QCoreApplication::translate("OMClass", "\346\211\213\345\212\250\346\223\215\344\275\234", nullptr));
        label_display1->setText(QCoreApplication::translate("OMClass", "\346\234\252\345\212\240\350\275\275\345\233\276\345\203\217", nullptr));
        label_4->setText(QCoreApplication::translate("OMClass", "\346\263\245\347\202\256\345\220\216\345\235\220\345\212\233\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("OMClass", "\346\260\264\345\271\263\344\275\215\347\275\256\357\274\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("OMClass", "\346\230\276\347\244\272\345\233\276\345\203\2171", nullptr));
        pushButton_11->setText(QCoreApplication::translate("OMClass", "\346\230\276\347\244\272\345\233\276\345\203\2172", nullptr));
        pushButtonRC1->setText(QCoreApplication::translate("OMClass", "\345\244\247\347\224\265\346\234\272\345\274\200", nullptr));
        pushButtonRC13->setText(QCoreApplication::translate("OMClass", "\350\247\243\351\231\244\344\277\235\345\216\213", nullptr));
        pushButtonRC13_2->setText(QCoreApplication::translate("OMClass", "\344\277\235\345\216\213", nullptr));
        pushButtonRC1_2->setText(QCoreApplication::translate("OMClass", "\345\244\247\347\224\265\346\234\272\345\205\263", nullptr));
        pushButtonRC32->setText(QCoreApplication::translate("OMClass", "\345\244\271\347\210\252\346\235\276", nullptr));
        pushButtonRC31->setText(QCoreApplication::translate("OMClass", "\345\244\271\347\210\252\347\264\247", nullptr));
        pushButtonRC26_2->setText(QCoreApplication::translate("OMClass", "\346\260\264\345\271\263\345\267\246\347\247\273", nullptr));
        pushButtonRC28->setText(QCoreApplication::translate("OMClass", "\346\260\264\345\271\263\345\217\263\347\247\273", nullptr));
        pushButtonRC3->setText(QCoreApplication::translate("OMClass", "\346\225\264\350\275\246\345\211\215\350\277\233", nullptr));
        pushButtonRC2->setText(QCoreApplication::translate("OMClass", "\346\225\264\350\275\246\345\220\216\351\200\200", nullptr));
        pushButtonRC30->setText(QCoreApplication::translate("OMClass", "\345\215\241\346\255\273\346\250\241\347\273\204", nullptr));
        pushButtonRC7->setText(QCoreApplication::translate("OMClass", "\346\263\245\345\262\251\351\251\254\350\276\276\n"
"\345\220\216\351\200\200", nullptr));
        pushButtonRC29->setText(QCoreApplication::translate("OMClass", "\346\235\276\345\274\200\346\250\241\347\273\204", nullptr));
        pushButtonRC8->setText(QCoreApplication::translate("OMClass", "\346\263\245\345\262\251\351\251\254\350\276\276\n"
"\345\211\215\350\277\233", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_4), QCoreApplication::translate("OMClass", "\346\225\264\350\275\246\347\247\273\345\212\250", nullptr));
        pushButtonRC4_2->setText(QCoreApplication::translate("OMClass", "\345\201\234\346\255\242\346\227\213\350\275\254", nullptr));
        pushButtonRC5->setText(QCoreApplication::translate("OMClass", "\345\207\277\345\262\251\345\211\215\350\277\233", nullptr));
        pushButtonRC4->setText(QCoreApplication::translate("OMClass", "\345\207\277\345\262\251\346\227\213\350\275\254", nullptr));
        pushButtonRC6->setText(QCoreApplication::translate("OMClass", "\345\207\277\345\262\251\345\220\216\351\200\200", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("OMClass", "\345\274\200\345\255\224", nullptr));
        pushButtonRC19->setText(QCoreApplication::translate("OMClass", "\351\251\254\350\276\276\346\224\266\351\222\216", nullptr));
        pushButtonRC21->setText(QCoreApplication::translate("OMClass", "\351\251\254\350\276\276\346\235\276\351\222\216", nullptr));
        pushButtonRC22->setText(QCoreApplication::translate("OMClass", "\351\251\254\350\276\276\345\244\271\351\222\216", nullptr));
        pushButtonRC26->setText(QCoreApplication::translate("OMClass", "\346\250\241\347\273\204\345\220\216\351\200\200", nullptr));
        pushButtonRC25->setText(QCoreApplication::translate("OMClass", "\346\250\241\347\273\204\345\211\215\350\277\233", nullptr));
        pushButtonRC24->setText(QCoreApplication::translate("OMClass", "\346\262\271\347\274\270\347\264\247", nullptr));
        pushButtonRC17->setText(QCoreApplication::translate("OMClass", "\346\262\271\347\274\270\345\220\216\351\200\200", nullptr));
        pushButtonRC23->setText(QCoreApplication::translate("OMClass", "\346\262\271\347\274\270\346\235\276", nullptr));
        pushButtonRC18->setText(QCoreApplication::translate("OMClass", "\346\262\271\347\274\270\345\211\215\350\277\233", nullptr));
        pushButtonRC20->setText(QCoreApplication::translate("OMClass", "\351\251\254\350\276\276\346\215\205\351\222\216", nullptr));
        pushButtonRC23_2->setText(QCoreApplication::translate("OMClass", "\346\216\211\351\222\216", nullptr));
        pushButtonRC20_2->setText(QCoreApplication::translate("OMClass", "\346\262\271\347\274\270\345\276\200\345\244\215", nullptr));
        pushButtonRC20_3->setText(QCoreApplication::translate("OMClass", "\345\201\234\346\255\242\345\276\200\345\244\215", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("OMClass", "\346\215\205\351\222\216/\351\200\232\346\260\247", nullptr));
        pushButtonRC10->setText(QCoreApplication::translate("OMClass", "\346\263\245\347\202\256\345\220\216\351\200\200", nullptr));
        pushButtonRC9->setText(QCoreApplication::translate("OMClass", "\346\263\245\347\202\256\345\211\215\350\277\233", nullptr));
        pushButtonRC12->setText(QCoreApplication::translate("OMClass", "\345\241\253\346\263\245", nullptr));
        pushButtonRC11->setText(QCoreApplication::translate("OMClass", "\346\214\244\346\263\245", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("OMClass", "\345\240\265\346\263\245", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OMClass", "\345\274\200\345\255\224", nullptr));
        openPore->setText(QCoreApplication::translate("OMClass", "\345\274\200\345\255\224", nullptr));
        holeStart->setText(QCoreApplication::translate("OMClass", "\345\220\257\345\212\250", nullptr));
        holeStop->setText(QCoreApplication::translate("OMClass", "\345\201\234\346\255\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OMClass", "\346\215\205\351\222\216", nullptr));
        steelStop->setText(QCoreApplication::translate("OMClass", "\345\201\234\346\255\242", nullptr));
        dropSteel->setText(QCoreApplication::translate("OMClass", "\350\220\275\351\222\216", nullptr));
        steelStart->setText(QCoreApplication::translate("OMClass", "\345\220\257\345\212\250", nullptr));
        clipTight->setText(QCoreApplication::translate("OMClass", "\345\244\271\347\264\247", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("OMClass", "\345\240\265\346\263\245", nullptr));
        blockMud->setText(QCoreApplication::translate("OMClass", "\345\240\265\346\263\245", nullptr));
        mudStop->setText(QCoreApplication::translate("OMClass", "\345\201\234\346\255\242", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QCoreApplication::translate("OMClass", "\350\207\252\345\212\250\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OMClass: public Ui_OMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OM_H
