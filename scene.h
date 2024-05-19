#include "render_controller.h"
#include "knobs_controller.h"

class Scene {
protected:
  RenderController render_controller;
  KnobsController knobs_controller;

  std::string game_state;

public:
  virtual void draw() = 0;
  void setRenderController(RenderController *render_controller);
  void setKnobsController(KnobsController *knobs_controller);
  void setGameState(std::string game_state);
  std::string getGameState();
};
