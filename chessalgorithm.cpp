#include "chessalgorithm.h"
#include "chessboard.h"

ChessAlgorithm::ChessAlgorithm(QObject *parent) : QObject(parent), m_board(0)
{
    m_currentPlayer = NoPlayer;
    m_result = NoResult;
}

ChessBoard *ChessAlgorithm::board() const
{
    return m_board;
}

void ChessAlgorithm::newGame()
{
    setupBoard();
    board()->setFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"); //FEN padrão para desenvolver o código
    setResult(NoResult);
    setCurrentPlayer(Player1);
}

void ChessAlgorithm::setupBoard()
{
    setBoard(new ChessBoard(8,8, this));
}


void ChessAlgorithm::setBoard(ChessBoard *board)
{
    if(board == m_board) return;
    if(m_board) delete m_board;
    m_board = board;
    emit boardChanged(m_board);
}


void ChessAlgorithm::setCurrentPlayer(ChessAlgorithm::Player value)
{
    if(currentPlayer() == value) {
        return;
    }
    m_currentPlayer = value;
    emit currentPlayerChanged(m_currentPlayer);
}


void ChessAlgorithm::setResult(Result value)
{
    if(result() == value) {
        return;
    }
    if(result() == NoResult) {
        m_result = value;
        emit gameOver(m_result);
    } else {
    m_result = value;
    }
}


bool ChessAlgorithm::move(int colFrom, int rankFrom, int colTo, int rankTo)
{
    Q_UNUSED(colFrom)
    Q_UNUSED(rankFrom)
    Q_UNUSED(colTo)
    Q_UNUSED(rankTo)
    return false;
}

bool ChessAlgorithm::move(const QPoint &from, const QPoint &to)
{
    return move(from.x(), from.y(), to.x(), to.y());
}

/*
 Tentativa de verificação de movimentos:
 *
 *
 * ROOK:
 * if(colFrom != colTo) return false;
 * if(rankFrom != rankTo) return false;
 * move(colFrom, rankFrom, colTo, rankTo);
 *
 * BISHOP:
 * ????? eu realmente não consegui implementar algo, pensei que para os bispos de casas pretas eles sempre vão
 * estar em casas que são por exemplo Col+Rank % 2 = 0. Mas nesse sentido o bispo pode teleportar para qualquer
 * casa que dividindo por 2 dê resto 0 e não somente para as casas da sua mesma diagonal. Enfim realmente não sei o que fazer
 * kkkkkkkkk :X
 *
 * Pawn:
 * if(colFrom = 1 || colFrom = 6) ele pode se mover 2 casas
 * e aqui deveriamos implementar a verificação de caso haja alguem em uma casa na diagonal é possível capturar
 * também tem a regra do en passant, mas essa é muito compelxa.
 * mas pra uma regra geral sem o enPassant, podemos dizer que o peao sempre vai se movimentar rank+1 se ele for branco ou rank-1 se ele
 * for um peão negro.
 *
 * Queen:
 * rook + bishop
 *
 * King:
 * Implementar CHECK é muito complexo, porém sem usar o CHEQUE é bem tranquilo afinal ele só se move uma casa sempre.
 * Implementar também o ROQUE. if(board()->data(colFrom, rankFrom) = 'K' && board()->data(0,0) = 'R' && não tiver nenhuma outra peça
 * no caminho (checar se a data do 0,5 e 0,6 == ' '){
 * move(colFrom, rankFrom, 0, 6)
 * move(0, 7, 0, 5)
 * } Esse aqui seria o roque do kingsidd
 * ou seja, mover duas peças ao mesmo tempo.
 *
 *
 * PROMOÇÃO DE PEÃO (verificar toda vez que um peão se mover)
 * sabendo que o peão é branco ou negro
 * if(colTo = 0 && colTo = 7) primeira ou ultima coluna
 * m_view->setPiece('Q', QIcon(":images/damabranca.svg")); Colocar pra somente evoluir para dama para facilitar, no entanto em um jogo
 * real deve-se ser possível "evoluir" para qualquer peça (além de peão)
 * update();
 * setCurrentPlayer() (passa a vez)
 *
 * EnPassant, Roque e etc...
 *
 * Eu realmente pensei em como implementar cada um desses, mas eu fiquei bastante perdido, tentei procurar alguns tutoriais,
 * bibliografias, ou até códigos já implementados no github. Mas todos implementaram o jogo em si de uma maneira diferente da minha
 * então ficou muito complicado tentar implementar.
*/
