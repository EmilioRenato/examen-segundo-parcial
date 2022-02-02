#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QPainter>
#include <QFile>
#include <QDebug>

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

    void on_actionAbrir_ctr_a_triggered();

    void on_actionNuevo_triggered();

    void on_actionSalir_triggered();

private:
    Ui::principal *ui;
    void Calcular();
    QString m_altura;
    QString m_peso;
    int m_dia;
    int m_mes;
    int m_anio;
    QPixmap lienzo;
    void dibujar();
    void limpiar();
    void guarar();
    QString allData2string();
    QString m_altura_max;
    QString m_peso_max;



};
#endif // PRINCIPAL_H
