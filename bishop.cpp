#include "bishop.h"
#include "chessboard.h"

Bishop::Bishop(QObject *parent) : ChessAlgorithm(parent)
{

}

void Bishop::newGame()
{
    setupBoard();
    board()->setFen("rnbk1bnr/ppp1p1pp/8/1B6/8/8/PPP2PPP/RNB1K1NR w KQ - 0 1");
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

bool Bishop::move(int colFrom, int rankFrom, int colTo, int rankTo)
{
    if(currentPlayer() == NoPlayer) return false;

    // acertando a peça
    char source = board()->data(colFrom, rankFrom);
    if(currentPlayer() == Player1 && source != 'B') return false;
    if(currentPlayer() == Player2 && source != 'b') return false;

    char destination = board()->data(colTo, rankTo);
    if ((currentPlayer() == Player1) && (destination == 'P' || destination == 'N' || destination == 'B' || destination == 'Q' || destination == 'R' )) return false;
    if ((currentPlayer() == Player2) && (destination == 'p' || destination == 'n' || destination == 'b' || destination == 'q' || destination == 'r')) return false;
    if (destination == 'k') setResult(Player1Wins);
    if (destination == 'K') setResult(Player2Wins);
    //
    if(colFrom != colTo && rankFrom != rankTo){
        //if(colFrom + rankFrom == colTo + rankTo){
            board()->movePiece(colFrom, rankFrom, colTo, rankTo);
            setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
            return true;
        //}
    }else if(colFrom == colTo || rankFrom == rankTo){
        return false;
    }else
        return false;
}
