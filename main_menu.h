#include "render_controller.h"
#include "knobs_controller.h"

class MainMenu
{
private:
    RenderController render_controller;
    KnobsController knobs_controller;

    std::string game_state;
public:
    MainMenu();
    void draw();
    void setRenderController(RenderController *render_controller);
    std::string getGameState();
};
