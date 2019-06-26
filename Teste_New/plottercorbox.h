#ifndef PLOTTERCORBOX_H
#define PLOTTERCORBOX_H

#include <QWidget>

class PlotterCorBox : public QWidget
{
    Q_OBJECT
public:
    explicit PlotterCorBox(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // PLOTTERCORBOX_H
