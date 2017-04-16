#ifndef GAMEBUTTON_HPP
#define GAMEBUTTON_HPP
#include <QPushButton>
class GameButton : public QPushButton
{
    Q_OBJECT
public:
    GameButton(int m_pos);
    void check();
    bool isDone(){return m_done;}
public slots:
    void tic();
private:
    bool m_done;
    int m_pos;
};

#endif // GAMEBUTTON_HPP
