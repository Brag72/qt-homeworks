#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject {
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();

    int getSeconds() const; // Новый метод для доступа к текущему времени

signals:
    void timeChanged(int seconds);

private slots:
    void updateTime();

private:
    int m_seconds = 0;
    QTimer* m_timer;
};

#endif // STOPWATCH_H
