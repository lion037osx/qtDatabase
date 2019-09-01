#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include<QDebug>
#include <QString>
#include<QFileDialog>
#include<QtCore>
#include <QTextEdit>
#include <QDateTime>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "QDir"
#include <QtPlugin>
#include <QSqlDriver>
#include <QPdfWriter>

#define __DEBUGGER__

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->lineEditFirstName->setText("Name");
    ui->lineEditLastName->setText("LastName");
    ui->lineEditPhone->setText("54911");
    ui->lineEditAddress->setText("Av. ________  N ____ Dto:_");
    ui->lineEditemail->setText("@gmail.com");
}

MainWindow::~MainWindow(){
    delete ui;
}

enum{
    DEBUGGER_PDF,CREATE_DATABASE,ADD_USER,CLEAR,UPDATE_DATABASE_CSV,VIEW_TABLE,CHECK_ID
}/*FUNCTION_DB_MYSQL*/;

void MainWindow::on_pushButton_clicked(){
int year;
int mon;
int day;
int hour;
int min;
int sec;
int * mide = new int;
int * lengthMax=new int;
*lengthMax=560;
char namePDF[120];
char dateTime[40],stringText[40];
QDateTime UTC(QDateTime::currentDateTimeUtc());
QDateTime local(UTC.toLocalTime());
QByteArray captureFisrtName=ui->lineEditFirstName->text().toLatin1();
QByteArray captureLastName=ui->lineEditLastName->text().toLatin1();
QByteArray capturePhone=ui->lineEditPhone->text().toLatin1();
QByteArray captureAddress=ui->lineEditAddress->text().toLatin1();
QByteArray captureFisrtEmail=ui->lineEditemail->text().toLatin1();
QLineF line(0, 120, 600, 120);
//QPrinter printer(QPrinter::HighResolution);
QPrinter printer;
QPainter painter;
QTime time(UTC.time());
QDateTime * date_time= new QDateTime(UTC.date());
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    qreal top=20, left=15, right=15, bottom=20;
    printer.setPageMargins(left, top, right, bottom, QPrinter::Millimeter);
    hour=time.currentTime().hour();
    sec=time.second();
    min=time.minute();
    day=date_time->date().day();
    mon=date_time->date().month();
    year= (date_time->date().year());
    QString currentDir=QDir::currentPath();
    QString currentDirLogo=currentDir;
    currentDirLogo+="/../sourceCode/png/logo.png";
    currentDir+=    "/../sourceCode/pdf/cotiz";
    QString filenameImageLogo(currentDirLogo);
    sprintf(namePDF,"%d%02d%02d%02d%02d%02d.pdf",(year),mon,day,hour,min,sec);
    currentDir+=namePDF;
    //sprintf(dateTime,"%2d / %2d / %4d",*day,*mon,(*year+1970));
    qDebug()<<currentDir;
    printer.setOutputFileName(currentDir);
    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");          
        return ;
    }
    QFile f(currentDir);
    QPdfWriter* writer = new QPdfWriter(&f);
    writer->setPageSize(QPagedPaintDevice::A4);
    QPixmap pixmap(256,256);
    pixmap.load(filenameImageLogo,"png");
    QRect rect(100,500,128,128);
    pixmap.scaled(rect.size());
    //qDebug()<<" x:"<<rect.x()<<" y:"<<rect.y()<<" h:"<<rect.size().height()<<" w:"<<rect.size().width();
    painter.setPen(Qt::gray);
    painter.drawPixmap( rect.x(),rect.y() ,rect.size().height() ,rect.size().width(), pixmap);
    painter.setFont(QFont("Helvetica", 6, QFont::Bold));
    strcpy(stringText,"X");
    *mide=(*lengthMax-(strlen(stringText)))/2;
    painter.drawText(*mide, 10,stringText);
    strcpy(stringText,"Documento");
    *mide=(*lengthMax-(strlen(stringText)))/2;
    painter.drawText(*mide, 20,stringText);
    strcpy(stringText,"no Valido");
    *mide=(*lengthMax-(strlen(stringText)))/2;
    painter.drawText(*mide, 30,stringText);
    strcpy(stringText,"como factura");
    *mide=(*lengthMax-(strlen(stringText)))/2;
    painter.drawText(*mide, 40,stringText);
    //Titles
    painter.setFont(QFont("Helvetica", 11, QFont::Bold));
    painter.drawText( 450, 70,dateTime);
    *mide=(*lengthMax-(strlen("Cotizacion"))*8)/2;
    painter.drawText(*mide, 200, "Cotizacion");
    *mide=(*lengthMax-(strlen("by lio desi/home/meQgagn")*8))/2;
    painter.drawText(*mide, 240, "by lio design");
    writer->newPage();
    delete writer;
    delete mide;

