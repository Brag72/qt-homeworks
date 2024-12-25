#include "stopwatchclass.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject(parent), m_timer(new QTimer(this)) {
    connect(m_timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

void Stopwatch::start() {
    if (!m_timer->isActive()) {
        m_timer->start(100); // Обновляем каждую 0.1 секунды
    }
}

void Stopwatch::stop() {
    if (m_timer->isActive()) {
        m_timer->stop();
    }
}

void Stopwatch::reset() {
    m_seconds = 0;
    emit timeChanged(m_seconds);
}

void Stopwatch::updateTime() {
    ++m_seconds;
    emit timeChanged(m_seconds);
}

// Новая реализация метода
int Stopwatch::getSeconds() const {
    return m_seconds;
}
