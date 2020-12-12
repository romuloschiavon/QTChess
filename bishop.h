#ifndef BISHOP_H
#define BISHOP_H

#include "chessalgorithm.h"
#include <QObject>

class Bishop : public ChessAlgorithm
{
public:
    Bishop(QObject *parent = 0);
    void newGame();
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);

private:
    QPoint m_bishop;
};

#endif // BISHOP_H
