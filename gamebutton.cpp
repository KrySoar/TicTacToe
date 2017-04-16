#include <QPushButton>
#include <QMessageBox>

#include "gamebutton.hpp"
#include "game.hpp"

GameButton::GameButton(int pos) : QPushButton()
{
    m_pos=pos;
    m_done=false;
    setFixedSize(100,100);//size of a cell
    connect(this,SIGNAL(clicked(bool)),this,SLOT(tic()));//when a cell is clicked(),call tic()
}

int gameArray[9];//for check()

void GameButton::check()
{
    if((gameArray[0]==1 && gameArray[1]==1 && gameArray[2]==1)||
       (gameArray[3]==1 && gameArray[4]==1 && gameArray[5]==1)||
       (gameArray[6]==1 && gameArray[7]==1 && gameArray[8]==1)||

       (gameArray[0]==1 && gameArray[3]==1 && gameArray[6]==1)||
       (gameArray[1]==1 && gameArray[4]==1 && gameArray[7]==1)||
       (gameArray[2]==1 && gameArray[5]==1 && gameArray[8]==1)||

       (gameArray[0]==1 && gameArray[4]==1 && gameArray[8]==1)||
       (gameArray[2]==1 && gameArray[4]==1 && gameArray[6]==1))
    {
        QMessageBox::information(this,"TicTacToe","X has won");
        emit exit(0);

    }else if((gameArray[0]==2 && gameArray[1]==2 && gameArray[2]==2)||
             (gameArray[3]==2 && gameArray[4]==2 && gameArray[5]==2)||
             (gameArray[6]==2 && gameArray[7]==2 && gameArray[8]==2)||

             (gameArray[0]==2 && gameArray[3]==2 && gameArray[6]==2)||
             (gameArray[1]==2 && gameArray[4]==2 && gameArray[7]==2)||
             (gameArray[2]==2 && gameArray[5]==2 && gameArray[8]==2)||

             (gameArray[0]==2 && gameArray[4]==2 && gameArray[8]==2)||
             (gameArray[2]==2 && gameArray[4]==2 && gameArray[6]==2))
    {
        QMessageBox::information(this,"TicTacToe","O has won");
        emit exit(0);
    }else if(gameArray[0]!=0 && gameArray[1]!=0 && gameArray[2]!=0 &&
             gameArray[3]!=0 && gameArray[4]!=0 && gameArray[5]!=0 &&
             gameArray[6]!=0 && gameArray[7]!=0 && gameArray[8]!=0)
    {
        QMessageBox::information(this,"TicTacToe","Equality");
        emit exit(0);
    }
}

void GameButton::tic()
{
    /* the function tic() define :
     * -if we can tic or not
     * -if the tic is 'X' or 'O'
     */

    if(m_done != true)
    {
        if(Game::getWho())
        {
            setText("O");
            Game::setWho(false);
        }
        else if (!Game::getWho())
        {
            setText("X");
            Game::setWho(true);
        }

        switch(m_pos)//fill the gameArray[]
        {
        case 0:
            if(text()=="X")
                gameArray[0]=1;
            else if(text()=="O")
                gameArray[0]=2;
            break;

        case 1:
            if(text()=="X")
                gameArray[1]=1;
            else if(text()=="O")
                gameArray[1]=2;
            break;

        case 2:
            if(text()=="X")
                gameArray[2]=1;
            else if(text()=="O")
                gameArray[2]=2;
            break;

        case 3:
            if(text()=="X")
                gameArray[3]=1;
            else if(text()=="O")
                gameArray[3]=2;
            break;

        case 4:
            if(text()=="X")
                gameArray[4]=1;
            else if(text()=="O")
                gameArray[4]=2;
            break;

        case 5:
            if(text()=="X")
                gameArray[5]=1;
            else if(text()=="O")
                gameArray[5]=2;
            break;

        case 6:
            if(text()=="X")
                gameArray[6]=1;
            else if(text()=="O")
                gameArray[6]=2;
            break;

        case 7:
            if(text()=="X")
                gameArray[7]=1;
            else if(text()=="O")
                gameArray[7]=2;
            break;

        case 8:
            if(text()=="X")
                gameArray[8]=1;
            else if(text()=="O")
                gameArray[8]=2;
            break;

        default:
            break;
        }
        check();
        m_done=true;
    }
}
