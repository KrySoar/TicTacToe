#include <QWidget>
#include "game.hpp"
bool Game::who = false;
Game::Game() : QWidget()
{
    setFixedSize(400,400);

    top_left  = new GameButton(0);
    top_midle = new GameButton(1);
    top_right = new GameButton(2);

    mid_left  = new GameButton(3);
    mid_midle = new GameButton(4);
    mid_right =new GameButton(5);

    bot_left  = new GameButton(6);
    bot_midle = new GameButton(7);
    bot_right = new GameButton(8);

    gridLayout = new QGridLayout;

    gridLayout->addWidget(top_left,0,0);
    gridLayout->addWidget(top_midle,0,1);
    gridLayout->addWidget(top_right,0,2);

    gridLayout->addWidget(mid_left,1,0);
    gridLayout->addWidget(mid_midle,1,1);
    gridLayout->addWidget(mid_right,1,2);

    gridLayout->addWidget(bot_left,2,0);
    gridLayout->addWidget(bot_midle,2,1);
    gridLayout->addWidget(bot_right,2,2);

    setLayout(gridLayout);

}
