#ifndef SHAKKIKELLO_H
#define SHAKKIKELLO_H
#include <QTimer>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class shakkikello;
}
QT_END_NAMESPACE

class shakkikello : public QMainWindow
{
    Q_OBJECT

public:
    shakkikello(QWidget *parent = nullptr);
    ~shakkikello();

public slots:
    void timeout();
    void startGame();
    void stopGame();
    void switchPlayer();
    void setGameTime(short time);
    void checkGameOver();
    void updateProgressBar();
    void setGameInfoText(QString text, short time);

private:
    Ui::shakkikello *ui;
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer;

};
#endif // SHAKKI

