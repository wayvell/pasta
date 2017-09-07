#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->tableWidget->setRowCount(20); // указываем количество строк
    ui->tableWidget->setColumnCount(2);
    // выделяем память под все ячейки таблицы
    for(int stroka = 0; stroka <   ui->tableWidget->rowCount(); stroka++)
    for(int stolbeu = 0; stolbeu <   ui->tableWidget->columnCount(); stolbeu++)
        ui->tableWidget->setItem(stroka, stolbeu, new QTableWidgetItem());

    QwtPlot *d_plot = new QwtPlot( this );
    d_plot->setGeometry(30,70,400,350);
    d_plot->setTitle( "прототип");
    d_plot->setAxisTitle(QwtPlot::yLeft, "Y");
       d_plot->setAxisTitle(QwtPlot::xBottom, "X");
       d_plot->insertLegend( new QwtLegend() );
       QwtPlotGrid *grid = new QwtPlotGrid(); //
           grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
           grid->attach( d_plot );
           QwtPlotCurve *curve = new QwtPlotCurve();
               curve->setTitle( "Кривая замеса" );
               curve->setPen( Qt::blue, 6 ); // цвет и толщина кривой
               curve->setRenderHint
                       ( QwtPlotItem::RenderAntialiased, true );
               QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
                    QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
                curve->setSymbol( symbol );

                // Добавить точки на ранее созданную кривую
                QPolygonF points;
                QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку

                  for (int i=0; i<=25;i++)
                  {
                      points << QPointF( i, i+2 );
                      QTableWidgetItem *item = new QTableWidgetItem();
                      ui->tableWidget->setRowCount(i+1);
                      item->setText(QString("%1").arg(i)); // вставляем текст

                      ui->tableWidget->setItem(i, 0, item);
                  }

                 curve->setSamples( points ); // ассоциировать набор точек с кривой
                  QwtPlotPanner *d_panner = new QwtPlotPanner( d_plot->canvas() );
                 curve->attach( d_plot );
                 d_panner->setMouseButton( Qt::RightButton );
                 QwtPlotPicker *d_picker =
                           new QwtPlotPicker(
                               QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
                   QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
                   QwtPicker::ActiveOnly, // включение/выключение
                   d_plot->canvas() ); // ассоциация с полем

                   // Цвет перпендикулярных линий
                   d_picker->setRubberBandPen( QColor( Qt::red ) );

                   // цвет координат положения указателя
                   d_picker->setTrackerPen( QColor( Qt::black ) );

                   // непосредственное включение вышеописанных функций
                   d_picker->setStateMachine( new QwtPickerDragPointMachine() );
                   connect(ui->pushButton,SIGNAL(clicked(bool)), this, SLOT(increm()));
                   connect(ui->action_3, SIGNAL(triggered(bool)), this,SLOT(save()));
                   connect(ui->action_4, SIGNAL(triggered(bool)), qApp,SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::increm()
{
q++;

 ui->lcdNumber->display(q);

}
//сохранение таблицы
void MainWindow::saved()
{
   QFile *f1 =new QFile("test.txt");
            if(!f1->exists()) // если файл не существует, то
            { // формирмируем сообщение
                QMessageBox msg(QMessageBox::Information,
                    ("Файл не найден"),
                   ("Файл book.txt создан"),
                    QMessageBox::Ok,0);
                msg.exec();// выводим сообщение на экран
            }
            f1->open(QFile::ReadWrite); // открываем файл
            QDataStream out(f1);
            for(int i=0;i<ui->tableWidget->rowCount();i++)
            {
                    QTableWidgetItem* itm = ui->tableWidget->item(i,0);
                    QString itmqstr = itm -> text();
                    out<<itmqstr;
            }
                f1->close(); // закрываем файл
                delete f1; // освобождаем память
}
