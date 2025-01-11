#include "Enemy.h"
#include "gamestate.h"
#include <sgg/graphics.h>
#include <iostream>
#include "util.h"


Enemy::Enemy(float pos_x, float pos_y, float width, float height, const std::string& texture) :
    GameObject("Enemy"), Box(pos_x, pos_y, width, height), m_texture(texture) {
}

void Enemy::update(float dt) {
    moveEnemy(dt);
    //m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    //m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y;
}


void Enemy::reverseDirection() {
    m_speed = -m_speed; 
}


void Enemy::ChangeSpritesReverse() {
    m_sprites_enemy.clear();
    if (m_speed > 0) {
        m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking1.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking2.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking3.png")); //Kanonika
        m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking4.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking5.png"));
    }
    else {
        m_sprites_enemy.push_back(m_state->getFullAssetPath("Aninja_walking1.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("Aninja_walking2.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("Aninja_walking3.png")); //Anapoda
        m_sprites_enemy.push_back(m_state->getFullAssetPath("Aninja_walking4.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("Aninja_walking5.png"));
    }
}


void Enemy::draw() {
    if (m_state->m_debugging) {
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush_enemy_debug);
        }
        int s = (int)fmodf(1000  -m_pos_x * 10.0f, m_sprites_enemy.size());
        m_brush_enemy.texture = m_sprites_enemy[s];
        graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, m_brush_enemy);
}

void Enemy::moveEnemy(float dt){
    
    float delta_time = dt / 1000.0f;


    m_pos_x += m_speed * delta_time;
    if (m_pos_y >= 5.4f) {
        m_pos_y = 5.4f;
       
    }


}



void Enemy::init() {


    m_brush_enemy.texture = m_state->getFullAssetPath(m_texture);
    m_brush_enemy.fill_opacity = 1.0f;
    m_brush_enemy.outline_opacity = 0.0f;


    m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking1.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking2.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking3.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking4.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("ninja_walking5.png"));


   ;
    m_brush_enemy_debug.fill_opacity = 0.1f;
    


    SETCOLOR(m_brush_enemy_debug.fill_color, 0.0f, 0.0f, 1.0f);
    SETCOLOR(m_brush_enemy_debug.outline_color, 0.2f, 0.2f, 1.0f);

}

void Enemy::reset(){

}

void Enemy::setPosition(float m_pos_x, float m_pos_y) {
    this->m_pos_x = m_pos_x;
    this->m_pos_y = m_pos_y;
}


//m_pos_x tou ninja - m_pos_x tou paixti