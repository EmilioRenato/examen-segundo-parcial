#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class principal; }
QT_END_NAMESPACE

class principal : public QMainWindow
{
    Q_OBJECT

public:
    principal(QWidget *parent = nullptr);
    ~principal();


private slots:
    void on_btnCalcular_clicked();

    void on_actionGuardar_triggered();

    void on_actionCalcular_triggered();

private:
    Ui::principal *ui;
    void Calcular();
    QString m_altura;
    QString m_peso;
    QPixmap lienzo;
    void dibujar();

};
#endif // PRINCIPAL_H
