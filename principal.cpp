#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principal)
{
    ui->setupUi(this);
    m_altura="";
    m_peso="";
    m_dia=0;
    m_mes=0;
    m_anio=0;
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outTabla->setPixmap(lienzo);

}

principal::~principal()
{
    delete ui;
}

void principal::Calcular()
{
    m_altura = ui->inMetros->text();
    m_peso = ui->inPeso->text();
    m_dia = ui->inDia->value();
    m_mes = ui->inMes->value();
    m_anio = ui->inAnio->value();
    if(m_altura==""||m_peso==""||m_dia==0||m_mes==0||m_anio==0){
        QMessageBox::warning(this,
                             "Ingreso de datos",
                             "Debe llenar los datos");
    }else{
    float numeroPeso;
    float numeroAltura;
    float imcTotal=0;
    bool ok;
    numeroAltura=m_altura.toFloat(&ok);
    numeroPeso=m_peso.toFloat(&ok);
    imcTotal=numeroPeso/(numeroAltura*numeroAltura);
    QString b = QString::number(imcTotal);
    ui->outImc->setText(b);
    ui->outActualAltura->setText(m_altura);
    ui->outActualPeso->setText(m_peso);
    ui->outTexto->appendPlainText(allData2string());
            ui->statusbar->showMessage("Calculando datos " , 500);
    limpiar();
    }
}

void principal::dibujar()
{
    lienzo.fill(Qt::blue);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);



    // Dibujar segunda barra
    painter.drawRect(x+170, y+200, 100, 250);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+290,y+350,100,100);

}

void principal::limpiar()
{
    ui->inPeso->setText("");
    ui->inMetros->setText("");
    ui->inAnio->setValue(0);
    ui->inMes->setValue(0);
    ui->inDia->setValue(0);

}

void principal::guarar()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar archivo",
                                                         QDir::home().absolutePath(),

                                                         "Archivos de salarios (*.slr)");

    QFile archivo(nombreArchivo);
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream salida(&archivo);
        salida << ui->outTexto->toPlainText();
        ui->statusbar->showMessage("Datos almacenados en " + nombreArchivo, 5000);
    }else {
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar el archivo");
    }
    archivo.close();

}

QString principal::allData2string()
{
    QString str = "";
    str.append("Fecha: [" + QString::number(m_dia)+"/" + QString::number(m_mes)+"/"
    + QString::number(m_anio)+"] Peso:"+m_peso+" Altura"+ m_altura+ "\n");
    return str;
}



void principal::on_btnCalcular_clicked()
{
    Calcular();

}


void principal::on_actionGuardar_triggered()
{
    guarar();
}


void principal::on_actionCalcular_triggered()
{
    Calcular();
}


void principal::on_actionAbrir_ctr_a_triggered()
{
    QString nombreArchivo = QFileDialog::getOpenFileName(this,
                                                         "Abrir archivo",
                                                         QDir::home().absolutePath(),
                                                         "Archivos de salarios (*.slr)");
    QFile archivo(nombreArchivo);
    if(archivo.open(QFile::ReadOnly)){
        QTextStream entrada(&archivo);
        QString datos = entrada.readAll();
        ui->outTexto->clear();
        ui->outTexto->setPlainText(datos);
        ui->statusbar->showMessage("Datos leidos desde " + nombreArchivo, 500);
    }else {
        QMessageBox::warning(this,
                             "Abrir datos",
                             "No se pudo abrir el archivo");
    }
    archivo.close();
}


void principal::on_actionNuevo_triggered()
{
    limpiar();
    ui->outTexto->clear();
    ui->outImc->clear();
    ui->outActualAltura->clear();
    ui->outActualPeso->clear();
}


void principal::on_actionSalir_triggered()
{
    close();
}

