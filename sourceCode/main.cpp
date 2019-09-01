#include "mainwindow.h"
#include <QApplication>

#include <QDesktopWidget>
#include <QSplashScreen>
#include <QTimer>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>
#include <QIcon>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString currentDir=QDir::currentPath();
    currentDir+="/../sourceCode/png/";
    QSplashScreen *splash=new QSplashScreen;
    #ifdef Q_OS_LINUX
    qDebug()<<"LINUX OS";
    splash->setPixmap(QPixmap(currentDir + "flame.png"));
    #endif
    #ifdef Q_OS_MACOS
    qDebug()<<"MAC OS";
    splash->setPixmap(QPixmap(currentDir+"oso.png"));
    #endif
    splash->setWindowOpacity(0.99);
    splash->show();
    QTimer::singleShot(1900,splash,SLOT(close()));
    MainWindow w;
    QIcon icon(currentDir + "vector.png");
    w.setWindowIcon(icon);
    w.move(QApplication::desktop()->screen()->rect().center()-w.rect().center());
    QTimer::singleShot(1500,&w,SLOT(show()));
    return a.exec();
}
