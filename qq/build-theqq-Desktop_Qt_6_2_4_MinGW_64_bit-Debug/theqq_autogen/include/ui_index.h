/********************************************************************************
** Form generated from reading UI file 'index.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEX_H
#define UI_INDEX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_index
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *username;
    QLineEdit *sign;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_4;
    QListWidget *listWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget_2;
    QWidget *tab_5;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QToolButton *toolButton_2;
    QWidget *tab_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *index)
    {
        if (index->objectName().isEmpty())
            index->setObjectName(QString::fromUtf8("index"));
        index->resize(311, 633);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(index->sizePolicy().hasHeightForWidth());
        index->setSizePolicy(sizePolicy);
        index->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{border:one;\n"
"}\n"
"QWidget{\n"
"border:\"rgb(122,197,196)\";\n"
"}"));
        widget = new QWidget(index);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 311, 111));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(311, 111));
        widget->setMaximumSize(QSize(311, 111));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color:rgb(122,196,197);\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 41, 61, 61));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(61);
        sizePolicy1.setVerticalStretch(61);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(61, 61));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-radius:14px;\n"
"border-width:0px;\n"
"border-style:solid;\n"
"}"));
        label->setScaledContents(true);
        username = new QLabel(widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(77, 42, 109, 30));
        username->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:23px;\n"
"}\n"
""));
        sign = new QLineEdit(widget);
        sign->setObjectName(QString::fromUtf8("sign"));
        sign->setGeometry(QRect(77, 78, 106, 17));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, -5, 311, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(31, 16));
        label_2->setMaximumSize(QSize(31, 16));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border-image:url(\":/images/myappico.ico\")\n"
"}"));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(21, 21));
        pushButton->setMaximumSize(QSize(21, 21));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(21, 21));
        pushButton_2->setMaximumSize(QSize(21, 21));

        horizontalLayout->addWidget(pushButton_2);

        tabWidget = new QTabWidget(index);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 140, 318, 441));
        tabWidget->setMinimumSize(QSize(318, 384));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(11);
        font.setBold(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QWidget::tab{\n"
"background-color: rgba(203, 203, 203,250);\n"
"border-style:solid;\n"
"border-bottom-width:2px;\n"
"border-radius:0px;\n"
"height:32px;\n"
"width:106px;\n"
"color: rgb(100, 100, 100);\n"
"border-color: rgb(255, 255, 255);\n"
"border-bottom-color:rgba(163, 163, 163,250);\n"
"}\n"
"QWidget::tab:selected{\n"
"border-bottom-color: rgb(80, 80, 80);\n"
"border-bottom-width:2px;\n"
"border-radius-:2px;\n"
"}\n"
"QWidget::pane{\n"
"border-style:solid;\n"
"background-color: rgba(203, 203, 203,250);\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(10);
        tab->setFont(font1);
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QScrollArea(tab);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setStyleStrategy(QFont::PreferAntialias);
        scrollArea_3->setFont(font2);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 318, 407));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(scrollAreaWidgetContents_3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setFont(font2);
        listWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(listWidget, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_3->addWidget(scrollArea_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 4, 0, 0);
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font3.setPointSize(9);
        font3.setStyleStrategy(QFont::PreferAntialias);
        tabWidget_2->setFont(font3);
        tabWidget_2->setStyleSheet(QString::fromUtf8("::tab{\n"
"background-color: rgba(203, 203, 203,200);\n"
"border-style:solid;\n"
"border-width:0px;\n"
"border-radius:2px;\n"
"height:25px;\n"
"width:50px;\n"
"color: rgb(100, 100, 100);\n"
"border-color: rgb(255, 255, 255);\n"
"}\n"
"::tab:selected{\n"
"border-radius:2px;\n"
"}\n"
":pane{\n"
"}"));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFont(font2);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{\n"
"background-color:rgba(0,0,0,0);\n"
"border-color:rgba(0,0,6,0);\n"
"border-style:solid;\n"
"border-width:0px;\n"
"width:10px;\n"
"padding-top:0px;\n"
"padding-bottom:0px;\n"
"}\n"
"\n"
"\n"
"QScrollBar::handle:vertical{\n"
"border-style:solid;\n"
"border-width:2px;\n"
"border-radius:4px;\n"
"background-color:rgba(145,145,145,255);\n"
"border-color:rgba(0,0,0,0);\n"
"min-height:44px;}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,0);}\n"
"\n"
"\n"
"QScrollBar::sub-page:vertical,QScrollBar::sub-page:vertical{background:rgba(0,0,0,0);}"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 100, 30));
        scrollAreaWidgetContents->setCursor(QCursor(Qt::ArrowCursor));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("#scrollAreaWidgetContents{\n"
"background-color: rgb(203, 203, 203);\n"
"}"));
        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(9, 9, 299, 361));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        scrollArea_4 = new QScrollArea(tab_5);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setGeometry(QRect(9, 9, 291, 371));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 291, 371));
        toolButton_2 = new QToolButton(scrollAreaWidgetContents_4);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 0, 291, 81));
        toolButton_2->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	background-color:rgb(126,197,197);\n"
"}"));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);
        tabWidget_2->addTab(tab_5, QString());

        gridLayout_2->addWidget(tabWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        scrollArea_2 = new QScrollArea(tab_3);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 318, 415));
        scrollArea_2->setFont(font2);
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 318, 415));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_2 = new QListWidget(scrollAreaWidgetContents_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setFont(font2);
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget::Item{\n"
"background-color: rgb(173, 173, 173);\n"
"}\n"
"\n"
"QListWidget::Item:hover{\n"
"background-color: rgba(203, 203, 203, 100);\n"
"}"));

        verticalLayout->addWidget(listWidget_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab_3, QString());
        layoutWidget1 = new QWidget(index);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 110, 321, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(layoutWidget1);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(21, 31));
        toolButton->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color:rgb(113,183,193);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(21, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color:rgb(113,183,193);\n"
"}"));

        horizontalLayout_2->addWidget(lineEdit);

        widget_5 = new QWidget(index);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 580, 311, 51));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgba(203, 203, 203,200);\n"
"border-top-width:1px;\n"
"border-top-color:rgba(163, 163, 163,250);\n"
"border-style:solid;"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 9, -1, 9);
        horizontalSpacer_5 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        toolButton_4 = new QToolButton(widget_5);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(30, 30));
        toolButton_4->setMaximumSize(QSize(30, 30));
        toolButton_4->setFont(font2);
        toolButton_4->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-style:solid;\n"
"border-color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/sangangy.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon1);
        toolButton_4->setIconSize(QSize(25, 25));
        toolButton_4->setAutoRaise(false);

        horizontalLayout_3->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(widget_5);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(30, 30));
        toolButton_3->setMaximumSize(QSize(30, 30));
        toolButton_3->setFont(font2);
        toolButton_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-style:solid;\n"
"border-color: rgba(255, 255, 255, 0);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/tianjiahaoyou.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(25, 25));
        toolButton_3->setAutoRaise(false);

        horizontalLayout_3->addWidget(toolButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        retranslateUi(index);
        QObject::connect(pushButton_2, &QPushButton::clicked, index, qOverload<>(&QWidget::close));
        QObject::connect(pushButton, &QPushButton::clicked, index, qOverload<>(&QWidget::showMinimized));

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(index);
    } // setupUi

    void retranslateUi(QWidget *index)
    {
        index->setWindowTitle(QCoreApplication::translate("index", "Form", nullptr));
        label->setText(QString());
        username->setText(QCoreApplication::translate("index", "username", nullptr));
        sign->setText(QCoreApplication::translate("index", "\344\270\252\346\200\247\347\255\276\345\220\215", nullptr));
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("index", "\344\270\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("index", "X", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("index", "\346\266\210\346\201\257", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("index", "\345\245\275\345\217\213", nullptr));
        toolButton_2->setText(QCoreApplication::translate("index", "\347\233\270\344\272\262\347\233\270\347\210\261\344\270\200\345\256\266\344\272\272", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("index", "\347\276\244\350\201\212", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("index", "\350\201\224\347\263\273\344\272\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("index", "\347\251\272\351\227\264", nullptr));
        toolButton->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("index", "\346\220\234\347\264\242", nullptr));
        toolButton_4->setText(QString());
        toolButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class index: public Ui_index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEX_H