//Data Clients
    painter.setFont(QFont("Helvetica", 11, QFont::Normal));
    painter.drawText(20, 80, "Name:");
    painter.drawText(20, 100, "Lastname:");
    painter.drawText(20, 120, "Phone:");
    painter.drawText(20, 140, "Direccion:");
    painter.drawText(20, 160, "e-mail:");
    painter.setFont(QFont("Helvetica", 11, QFont::Bold));
    painter.drawText(100, 80,captureFisrtName );
    painter.drawText(100, 100, captureLastName);
    painter.drawText(100, 120, capturePhone);
    painter.drawText(100, 140, captureAddress);
    painter.drawText(100, 160, captureFisrtEmail);
    int margen=60;
    painter.drawText(QRect(margen, 240, *lengthMax, 240), "Description");
    line.setLine(0,45,*lengthMax,45);
    painter.drawLine(line);
    line.setLine(margen,250,*lengthMax,250);
    painter.drawLine(line);
    line.setLine(margen,750,*lengthMax,750);
    painter.drawLine(line);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Helvetica", 11, QFont::Normal));
    if(ui->checkBoxIC1->isChecked()){
    painter.drawText(100, 200, "*   IC 1   x unidad $ ");
    }
    if(ui->checkBoxIC2->isChecked()){
    painter.drawText(100, 250, "*   IC 2   x unidad $ ");
    }
    if(ui->checkBoxIC3->isChecked()){
    painter.drawText(100, 300, "*   IC 3   x unidad $ ");
    }
  if(ui->checkBoxIC4->isChecked()){
    painter.drawText(100, 350, "*   IC 4  x unidad $ ");
    }
    delete lengthMax;
painter.end();
}

