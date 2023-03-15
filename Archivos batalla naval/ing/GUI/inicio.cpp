#include "inicio.h"
#include "qnamespace.h"
#include "ui_inicio.h"
inicio::inicio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inicio)
{
    ui->setupUi(this);

    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    // ...
    player->setSource(QUrl::fromLocalFile("sound/PiratasDelCaribe.mp3"));
    audioOutput->setVolume(100);
    player->play();
    player->loops();
    RoutineStart();
}

void inicio::Ocultar(bool checked){
    ui->LineCoorX->setDisabled(checked);
    ui->LineCoorY->setDisabled(checked);
    ui->BoxOrientacion->setDisabled(checked);
}

void inicio::GenerateBotonera(){
    int tam = ui->spinBox->value();
    this->buttons = new QPushButton**[tam];
    this->labels = new QLabel**[tam];
    bool state = tam >=10;
    ui->widget_6->setHidden(state);
    ui->widget_10->setHidden(!state);
    if(state){
        ui->widget_10->setStyleSheet("opacity: 0.75");
    }else{
        ui->widget_6->setStyleSheet("opacity: 0.75");
    }

    //RulesCss(this->buttons, this->labels);
    for(int i=0; i<tam; i++){
        this->buttons[i] = new QPushButton*[tam];
        this->labels[i] = new QLabel*[tam];
        for(int j=0; j<tam; j++){
            QPushButton* button = new QPushButton();
            this->buttons[i][j] = new QPushButton();
            this->labels[i][j] = new QLabel();
            connect(button, &QPushButton::released, this,[=]() { handleButton(i, j); });
            this->buttons[i][j] = button;
            if(state){
                ui->LayoutEsp1->addWidget(button, i, j);
                ui->LayoutEsp2->addWidget(this->labels[i][j], i, j);
            }else{
                ui->gridLayout_2->addWidget(button, i, j);
                ui->gridLayout_3->addWidget(this->labels[i][j], i, j);
            }
        }
    }
}

void inicio::handleButton(int i, int j, bool state, bool pl){
    if(state){
        this->buttons[i][j]->setDisabled(true);
        int rango = this->BatallaNaval->Pl(false).rangoMovimiento(false);
        this->BatallaNaval->battle(i+1, j+1, true);
        if(this->BatallaNaval->Pl(true).looser()!=this->BatallaNaval->Pl(false).looser()) WinnerRoutine();
        int jug = rand()%rango;
        std::pair<int, int> mov = this->BatallaNaval->Pl(false).getMovimiento(jug, false);
        this->BatallaNaval->Pl(false).DelMovimientoVec(jug, false);
        this->BatallaNaval->battle(mov.first, mov.second, false);
    }else{
        if(pl){
            this->BatallaNaval->battle(i, j, true, false);
            this->buttons[i-1][j-1]->setDisabled(true);
        }else this->BatallaNaval->battle(i, j, false, false);
    }
    if(this->BatallaNaval->Pl(true).looser()!=this->BatallaNaval->Pl(false).looser()) WinnerRoutine();
    actualizarMapa();

}
void inicio::WinnerRoutine(){
    !this->BatallaNaval->Pl(true).looser() ? ui->LabelDef->show() : ui->LabelWinn->show();
    ui->widget_10->hide();
    ui->pushButton_3->show();
}

void inicio::actualizarMapa(){
    char** mapa = this->BatallaNaval->Pl(true).mapi();
    char** mapa2 = this->BatallaNaval->Pl(false).mapi();
    int** mapilab = this->BatallaNaval->Pl(true).mapi2();
    int** mapilab2 = this->BatallaNaval->Pl(false).mapi2();
    int tam = ui->spinBox->value();
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            this->labels[i][j]->setText(QString::fromStdString(std::to_string(mapilab[i][j])));
            switch(mapa[i][j]){
            case '-':this->buttons[i][j]->setStyleSheet("background-color:white; color:black");
                break;
            case 'X': this->buttons[i][j]->setStyleSheet("background-color:red; color:black");
                this->buttons[i][j]->setDisabled(true);
                break;
            case 'O': this->buttons[i][j]->setStyleSheet("background-color:blue; color:black");
                break;
            }
            switch(mapa2[i][j]){
            case '-': this->labels[i][j]->setStyleSheet("background-color:white; color:black");
                break;
            case 'X': this->labels[i][j]->setStyleSheet("background-color:red; color:black");
                break;
            case 'O': this->labels[i][j]->setStyleSheet("background-color:blue; color:black");
                break;
            }
            if(mapilab2[i][j]==0&&mapa[i][j]=='-') this->buttons[i][j]->setStyleSheet("background-color:white; color:black");
            //RulesCss(this->buttons[i][j], this->labels[i][j]);
        }

    }
    List(this->BatallaNaval->Listado(true),this->listado1);
    List(this->BatallaNaval->Listado(false),this->listado2);
}
void inicio::List(gestor listado, QLabel **label){
    int MAX = listado.sizeShip();
    std::string nombre;
    for(int i=0; i<7; i++){
        label[i]->setText(NULL);
    }
    for(int i=0; i<MAX; i++){
        nombre = "Barco: "+listado.showList(i)->getNombre();
        label[i]->setText(QString::fromStdString(nombre));
    }
}

