#ifndef UCIENGINE_H
#define UCIENGINE_H

#include <QObject>
#include <QProcess>

class UciEngine : public QObject
{
    Q_OBJECT
public:
    UciEngine(QObject *parent = 0);

/* Aqui houve uma tentativa de implementar algo que pudesse finalmente conectar a StockFish Engine com o programa, no entanto não consegui
 *
 *
 *  public slots:
    void startEngine(const QString &enginePath) {
        m_uciEngine->start(enginePath);
    }
    void sendCommand(const QString &command) {
        m_uciEngine->write(command.toLatin1());
    }

private slots:
    void readFromEngine();

signals:
    void messageReceived(QString);

private:
    QProcess *m_uciEngine;

*/
};

#endif // UCIENGINE_H
