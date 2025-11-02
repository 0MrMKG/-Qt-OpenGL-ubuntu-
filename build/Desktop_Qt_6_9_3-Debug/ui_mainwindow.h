/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <foxopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWireframe;
    QAction *actionDrawCube;
    QAction *actionCube;
    QAction *actionisDraw;
    QAction *actionMove;
    QAction *actionMoveCube;
    QAction *actionLightColor;
    QAction *actionRotate;
    QWidget *centralWidget;
    FoxOpenGLWidget *openGLWidget;
    QMenuBar *menuBar;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBarMove;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1110, 693);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color:rgb(68, 68, 68);\n"
"	color:rgb(255, 255, 255);\n"
"	font: 12pt;\n"
"}\n"
"QMenuBar {\n"
"	background-color:rgb(200, 200, 200);\n"
"	color:rgb(60, 60, 60);\n"
"}\n"
"QWidget:checked {\n"
"	background-color:rgb(150, 150, 150);\n"
"}"));
        actionWireframe = new QAction(MainWindow);
        actionWireframe->setObjectName("actionWireframe");
        actionWireframe->setCheckable(true);
        actionWireframe->setChecked(false);
        actionDrawCube = new QAction(MainWindow);
        actionDrawCube->setObjectName("actionDrawCube");
        actionDrawCube->setCheckable(true);
        actionDrawCube->setChecked(false);
        actionCube = new QAction(MainWindow);
        actionCube->setObjectName("actionCube");
        actionisDraw = new QAction(MainWindow);
        actionisDraw->setObjectName("actionisDraw");
        actionisDraw->setAutoRepeat(true);
        actionisDraw->setVisible(true);
        actionisDraw->setMenuRole(QAction::NoRole);
        actionisDraw->setIconVisibleInMenu(false);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName("actionMove");
        actionMove->setEnabled(true);
        actionMoveCube = new QAction(MainWindow);
        actionMoveCube->setObjectName("actionMoveCube");
        actionMoveCube->setCheckable(true);
        actionMoveCube->setEnabled(false);
        actionLightColor = new QAction(MainWindow);
        actionLightColor->setObjectName("actionLightColor");
        actionLightColor->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/Picture/light.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionLightColor->setIcon(icon);
        QFont font;
        font.setPointSize(10);
        actionLightColor->setFont(font);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName("actionRotate");
        actionRotate->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/Picture/start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRotate->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        openGLWidget = new FoxOpenGLWidget(centralWidget);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(400, 220, 300, 200));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1110, 24));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);
        toolBarMove = new QToolBar(MainWindow);
        toolBarMove->setObjectName("toolBarMove");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBarMove);

        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(actionCube);
        mainToolBar->addAction(actionWireframe);
        toolBarMove->addSeparator();
        toolBarMove->addAction(actionLightColor);
        toolBarMove->addAction(actionRotate);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionWireframe->setText(QCoreApplication::translate("MainWindow", "Wireframe", nullptr));
        actionDrawCube->setText(QCoreApplication::translate("MainWindow", "Cube", nullptr));
        actionCube->setText(QCoreApplication::translate("MainWindow", "Cube", nullptr));
        actionisDraw->setText(QCoreApplication::translate("MainWindow", "DRAW:", nullptr));
#if QT_CONFIG(tooltip)
        actionisDraw->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600; color:#ffff00;\">Draw:</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMove->setText(QCoreApplication::translate("MainWindow", "MOVE:", nullptr));
        actionMoveCube->setText(QCoreApplication::translate("MainWindow", "Cube", nullptr));
        actionLightColor->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "Selete", nullptr));
        toolBarMove->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
