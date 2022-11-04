#ifndef IRRLICHTWINDOW_H
#define IRRLICHTWINDOW_H

#include <QDialog>
#include <QTimer>

#include <irrlicht.h>

namespace Ui {
class IrrlichtWindow;
}

class IrrlichtWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IrrlichtWindow(QWidget *parent = nullptr);
    ~IrrlichtWindow();

private:
    Ui::IrrlichtWindow *ui;

    irr::SIrrlichtCreationParameters params;
    irr::IrrlichtDevice *device;
    irr::video::IVideoDriver *driver;
    irr::scene::ISceneManager *smgr;
    QTimer timer;

    void init_irr();

private slots:
    void timerSlot();
    void timerSetInterval(int millis);
};

#endif // IRRLICHTWINDOW_H
