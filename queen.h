#ifndef QUEEN_H
#define QUEEN_H

#include "chessalgorithm.h"
#include <QObject>

class Queen : public ChessAlgorithm
{
public:
    Queen(QObject *parent = 0);
    void newGame();
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);

private:
    QPoint m_queen;
};

#endif // BISHOP_H
