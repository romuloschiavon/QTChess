#include "pawn.h"
#include "chessboard.h"

Pawn::Pawn(QObject *parent) : ChessAlgorithm(parent)
{

}

void Pawn::newGame()
{
    setupBoard();
    board()->setFen("rnbk1bnr/ppp1p1pp/8/1B6/8/8/PPP2PPP/RNB1K1NR w KQ - 0 1");
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

bool Pawn::move(int colFrom, int rankFrom, int colTo, int rankTo)
{
    if(currentPlayer() == NoPlayer) return false;

    // acertando a peça
    char source = board()->data(colFrom, rankFrom);
    if(currentPlayer() == Player1 && source != 'P') return false;
    if(currentPlayer() == Player2 && source != 'p') return false;

    char destination = board()->data(colTo, rankTo);
    if ((currentPlayer() == Player1) && (destination == 'P' || destination == 'N' || destination == 'B' || destination == 'Q' || destination == 'R' )) return false;
    if ((currentPlayer() == Player2) && (destination == 'p' || destination == 'n' || destination == 'b' || destination == 'q' || destination == 'r')) return false;
    if (destination == 'k') setResult(Player1Wins);
    if (destination == 'K') setResult(Player2Wins);
    if(colFrom == colTo && rankFrom == 2 && currentPlayer() == Player1){
        if(colFrom == colTo && rankTo <= 4){
            board()->movePiece(colFrom, rankFrom, colTo, rankTo);
            setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
            return true;
        }
    }else if(colFrom == colTo && rankFrom == 7 && currentPlayer() == Player2){
        if(colFrom == colTo && rankTo >= 5){
            board()->movePiece(colFrom, rankFrom, colTo, rankTo);
            setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
            return true;
        }
    }else if(colFrom == colTo && rankFrom == rankTo+1 && currentPlayer() == Player1){
        board()->movePiece(colFrom, rankFrom, colTo, rankTo);
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return true;
    }else if(colFrom == colTo && rankFrom == rankTo-1 && currentPlayer() == Player2){
        board()->movePiece(colFrom, rankFrom, colTo, rankTo);
        setCurrentPlayer(currentPlayer() == Player1 ? Player2 : Player1);
        return true;
    }
    return false;
}
