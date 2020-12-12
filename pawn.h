#ifndef PAWN_H
#define PAWN_H

#include "chessalgorithm.h"
#include <QObject>

class Pawn : public ChessAlgorithm
{
public:
    Pawn(QObject *parent = 0);
    void newGame();
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);

private:
    QPoint m_pawn;
};

#endif // PAWN_H
