#include "irrlichtwindow.h"
#include "ui_irrlichtwindow.h"

using namespace irr;

IrrlichtWindow::IrrlichtWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IrrlichtWindow)
{
    ui->setupUi(this);

    params.DriverType = video::EDT_OPENGL;
    params.WindowId = (void*)winId();
    device = createDeviceEx(params);

    connect(&timer, SIGNAL(timeout()),
            this, SLOT(timerSlot()));
    timer.start(100);

    init_irr();
}

IrrlichtWindow::~IrrlichtWindow()
{
    device->drop();
    delete ui;
}

void IrrlichtWindow::init_irr() {
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
}

void IrrlichtWindow::timerSlot() {
    if (!device->run()) return;

    driver->beginScene(true, true, video::SColor(255, 100, 100, 140));
    smgr->drawAll();
    driver->endScene();
}

void IrrlichtWindow::timerSetInterval(int millis) {
    timer.setInterval(millis);
}
