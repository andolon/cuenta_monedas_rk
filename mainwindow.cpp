#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralWidget->setStyleSheet("background-image:url(:/fondo.png); background-position: center; ");

    cur = new QCursor;
    cur->setPos(0,0);

    int alto_pantalla;
    int ancho_pantalla;
    QRect rec = QApplication::desktop()->availableGeometry(-1);
    alto_pantalla  = rec.height();
    ancho_pantalla = rec.width();

    this->resize(ancho_pantalla, alto_pantalla);

    cuenta = 0;

    /*
    QLocale loc = QLocale::system(); // current locale
    loc.setNumberOptions(QLocale::c().numberOptions()); // borrow number options from the "C" locale
    QLocale::setDefault(loc); // set as default
    */

    izquierda_200_y_central_500 = true;

    connect(this, SIGNAL(click(int)), this, SLOT(SumaValor(int)));


    //    ui->radioButton_der_izq->ind

    //connect(ui->buttonGroup, SIGNAL(buttonClicked(int)),
    //                    this, SLOT(onGroupButtonClicked(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(event->buttons() == Qt::RightButton)
    {
        //qDebug() << "Only right button";
        emit click(100);
    }

    if(event->buttons() == Qt::LeftButton)
    {
        //qDebug() << "Only left button";

        if(izquierda_200_y_central_500==true)
        {
            emit click(200);
        }
        else
        {
            emit click(500);
        }
    }

    if(event->buttons() == Qt::MiddleButton)
    {
        //qDebug() << "Only middle button";

        if(izquierda_200_y_central_500==true)
        {
            emit click(500);
        }
        else
        {
            emit click(200);
        }


    }
}

/*
void MainWindow::wheelEvent(QWheelEvent * event)
{
    //qDebug() << event->type();

    if( event->type() == QEvent::Wheel)
    {
        on_ResetpushButton_clicked();
    }
}

*/


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {

    case Qt::Key_Period:
    {

        on_ResetpushButton_clicked();

        break;
    }

    default:
        break;
    }

}

void MainWindow::SumaValor(int valor)
{
    cuenta += valor;

    ui->lineEdit->setText(QString::number(cuenta));

    QApplication::beep();

}

void MainWindow::on_ResetpushButton_clicked()
{
    cur->setPos(0,0);
    cuenta = 0;
    ui->lineEdit->setText(QString::number(cuenta));

}

void MainWindow::on_pushButton_clicked()
{
    qApp->quit();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

    if(0 == QString::compare("izquierda=200 y central=500", arg1, Qt::CaseInsensitive))
    {
        izquierda_200_y_central_500 = true;
        //qDebug() << "1";
    }

    if(0 == QString::compare("izquierda=500 y central=200", arg1, Qt::CaseInsensitive))
    {
        izquierda_200_y_central_500 = false;
        //qDebug() << "2";
    }
}
