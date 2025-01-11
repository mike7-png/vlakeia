#include "players.h"
#include "gamestate.h"
#include <sgg/graphics.h>
#include <iostream>
#include "util.h"



void Player::init() {
    m_pos_x = 1.0f;
    m_pos_y = 8.2f;
    m_width /= 2.0f;


    m_brush_player.fill_opacity = 1.0f;
    m_brush_player.outline_opacity = 0.0f;
   


    m_money = 0;
}



void Player::fillsprites() {
    if (m_state->getLevel()->getRobot()) {
        m_sprites.clear();
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left0.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left1.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left2.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left3.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left4.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left5.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left6.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left7.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left8.png"));
        m_sprites.push_back(m_state->getFullAssetPath("Boing-left9.png"));
    }
    if (m_state->getLevel()->getGolem()) {
        m_sprites.clear();
        m_sprites.push_back(m_state->getFullAssetPath("golem.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem2.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem3.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem4.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem5.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem6.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem7.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem8.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem9.png"));
        m_sprites.push_back(m_state->getFullAssetPath("golem10.png"));

    }
    if (m_state->getLevel()->getMan()) {
        m_sprites.clear();
        m_sprites.push_back(m_state->getFullAssetPath("wraios1.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios2.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios3.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios4.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios5.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios6.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios7.png"));
        m_sprites.push_back(m_state->getFullAssetPath("wraios8.png"));

    }
}


void Player::update(float dt) {
    movePlayer(dt);
    m_state->m_global_offset_x = m_state->getCanvasWidth() / 2.0f - m_pos_x;
    m_state->m_global_offset_y = m_state->getCanvasHeight() / 2.0f - m_pos_y;
    /*std::cout << m_pos_x << " " << m_pos_y << endl;*/

    GameObject::update(dt);
}

void Player::movePlayer(float dt) {
    float delta_time = dt / 1000.0f;


    //const float velocity = 2.0f;
    if (graphics::getKeyState(graphics::SCANCODE_A)) {
        m_pos_x -= delta_time * velocity;
        if (m_state->getLevel()->getMan()) {
            m_sprites.clear();
            m_sprites.push_back(m_state->getFullAssetPath("Awraios8.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios7.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios6.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios5.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios4.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios3.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios2.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Awraios1.png"));
            
        }
        if (m_state->getLevel()->getGolem()) {
            m_sprites.clear();
            m_sprites.push_back(m_state->getFullAssetPath("Agolem10.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem9.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem8.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem7.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem6.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem5.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem4.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem3.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem2.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem1.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Agolem.png"));
        }
        if (m_state->getLevel()->getRobot()) {
            m_sprites.clear();
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left9.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left8.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left7.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left6.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left5.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left4.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left3.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left2.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left1.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left0.png"));
        }
    }
    if (graphics::getKeyState(graphics::SCANCODE_D)) {
        m_pos_x += delta_time * velocity;
        if (m_state->getLevel()->getMan()) {
            m_sprites.clear();
            m_sprites.push_back(m_state->getFullAssetPath("wraios1.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios2.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios3.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios4.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios5.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios6.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios7.png"));
            m_sprites.push_back(m_state->getFullAssetPath("wraios8.png"));

        }
        if (m_state->getLevel()->getGolem()) {
            m_sprites.clear();
            m_sprites.push_back(m_state->getFullAssetPath("golem.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem2.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem3.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem4.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem5.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem6.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem7.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem8.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem9.png"));
            m_sprites.push_back(m_state->getFullAssetPath("golem10.png"));
        }
        if (m_state->getLevel()->getRobot()) {
            m_sprites.clear();
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left0.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left1.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left2.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left3.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left4.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left5.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left6.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left7.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left8.png"));
            m_sprites.push_back(m_state->getFullAssetPath("Boing-left9.png"));
        
        }
    }
    if (m_vx == 0) {
        if (m_state->getLevel()->getRobot()) {
            graphics::Brush Brushrobot;
            Brushrobot.texture = m_state->getFullAssetPath("Boing-back.png");
            graphics::drawRect(m_pos_x, m_pos_y, 0.8f, 0.8f, Brushrobot);
        }
    }
    if (m_vx == 0) {
        if (m_state->getLevel()->getGolem()) {
            graphics::Brush Brushgolem;
            Brushgolem.texture = m_state->getFullAssetPath("Agolem10.png");
            graphics::drawRect(m_pos_x, m_pos_y, 0.8f, 0.8f, Brushgolem);
        }
    }

    m_vx = std::min(m_max_velocity, m_vx );
    m_vx = std::max(-m_max_velocity, m_vx);
    m_vx -= 0.2f * m_vx / (0.1f + fabs(m_vx));
    if (fabs(m_vx) < 0.01f) m_vx = 0.0f;
    m_pos_x += delta_time * m_vx;

    if (graphics::getKeyState(graphics::SCANCODE_W) && m_vy == 0.0f) {
        m_vy = -m_accel_vertical;
    }

    m_vy += delta_time * m_gravity;
    std::cout << m_vy << endl;
    m_vy = std::min(m_vy, m_max_velocity);
    m_pos_y += m_vy * delta_time;

    if (m_pos_y >= 8.2f) {
        m_pos_y = 8.2f;
        m_vy = 0.0f;
    }
}