void inicio::createList(int MAX){
    this->listado1 = new QLabel*[MAX];
    this->listado2 = new QLabel*[MAX];
    bool state = ui->spinBox->value()>= 10;
    for(int i=0; i<MAX; i++){
        this->listado1[i] = new QLabel();
        this->listado2[i] = new QLabel();
        if(state){
            ui->verticalLayoutEsp1->addWidget(this->listado1[i], i);
            ui->verticalLayoutEsp2->addWidget(this->listado2[i], i);
        }else{
            ui->verticalLayout_2->addWidget(this->listado1[i], i);
            ui->verticalLayout_3->addWidget(this->listado2[i], i);
        }
    }
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
        this->BatallaNaval = new juego(ui->Line_Name_Input->text().toStdString(), ui->spinBox->value(), this->Ships);
        this->SizeMap = ui->spinBox->value();
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
    bool band;
    if(ui->Check_Box_Ships_Random->isChecked()){
        this->BatallaNaval->ingreso(1);
        band = true;
        this->porcentaje = 100;
    }else{
        std::string barco;
        if(ui->Check_Box_Pos_Random->isChecked()){
            barco = ui->BoxShips->currentText().toStdString();
            band = this->BatallaNaval->ingreso(2, barco);
        }else{
            int x = ui->LineCoorX->text().toInt();
            int y = ui->LineCoorY->text().toInt();
            if((x>0&&x<=ui->spinBox->value())&&(y>0&&y<=ui->spinBox->value())){
                barco = ui->BoxShips->currentText().toStdString();
                std::string ori = ui->BoxOrientacion->currentText().toStdString();
                band = this->BatallaNaval->ingreso(0, barco, x, y, ori[0]);
            }else band = false;
        }
    }
    if(band) this->porcentaje+=100/this->Ships;
    if(100-this->porcentaje<100/this->Ships) this->porcentaje = 100;
    on_progressBar_valueChanged(this->porcentaje);
    if(this->porcentaje==100){
        ui->widget_4->hide();
        ui->widget_5->show();
    }
}

void inicio::on_horizontalSlider_Size_sliderReleased(){
    int x = (ui->spinBox->value()/2)-1;
    ui->horizontalSlider_Ships_2->setMaximum(x);
    ui->spinBox_2->setMaximum(x);
}


void inicio::on_Check_Box_Ships_Random_clicked(bool checked){
    ui->BoxShips->setDisabled(checked);
    ui->Check_Box_Pos_Random->setDisabled(checked);
    on_Check_Box_Pos_Random_clicked(checked);
}


void inicio::on_Check_Box_Pos_Random_clicked(bool checked){
    Ocultar(checked);
}


void inicio::on_start_combat_clicked(){
    ui->widget_5->hide();
    ui->Tablero->setHidden(false);
    if(ui->spinBox->value()>=10){
        ui->widget_10->show();
    }else {
        ui->widget_8->show();
        ui->widget_7->show();
    }
    GenerateBotonera();
    createList(7);
    actualizarMapa();
}


void inicio::on_pushButton_3_clicked(){
    EliminarGUI();
    remove("jugadas.bin");
    remove("juego.bin");
    remove("MovEsp.bin");
    RoutineButonContinue();
    ui->widget_3->show();
}
void inicio::RoutineButonContinue(){
    ui->Line_Name_Input->setText(NULL);
    on_Check_Box_Ships_Random_clicked(false);
    ui->Check_Box_Ships_Random->setChecked(false);
    ui->Check_Box_Pos_Random->setChecked(false);
    ui->LineCoorX->setText(NULL);
    ui->LineCoorY->setText(NULL);
    disconnect(ui->horizontalSlider_Size, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    disconnect(ui->horizontalSlider_Ships_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    disconnect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider_Size, SLOT(setValue(int)));
    disconnect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_Ships_2, SLOT(setValue(int)));
    RoutineStart();
}

