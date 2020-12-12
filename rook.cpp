#include "rook.h"
#include "chessboard.h"

Rook::Rook(QObject *parent) : ChessAlgorithm(parent)
{

}

void Rook::newGame()
{
    setupBoard();
    board()->setFen("rp2k1pr/p6p/8/8/8/8/P6P/RP2K1PR w KQkq - 0 1");
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

bool Rook::move(int colFrom, int rankFrom, int colTo, int rankTo)
{
    if(currentPlayer() == NoPlayer) return false;

    // acertando a peça
    char source = board()->data(colFrom, rankFrom);
    if(currentPlayer() == Player1 && source != 'R') return false;
    if(currentPlayer() == Player2 && source != 'r') return false;

    char destination = board()->data(colTo, rankTo);
    if ((currentPlayer() == Player1) && (destination == 'P' || destination == 'N' || destination == 'B' || destination == 'Q' || destination == 'R' )) return false;
    if ((currentPlayer() == Player2) && (destination == 'p' || destination == 'n' || destination == 'b' || destination == 'q' || destination == 'r')) return false;
    if (destination == 'k') setResult(Player1Wins);
    if (destination == 'K') setResult(Player2Wins);
    //
    if(colFrom != colTo && rankFrom == rankTo){
        board()->movePiece(colFrom, rankFrom, colTo, rankTo);
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return true;
    } else if (colFrom == colTo && rankFrom != rankTo){
        board()->movePiece(colFrom, rankFrom, colTo, rankTo);
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return true;
    } else
        return false;
}
