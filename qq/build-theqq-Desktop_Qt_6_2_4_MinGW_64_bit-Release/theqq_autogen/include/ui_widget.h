/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *btnLogin;
    QLineEdit *password;
    QComboBox *comboBox;
    QLineEdit *account;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_3;
    QLabel *labtop;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnMin;
    QPushButton *btnClose;
    QLabel *lab;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->setEnabled(true);
        Widget->resize(430, 330);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(430, 330));
        Widget->setMaximumSize(QSize(430, 330));
        Widget->setStyleSheet(QString::fromUtf8("QLabel{\n"
"background-color:rgb(0, 170, 255)\n"
"}\n"
".QWidget{\n"
"background-color:rgb(255,255,255)\n"
"}\n"
"\n"
"QPushButton#btnMin{\n"
"image:url(:/images/min.jpg);\n"
"}\n"
"QPushButton#btnClose{\n"
"image:url(:/images/close.jpg);\n"
"}\n"
"QPushButton#btnClose:hover{\n"
"background-color:red\n"
"}\n"
"QPushButton#btnLogin\n"
"{\n"
"background-color:rgb(11, 194, 255);\n"
"border-radius:5px;\n"
"font:normal 18px \"\346\245\267\344\275\223\";\n"
"color:white;\n"
"}\n"
"QComboBox,QLineEdit{\n"
"border:none;\n"
"border-bottom:1px solid rgb(229,229,229);\n"
"}\n"
"QComboBox:hover,QLineEdit:hover{\n"
"border-bottom:1px solid rgb(193,193,193);\n"
"}\n"
"QComboBox:focus,QLineEdit:focus{\n"
"border-bottom:1px solid rgb(18,183,245);\n"
"}\n"
"QComboBox::drop-down:hover{\n"
"image:url(:/images/4.png);\n"
"}\n"
"QComboBox::drop-drow:checked{\n"
"image:url(:/images/3.png);\n"
"}\n"
"\n"
"\n"
"\n"
""));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 130, 430, 200));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 170, 80, 24));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 160, 32, 32));
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        btnLogin = new QPushButton(widget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(100, 130, 240, 30));
        btnLogin->setMinimumSize(QSize(240, 30));
        btnLogin->setMaximumSize(QSize(240, 30));
        password = new QLineEdit(widget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(100, 60, 240, 30));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 30, 251, 30));
        account = new QLineEdit(widget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(100, 40, 231, 23));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 100, 256, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(layoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout->addWidget(checkBox_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        layoutWidget1->raise();
        pushButton->raise();
        pushButton_2->raise();
        password->raise();
        comboBox->raise();
        account->raise();
        btnLogin->raise();
        labtop = new QLabel(Widget);
        labtop->setObjectName(QString::fromUtf8("labtop"));
        labtop->setGeometry(QRect(0, 0, 430, 130));
        labtop->setMinimumSize(QSize(0, 130));
        labtop->setMaximumSize(QSize(16777215, 130));
        labtop->setPixmap(QPixmap(QString::fromUtf8(":/images/blue70-2.gif")));
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(360, 0, 72, 34));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMin = new QPushButton(layoutWidget1);
        btnMin->setObjectName(QString::fromUtf8("btnMin"));
        btnMin->setMinimumSize(QSize(32, 32));
        btnMin->setMaximumSize(QSize(32, 32));

        horizontalLayout_2->addWidget(btnMin);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setMinimumSize(QSize(32, 32));
        btnClose->setMaximumSize(QSize(32, 32));

        horizontalLayout_2->addWidget(btnClose);

        btnClose->raise();
        btnMin->raise();
        lab = new QLabel(Widget);
        lab->setObjectName(QString::fromUtf8("lab"));
        lab->setGeometry(QRect(180, 90, 71, 71));
        lab->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-image:url(\":/images/touxiang02.jpg\");\n"
"border-radius:34px;\n"
"}"));
        widget->raise();
        layoutWidget1->raise();
        labtop->raise();
        lab->raise();

        retranslateUi(Widget);
        QObject::connect(btnMin, &QPushButton::clicked, Widget, qOverload<>(&QWidget::showMinimized));
        QObject::connect(btnClose, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        btnLogin->setText(QCoreApplication::translate("Widget", "\345\256\211\345\205\250\347\231\273\345\275\225", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("Widget", "\345\257\206\347\240\201", nullptr));
        account->setPlaceholderText(QCoreApplication::translate("Widget", "QQ\345\217\267\347\240\201", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "CheckBox", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        labtop->setText(QString());
        btnMin->setText(QString());
        btnClose->setText(QString());
        lab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
