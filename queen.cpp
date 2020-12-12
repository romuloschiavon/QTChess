#include "queen.h"
#include "chessboard.h"

Queen::Queen(QObject *parent) : ChessAlgorithm(parent)
{

}

void Queen::newGame()
{
    setupBoard();
    board()->setFen("rnbqkbnr/pp3ppp/8/8/8/8/PP3PPP/RNBQKBNR w KQkq - 0 1");
    // 'w' - white to move
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

bool Queen::move(int colFrom, int rankFrom, int colTo, int rankTo)
{
    if(currentPlayer() == NoPlayer) return false;

    // is there a piece of the right color?
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
        //
    }else if(colFrom == colTo || rankFrom == rankTo){
        return false;
    }if(colFrom != colTo && rankFrom == rankTo){
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
