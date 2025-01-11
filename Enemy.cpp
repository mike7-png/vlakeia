#include "Enemy.h"
#include "gamestate.h"
#include <sgg/graphics.h>
#include <iostream>
#include "util.h"


Enemy::Enemy(float pos_x, float pos_y, float width, float height, const std::string& texture) :
    GameObject("Enemy"), Box(pos_x, pos_y, width, height), m_texture(texture),m_isMovingRight(true) {
    m_speed = 1.3f; //speed
}


void Enemy::update(float dt) {
    cout<<"enemy= " << m_pos_x << endl;
    moveEnemy(dt);
    //m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    //m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y;
}


void Enemy::reverseDirection() {
    if (m_isMovingRight) {
        m_pos_x -= 0.1;
    }
    else {
        m_pos_x += 0.1;
    }
    m_isMovingRight = !m_isMovingRight; // Αλλαγή κατεύθυνσης
}



void Enemy::ChangeSpritesReverse() {
    m_sprites_enemy.clear();
    if (m_speed > 0) {
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blobpng"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blobpng"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blobpng")); //Kanonika
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blobpng"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blobpng"));
    }                                                        
    else {                                                   
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png")); //Anapoda
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
        m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
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

void Enemy::moveEnemy(float dt) {
    if (m_isMovingRight) {
        m_pos_x += m_speed * (dt / 1000.0f);
    }
    else {
        m_pos_x -= m_speed * (dt / 1000.0f);
    }
}




void Enemy::init() {


    m_brush_enemy.texture = m_state->getFullAssetPath(m_texture);
    m_brush_enemy.fill_opacity = 1.0f;
    m_brush_enemy.outline_opacity = 0.0f;


    m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));
    m_sprites_enemy.push_back(m_state->getFullAssetPath("blob.png"));


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