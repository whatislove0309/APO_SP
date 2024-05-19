#include "render_controller.h"
#include "knobs_controller.h"

class MainMenu
{
private:
    RenderController render_controller;
    KnobsController knobs_controller;

    std::string btn_selected;
public:
    MainMenu();
    void draw();
    void setRenderController(RenderController *render_controller);
    std::string getGameState();
};
