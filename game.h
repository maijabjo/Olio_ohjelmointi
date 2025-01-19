#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int maxN);
    ~Game();
    void play();
private:
    void printGameResult();
    int maxNumber;
    int playerQuess;
    int randomNumber;
    int numOfGuesses;
};

#endif // GAME_H
