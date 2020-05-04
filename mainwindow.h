#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QDesktopWidget>
//#include <windows.h> // WinApi header
#include <QAbstractButton>
#include <QDebug>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    long cuenta;

    QCursor *cur;

    bool izquierda_200_y_central_500;

private slots:
    void SumaValor(int valor);

    void on_ResetpushButton_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void keyPressEvent(QKeyEvent *event);

    /* void wheelEvent(QWheelEvent * event); */

signals:
    void click(int valor);

};

#endif // MAINWINDOW_H
