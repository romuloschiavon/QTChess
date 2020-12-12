#include "basepiece.h"

BasePiece::BasePiece(QObject *)
{
    m_piece = ' ';
}

char BasePiece::getPiece(int colFrom, int rankFrom)
{
    return m_piece = board()->data(colFrom, rankFrom);
}
