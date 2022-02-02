#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::principal)
{
    ui->setupUi(this);
    m_altura="";
    m_peso="";
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
    if(m_altura==""||m_peso==""){
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
    ui->outImc->setText(b);}
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

    // Dibujar primera barra
    painter.drawRect(x+10, y+10,10,40);

    // Crear un objeto color para el relleno
   // QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
   // QColor colorBorde(78,3,48);

    // Cambiar el color del pincel
   // pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
   // painter.setPen(pincel);

    // Establecer el color al brush (relleno)
  //  painter.setBrush(colorRelleno);

    // Dibujar segunda barra
  //  painter.drawRect(x+170, y+200, 100, 250);

    // Creando los colores de la tercera barra
  //  QColor cRellenoBarra3(253, 253, 115);
  //  QColor cBordeBarra3(174, 174, 51);
//
    // Estableciendo colores al puncel y al painter
  //  pincel.setColor(cBordeBarra3);
   // painter.setPen(pincel);
   // painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+290,y+350,100,100);
}



void principal::on_btnCalcular_clicked()
{
    Calcular();
}


void principal::on_actionGuardar_triggered()
{

}


void principal::on_actionCalcular_triggered()
{
    Calcular();
}

