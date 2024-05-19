/*******************************************************************
  Project main function template for MicroZed based MZ_APO board
  designed by Petr Porazil at PiKRON

  Project developers: Deshko Vladyslav, Fedorchuk Sofiia

 *******************************************************************/

#include "scene_controller.h"

#define _POSIX_C_SOURCE 200112L

#define WIDTH 320
#define HEIGHT 480

int main(int argc, char *argv[]) {

  SceneController scene_controller = SceneController();
  scene_controller.startGame();

  return 0;
}
