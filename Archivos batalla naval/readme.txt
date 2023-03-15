La carpeta sound se deberá incluir en el build, para que funcione la música.
En lo posible tener instalado el módulo qtMultimedia, si no eliminar o comentar variables:
en el .h:
#include <QAudioOutput>
#include <QMediaPlayer>
en el .cpp: 
player = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile("sound/PiratasDelCaribe.mp3"));
    audioOutput->setVolume(100);
    player->play();
    player->loops();