void inicio::RoutineStart(){
    ui->widget_10->show();
    ui->widget_6->show();
    ui->widget_8->show();
    ui->widget_9->show();
    ui->widget_2->hide();//
    ui->widget_4->hide();//
    ui->widget_5->hide();//
    ui->widget_7->hide();//
    ui->widget_10->hide();
    ui->LabelWinn->hide();//
    ui->LabelDef->hide();//
    ui->Tablero->hide();//
    ui->pushButton_3->hide();//
    this->porcentaje = 0;//
    ui->progressBar->setMinimum(0);//
    ui->progressBar->setMaximum(100);//
    ui->progressBar->setValue(0);//
    ui->horizontalSlider_Size->setMinimum(5);//
    ui->horizontalSlider_Size->setMaximum(16);//
    ui->spinBox->setMinimum(5);//
    ui->spinBox->setMaximum(16);//
    ui->horizontalSlider_Ships_2->setMinimum(1);//
    ui->horizontalSlider_Ships_2->setMaximum(7);//
    ui->spinBox_2->setMinimum(1);//
    ui->spinBox_2->setMaximum(ui->spinBox->value()/2-1);//
    ui->horizontalSlider_Size->singleStep();//
    connect(ui->horizontalSlider_Size, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->horizontalSlider_Ships_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider_Size, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_Ships_2, SLOT(setValue(int)));

}

void inicio::EliminarGUI(){
    for(int i=0; i<this->SizeMap;i++){
        for(int j=0; j<this->SizeMap;j++){
            delete  this->buttons[i][j];
            delete  this->labels[i][j];
        }
        if(i<this->Ships){
            delete this->listado1[i];
            delete this->listado2[i];
        }
        delete [] this->buttons[i];
        delete [] this->labels[i];
    }
    delete this->listado1;
    delete this->listado2;
    delete this->buttons;
    delete this->labels;
    delete this->BatallaNaval;
}

void inicio::on_ButonSave_clicked(){
    QMessageBox::information(this, "Exito", QString::fromStdString("Guardado Exitoso"));
    std::vector<std::pair<int , int>> aux, aux2;
    aux = this->BatallaNaval->Pl(true).getVec((true));
    aux2 = this->BatallaNaval->Pl(false).getVec((true));
    int i=0, j=0;
    while(i!=aux.size()||j!=aux2.size()){
        if(i!=aux.size()){
            SaveMovesGral(aux, i);
            i++;
        }
        if(j!=aux2.size()){
            SaveMovesGral(aux2, j);
            j++;
        }
    }
    this->BatallaNaval->Pl(true).deletevec(true);
    this->BatallaNaval->Pl(false).deletevec(true);
    this->BatallaNaval->GeneracionMapa();
}


