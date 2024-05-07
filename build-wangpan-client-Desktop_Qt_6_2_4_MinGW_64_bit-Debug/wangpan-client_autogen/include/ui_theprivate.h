/********************************************************************************
** Form generated from reading UI file 'theprivate.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEPRIVATE_H
#define UI_THEPRIVATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_thePrivate
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *sendMsg_pb;

    void setupUi(QWidget *thePrivate)
    {
        if (thePrivate->objectName().isEmpty())
            thePrivate->setObjectName(QString::fromUtf8("thePrivate"));
        thePrivate->resize(370, 282);
        verticalLayout_2 = new QVBoxLayout(thePrivate);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(thePrivate);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(thePrivate);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        sendMsg_pb = new QPushButton(thePrivate);
        sendMsg_pb->setObjectName(QString::fromUtf8("sendMsg_pb"));

        horizontalLayout->addWidget(sendMsg_pb);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(thePrivate);

        QMetaObject::connectSlotsByName(thePrivate);
    } // setupUi

    void retranslateUi(QWidget *thePrivate)
    {
        thePrivate->setWindowTitle(QCoreApplication::translate("thePrivate", "Form", nullptr));
        sendMsg_pb->setText(QCoreApplication::translate("thePrivate", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thePrivate: public Ui_thePrivate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEPRIVATE_H
