#ifndef INICIO_H
#define INICIO_H
#include "LogicGame/juego.h"
#include "LogicGame/gestor.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <cstdio>
#include <QMediaPlayer>
#include <QIcon>
//#include <QObject>
//#include <QtMultimedia>
#include <QAudioOutput>
QT_BEGIN_NAMESPACE
namespace Ui { class inicio; }
QT_END_NAMESPACE
class inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    void Ocultar(bool);
    void GenerateBotonera();
    void handleButton(int, int, bool = true, bool = true);
    void actualizarMapa();
    void List(gestor listado, QLabel** label);
    void createList(int MAX);
    void OcultarTodo();
    void generarArchivo(int, int, std::string);
    void SaveMovesGral(std::vector<std::pair<int , int>> aux, int i);
    void WinnerRoutine();
    void RoutineButonContinue();
    void RoutineStart();
    void EliminarGUI();
    ~inicio();

private slots:
    void on_ButonNewGame_clicked();

    void on_Buton_ADD_Date_clicked();

    void on_progressBar_valueChanged(int value);


    void on_Buton_ADD_Ship_released();



    void on_horizontalSlider_Size_sliderReleased();

    void on_Check_Box_Ships_Random_clicked(bool checked);

    void on_Check_Box_Pos_Random_clicked(bool checked);

    void on_start_combat_clicked();

    void on_pushButton_3_clicked();

    void on_ButonSave_clicked();

    void on_ButonLoadGame_clicked();

    void on_ExitButton_clicked();

    void on_play_stop_clicked();

private:
    int Ships;
    int SizeMap;
    int porcentaje;
    juego *BatallaNaval;
    QLabel *** labels;
    QPushButton ***buttons;
    QLabel ** listado1;
    QLabel ** listado2;
    Ui::inicio *ui;
    QAudioOutput *audioOutput;
    QMediaPlayer *player;
};

#endif // INICIO_H
