#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QSettings>
#include <QDir>

#include "ui_QueueTest.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication* ThisApp);
    ~MainWindow(void);

protected:
  //Ui_MainWindow* mw;
  QSettings*     AppSettings;
  QApplication*  TheApp;
  QDir*          Directory;

protected slots:
    void ProcessDataClicked(bool checked);
};

#endif