void inicio::on_ButonLoadGame_clicked(){
    QString filtro = "Binary Files (*.bin)";
    QString filepath = QFileDialog::getOpenFileName(this, "Elija el archivo a cargar", ":/saves/", filtro);
    if(filepath.toStdString()!=""){
        QMessageBox::information(this, "ABRISTE", filepath);
        std::fstream archi(filepath.toStdString(), std::ios::in| std::ios::binary);
        std::fstream archi2("jugadas.bin", std::ios::in|std::ios::binary);
        std::fstream archi3("MovEsp.bin", std::ios::in|std::ios::binary);
        std::fstream archi4("LanchasDestruidas.bin", std::ios::in| std::ios::binary);
        NSave Jug;
        NShips Barcos;
        Npos tiradas;
        int CantLanchasPropias, CantLanchasEnemigas, cantidadJugadas, lanchasDestroy,lanchasDestroy2 ;
        if(archi.is_open()&&archi2.is_open()&&archi3.is_open()){
            std::string name;
            archi.read(reinterpret_cast<char*>(&Jug), sizeof(NSave));
            name = Jug.nombre;//nombre, int SizeMap, int Ships
            this->BatallaNaval= new juego(name, Jug.SizeMap, Jug.CantShip);
            this->Ships = Jug.CantShip;
            archi2.read(reinterpret_cast<char*>(&cantidadJugadas), sizeof(int));
            archi2.read(reinterpret_cast<char*>(&CantLanchasPropias), sizeof(int));
            archi2.read(reinterpret_cast<char*>(&CantLanchasEnemigas), sizeof(int));
            archi2.read(reinterpret_cast<char*>(&lanchasDestroy2), sizeof(int));
            archi2.read(reinterpret_cast<char*>(&lanchasDestroy), sizeof(int));
            int i=0;
            int j=0;
            int ContadorLanchas1 = 0;
            int ContadorLanchas2 = 0;
            int destroy = 0;
            int destroy2 = 0;
            bool state;
            while(i<Jug.CantShip*2){
                archi.read(reinterpret_cast<char*>(&Barcos), sizeof(NShips));
                state = i%2==0;
                if(state){
                    if(Barcos.Barco== 'L' && ContadorLanchas1<CantLanchasPropias){
                        archi3.seekg(sizeof(Npos)*ContadorLanchas1, std::ios::beg);
                        archi3.read(reinterpret_cast<char*>(&tiradas), sizeof(Npos));
                        this->BatallaNaval->ingresoCarga(tiradas.x, tiradas.y, Barcos.Ori, Barcos.Barco, state);
                        ContadorLanchas1++;
                    }else if(Barcos.Barco != 'L'){
                        this->BatallaNaval->ingresoCarga(Barcos.Posx, Barcos.Posy, Barcos.Ori, Barcos.Barco, state);
                    }else{
                        archi4.seekg(sizeof(Npos)*destroy, std::ios::beg);
                        archi4.read(reinterpret_cast<char*>(&tiradas), sizeof(Npos));
                        this->BatallaNaval->ingresoCarga(tiradas.x, tiradas.y, Barcos.Ori, Barcos.Barco, state);
                        destroy++;
                    }
                }else{
                    if(Barcos.Barco == 'L' && ContadorLanchas2<CantLanchasEnemigas){
                        archi3.seekg(sizeof(Npos)*CantLanchasPropias+sizeof(Npos)*(ContadorLanchas2), std::ios::beg);
                        archi3.read(reinterpret_cast<char*>(&tiradas), sizeof(Npos));
                        this->BatallaNaval->ingresoCarga(tiradas.x, tiradas.y, Barcos.Ori, Barcos.Barco, state);
                        ContadorLanchas2++;
                    }else if(Barcos.Barco != 'L'){
                        this->BatallaNaval->ingresoCarga(Barcos.Posx, Barcos.Posy, Barcos.Ori, Barcos.Barco, state);
                    }else{
                        archi4.seekg(sizeof(Npos)*lanchasDestroy+sizeof(Npos)*(destroy2), std::ios::beg);
                        archi4.read(reinterpret_cast<char*>(&tiradas), sizeof(Npos));
                        this->BatallaNaval->ingresoCarga(tiradas.x, tiradas.y, Barcos.Ori, Barcos.Barco, state);
                        destroy2++;
                    }
                }
                i++;
            }
            archi4.close();
            remove("LanchasDestruidas.bin");
            archi2.close();
            ui->widget_5->hide();
            ui->Tablero->hide();
            ui->widget_7->hide();
            ui->Line_Name_Input->setText(QString::fromStdString(name));
            ui->spinBox->setValue(Jug.SizeMap);
            ui->spinBox_2->setValue(Jug.CantShip);
            on_start_combat_clicked();
            while(j<cantidadJugadas){
                archi.read(reinterpret_cast<char*>(&tiradas), sizeof(Npos));
                state = (j%2==0);
                handleButton(tiradas.x, tiradas.y, false, state);
                j++;
            }
            archi3.close();
            actualizarMapa();
            ui->widget_3->hide();
            ui->widget_2->hide();
        }
    }else{
        QMessageBox::information(this, "Fallo", "Ningun Elemento seleccionado");
    }
}
inicio::~inicio(){
    delete ui;
}
void inicio::SaveMovesGral(std::vector<std::pair<int, int> > aux, int i){
    std::fstream archi("juego.bin", std::ios::out|std::ios::app|std::ios::binary);
    std::fstream archi3("juego.txt", std::ios::out|std::ios::app);
    Npos juego;
    juego.x = aux[i].first;
    juego.y = aux[i].second;
    archi.write(reinterpret_cast<char*>(&juego), sizeof(Npos));
    archi3<<"Coor X: "<<juego.x<<std::endl;
    archi3<<"Coor Y: "<<juego.y<<std::endl;
    archi.close();
    archi3.close();
}

void inicio::on_ExitButton_clicked(){
    EliminarGUI();
    exit(-1);
}

