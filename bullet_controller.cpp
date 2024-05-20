#include "bullet_controller.h"

BulletController::BulletController(RenderController *render_controller)
{
    this->render_controller = render_controller;
}

void BulletController::draw()
{
    for (Bullet *bullet : bullets)
    {
        if (!bullet->getIsOut())
        {
            bullet->draw();
        }
    }
}

void BulletController::createBullet(int x)
{
    for (Bullet *bullet : bullets)
    {
        if (bullet->getIsOut())
        {
            bullet->reset(x);
            return;
        }
    }

    bullets.push_back(
        new Bullet(render_controller, x));
}

void BulletController::shoot(int x1, int x2)
{
    auto now = std::chrono::steady_clock::now();
    if ((now - last_time) > bullet_delay)
    {
        createBullet(x1);
        createBullet(x2);
        last_time = now;
    }
}

std::vector<Bullet *>* BulletController::bulletsList() {
    return &bullets;
}
