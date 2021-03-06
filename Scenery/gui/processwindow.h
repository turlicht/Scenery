#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H

#include "process/process.h"
#include <QWidget>

namespace Ui {
class ProcessWindow;
}

class ProcessWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit ProcessWindow(Process *process, QString file, QWidget *parent = 0);
    ~ProcessWindow();

protected:
    void closeEvent(QCloseEvent * );
    
private:
    Ui::ProcessWindow *ui;
    Process *process;
    QString file;

public slots:
    void loadParam();
    void saveParam();

    void slotMode(QString mode);
    void slotColorRangeParam();
    void slotMotionParam();
    void slotHaarFile(int index);
    void slotHaarParam();
    void slotContourParam();
    void slotHoughCircleParam();

    void slotClusterMode(QString mode);
    void slotClusterSimple();
    void slotClusterTable();
    void slotSeqArea();
    void slotFilterSeqArea();
    void slotTransform2D();

};

#endif // PROCESSWINDOW_H