void MainWindow::funcion(int value){
   // QPluginLoader loader("/usr/local/lib/libqsqlmysql.dylib");
    QPluginLoader loader("/usr/lib/x86_64-linux-gnu/qt5/plugins/sqldrivers");
    loader.load();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    QString nameDatabase= "dbmega";
    db.setDatabaseName(nameDatabase);
    db.setUserName("myuser");
    db.setPassword("pass");
    QString currentDir=QDir::currentPath();
    currentDir+= "/../sourceCode";
#ifdef __DEBUGGER__
//     qDebug()  <<"current dir"<<currentDir;
#endif
      QSqlQuery query( "SELECT * from People" );
#ifdef __DEBUGGER__
     qDebug()  <<"QSqlQuery state_q: ";
#endif
switch(value){
    case   DEBUGGER_PDF:
        #ifdef __DEBUGGER__
            qDebug()  <<"\r\nCrear pdf"<<value;
        #endif
             on_pushButton_clicked();
        break;
    case CREATE_DATABASE:
        #if defined(__DEBUGGER__)
            qDebug()  <<"Crear base de datos"<<value;
        #endif
        if(db.open()){
            //--- we're good! ---ldd libqsqlmysql.so
            qDebug()  << "Database open success! \n";
            bool stateQuery =query.exec( "CREATE TABLE IF NOT EXISTS People(id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(42), lastname VARCHAR(42),phone INT,address VARCHAR(42),email VARCHAR(42))" );
            qDebug()  << "State Query"<<stateQuery;
            //bool data_void=0;
         if ( !query.isActive() )
            qDebug() <<"Step One" << "Query Error" + query.lastError().text();
        else while (query.next()) {
            int Id = query.value(0).toInt();
            QString word = query.value(1).toString();
            qDebug()  <<"Step Duo" << QString( "%1\t%2\n").arg(Id).arg( word );
            }
            query.exec();
        }
        else{
             qDebug()<<db.lastError().text();
        }
        break;

    case ADD_USER:
             if ( !query.isActive() ){
               qDebug()  <<"Add user"<<value;
             }

             if(db.open())
             {
                int id_tmp=0;
                query.exec("SELECT * FROM People");
                query.exec();
                while ( query.next() ) {
                    id_tmp = query.value(0).toInt();
                 }
                qDebug()  <<        "data base open : -> ADD DATA"<<value<<"\r\n";
                query.prepare(      "INSERT INTO People(id,firstname,lastname,phone,address,email) "    \
                                    "VALUES (:id,:firstname,:lastname,:phone,:address,:email)");
                query.bindValue(    ":id", ++id_tmp);
                QString sIdTmp = QString::number(id_tmp);
                     ui->lineEditID->setText(sIdTmp);
                query.bindValue(    ":firstname", ui->lineEditFirstName->text().toLatin1());
                query.bindValue(    ":lastname", ui->lineEditLastName->text().toLatin1());
                query.bindValue(    ":phone", ui->lineEditPhone->text().toInt());
                query.bindValue(    ":address", ui->lineEditAddress->text().toLatin1());
                query.bindValue(    ":email", ui->lineEditemail->text().toLatin1());
                query.exec();
                db.close();
             }
        break;

    case CLEAR:
            qDebug()<<"clear table People";
            query.prepare( "TRUNCATE people" );
            query.exec();
            break;
    case UPDATE_DATABASE_CSV:
    if(db.open()){
           int c=0;
           qDebug()<<"current dir "<<currentDir;
           c=  query.exec( "LOAD DATA LOCAL INFILE '"+currentDir+"/pdf/db/agenda_database.csv' INTO TABLE "+nameDatabase+".People FIELDS TERMINATED BY ';' lines terminated by '\r'");
           #if defined(__DEBUGGER__)
               qDebug()  <<"state Update data base C:" <<c;
           #endif
        db.close();
    }
    break;
case VIEW_TABLE:

    if(db.open()){
        query.exec("SELECT * FROM People");
        query.exec();
        while ( query.next() ) {
             query.value(0).toInt();
        }
    }
      db.close();
        break;

case CHECK_ID:
    break;
//    query.exec("SELECT * FROM People");
//    query.exec();
//    query.value(0).toInt();
    default:
        break;
    }
}



void MainWindow::on_pushButtonCreateDataBase_clicked(){
     MainWindow::funcion(CREATE_DATABASE);
}

void MainWindow::on_pushButtonAddUser_clicked(){
     MainWindow::funcion(ADD_USER);
}

void MainWindow::on_pushButtonClear_clicked(){
     MainWindow::funcion(CLEAR);
}

void MainWindow::on_pushButtonUpdateDatabase_clicked(){
    // MainWindow::funcion(UPDATE_DATABASE);
}

void MainWindow::on_pushButtonViewTable_clicked(){
     MainWindow::funcion(VIEW_TABLE);
}


void MainWindow::on_radioButtonCheckId_clicked()
{
bool tmp=ui->radioButtonCheckId->isChecked();
if(tmp){
      ui->lineEditID->setEnabled(1);
      ui->pushButtonSearch->setEnabled(1);
      ui->pushButtonCreateDataBase->setEnabled(1);
    }
else{
      ui->lineEditID->setDisabled(1);
      ui->pushButtonSearch->setDisabled(1);
      ui->pushButtonCreateDataBase->setDisabled(1);
    }

    qDebug()<<"click"<<tmp;

}

void MainWindow::on_pushButtonGeneratorPDF_clicked()
{
MainWindow::funcion(DEBUGGER_PDF);}
