#include <iostream>
#include <time.h>
#include "render_controller.h"
#include "main_menu.h"

class SceneController
{
private:
    std::string game_state;
    RenderController render_controller;
    struct timespec loop_delay;

    MainMenu main_menu;

public:
    SceneController();
    std::string getGameState();
    void setGameState(std:: string game_state);

    void startGame();
};
