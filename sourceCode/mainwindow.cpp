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

void MainWindow::on_pushButton_clicked(){
int *year=new int ;
int *mon=new int ;
int *day=new int ;
int *hour=new int ;
int *min=new int ;
int *sec=new int ;
int *mide=new int ;
int *lengthMax=new int;
*lengthMax=560;
char namePDF[120];
char dateTime[40],stringText[40];
QDateTime UTC(QDateTime::currentDateTimeUtc());
QDateTime local(UTC.toLocalTime());
QByteArray captureFisrtName=ui->lineEditFirstName->text().toLatin1();
QByteArray captureLastName=ui->lineEditLastName->text().toLatin1();
QByteArray capturePhone=ui->lineEditPhone->text().toLatin1();
QByteArray captureFisrtAddress=ui->lineEditAddress->text().toLatin1();
QByteArray captureFisrtEmail=ui->lineEditemail->text().toLatin1();
QLineF line(0, 120, 600, 120);
//QPrinter printer(QPrinter::HighResolution);
QPrinter printer;
QPainter painter;
    time_t  time=UTC.toTime_t();
    time=time-10800;
    *year=(UTC.toTime_t()/31556926);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    qreal top=20, left=15, right=15, bottom=20;
    printer.setPageMargins(left, top, right, bottom, QPrinter::Millimeter);
    *sec=time%60;
    *min=(time/60)%60;
    *hour=(time/3600)%24;
    *day=(time/(3600*24))%31;
    *mon=(((time-(time/31556926)))/2629743%12)+1;
    sprintf(namePDF,"/home/mega/Documentos/sources/qt/qtPdfMysql/pdf/Presupuesto%d-%02d-%02d %02d %02d %02d.pdf",(*year+1970),*mon,*day,*hour,*min,*sec);
    qDebug (namePDF);
    sprintf(dateTime,"%2d / %2d / %4d",*day,*mon,(*year+1970));
    printer.setOutputFileName(namePDF);
    delete year;
    delete mon;
    delete day;
    delete hour;
    delete min;
    delete sec;
    if (! painter.begin(&printer)) { // failed to open file
        qWarning("failed to open file, is it writable?");          
        return ;
    }
    QFile f(namePDF);
    QPdfWriter* writer = new QPdfWriter(&f);
    writer->setPageSize(QPagedPaintDevice::A4);
    painter.setPen(Qt::gray);
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
    *mide=(*lengthMax-(strlen("by lio desi/home/megagn")*8))/2;
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
    painter.drawText(100, 140, captureFisrtAddress);
    painter.drawText(100, 160, captureFisrtEmail);
    painter.drawText(QRect(100, 100, 2000, 200), "test");
    line.setLine(0,45,*lengthMax,45);
    painter.drawLine(line);
    line.setLine(0,250,*lengthMax,250);
    painter.drawLine(line);
    line.setLine(0,750,*lengthMax,750);
    painter.drawLine(line);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Helvetica", 11, QFont::Normal));
    if(ui->checkBoxPuff1->isChecked()){
    painter.drawText(100, 400, "*   IC 1   x unidad $ ");
    }
    if(ui->checkBoxPuff2->isChecked()){
    painter.drawText(100, 450, "*   IC 2   x unidad $ ");
    }
    if(ui->checkBoxPuff3->isChecked()){
    painter.drawText(100, 500, "*   IC 3   x unidad $ ");
    }
  if(ui->checkBoxSofa1->isChecked()){
    painter.drawText(100, 650, "*   IC 4  x unidad $ ");
    }
    delete lengthMax;
    painter.end();
    QPluginLo
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
    currentDir+= "/../source_code";
#ifdef __DEBUGGER__
//     qDebug()  <<"current dir"<<currentDir;
#endif
            QSqlQuery query( "SELECT * from People" );

#ifdef __DEBUGGER__
     qDebug()  <<"QSqlQuery state_q: ";
#endif
switch(value){
    case 1:
        #ifdef __DEBUGGER__
            qDebug()  <<"\r\nCrear pdf"<<value;
        #endif
        break;

    case 2:
        #if defined(__DEBUGGER__)
            qDebug()  <<"Crear base de datos"<<value;
        #endif

        if(db.open())  {
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
        else
        {
             qDebug()  <<db.lastError().text();
        }
        break;

    case 3:
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
                query.bindValue(    ":firstname", ui->lineEditFirstName->text().toLatin1());
                query.bindValue(    ":lastname", ui->lineEditLastName->text().toLatin1());
                query.bindValue(    ":phone", ui->lineEditPhone->text().toInt());
                query.bindValue(    ":address", ui->lineEditAddress->text().toLatin1());
                query.bindValue(    ":email", ui->lineEditemail->text().toLatin1());
                query.exec();
                db.close();
             }
        break;

    case 4 :
            qDebug()<<"clear table People";
            query.prepare( "TRUNCATE people" );
            query.exec();
            break;
    case 5 :
    if(db.open())
    {
           int c=0;
           c=  query.exec( "LOAD DATA LOCAL INFILE '"+currentDir+"/pdf/db/agenda_database.csv' INTO TABLE "+nameDatabase+".People FIELDS TERMINATED BY ';' lines terminated by '\r'");
           #if defined(__DEBUGGER__)
               qDebug()  <<"state Update data base C:" <<c;
           #endif
        db.close();
    }
    break;
case 6:

    if(db.open()){
        query.exec("SELECT * FROM People");
        query.exec();
        while ( query.next() ) {
            int tmp = query.value(0).toInt();
        }
    }
      db.close();
        break;
    default:
        break;
    }
}


void MainWindow::on_pushButtonCreateDataBase_clicked(){
     MainWindow::funcion(2);
}

void MainWindow::on_pushButtonAddUser_clicked(){
     MainWindow::funcion(3);
}

void MainWindow::on_pushButtonClear_clicked(){
     MainWindow::funcion(4);
}

void MainWindow::on_pushButtonUpdateDatabase_clicked(){
     MainWindow::funcion(5);
}

void MainWindow::on_pushButtonViewTable_clicked(){
     MainWindow::funcion(6);
}
