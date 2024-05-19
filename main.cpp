/*******************************************************************
  Project main function template for MicroZed based MZ_APO board
  designed by Petr Porazil at PiKRON

  Project developers: Deshko Vladyslav, Fedorchuk Sofiia

 *******************************************************************/

#define _POSIX_C_SOURCE 200112L

#define WIDTH 320
#define HEIGHT 480

#include <cstdlib>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "scene_controller.h"

int main(int argc, char *argv[]) {

  SceneController scene_controller = SceneController();
  scene_controller.startGame();

  return 0;
}
