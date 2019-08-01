#include "worker.h"
#include <iostream>

// --- CONSTRUCTOR ---
Worker::Worker() {
    // you could copy data from constructor arguments to internal variables here.
}

// --- DECONSTRUCTOR ---
Worker::~Worker() {
    std::cout << "Worker thread: Worker destroyed." << std::endl;
    // free resources
}

// --- PROCESS ---
// Start processing data.
void Worker::process() {
    // allocate resources using new here
    while ( true ) {
        mutex.lock();

        if ( terminationRequested ) {
            mutex.unlock();
            break;
        }

        //std::cout << " HI" << std::endl;


        mutex.unlock();
        QAbstractEventDispatcher::instance(QThread::currentThread())->processEvents(QEventLoop::AllEvents);
    }


    emit finished();

}

void Worker::setTerminationFlag() {
    QMutexLocker locker(&mutex);
    terminationRequested = true;
    std::cout << "Worker thread: Termination flag set successfully." << std::endl;
}
