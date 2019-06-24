/********************************************************************************
** Form generated from reading UI file 'UserGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERGUI_H
#define UI_USERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserGUIClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *questionsList;
    QListWidget *answerList;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *questionInput;
    QLabel *label_2;
    QLineEdit *answerInput;
    QGridLayout *gridLayout;
    QPushButton *answerButton;
    QPushButton *askButton;
    QSpinBox *likes;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserGUIClass)
    {
        if (UserGUIClass->objectName().isEmpty())
            UserGUIClass->setObjectName(QString::fromUtf8("UserGUIClass"));
        UserGUIClass->resize(790, 433);
        centralWidget = new QWidget(UserGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        questionsList = new QListWidget(centralWidget);
        questionsList->setObjectName(QString::fromUtf8("questionsList"));

        horizontalLayout->addWidget(questionsList);

        answerList = new QListWidget(centralWidget);
        answerList->setObjectName(QString::fromUtf8("answerList"));

        horizontalLayout->addWidget(answerList);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        questionInput = new QLineEdit(centralWidget);
        questionInput->setObjectName(QString::fromUtf8("questionInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, questionInput);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        answerInput = new QLineEdit(centralWidget);
        answerInput->setObjectName(QString::fromUtf8("answerInput"));

        formLayout->setWidget(1, QFormLayout::FieldRole, answerInput);


        gridLayout_2->addLayout(formLayout, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        answerButton = new QPushButton(centralWidget);
        answerButton->setObjectName(QString::fromUtf8("answerButton"));

        gridLayout->addWidget(answerButton, 1, 1, 1, 1);

        askButton = new QPushButton(centralWidget);
        askButton->setObjectName(QString::fromUtf8("askButton"));

        gridLayout->addWidget(askButton, 1, 0, 1, 1);

        likes = new QSpinBox(centralWidget);
        likes->setObjectName(QString::fromUtf8("likes"));
        likes->setCursor(QCursor(Qt::ArrowCursor));

        gridLayout->addWidget(likes, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        UserGUIClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(UserGUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UserGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UserGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UserGUIClass->setStatusBar(statusBar);

        retranslateUi(UserGUIClass);

        QMetaObject::connectSlotsByName(UserGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserGUIClass)
    {
        UserGUIClass->setWindowTitle(QApplication::translate("UserGUIClass", "UserGUI", nullptr));
        label->setText(QApplication::translate("UserGUIClass", "Your Question", nullptr));
        label_2->setText(QApplication::translate("UserGUIClass", "Your Answer", nullptr));
        answerButton->setText(QApplication::translate("UserGUIClass", "Answer", nullptr));
        askButton->setText(QApplication::translate("UserGUIClass", "Ask", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserGUIClass: public Ui_UserGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERGUI_H
