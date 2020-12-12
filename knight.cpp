#include "knight.h"
#include "chessboard.h"

Knight::Knight(QObject *parent) : ChessAlgorithm(parent)
{

}

void Knight::newGame()
{
    setupBoard();
    board()->setFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

bool Knight::move(int colFrom, int rankFrom, int colTo, int rankTo)
{
    if(currentPlayer() == NoPlayer) return false;

    // is there a piece of the right color?
    char source = board()->data(colFrom, rankFrom);
    if(currentPlayer() == Player1 && source != 'N') return false;
    if(currentPlayer() == Player2 && source != 'n') return false;

    char destination = board()->data(colTo, rankTo);
    if ((currentPlayer() == Player1) && (destination == 'P' || destination == 'N' || destination == 'B' || destination == 'Q' || destination == 'R' )) return false;
    if ((currentPlayer() == Player2) && (destination == 'p' || destination == 'n' || destination == 'b' || destination == 'q' || destination == 'r')) return false;
    if (destination == 'k') setResult(Player1Wins);
    if (destination == 'K') setResult(Player2Wins);
    //
    if((colFrom == colTo-1 || colFrom == colTo+1) && (rankFrom == rankTo+2 || rankFrom == rankTo-2)){
        board()->movePiece(colFrom, rankFrom, colTo, rankTo);
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return true;
    } else if((colFrom == colTo+2 || colFrom == colTo-2) && (rankFrom == rankTo+1 || rankFrom == rankTo-1)){
        board()->movePiece(colFrom, rankFrom, colTo, rankTo);
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return true;
    }else
        return false;

}
