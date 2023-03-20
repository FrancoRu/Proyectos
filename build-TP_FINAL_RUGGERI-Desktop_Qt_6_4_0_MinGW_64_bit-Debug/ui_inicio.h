/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_7;
    QSlider *horizontalSlider_Size;
    QSpinBox *spinBox;
    QLabel *label_8;
    QSlider *horizontalSlider_Ships_2;
    QSpinBox *spinBox_2;
    QPushButton *Buton_ADD_Date;
    QLineEdit *Line_Name_Input;
    QWidget *widget_4;
    QFormLayout *formLayout;
    QCheckBox *Check_Box_Pos_Random;
    QLabel *label_4;
    QComboBox *BoxShips;
    QLabel *label_3;
    QLineEdit *LineCoorY;
    QLabel *label_5;
    QLineEdit *LineCoorX;
    QLabel *label_6;
    QComboBox *BoxOrientacion;
    QProgressBar *progressBar;
    QPushButton *Buton_ADD_Ship;
    QCheckBox *Check_Box_Ships_Random;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QPushButton *ButonNewGame;
    QPushButton *ButonLoadGame;
    QWidget *widget_5;
    QPushButton *start_combat;
    QWidget *Tablero;
    QWidget *widget_6;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QWidget *widget_7;
    QPushButton *ButonSave;
    QWidget *widget_8;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *LabelDef;
    QLabel *LabelWinn;
    QPushButton *pushButton_3;
    QWidget *widget_10;
    QWidget *gridLayoutWidget_3;
    QGridLayout *LayoutEsp1;
    QWidget *gridLayoutWidget_4;
    QGridLayout *LayoutEsp2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayoutEsp1;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayoutEsp2;
    QPushButton *ExitButton;
    QPushButton *play_stop;
    QLabel *LabelNombre;
    QWidget *widget_11;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QProgressBar *HP_ALIADO;
    QProgressBar *HP_ENEMIGO;

    void setupUi(QMainWindow *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName("inicio");
        inicio->resize(1024, 600);
        inicio->setMinimumSize(QSize(1024, 600));
        inicio->setMaximumSize(QSize(1024, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Im\303\241genes/images.png"), QSize(), QIcon::Normal, QIcon::Off);
        inicio->setWindowIcon(icon);
        centralwidget = new QWidget(inicio);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1024, 600));
        centralwidget->setMaximumSize(QSize(1024, 600));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1024, 600));
        widget->setMinimumSize(QSize(1024, 600));
        widget->setMaximumSize(QSize(1024, 600));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1024, 600));
        label->setMinimumSize(QSize(1024, 600));
        label->setMaximumSize(QSize(1024, 576));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/world-of-warships-legends-llega-a-la-consola-con-acceso-temprano-en-todo-el-mundo-frikigamers.com_.jpg-1024x576.jpg")));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 420, 273, 134));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 0, 1, 2);

        horizontalSlider_Size = new QSlider(widget_2);
        horizontalSlider_Size->setObjectName("horizontalSlider_Size");
        horizontalSlider_Size->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_Size, 1, 2, 1, 1);

        spinBox = new QSpinBox(widget_2);
        spinBox->setObjectName("spinBox");

        gridLayout->addWidget(spinBox, 1, 3, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 2, 0, 1, 2);

        horizontalSlider_Ships_2 = new QSlider(widget_2);
        horizontalSlider_Ships_2->setObjectName("horizontalSlider_Ships_2");
        horizontalSlider_Ships_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_Ships_2, 2, 2, 1, 1);

        spinBox_2 = new QSpinBox(widget_2);
        spinBox_2->setObjectName("spinBox_2");

        gridLayout->addWidget(spinBox_2, 2, 3, 1, 1);

        Buton_ADD_Date = new QPushButton(widget_2);
        Buton_ADD_Date->setObjectName("Buton_ADD_Date");

        gridLayout->addWidget(Buton_ADD_Date, 3, 1, 1, 2);

        Line_Name_Input = new QLineEdit(widget_2);
        Line_Name_Input->setObjectName("Line_Name_Input");

        gridLayout->addWidget(Line_Name_Input, 0, 1, 1, 3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 330, 258, 221));
        formLayout = new QFormLayout(widget_4);
        formLayout->setObjectName("formLayout");
        Check_Box_Pos_Random = new QCheckBox(widget_4);
        Check_Box_Pos_Random->setObjectName("Check_Box_Pos_Random");

        formLayout->setWidget(1, QFormLayout::SpanningRole, Check_Box_Pos_Random);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        BoxShips = new QComboBox(widget_4);
        BoxShips->addItem(QString());
        BoxShips->addItem(QString());
        BoxShips->addItem(QString());
        BoxShips->addItem(QString());
        BoxShips->addItem(QString());
        BoxShips->setObjectName("BoxShips");
        BoxShips->setEnabled(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, BoxShips);

        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        LineCoorY = new QLineEdit(widget_4);
        LineCoorY->setObjectName("LineCoorY");

        formLayout->setWidget(3, QFormLayout::FieldRole, LineCoorY);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        LineCoorX = new QLineEdit(widget_4);
        LineCoorX->setObjectName("LineCoorX");

        formLayout->setWidget(4, QFormLayout::FieldRole, LineCoorX);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        BoxOrientacion = new QComboBox(widget_4);
        BoxOrientacion->addItem(QString());
        BoxOrientacion->addItem(QString());
        BoxOrientacion->setObjectName("BoxOrientacion");

        formLayout->setWidget(5, QFormLayout::FieldRole, BoxOrientacion);

        progressBar = new QProgressBar(widget_4);
        progressBar->setObjectName("progressBar");
        progressBar->setMouseTracking(false);
        progressBar->setValue(0);
        progressBar->setFormat(QString::fromUtf8("%p%"));

        formLayout->setWidget(6, QFormLayout::LabelRole, progressBar);

        Buton_ADD_Ship = new QPushButton(widget_4);
        Buton_ADD_Ship->setObjectName("Buton_ADD_Ship");

        formLayout->setWidget(6, QFormLayout::FieldRole, Buton_ADD_Ship);

        Check_Box_Ships_Random = new QCheckBox(widget_4);
        Check_Box_Ships_Random->setObjectName("Check_Box_Ships_Random");

        formLayout->setWidget(0, QFormLayout::SpanningRole, Check_Box_Ships_Random);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 480, 150, 80));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        ButonNewGame = new QPushButton(widget_3);
        ButonNewGame->setObjectName("ButonNewGame");
        ButonNewGame->setStyleSheet(QString::fromUtf8("  min-width: 130px;\n"
"  height: 40px;\n"
"  color: #fff;\n"
"  padding: 5px 10px;\n"
"  font-weight: bold;\n"
"  cursor: pointer;\n"
"  transition: all 0.3s ease;\n"
"  position: relative;\n"
"  display: inline-block;\n"
"  outline: none;\n"
"  border-radius: 20px;\n"
"  border: 2px solid #212529;\n"
"  background: #212529;"));

        verticalLayout->addWidget(ButonNewGame);

        ButonLoadGame = new QPushButton(widget_3);
        ButonLoadGame->setObjectName("ButonLoadGame");
        ButonLoadGame->setStyleSheet(QString::fromUtf8("  min-width: 130px;\n"
"  height: 40px;\n"
"  color: #fff;\n"
"  padding: 5px 10px;\n"
"  font-weight: bold;\n"
"  cursor: pointer;\n"
"  transition: all 0.3s ease;\n"
"  position: relative;\n"
"  display: inline-block;\n"
"  outline: none;\n"
"  border-radius: 20px;\n"
"  border: 2px solid #212529;\n"
"  background: #212529;"));

        verticalLayout->addWidget(ButonLoadGame);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(0, 440, 311, 111));
        start_combat = new QPushButton(widget_5);
        start_combat->setObjectName("start_combat");
        start_combat->setGeometry(QRect(9, 43, 271, 81));
        start_combat->setStyleSheet(QString::fromUtf8("  min-width: 130px;\n"
"  height: 40px;\n"
"  color: #fff;\n"
"  padding: 5px 10px;\n"
"  font-weight: bold;\n"
"  cursor: pointer;\n"
"  transition: all 0.3s ease;\n"
"  position: relative;\n"
"  display: inline-block;\n"
"  outline: none;\n"
"  border-radius: 20px;\n"
"  border: 2px solid #212529;\n"
"  background: #212529;"));
        Tablero = new QWidget(widget);
        Tablero->setObjectName("Tablero");
        Tablero->setGeometry(QRect(0, 0, 1024, 600));
        Tablero->setMinimumSize(QSize(1024, 600));
        Tablero->setMaximumSize(QSize(1024, 600));
        widget_6 = new QWidget(Tablero);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(0, 0, 1024, 300));
        widget_6->setMinimumSize(QSize(0, 300));
        widget_6->setMaximumSize(QSize(1024, 300));
        widget_6->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget = new QWidget(widget_6);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 10, 521, 291));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 3);
        gridLayoutWidget_2 = new QWidget(widget_6);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(540, 10, 481, 291));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 3);
        widget_7 = new QWidget(Tablero);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(900, 300, 120, 64));
        ButonSave = new QPushButton(widget_7);
        ButonSave->setObjectName("ButonSave");
        ButonSave->setGeometry(QRect(20, 10, 81, 31));
        widget_8 = new QWidget(Tablero);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(540, 310, 171, 125));
        verticalLayoutWidget = new QWidget(widget_8);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 171, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        widget_9 = new QWidget(Tablero);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(720, 310, 171, 125));
        verticalLayoutWidget_2 = new QWidget(widget_9);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 171, 121));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        LabelDef = new QLabel(widget);
        LabelDef->setObjectName("LabelDef");
        LabelDef->setGeometry(QRect(0, 0, 1024, 600));
        LabelDef->setMinimumSize(QSize(1024, 600));
        LabelDef->setMaximumSize(QSize(1024, 600));
        LabelDef->setPixmap(QPixmap(QString::fromUtf8(":/images/ImgDefeatRev.jpg")));
        LabelWinn = new QLabel(widget);
        LabelWinn->setObjectName("LabelWinn");
        LabelWinn->setGeometry(QRect(0, 0, 1024, 600));
        LabelWinn->setMinimumSize(QSize(1024, 600));
        LabelWinn->setMaximumSize(QSize(1024, 600));
        LabelWinn->setPixmap(QPixmap(QString::fromUtf8(":/images/ImgVictoriRev.jpg")));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 420, 154, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("  min-width: 130px;\n"
"  height: 40px;\n"
"  color: #fff;\n"
"  padding: 5px 10px;\n"
"  font-weight: bold;\n"
"  cursor: pointer;\n"
"  transition: all 0.3s ease;\n"
"  position: relative;\n"
"  display: inline-block;\n"
"  outline: none;\n"
"  border-radius: 20px;\n"
"  border: 2px solid #212529;\n"
"  background: #212529;"));
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(60, 10, 850, 430));
        widget_10->setMinimumSize(QSize(850, 430));
        widget_10->setMaximumSize(QSize(850, 430));
        gridLayoutWidget_3 = new QWidget(widget_10);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 581, 311));
        LayoutEsp1 = new QGridLayout(gridLayoutWidget_3);
        LayoutEsp1->setObjectName("LayoutEsp1");
        LayoutEsp1->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_4 = new QWidget(widget_10);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(590, 0, 261, 311));
        LayoutEsp2 = new QGridLayout(gridLayoutWidget_4);
        LayoutEsp2->setObjectName("LayoutEsp2");
        LayoutEsp2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(widget_10);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(0, 310, 581, 121));
        verticalLayoutEsp1 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayoutEsp1->setObjectName("verticalLayoutEsp1");
        verticalLayoutEsp1->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(widget_10);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(590, 310, 261, 121));
        verticalLayoutEsp2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayoutEsp2->setObjectName("verticalLayoutEsp2");
        verticalLayoutEsp2->setContentsMargins(0, 0, 0, 0);
        ExitButton = new QPushButton(widget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(0, 560, 154, 24));
        ExitButton->setMinimumSize(QSize(154, 24));
        ExitButton->setMaximumSize(QSize(40, 24));
        ExitButton->setStyleSheet(QString::fromUtf8("  min-width: 130px;\n"
"  height: 40px;\n"
"  color: #fff;\n"
"  padding: 5px 10px;\n"
"  font-weight: bold;\n"
"  cursor: pointer;\n"
"  transition: all 0.3s ease;\n"
"  position: relative;\n"
"  display: inline-block;\n"
"  outline: none;\n"
"  border-radius: 20px;\n"
"  border: 2px solid #212529;\n"
"  background: #212529;"));
        play_stop = new QPushButton(widget);
        play_stop->setObjectName("play_stop");
        play_stop->setGeometry(QRect(930, 560, 51, 22));
        play_stop->setMinimumSize(QSize(51, 22));
        play_stop->setMaximumSize(QSize(51, 22));
        play_stop->setIconSize(QSize(51, 22));
        LabelNombre = new QLabel(widget);
        LabelNombre->setObjectName("LabelNombre");
        LabelNombre->setGeometry(QRect(0, 460, 211, 21));
        LabelNombre->setStyleSheet(QString::fromUtf8("font-family: \"Arial Black\", Gadget, sans-serif;\n"
"font-size: 14px;\n"
"letter-spacing: 0px;\n"
"word-spacing: 2px;\n"
"color: #000000;\n"
"font-weight: normal;\n"
"text-decoration: none;\n"
"font-style: normal;\n"
"font-variant: normal;\n"
"text-transform: none;\n"
"background-color: #0744d5;"));
        widget_11 = new QWidget(widget);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, 480, 120, 71));
        formLayoutWidget = new QWidget(widget_11);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(0, 0, 122, 132));
        formLayout_3 = new QFormLayout(formLayoutWidget);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName("label_10");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_10);

        HP_ALIADO = new QProgressBar(formLayoutWidget);
        HP_ALIADO->setObjectName("HP_ALIADO");
        HP_ALIADO->setStyleSheet(QString::fromUtf8(""));
        HP_ALIADO->setValue(24);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, HP_ALIADO);

        HP_ENEMIGO = new QProgressBar(formLayoutWidget);
        HP_ENEMIGO->setObjectName("HP_ENEMIGO");
        HP_ENEMIGO->setValue(24);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, HP_ENEMIGO);

        inicio->setCentralWidget(centralwidget);

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QMainWindow *inicio)
    {
        inicio->setWindowTitle(QCoreApplication::translate("inicio", "inicio", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("inicio", "Nombre:", nullptr));
        label_7->setText(QCoreApplication::translate("inicio", "Tama\303\261o del Mapa", nullptr));
        label_8->setText(QCoreApplication::translate("inicio", "Cantidad de Barcos", nullptr));
        Buton_ADD_Date->setText(QCoreApplication::translate("inicio", "Cargar datos", nullptr));
        Check_Box_Pos_Random->setText(QCoreApplication::translate("inicio", "Posicionamiento aleatorio", nullptr));
        label_4->setText(QCoreApplication::translate("inicio", "Barcos Disponibles", nullptr));
        BoxShips->setItemText(0, QCoreApplication::translate("inicio", "Portaaviones", nullptr));
        BoxShips->setItemText(1, QCoreApplication::translate("inicio", "Destructor", nullptr));
        BoxShips->setItemText(2, QCoreApplication::translate("inicio", "Crucero", nullptr));
        BoxShips->setItemText(3, QCoreApplication::translate("inicio", "Submarino", nullptr));
        BoxShips->setItemText(4, QCoreApplication::translate("inicio", "Lancha de Combate", nullptr));

        label_3->setText(QCoreApplication::translate("inicio", "Coordenada X:", nullptr));
        label_5->setText(QCoreApplication::translate("inicio", "Coordenada Y:", nullptr));
        label_6->setText(QCoreApplication::translate("inicio", "Orientacion:", nullptr));
        BoxOrientacion->setItemText(0, QCoreApplication::translate("inicio", "Horizontal", nullptr));
        BoxOrientacion->setItemText(1, QCoreApplication::translate("inicio", "Vertical", nullptr));

        Buton_ADD_Ship->setText(QCoreApplication::translate("inicio", "Cargar Barco", nullptr));
        Check_Box_Ships_Random->setText(QCoreApplication::translate("inicio", "Barcos aleatorios", nullptr));
        ButonNewGame->setText(QCoreApplication::translate("inicio", "Nuevo Juego", nullptr));
        ButonLoadGame->setText(QCoreApplication::translate("inicio", "Cargar Partida", nullptr));
        start_combat->setText(QCoreApplication::translate("inicio", "COMENZAR BATALLA", nullptr));
        ButonSave->setText(QCoreApplication::translate("inicio", "Guardar", nullptr));
        LabelDef->setText(QString());
        LabelWinn->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("inicio", "Continuar", nullptr));
        ExitButton->setText(QCoreApplication::translate("inicio", "Salir", nullptr));
        play_stop->setText(QString());
        LabelNombre->setText(QString());
        label_9->setText(QCoreApplication::translate("inicio", "HP A", nullptr));
        label_10->setText(QCoreApplication::translate("inicio", "HP E", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
