#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <irrlicht.h>

#include "irrlichtwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    IrrlichtWindow *iwindow;

    irr::SIrrlichtCreationParameters params;
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver *driver;
    irr::scene::ISceneManager *smgr;
    QTimer timer;

    void init_irr();

public slots:
    void timerSlot();
    void timerSetInterval(int millis);
};
#endif // MAINWINDOW_H
