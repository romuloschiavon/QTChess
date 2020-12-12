#include "uciengine.h"

/* Aqui é a minha tentativa de integrar com a StockFish. A Ideia foi enviar a FEN atual do jogo para o stockfish
 * e assim o stockfish daria a resposta de uma FEN diferente com o seu movimento já calculado. Porém não consegui...

UciEngine::UciEngine(QObject *parent) : QObject(parent) {
    m_uciEngine = new QProcess(this);
    m_uciEngine->setReadChannel(QProcess::StandardOutput);
    connect(m_uciEngine, SIGNAL(readyRead()),
            SLOT(readFromEngine()));
}

void readFromEngine() {
    while(m_uciEngine->canReadLine()) {
        QString line = QString::fromLatin1(m_uciEngine-
                                           >readLine());
        emit messageReceived(line);
    }
}

*/
