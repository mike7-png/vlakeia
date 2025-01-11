#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>
#include <vector>
#include <string>
#include <iostream>

class Enemy : public GameObject, public Box {


public:
    float m_speed = 1.3f; // ������� �������� �������

    graphics::Brush m_brush_enemy; // Brush ��� ��������
    graphics::Brush m_brush_enemy_debug;
    std::vector<std::string> m_sprites_enemy; // Sprites ��� ������
    string m_texture;

    // �������������
    Enemy(float pos_x, float pos_y, float width, float height, const std::string& texture);
    void setPosition(float m_pos_x, float m_pos_y);

    // ��������� �����
    void update(float dt) override;

    // ��������
    void draw() override;
    void moveEnemy(float dt);


    // ������������
    void init() override;
    void reset();

    void reverseDirection();
    void ChangeSpritesReverse();
};


