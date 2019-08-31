/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonExit;
    QLineEdit *lineEditFirstName;
    QLineEdit *lineEditPhone;
    QLineEdit *lineEditLastName;
    QLineEdit *lineEditAddress;
    QLineEdit *lineEditemail;
    QLabel *labelFirstName;
    QLabel *labelLastName;
    QLabel *labelPhone;
    QLabel *labelAddress;
    QLabel *labelEmail;
    QLabel *labelCotizar;
    QPushButton *pushButtonCreateDataBase;
    QCheckBox *checkBoxIC1;
    QCheckBox *checkBoxIC2;
    QCheckBox *checkBoxIC3;
    QCheckBox *checkBoxIC4;
    QPushButton *pushButtonAddUser;
    QPushButton *pushButtonClear;
    QLabel *labelPrices;
    QTextEdit *textEditPrice1;
    QTextEdit *textEditPrice2;
    QTextEdit *textEditPrice3;
    QTextEdit *textEditPrice4;
    QPushButton *pushButtonUpdateDatabase;
    QPushButton *pushButtonViewTable;
    QPushButton *pushButtonSearch;
    QRadioButton *radioButtonCheckId;
    QLineEdit *lineEditID;
    QPushButton *pushButtonGeneratorPDF;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(916, 713);
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(8);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonExit = new QPushButton(centralWidget);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(680, 520, 171, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans"));
        font1.setPointSize(10);
        pushButtonExit->setFont(font1);
        lineEditFirstName = new QLineEdit(centralWidget);
        lineEditFirstName->setObjectName(QStringLiteral("lineEditFirstName"));
        lineEditFirstName->setGeometry(QRect(200, 80, 211, 41));
        lineEditPhone = new QLineEdit(centralWidget);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));
        lineEditPhone->setGeometry(QRect(200, 180, 211, 41));
        lineEditLastName = new QLineEdit(centralWidget);
        lineEditLastName->setObjectName(QStringLiteral("lineEditLastName"));
        lineEditLastName->setGeometry(QRect(200, 130, 211, 41));
        lineEditAddress = new QLineEdit(centralWidget);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));
        lineEditAddress->setGeometry(QRect(200, 230, 211, 51));
        lineEditemail = new QLineEdit(centralWidget);
        lineEditemail->setObjectName(QStringLiteral("lineEditemail"));
        lineEditemail->setGeometry(QRect(200, 290, 211, 51));
        labelFirstName = new QLabel(centralWidget);
        labelFirstName->setObjectName(QStringLiteral("labelFirstName"));
        labelFirstName->setGeometry(QRect(70, 90, 91, 16));
        labelFirstName->setFont(font1);
        labelLastName = new QLabel(centralWidget);
        labelLastName->setObjectName(QStringLiteral("labelLastName"));
        labelLastName->setGeometry(QRect(70, 140, 91, 16));
        labelLastName->setFont(font1);
        labelPhone = new QLabel(centralWidget);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));
        labelPhone->setGeometry(QRect(70, 190, 81, 16));
        labelPhone->setFont(font1);
        labelAddress = new QLabel(centralWidget);
        labelAddress->setObjectName(QStringLiteral("labelAddress"));
        labelAddress->setGeometry(QRect(70, 240, 81, 16));
        labelAddress->setFont(font1);
        labelEmail = new QLabel(centralWidget);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));
        labelEmail->setGeometry(QRect(70, 300, 81, 16));
        labelEmail->setFont(font1);
        labelCotizar = new QLabel(centralWidget);
        labelCotizar->setObjectName(QStringLiteral("labelCotizar"));
        labelCotizar->setGeometry(QRect(540, 30, 59, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Century Gothic"));
        font2.setPointSize(10);
        labelCotizar->setFont(font2);
        pushButtonCreateDataBase = new QPushButton(centralWidget);
        pushButtonCreateDataBase->setObjectName(QStringLiteral("pushButtonCreateDataBase"));
        pushButtonCreateDataBase->setEnabled(false);
        pushButtonCreateDataBase->setGeometry(QRect(20, 510, 171, 81));
        pushButtonCreateDataBase->setFont(font1);
        checkBoxIC1 = new QCheckBox(centralWidget);
        checkBoxIC1->setObjectName(QStringLiteral("checkBoxIC1"));
        checkBoxIC1->setGeometry(QRect(550, 90, 89, 20));
        checkBoxIC1->setFont(font1);
        checkBoxIC2 = new QCheckBox(centralWidget);
        checkBoxIC2->setObjectName(QStringLiteral("checkBoxIC2"));
        checkBoxIC2->setGeometry(QRect(550, 120, 89, 20));
        checkBoxIC2->setFont(font1);
        checkBoxIC3 = new QCheckBox(centralWidget);
        checkBoxIC3->setObjectName(QStringLiteral("checkBoxIC3"));
        checkBoxIC3->setGeometry(QRect(550, 150, 89, 20));
        checkBoxIC3->setFont(font1);
        checkBoxIC4 = new QCheckBox(centralWidget);
        checkBoxIC4->setObjectName(QStringLiteral("checkBoxIC4"));
        checkBoxIC4->setGeometry(QRect(550, 180, 89, 20));
        checkBoxIC4->setFont(font1);
        pushButtonAddUser = new QPushButton(centralWidget);
        pushButtonAddUser->setObjectName(QStringLiteral("pushButtonAddUser"));
        pushButtonAddUser->setGeometry(QRect(20, 410, 171, 81));
        pushButtonAddUser->setFont(font1);
        pushButtonClear = new QPushButton(centralWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setEnabled(false);
        pushButtonClear->setGeometry(QRect(660, 230, 171, 81));
        pushButtonClear->setFont(font1);
        labelPrices = new QLabel(centralWidget);
        labelPrices->setObjectName(QStringLiteral("labelPrices"));
        labelPrices->setGeometry(QRect(640, 30, 59, 16));
        labelPrices->setFont(font1);
        textEditPrice1 = new QTextEdit(centralWidget);
        textEditPrice1->setObjectName(QStringLiteral("textEditPrice1"));
        textEditPrice1->setGeometry(QRect(640, 90, 81, 21));
        textEditPrice2 = new QTextEdit(centralWidget);
        textEditPrice2->setObjectName(QStringLiteral("textEditPrice2"));
        textEditPrice2->setGeometry(QRect(640, 120, 81, 21));
        textEditPrice3 = new QTextEdit(centralWidget);
        textEditPrice3->setObjectName(QStringLiteral("textEditPrice3"));
        textEditPrice3->setGeometry(QRect(640, 150, 81, 21));
        textEditPrice4 = new QTextEdit(centralWidget);
        textEditPrice4->setObjectName(QStringLiteral("textEditPrice4"));
        textEditPrice4->setGeometry(QRect(640, 180, 81, 21));
        pushButtonUpdateDatabase = new QPushButton(centralWidget);
        pushButtonUpdateDatabase->setObjectName(QStringLiteral("pushButtonUpdateDatabase"));
        pushButtonUpdateDatabase->setEnabled(false);
        pushButtonUpdateDatabase->setGeometry(QRect(210, 510, 171, 81));
        pushButtonUpdateDatabase->setFont(font1);
        pushButtonViewTable = new QPushButton(centralWidget);
        pushButtonViewTable->setObjectName(QStringLiteral("pushButtonViewTable"));
        pushButtonViewTable->setGeometry(QRect(210, 410, 171, 81));
        pushButtonViewTable->setFont(font1);
        pushButtonSearch = new QPushButton(centralWidget);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));
        pushButtonSearch->setEnabled(false);
        pushButtonSearch->setGeometry(QRect(420, 510, 171, 81));
        QFont font3;
        font3.setPointSize(10);
        pushButtonSearch->setFont(font3);
        radioButtonCheckId = new QRadioButton(centralWidget);
        radioButtonCheckId->setObjectName(QStringLiteral("radioButtonCheckId"));
        radioButtonCheckId->setGeometry(QRect(70, 30, 112, 23));
        radioButtonCheckId->setFont(font3);
        lineEditID = new QLineEdit(centralWidget);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        lineEditID->setEnabled(false);
        lineEditID->setGeometry(QRect(250, 30, 113, 25));
        lineEditID->setAcceptDrops(true);
        lineEditID->setFrame(false);
        pushButtonGeneratorPDF = new QPushButton(centralWidget);
        pushButtonGeneratorPDF->setObjectName(QStringLiteral("pushButtonGeneratorPDF"));
        pushButtonGeneratorPDF->setGeometry(QRect(420, 410, 171, 81));
        pushButtonGeneratorPDF->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 916, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonExit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Budget", Q_NULLPTR));
        pushButtonExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        labelFirstName->setText(QApplication::translate("MainWindow", "Nombre", Q_NULLPTR));
        labelLastName->setText(QApplication::translate("MainWindow", "Apellido", Q_NULLPTR));
        labelPhone->setText(QApplication::translate("MainWindow", "Telefono", Q_NULLPTR));
        labelAddress->setText(QApplication::translate("MainWindow", "Direccion", Q_NULLPTR));
        labelEmail->setText(QApplication::translate("MainWindow", "e-mail", Q_NULLPTR));
        labelCotizar->setText(QApplication::translate("MainWindow", "Cotizar", Q_NULLPTR));
        pushButtonCreateDataBase->setText(QApplication::translate("MainWindow", "Crear Base de Datos", Q_NULLPTR));
        checkBoxIC1->setText(QApplication::translate("MainWindow", "IC 1", Q_NULLPTR));
        checkBoxIC2->setText(QApplication::translate("MainWindow", "IC 2", Q_NULLPTR));
        checkBoxIC3->setText(QApplication::translate("MainWindow", "IC 3", Q_NULLPTR));
        checkBoxIC4->setText(QApplication::translate("MainWindow", "IC 4", Q_NULLPTR));
        pushButtonAddUser->setText(QApplication::translate("MainWindow", "Guardar Usuario", Q_NULLPTR));
        pushButtonClear->setText(QApplication::translate("MainWindow", "Borrar Tabla", Q_NULLPTR));
        labelPrices->setText(QApplication::translate("MainWindow", "Price $", Q_NULLPTR));
        pushButtonUpdateDatabase->setText(QApplication::translate("MainWindow", "UpdateDatabase", Q_NULLPTR));
        pushButtonViewTable->setText(QApplication::translate("MainWindow", "ViewTable", Q_NULLPTR));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        radioButtonCheckId->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        lineEditID->setInputMask(QString());
        lineEditID->setPlaceholderText(QString());
        pushButtonGeneratorPDF->setText(QApplication::translate("MainWindow", "Gen PDF", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
