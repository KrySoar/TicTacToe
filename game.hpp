#ifndef GAME_HPP
#define GAME_HPP

#include <QWidget>
#include <QGridLayout>

#include "gamebutton.hpp"

class Game : public QWidget
{  
public:
    Game();
    static bool getWho(){return who;}
    static void setWho(bool b){who=b;}
private:

    static bool who;

    QGridLayout *gridLayout;

    GameButton *top_left;
    GameButton *top_midle;
    GameButton *top_right;

    GameButton *mid_left;
    GameButton *mid_midle;
    GameButton *mid_right;

    GameButton *bot_left;
    GameButton *bot_midle;
    GameButton *bot_right;

};

#endif // GAME_HPP
