#ifndef DIALOGOPEN_H
#define DIALOGOPEN_H

#include <QDialog>
#include <QString>


namespace Ui {

class DialogOpen;
}
/**
 * @brief Caixa de dialogo para informa o diretorio do arquivo para ler.
 */
class DialogOpen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOpen(QWidget *parent = nullptr);
    ~DialogOpen();
    QString learFile();
private:
    Ui::DialogOpen *ui;
};

#endif // DIALOGOPEN_H
