#pragma once

#include "fractalcreator.h"

#include "worker.h"
#include <QThread>

#include <QMainWindow>
//#include <QWidget>
#include <QPushButton>
//#include <QSlider>
#include <QLabel>
//#include <QComboBox>
#include <QListWidget>
//#include <QProgressBar>
//#include <QPicture>



class VerticalBox : public QMainWindow {

    Q_OBJECT

public:
    VerticalBox(QWidget *parent = 0);

private slots:
    //void onClick();
    //void onCheck(int);

    //void onOkPressed();
    //void onApplyPressed();

    void drawBufferOnGUI(uint32_t* bufferOfImage);

    void stopInfiniteLoop();

    void finishButtonJobs();
    //void errorString(QString);

    /*
    void addItem();
    void renameItem();
    void removeItem();
    void clearItems();
    */

signals:
    void startFractalCreation();
    void drawingCompleted();
    void signalTermination();

private:

    //void displayFractal(std::string&& mode);

    void tryInfiniteLoop(std::string&& mode);

    /*
    QPushButton *clickBtn;
    QLabel *label;
    QSlider *slider;
    QComboBox *combo;
    */

    QThread* thread = new QThread;
    tmcvsp::FractalCreator* worker = new tmcvsp::FractalCreator();

    //tmcvsp::FractalCreator* fractalCreator;


    QImage img;
    QLabel *l;

    QLineEdit *xLocTextSingle;
    QLineEdit *yLocTextSingle;
    QLineEdit *scaleTextSingle;

    QLineEdit *xLocTextVideo;
    QLineEdit *yLocTextVideo;
    QLineEdit *scaleTextVideo;
    QLineEdit *scaleFactorTextVideo;
    QLineEdit *totalFramesTextVideo;

    /*
    QListWidget *lw;
    //QPushButton *start;
    QPushButton *add;
    QPushButton *rename;
    QPushButton *remove;
    QPushButton *removeAll;
    */

    QPushButton *startLoopSingle;
    QPushButton *startLoopVideo;
    QPushButton *stopLoopVideo;

    /*
    // For progress bar
    int progress;
    QTimer *timer;
    QProgressBar *pbar;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    static const int DELAY = 200;
    static const int MAX_VALUE = 100;
    */


    /*
    // Painting a number of ellipses
    QWidget *pwidget;
    */


    // Painting the Puff effect

    //QPicture pic;
    //QPainter* puffPainter;
    //QLabel* puffLabel;

    //int x;
    //qreal opacity;
    //int timerId;

    //void doPainting();




    //void updateBar();
    //void startMyTimer();
    //void stopMyTimer();






protected:
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void moveEvent(QMoveEvent *e);
    //void timerEvent(QTimerEvent *e);


    //void paintEvent(QPaintEvent *event);
    //void drawLines(QPainter *qp);


};
