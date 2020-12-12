#include "mainwindow.h"
#include "chessboard.h"
#include "chessview.h"
#include "chessalgorithm.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_selectedField(0)
{
    ui->setupUi(this);
    //implementando a chessview
    m_view = new ChessView;
    //fazendo funcionar o click usando uma função clicked e não o *event
    connect(m_view, &ChessView::clicked,
            this, &MainWindow::viewClicked);

    //colocando as peças
    m_view->setPiece('P', QIcon(":/images/peaobranco.svg")); // Peao
    m_view->setPiece('K', QIcon(":/images/reibranco.svg")); // Rei
    m_view->setPiece('Q', QIcon(":/images/damabranca.svg")); // Dama
    m_view->setPiece('R', QIcon(":/images/torrebranca.svg")); // Torre
    m_view->setPiece('N', QIcon(":/images/cavalobranco.svg")); // CAVALO
    m_view->setPiece('B', QIcon(":/images/bispobranco.svg")); // Bispo

    m_view->setPiece('p', QIcon(":/images/peaonegro.svg")); // Peao
    m_view->setPiece('k', QIcon(":/images/reinegro.svg")); // Rei
    m_view->setPiece('q', QIcon(":/images/damanegra.svg")); // Dama
    m_view->setPiece('r', QIcon(":/images/torrenegra.svg")); // Torre
    m_view->setPiece('n', QIcon(":/images/cavalonegro.svg")); // VACALO
    m_view->setPiece('b', QIcon(":/images/bisponegro.svg")); // Bispo

    //primeira implementação do tabuleiro
    //m_algorithm = new Pawn(this);
    //m_algorithm = new Bishop(this);
    //m_algorithm = new Rook(this);
    m_algorithm = new Knight(this);

    m_algorithm->newGame();
    m_view->setBoard(m_algorithm->board());
    setCentralWidget(m_view);
    m_view->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_view->setFieldSize(QSize(50,50));
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    //GameOver
    connect(m_algorithm, SIGNAL(gameOver(ChessAlgorithm::Result)), this, SLOT(gameOver(ChessAlgorithm::Result)));
}

//int helper = 1;
//implementando o highlighter
void MainWindow::viewClicked(const QPoint &field)
{
    if(m_clickPoint.isNull()) {
        if(m_view->board()->data(field.x(), field.y()) != ' ') {
            m_clickPoint = field;
            m_selectedField = new ChessView::FieldHighlight(
                        field.x(), field.y(), QColor(255, 0, 0, 50)
                        );
            m_view->addHighlight(m_selectedField);
        }
    } else {
        if(field != m_clickPoint) {
            m_algorithm->move(m_clickPoint, field);
        }
        m_clickPoint = QPoint();
        m_view->removeHighlight(m_selectedField);
        delete m_selectedField;
        m_selectedField = 0;
    }
}

//Implementando o GameOver
void MainWindow::gameOver(ChessAlgorithm::Result result)
{
    QString text;
    switch(result) {
    case ChessAlgorithm::Player1Wins: text = "Brancas vencem! 1 - 0"; break;
    case ChessAlgorithm::Player2Wins: text = "Negras vencem 0 - 1"; break;
    default:
        text = "Empate 1/2 - 1/2";
    }

    QMessageBox::information(this, "Game over", QStringLiteral("The game has ended. %1").arg(text));
}
