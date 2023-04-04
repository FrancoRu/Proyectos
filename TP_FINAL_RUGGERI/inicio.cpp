<<<<<<< HEAD
#include "inicio.h"
#include "ui_inicio.h"

inicio::inicio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inicio)
{
    this->porcentaje = 0;
    ui->setupUi(this);
    ui->widget_4->hide();
    ui->widget_2->hide();
    ui->widget_5->hide();
    ui->Tablero->hide();
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    ui->horizontalSlider_Size->setMinimum(5);
    ui->horizontalSlider_Size->setMaximum(16);
    ui->spinBox->setMinimum(5);
    ui->spinBox->setMaximum(16);

    ui->horizontalSlider_Ships_2->setMinimum(1);
    ui->horizontalSlider_Ships_2->setMaximum(7);
    ui->spinBox_2->setMinimum(1);
    ui->spinBox_2->setMaximum(7);
    ui->horizontalSlider_Size->singleStep();
    connect(ui->horizontalSlider_Size, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->horizontalSlider_Ships_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider_Size, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_Ships_2, SLOT(setValue(int)));

}

void inicio::loopSpin2(){
}

inicio::~inicio()
{
    delete ui;
}


void inicio::on_ButonNewGame_clicked()
{
    ui->widget_2->setHidden(false);
    ui->widget_3->hide();
}


void inicio::on_Buton_ADD_Date_clicked()
{
    if(ui->Line_Name_Input->text().toStdString()!=""){
        this->Ships = ui->spinBox_2->value();
        ui->widget_2->hide();
        ui->widget_4->setHidden(false);
    }
}


void inicio::on_progressBar_valueChanged(int value){
    ui->progressBar->setValue(value);
    if(value>=100){
        ui->widget_4->hide();
        ui->widget_5->setHidden(false);
    }
}




void inicio::on_Buton_ADD_Ship_released(){
    this->porcentaje+=100/this->Ships;
    on_progressBar_valueChanged(this->porcentaje);
}

void inicio::on_horizontalSlider_Size_sliderReleased(){
    int x = (ui->spinBox->value()/2)-1;
    ui->horizontalSlider_Ships_2->setMaximum(x);
    ui->spinBox_2->setMaximum(x);
}

=======
#include "inicio.h"
#include "ui_inicio.h"

inicio::inicio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inicio)
{
    this->porcentaje = 0;
    ui->setupUi(this);
    ui->widget_4->hide();
    ui->widget_2->hide();
    ui->widget_5->hide();
    ui->Tablero->hide();
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    ui->horizontalSlider_Size->setMinimum(5);
    ui->horizontalSlider_Size->setMaximum(16);
    ui->spinBox->setMinimum(5);
    ui->spinBox->setMaximum(16);

    ui->horizontalSlider_Ships_2->setMinimum(1);
    ui->horizontalSlider_Ships_2->setMaximum(7);
    ui->spinBox_2->setMinimum(1);
    ui->spinBox_2->setMaximum(7);
    ui->horizontalSlider_Size->singleStep();
    connect(ui->horizontalSlider_Size, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->horizontalSlider_Ships_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider_Size, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_Ships_2, SLOT(setValue(int)));

}

void inicio::loopSpin2(){
}

inicio::~inicio()
{
    delete ui;
}


void inicio::on_ButonNewGame_clicked()
{
    ui->widget_2->setHidden(false);
    ui->widget_3->hide();
}


void inicio::on_Buton_ADD_Date_clicked()
{
    if(ui->Line_Name_Input->text().toStdString()!=""){
        this->Ships = ui->spinBox_2->value();
        ui->widget_2->hide();
        ui->widget_4->setHidden(false);
    }
}


void inicio::on_progressBar_valueChanged(int value){
    ui->progressBar->setValue(value);
    if(value>=100){
        ui->widget_4->hide();
        ui->widget_5->setHidden(false);
    }
}




void inicio::on_Buton_ADD_Ship_released(){
    this->porcentaje+=100/this->Ships;
    on_progressBar_valueChanged(this->porcentaje);
}

void inicio::on_horizontalSlider_Size_sliderReleased(){
    int x = (ui->spinBox->value()/2)-1;
    ui->horizontalSlider_Ships_2->setMaximum(x);
    ui->spinBox_2->setMaximum(x);
}

>>>>>>> 3c4ee044a1ad98fad549525b4fa2ea720b6e3add
