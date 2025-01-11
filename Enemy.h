#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>
#include <vector>
#include <string>
#include <iostream>

class Enemy : public GameObject, public Box {

private:
    bool m_isMovingRight;

public:
    float m_speed;

    graphics::Brush m_brush_enemy;       
    graphics::Brush m_brush_enemy_debug; 
    std::vector<std::string> m_sprites_enemy; 
    std::string m_texture;               

    Enemy(float pos_x, float pos_y, float width, float height, const std::string& texture);


    void setPosition(float pos_x, float pos_y);


    void update(float dt) override;


    void draw() override;


    void moveEnemy(float dt);


    void init() override;
    void reset();

    void reverseDirection();
    void ChangeSpritesReverse();
};