void Player::draw() {
    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
        m_brush_player.texture = "SPATHI.PNG";
        graphics::drawRect(m_pos_x, m_pos_y, 0.8f, 0.8f, m_brush_player);
    }
    else {
        if (!m_sprites.empty()) {
            if (!graphics::getKeyState(graphics::SCANCODE_W)) {
                int s = static_cast<int>(fmodf(1000.0f - m_pos_x * 8.0f, m_sprites.size()));
                m_brush_player.texture = m_sprites[s];
            }
        }
        graphics::drawRect(m_pos_x, m_pos_y, 0.8f, 0.8f, m_brush_player);
    }

    if (m_state->m_debugging) {
        debugDraw();
    }
}


string Player::getCurrentSprite()
{
    int s = (int)fmodf(1000.0f - m_pos_x * 8.0f, m_sprites.size());
    return m_sprites[s];
}

void Player::debugDraw() {
    m_brush_player_debug.fill_opacity = 0.1f;
   
    SETCOLOR(m_brush_player_debug.fill_color, 0.0f, 1.0f, 0.0f);
    SETCOLOR(m_brush_player_debug.outline_color, 0.2f, 0.2f, 1.0f);
    graphics::drawRect(m_pos_x, m_pos_y, 1.0f, 1.0f, m_brush_player_debug);
}

void Player::addMoney(int amount) {
    m_money += amount;  
    std::cout << "Player received money. Total: " << m_money << std::endl;
}

int Player::getMoney() const {
    return m_money; 
}

void Player::addMoneyForBlock(const std::string& blockName) {
    if (blockName == "20_euros.png") {
        addMoney(20);  
    }
    else if (blockName == "50_euros.png") {
        addMoney(50);  
    }
    else if (blockName == "100_euros.png") {
        addMoney(100); 
    }
    else if (blockName == "10_euroes.png") {
        addMoney(10);  
    }
}

float Player::getPosX() const {
    return m_pos_x;  
}

float Player::getPosY() const {
    return m_pos_y;  
}

void Player::reset(){
    m_pos_x = 0.0f;
    m_pos_y = 5.0f;
    //if (RobotOn) {
    //    m_brush_player.texture = m_state->getFullAssetPath("Boing-left0.png");
    //} //kai ta alla an katafereis na vreis pws


}

/*
void Player::displayMoney(float m_pos_x, float m_pos_y) {
    std::string moneyText = "Money: " + std::to_string(m_money);
    float x_pos = m_pos_x;
    float y_pos = m_pos_y + 0.5f;

    graphics::Brush brush_money;
    brush_money.fill_color[0] = 1.0f;

    graphics::drawText(x_pos, y_pos, 30.0f, moneyText, brush_money);
}*/




