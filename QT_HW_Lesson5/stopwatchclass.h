#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    qreal elapsedTime() const;

signals:
    void timeUpdated(qreal seconds);

private:
    QTimer *timer;
    qreal timeElapsed;
};

#endif // STOPWATCH_H
