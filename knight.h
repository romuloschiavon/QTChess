#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessalgorithm.h"
#include <QObject>

class Knight : public ChessAlgorithm
{
public:
    Knight(QObject *parent = 0);
    void newGame();
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);

private:
    QPoint m_knight;
};

#endif // KNIGHT_H
