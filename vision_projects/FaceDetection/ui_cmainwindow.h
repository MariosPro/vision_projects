/********************************************************************************
** Form generated from reading UI file 'cmainwindow.ui'
**
** Created: Tue Jan 27 06:42:52 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "cqtopencvviewergl.h"

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QAction *actionStart;
    QAction *actionStop;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    CQtOpenCVViewerGl *cameraWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_fullFace;
    QCheckBox *checkBox_eyes;
    QCheckBox *checkBox_nose;
    QCheckBox *checkBox_mouth;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuCamera;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QString::fromUtf8("CMainWindow"));
        CMainWindow->resize(400, 300);
        actionStart = new QAction(CMainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStop = new QAction(CMainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        centralWidget = new QWidget(CMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cameraWidget = new CQtOpenCVViewerGl(centralWidget);
        cameraWidget->setObjectName(QString::fromUtf8("cameraWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cameraWidget->sizePolicy().hasHeightForWidth());
        cameraWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cameraWidget, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_fullFace = new QCheckBox(groupBox);
        checkBox_fullFace->setObjectName(QString::fromUtf8("checkBox_fullFace"));

        verticalLayout->addWidget(checkBox_fullFace);

        checkBox_eyes = new QCheckBox(groupBox);
        checkBox_eyes->setObjectName(QString::fromUtf8("checkBox_eyes"));
        checkBox_eyes->setEnabled(false);

        verticalLayout->addWidget(checkBox_eyes);

        checkBox_nose = new QCheckBox(groupBox);
        checkBox_nose->setObjectName(QString::fromUtf8("checkBox_nose"));
        checkBox_nose->setEnabled(false);

        verticalLayout->addWidget(checkBox_nose);

        checkBox_mouth = new QCheckBox(groupBox);
        checkBox_mouth->setObjectName(QString::fromUtf8("checkBox_mouth"));
        checkBox_mouth->setEnabled(false);

        verticalLayout->addWidget(checkBox_mouth);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        CMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QString::fromUtf8("menuCamera"));
        CMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCamera->menuAction());
        menuCamera->addAction(actionStart);
        menuCamera->addAction(actionStop);

        retranslateUi(CMainWindow);

        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QApplication::translate("CMainWindow", "CMainWindow", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("CMainWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("CMainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CMainWindow", "Options", 0, QApplication::UnicodeUTF8));
        checkBox_fullFace->setText(QApplication::translate("CMainWindow", "Detect Full Face", 0, QApplication::UnicodeUTF8));
        checkBox_eyes->setText(QApplication::translate("CMainWindow", "Detect Eyes", 0, QApplication::UnicodeUTF8));
        checkBox_nose->setText(QApplication::translate("CMainWindow", "Detect Nose", 0, QApplication::UnicodeUTF8));
        checkBox_mouth->setText(QApplication::translate("CMainWindow", "Detect Mouth", 0, QApplication::UnicodeUTF8));
        menuCamera->setTitle(QApplication::translate("CMainWindow", "Camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
