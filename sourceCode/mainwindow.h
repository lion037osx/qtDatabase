#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

void funcion(int x);

private slots:
    void on_pushButton_clicked();

    void on_pushButtonCreateDataBase_clicked();

    void on_pushButtonAddUser_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonUpdateDatabase_clicked();

    void on_pushButtonViewTable_clicked();

    void on_radioButtonCheckId_clicked();

    void on_pushButtonGeneratorPDF_clicked();

private:
     Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
