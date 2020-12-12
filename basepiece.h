#ifndef BASEPIECE_H
#define BASEPIECE_H

#include "chessalgorithm.h"
#include <QObject>

class ChessBoard{

class BasePiece : public ChessAlgorithm
{
    Q_OBJECT
public:
    BasePiece(QObject *parent = 0);
    char getPiece(int colFrom, int rankFrom);

private:
    char m_piece;
};

};
#endif // BASEPIECE_H
