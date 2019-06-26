#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "sculptor.h"
#include "plotter.h"
#include "vector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void RouteX();
    void RouteY();
    void RouteZ();
    void lear();
    void NewDimensions();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
