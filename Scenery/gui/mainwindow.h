#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

#include "manager.h"
#include "processwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(Manager *manager, QWidget *parent = 0);
    ~MainWindow();

    void saveControls(Scene *scene, QString file, int state, QString name);
    void loadControls(Scene *scene, QString file, int state);
    QStringList loadControlsStates(Scene *scene, QString file);

protected:
    void closeEvent(QCloseEvent *);
    void timerEvent(QTimerEvent *);

private:
    Ui::MainWindow *ui;
    Manager *manager;
    ProcessWindow *processWindow;
    int curState;

    void loadSettings();
    void addState(QString name);
    void delState(int n);


public slots:
    void changeScene(int n);
    void changeState(int n);

    void setFullScreen(bool full);
    void slotSaveControls();
    void slotLoadControls();
    void slotAddState();
    void slotDelState();

};

#endif // MAINWINDOW_H
