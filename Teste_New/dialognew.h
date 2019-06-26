#ifndef DIALOGNEW_H
#define DIALOGNEW_H

#include <QDialog>

namespace Ui {
class DialogNew;
}
/**
 * @brief Caixa de dialogo para informa as dimenções do escultor 3D.
 */
class DialogNew : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNew(QWidget *parent = nullptr);
    ~DialogNew();
    QString lear_Dimension_Y();
    QString lear_Dimension_X();
    QString lear_Dimension_Z();

private:
    Ui::DialogNew *ui;
};

#endif // DIALOGNEW_H
