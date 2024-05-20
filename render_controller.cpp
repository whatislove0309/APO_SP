#include "render_controller.h"

RenderController::RenderController()
{
  ParLCDController parlcd_controller = ParLCDController();
  mem_base = parlcd_controller.getMemBase();
  fb = new unsigned short[WIDTH * HEIGHT];

  backgroundImage = loadImg("/tmp/oleksandr/assets/background.565");
  levelBackgroundImage = loadImg("/tmp/oleksandr/assets/background_level.565");
  ship_1 = loadImg("/tmp/oleksandr/assets/ship_1.565");
  asteroid = loadImg("tmp/oleksandr/assets/asteroid.565");
}

void RenderController::update()
{
  parlcd_write_cmd(mem_base, 0x2c);
  for (size_t i = 0; i < WIDTH * HEIGHT; i++)
  {
    *(volatile uint16_t *)(mem_base + PARLCD_REG_DATA_o) = fb[i];
  }
}

void RenderController::reset() { fb = new unsigned short[WIDTH * HEIGHT]; }

void RenderController::drawMainBackground()
{
  drawImage(0, 0, backgroundImage);
}

void RenderController::drawLevelBackground()
{
  drawImage(0, 0, levelBackgroundImage);
}

void RenderController::drawImage(int x, int y, Image *img)
{
  if (img == NULL || img->data == NULL)
  {
    return;
  }

  for (int i = 0; i < img->height; i++)
  {
    for (int j = 0; j < img->width; j++)
    {
      int board_x = x + j;
      int board_y = y + i;

      if (board_x >= 0 && board_x < WIDTH && board_y >= 0 && board_y < HEIGHT)
      {
        if (img->data[i * img->width + j] != 0xFFE0)
        {
          fb[board_y * WIDTH + board_x] = img->data[i * img->width + j];
        }
      }
    }
  }
}

void RenderController::higlightRegion(int x, int y, int width, int height)
{
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      int board_x = x + j;
      int board_y = y + i;
      if (board_x >= 0 && board_x < WIDTH && board_y >= 0 && board_y < HEIGHT)
      {
        pxl_t *pixel = (pxl_t *)(fb + board_y * WIDTH + board_x);
        pixel->r <<= 1;
        pixel->g <<= 1;
        pixel->b <<= 1;
      }
    }
  }
}

void RenderController::drawShip(int x)
{
  drawImage(x, 248, ship_1);
}

void RenderController::drawAsteroid(int x, int y)
{
  drawImage(x, y, asteroid);
}

void RenderController::drawBullet(int x, int y, int width, int height)
{
  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      int drawY = y + j;
      int drawX = x + i;
      fb[drawY * WIDTH + drawX] = 0xffff;
    }
  }
}
