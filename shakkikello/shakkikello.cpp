#include "shakkikello.h"
#include "./ui_shakkikello.h"

shakkikello::shakkikello(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::shakkikello),
    player1Time(0),
    player2Time(0),
    currentPlayer(1),
    gameTime(0),
    pQTimer(new QTimer(this))
{
    ui->setupUi(this);

    connect(pQTimer, &QTimer::timeout, this, &shakkikello::timeout);
    connect(ui->playerOneButton, &QPushButton::clicked, this, &shakkikello::switchPlayer);
    connect(ui->playerTwoButton, &QPushButton::clicked, this, &shakkikello::switchPlayer);
    connect(ui->startButton, &QPushButton::clicked, this, &shakkikello::startGame);
    connect(ui->stopButton, &QPushButton::clicked, this, &shakkikello::stopGame);
    connect(ui->twoMinsButton, &QPushButton::clicked, this, [this](){ setGameTime(120); }); // 120 sekunnin nappi
    connect(ui->fiveMinsButton, &QPushButton::clicked, this, [this](){ setGameTime(300); }); // 5 minuutin nappi (300 sec)

    setGameInfoText("Select playtime and Start game", 14);
}

shakkikello::~shakkikello()
{
    delete ui;
}

void shakkikello::timeout()
{
    if (currentPlayer == 1)
        player1Time--;
    else
        player2Time--;

    updateProgressBar();
    checkGameOver();
}

void shakkikello::updateProgressBar()
{
    ui->playerOneBar->setValue((player1Time * 100) / gameTime);
    ui->playerTwoBar->setValue((player2Time * 100) / gameTime);
}

void shakkikello::setGameInfoText(QString text, short fontSize)
{
    QFont font = ui->label->font();
    font.setPointSize(fontSize);
    ui->label->setFont(font);
    ui->label->setText(text);
}

void shakkikello::setGameTime(short time)
{
    gameTime = time;
    player1Time = time;
    player2Time = time;
    updateProgressBar();
    setGameInfoText("Press Start game-button", 14);
}
void shakkikello::startGame()
{
    if (gameTime == 0) {
        setGameInfoText("ready to play", 14);
        return;
    }

    pQTimer->start(1000);
    setGameInfoText("Game ongoing", 14);
}

void shakkikello::stopGame()
{
    pQTimer->stop();
    setGameInfoText("Select new playtime and press start game ", 14);
}

void shakkikello::switchPlayer()
{
    if (!pQTimer->isActive()) return;

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void shakkikello::checkGameOver()
{
    if (player2Time <= 0)
    {
        stopGame();
        setGameInfoText(" Player 1 WON!!!", 0);

    } else if (player1Time <= 0) {
        stopGame();
        setGameInfoText("Player 2 WON!!!", 0);
    }
}
