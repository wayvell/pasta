#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
// выделяем память под все ячейки таблицы
/*
for(int stroka = 0; stroka < ui->tableWidget->rowCount(); stroka++)
  for(int stolbeu = 0; stolbeu < ui->tableWidget->columnCount(); stolbeu++)
  {
       QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
       item->setText(QString("%1_%2").arg(stroka).arg(stolbeu)); // вставляем текст

       ui->tableWidget->setItem(stroka, stolbeu, item); // вставляем ячейку
  }
  */
/*
     points << QPointF( 1.0, 1.0 ) // координаты x, y
  << QPointF( 1.5, 2.0 ) << QPointF( 3.0, 2.0 )
  << QPointF( 3.5, 3.0 ) << QPointF( 5.0, 4.0 ) <<QPointF( 6.0, 0.0 );
*/
