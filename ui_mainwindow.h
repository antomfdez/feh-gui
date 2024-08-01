/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QPushButton *buttonBrowser;
    QListWidget *listWidget;
    QPushButton *buttonSet;
    QLabel *imagen;
    QLabel *imagen2;
    QLabel *imagen0;
    QPushButton *Prev;
    QPushButton *Next;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1023, 708);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        buttonBrowser = new QPushButton(centralwidget);
        buttonBrowser->setObjectName(QString::fromUtf8("buttonBrowser"));
        buttonBrowser->setMinimumSize(QSize(200, 40));

        formLayout->setWidget(0, QFormLayout::SpanningRole, buttonBrowser);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(500, 200));
        listWidget->setMaximumSize(QSize(16777215, 200));

        formLayout->setWidget(1, QFormLayout::SpanningRole, listWidget);

        buttonSet = new QPushButton(centralwidget);
        buttonSet->setObjectName(QString::fromUtf8("buttonSet"));
        buttonSet->setMinimumSize(QSize(0, 300));
        buttonSet->setMaximumSize(QSize(16777215, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, buttonSet);

        imagen = new QLabel(centralwidget);
        imagen->setObjectName(QString::fromUtf8("imagen"));
        imagen->setMaximumSize(QSize(16777215, 16777215));
        imagen->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        imagen->setTextFormat(Qt::TextFormat::AutoText);
        imagen->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, imagen);

        imagen2 = new QLabel(centralwidget);
        imagen2->setObjectName(QString::fromUtf8("imagen2"));
        imagen2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, imagen2);

        imagen0 = new QLabel(centralwidget);
        imagen0->setObjectName(QString::fromUtf8("imagen0"));
        imagen0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, imagen0);

        Prev = new QPushButton(centralwidget);
        Prev->setObjectName(QString::fromUtf8("Prev"));
        Prev->setMinimumSize(QSize(100, 0));
        Prev->setMaximumSize(QSize(100, 16777215));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::GoPrevious")));
        Prev->setIcon(icon);

        formLayout->setWidget(2, QFormLayout::LabelRole, Prev);

        Next = new QPushButton(centralwidget);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setMaximumSize(QSize(100, 16777215));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::GoNext")));
        Next->setIcon(icon1);

        formLayout->setWidget(2, QFormLayout::FieldRole, Next);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1023, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonBrowser->setText(QCoreApplication::translate("MainWindow", "Browser", nullptr));
        buttonSet->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        imagen->setText(QCoreApplication::translate("MainWindow", "ImagePreview", nullptr));
        imagen2->setText(QCoreApplication::translate("MainWindow", "image2", nullptr));
        imagen0->setText(QCoreApplication::translate("MainWindow", "image1", nullptr));
        Prev->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        Next->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
