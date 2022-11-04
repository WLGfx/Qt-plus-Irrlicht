#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace irr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&timer, SIGNAL(timeout()),
            this, SLOT(timerSlot()));
    timer.start(100);
    init_irr();
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),
            this, SLOT(timerSetInterval(int)));

    iwindow = new IrrlichtWindow(this);
    ui->mdiArea->addSubWindow(iwindow);
    iwindow->show();
    ui->mdiArea->tileSubWindows();
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            iwindow, SLOT(timerSetInterval(int)));
}

MainWindow::~MainWindow()
{
    delete iwindow;
    delete ui;
}

void MainWindow::init_irr() {
    params.DriverType = video::EDT_OPENGL;
    params.WindowId = (void*)ui->widget->winId();
    device = createDeviceEx(params);
    driver = device->getVideoDriver();
    smgr = device->getSceneManager();
}

void MainWindow::timerSlot() {
    if (!device->run()) return;

    driver->beginScene(true, true, video::SColor(255, 100, 100, 140));
    smgr->drawAll();
    driver->endScene();
}

void MainWindow::timerSetInterval(int millis) {
    timer.setInterval(millis);
}
