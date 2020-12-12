#ifndef ROOK_H
#define ROOK_H

#include "chessalgorithm.h"
#include <QObject>

class ChessBoard;

class Rook : public ChessAlgorithm
{
public:
    Rook(QObject *parent = 0);
    void newGame();
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);

private:
    QPoint m_rook;
};

#endif // ROOK_H
