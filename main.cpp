#include "mainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QVector3D>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "foxmath.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);


    MainWindow w;
    w.show();

    return a.exec();
}
