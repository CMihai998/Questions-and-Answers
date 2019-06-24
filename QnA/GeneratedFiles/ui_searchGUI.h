/********************************************************************************
** Form generated from reading UI file 'searchGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHGUI_H
#define UI_SEARCHGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchGUI
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *input;
    QListWidget *listWidget;

    void setupUi(QWidget *searchGUI)
    {
        if (searchGUI->objectName().isEmpty())
            searchGUI->setObjectName(QString::fromUtf8("searchGUI"));
        searchGUI->resize(1045, 630);
        verticalLayout = new QVBoxLayout(searchGUI);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        input = new QLineEdit(searchGUI);
        input->setObjectName(QString::fromUtf8("input"));

        verticalLayout->addWidget(input);

        listWidget = new QListWidget(searchGUI);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(searchGUI);

        QMetaObject::connectSlotsByName(searchGUI);
    } // setupUi

    void retranslateUi(QWidget *searchGUI)
    {
        searchGUI->setWindowTitle(QApplication::translate("searchGUI", "searchGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchGUI: public Ui_searchGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHGUI_H
