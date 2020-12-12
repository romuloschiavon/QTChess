#ifndef VALIDMOVES_H
#define VALIDMOVES_H

#include "chessalgorithm.h"

#include <QObject>

class ValidMoves : public ChessAlgorithm
{
public:
    ValidMoves(QObject *parent = 0);
    bool move(int colFrom, int rankFrom, int colTo, int rankTo);

    //como eu não tenho classes especificas para cada uma das peças, terei que verificar em cada lance
    //qual lance será valido. Isso é um pouco pesado computacionalmente pois serão muitos ifs.
    //Se eu conseguir implementar um getType pro tipo da peça, assim fica mais fácil separar os validMoves para cada peça
    //Ou até mesmo criar 5 classes diferentes e nessas classes realizar as validações.
};

#endif // VALIDMOVES_H
