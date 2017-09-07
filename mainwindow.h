#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <fstream>
#include <string>
#include <locale>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QDialog>
#include <QLCDNumber>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_legend.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>
#include <QAction>
#include<QMessageBox>
#include <QContextMenuEvent>
#include <QMenu>
namespace Ui {
class MainWindow;
//class button;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  //  void save();
    double q;
private:
    Ui::MainWindow *ui;

private slots:
   void increm();
   void saved();
};

#endif // MAINWINDOW_H
