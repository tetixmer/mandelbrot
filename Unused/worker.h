#include <QObject>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QAbstractEventDispatcher>

class Worker : public QObject {
    Q_OBJECT

public:
    Worker();
    ~Worker();

public slots:
    void process();
    void setTerminationFlag();

signals:
    void finished();
    void error(QString err);    

private:
    // add your variables here
    QMutex mutex;
    bool terminationRequested = false;
};
