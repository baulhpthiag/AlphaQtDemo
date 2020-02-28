#include "testmainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>


TestMainWindow::TestMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // qt窗口部件

    resize(1000,800);

    //菜单栏 只有一个
    QMenuBar * qMenuBar = menuBar();
    setMenuBar(qMenuBar);
    QMenu * fileMenu=qMenuBar->addMenu("menu0");
    QMenu * editMenu = qMenuBar->addMenu("menu1");
    QAction * action0 = fileMenu->addAction("action0");
    fileMenu->addSeparator();
    QAction * action1 = fileMenu->addAction("action1");

    //工具栏
    QToolBar * qToolBar = new QToolBar(this);
    addToolBar(qToolBar);
    qToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    qToolBar->setFloatable(false);
    qToolBar->setMovable(false);
    qToolBar->addAction(action0);
    QPushButton * qPushButton0 = new QPushButton("pushButton0",this);
    qToolBar->addWidget(qPushButton0);


    //状态栏 只有一个
    QStatusBar * qStatusBar=statusBar();
    setStatusBar(qStatusBar);
    qStatusBar->addAction(action1);
    QLabel * label = new QLabel("testLabel",this);
    qStatusBar->addWidget(label);

    QLabel * label1 = new QLabel("testLabel1",this);
    qStatusBar->addPermanentWidget(label1);

    //铆接部件(浮动窗口)
    QDockWidget * dockWidgetTop = new QDockWidget("dockWidgetTop",this);
    addDockWidget(Qt::TopDockWidgetArea,dockWidgetTop);
    QDockWidget * dockWidgetBottom = new QDockWidget("dockWidgetBottom",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidgetBottom);

    //设置中心部件
    QTextEdit * textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);



}

TestMainWindow::~TestMainWindow()
{

}
