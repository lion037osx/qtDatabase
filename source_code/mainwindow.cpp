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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditFirstName->setText("Name");
    ui->lineEditLastName->setText("LastName");
    ui->lineEditPhone->setText("15--");
    ui->lineEditAddress->setText("Av. ________  N ____ Dto:_");
    ui->lineEditemail->setText("@gmail.com");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
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
   // printer.setOrientation(QPrinter::Landscape);

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

//Lines

    line.setLine(0,45,*lengthMax,45);
    painter.drawLine(line);

    line.setLine(0,250,*lengthMax,250);
    painter.drawLine(line);

    line.setLine(0,750,*lengthMax,750);
    painter.drawLine(line);

    //Config Puff

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
}




void MainWindow::funcion(int value){

   // QPluginLoader loader("/usr/local/lib/libqsqlmysql.dylib");
    QPluginLoader loader("/usr/lib/x86_64-linux-gnu/qt5/plugins/sqldrivers");

    loader.load();
    qDebug() << loader.errorString();
   // qDebug() << "drivers: "<< QSqlDatabase::drivers();



    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    QString nameDatabase= "dbmega";
    db.setDatabaseName(nameDatabase);
    db.setUserName("myuser");
    db.setPassword("pass");


            QSqlQuery query( "SELECT * from People" );

switch(value){
    case 1:
        #ifdef __DEBUGGER__
        qDebug()  <<"Crear pdf"<<value;
        #endif
        break;

    case 2:
        #if defined(__DEBUGGER__)
            qDebug()  <<"Crear base de datos"<<value;
        #endif



        if(db.open())  {
            //--- we're good! ---ldd libqsqlmysql.so
            qDebug()  << "Database open success! \n";

            bool stateQuery =query.exec( "CREATE TABLE IF NOT EXISTS People(id INTEGER UNIQUE PRIMARY KEY, FirstName VARCHAR(31), lastName VARCHAR(31),phone INT,address VARCHAR(31),mail VARCHAR(31))" );
            bool data_void=0;
             if(stateQuery)
             {
                int b=0;
                #if defined(__DEBUGGER__)
                    qDebug()  <<"Table People ahora existe!";
                #endif
                b=  query.exec( "LOAD DATA LOCAL INFILE '/home/mega/Documentos/sources/qt/qtPdfMysql/pdf/db/agenda_database.csv' INTO TABLE "+nameDatabase+".People FIELDS TERMINATED BY ';' lines terminated by '\r'");
                #if defined(__DEBUGGER__)
                    qDebug()  <<"Value B:" <<b;
                #endif
             }

             if ( !query.isActive() )
                qDebug() <<"Step One" << "Query Error" + query.lastError().text();

            else while (query.next()) {
                    int Id = query.value(0).toInt();
                    QString word = query.value(1).toString();
                    qDebug()  <<"Step Duo" << QString( "%1\t%2\n").arg(Id).arg( word );
                    }

            query.exec();

            db.close();
        }
        else
        {
             qDebug()  <<db.lastError().text();

              qDebug()  << "sudo apt-get install libmysqlclient20" ;
              qDebug()  << "sudo apt-get install libmysqlclient-dev";
              qDebug()  << "sudo ln -s /usr/lib/x86_64-linux-gnu/libmysqlclient.so /usr/lib/x86_64-linux-gnu/libmysqlclient_r.so";
        }
        break;

    case 3:
             qDebug()  <<"Add user"<<value;
        break;

    case 4 :
             qDebug()  <<"clear table People";
            query.prepare( "TRUNCATE people" );
            break;

    default:
        break;
    }
}


void MainWindow::on_pushButtonCreateDataBase_clicked()
{
         MainWindow::funcion(2);
}


void MainWindow::on_pushButtonAddUser_clicked()
{
          MainWindow::funcion(3);
}

void MainWindow::on_pushButtonClear_clicked()
{
             MainWindow::funcion(4);
}
