#pragma once
#include "gameobject.h"
#include "box.h"
#include <sgg/graphics.h>
#include <vector>
#include <string>
#include <iostream>

class Enemy : public GameObject, public Box {


public:
    float m_speed = 1.3f; // Σταθερή ταχύτητα κίνησης

    graphics::Brush m_brush_enemy; // Brush για σχεδίαση
    graphics::Brush m_brush_enemy_debug;
    std::vector<std::string> m_sprites_enemy; // Sprites του εχθρού
    string m_texture;

    // Κατασκευαστής
    Enemy(float pos_x, float pos_y, float width, float height, const std::string& texture);
    void setPosition(float m_pos_x, float m_pos_y);

    // Ενημέρωση θέσης
    void update(float dt) override;

    // Σχεδίαση
    void draw() override;
    void moveEnemy(float dt);


    // Αρχικοποίηση
    void init() override;
    void reset();

    void reverseDirection();
    void ChangeSpritesReverse();
};


