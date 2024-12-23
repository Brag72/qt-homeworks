#include "stopwatchclass.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent), timeElapsed(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        timeElapsed += 0.1;
        emit timeUpdated(timeElapsed);
    });
}

void Stopwatch::start() {
    timer->start(100);
}

void Stopwatch::stop() {
    timer->stop();
}

void Stopwatch::reset() {
    stop();
    timeElapsed = 0;
}

qreal Stopwatch::elapsedTime() const {
    return timeElapsed;
}
