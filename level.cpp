#include "level.h"
#include <sgg/graphics.h>
#include "players.h"
#include "Enemy.h"
#include "util.h"
#include "gamestate.h"
#include <iostream>

#include <cstdlib> // Required for exit()


void Level::init() {


    m_brush_background.outline_opacity = 0.0f;
    m_brush_background.fill_opacity = 1.0f;
    m_brush_background.texture = m_state->getFullAssetPath("paris1st.png");

    for (auto p_gob : m_static_objects)
        if (p_gob) p_gob->init();

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) p_gob->init();

    //-----------------portal----------------------------------------

    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));
    m_blocks_portal.push_back(Box(9.18, 8.2, 1.0f, 1.0f));

    m_blocks_names_portal.push_back("portal0.png");
    m_blocks_names_portal.push_back("portal1.png");
    m_blocks_names_portal.push_back("portal2.png");
    m_blocks_names_portal.push_back("portal3.png");
    m_blocks_names_portal.push_back("portal4.png");
    m_blocks_names_portal.push_back("portal5.png");
    m_blocks_names_portal.push_back("portal6.png");
    m_blocks_names_portal.push_back("portal7.png");
    m_blocks_names_portal.push_back("portal8.png");
    m_blocks_names_portal.push_back("portal9.png");
   


    m_block_brush_portal.outline_opacity = 0.0f;
    m_block_brush_portal_debug.fill_opacity = 0.1f;
    m_block_brush_portal.fill_opacity = 1.0f;
    SETCOLOR(m_block_brush_portal_debug.fill_color, 0.2f, 1.0f, 0.1f);
    SETCOLOR(m_block_brush_portal_debug.outline_color, 0.3f, 1.0f, 0.2f);


    //-------------------blocks--------------------------------------

   
    m_blocks.push_back(Box(5.4, 8.0, m_block_size, m_block_size));
    m_blocks.push_back(Box(5.2, 6, m_block_size, m_block_size));
    m_blocks.push_back(Box(3.37, 5.6, m_block_size, m_block_size));
    m_blocks.push_back(Box(3.37, 4.8, m_block_size, m_block_size));
    m_blocks.push_back(Box(1.3, 3.2, m_block_size, m_block_size));
    m_blocks.push_back(Box(2.95, 2.0, m_block_size, m_block_size));
    m_blocks.push_back(Box(10.0 - 3.37, 5.6, m_block_size, m_block_size));
    m_blocks.push_back(Box(10.0 - 3.37, 4.8, m_block_size, m_block_size));
    m_blocks.push_back(Box(8.7, 3.2, m_block_size, m_block_size));
    m_blocks.push_back(Box(7.05, 2.0, m_block_size, m_block_size));


    

    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");
    m_block_names.push_back("block.png");


    m_block_brush.outline_opacity = 0.0f;
    m_block_brush_debug.fill_opacity = 0.1f;
    m_block_brush.fill_opacity = 1.0f;
    SETCOLOR(m_block_brush_debug.fill_color, 0.2f, 1.0f, 0.1f);
    SETCOLOR(m_block_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);

    m_block_brush_wallet.fill_opacity = 0.1f;
    SETCOLOR(m_block_brush_wallet.fill_color, 1.0f, 0.0f, 0.0f);
    SETCOLOR(m_block_brush_wallet.outline_color, 0.0f, 0.0f, 1.0f);

    //------------------------------INVISIBLE---------------------------------------------------------

    m_blocks_invisible.push_back(Box(0, 1 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 1.5 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 2 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 2.5 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 3 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 3.5 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 4 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 4.5 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 5 , m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 5.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 6, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 6.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 7, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 7.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 8, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 8.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 9, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 9.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 10, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 10.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 11, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0, 11.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(5.24, 1.0f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(3.37, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(2.8, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(2.3, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(1.8, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(1.4, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(1.2, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0.8, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0.6, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0.3, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(0.1, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 1, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 1.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 2, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 2.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 3, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 3.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 4, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 4.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 5.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 6, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 6.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 7, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 7.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 8, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 8.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 9, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 9.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 10, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 10.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 11, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10, 11.5, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 2.8, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 2.3, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 1.8, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 1.4, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 1.2, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 0.8, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 0.6, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 0.3, 6.2f, m_block_size, m_block_size));
    m_blocks_invisible.push_back(Box(10.0 - 0.1, 6.2f, m_block_size, m_block_size));


    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
    m_block_names_invisible.push_back("");
 


    m_block_brush_invisible.outline_opacity = 0.0f;
    m_block_brush_invisible_debug.fill_opacity = 1.0f;
    m_block_brush_invisible.fill_opacity = 0.0f;
    SETCOLOR(m_block_brush_invisible_debug.fill_color, 1.0f, 0.0f, 0.0f);  // Κόκκινο χρώμα για το fill
    SETCOLOR(m_block_brush_invisible_debug.outline_color, 1.0f, 0.2f, 0.2f);  // Κόκκινο outline με λίγο πιο ανοιχτό χρώμα

    //--------------------------------money----------------------------------------------

    m_blocks_money.push_back(Box(5.24, 0.5, m_block_size/2, m_block_size/2));
    m_blocks_money.push_back(Box(5.37, 7.0, m_block_size / 2, m_block_size / 2));
    m_blocks_money.push_back(Box(2.95, 1.4, m_block_size / 2, m_block_size / 2));
    m_blocks_money.push_back(Box(5.2, 5, m_block_size / 2, m_block_size / 2));
    m_blocks_money.push_back(Box(3.33, 4.05, m_block_size / 2, m_block_size / 2));
    m_blocks_money.push_back(Box(0.5, 5.45, m_block_size / 2, m_block_size / 2));
    m_blocks_money.push_back(Box(1.30, 2.7, m_block_size / 2, m_block_size / 2));
    m_blocks_money.push_back(Box(9.5, 5.45, m_block_size / 2, m_block_size / 2));

    



    m_blocks_names_money.push_back("100_euros.png");
    m_blocks_names_money.push_back("20_euros.png");
    m_blocks_names_money.push_back("50_euros.png");
    m_blocks_names_money.push_back("10_euroes.png");
    m_blocks_names_money.push_back("10_euroes.png");
    m_blocks_names_money.push_back("100_euros.png");
    m_blocks_names_money.push_back("20_euros.png");
    m_blocks_names_money.push_back("100_euros.png");


    m_block_brush_money.outline_opacity = 0.0f;
    m_block_brush_money_debug.fill_opacity = 0.1f;
    m_block_brush_money.fill_opacity = 1.0f;


    SETCOLOR(m_block_brush_money_debug.fill_color, 0.0f, 0.0f, 1.0f);
    SETCOLOR(m_block_brush_money_debug.outline_color, 0.2f, 0.2f, 1.0f);

    //---------------------------portals------------------------------------------------------

    m_blocks_names_portal.push_back("portal0.png");
    m_blocks_names_portal.push_back("portal1.png");
    m_blocks_names_portal.push_back("portal2.png");
    m_blocks_names_portal.push_back("portal3.png");
    m_blocks_names_portal.push_back("portal4.png");                     //ISIA
    m_blocks_names_portal.push_back("portal5.png");
    m_blocks_names_portal.push_back("portal6.png");
    m_blocks_names_portal.push_back("portal7.png");
    m_blocks_names_portal.push_back("portal8.png");
    m_blocks_names_portal.push_back("portal9.png");

    m_block_brush_portal.outline_opacity = 0.0f;
    m_block_brush_portal_debug.fill_opacity = 0.1f;
    m_block_brush_portal.fill_opacity = 1.0f;


    SETCOLOR(m_block_brush_portal_debug.fill_color, 0.0f, 0.0f, 1.0f);
    SETCOLOR(m_block_brush_portal_debug.outline_color, 0.2f, 0.2f, 1.0f);




    //----------------------------hearts------------------------------------------------------


    m_blocks_hearts.push_back(Box(2 * m_block_size,  m_block_size, 2*m_block_size, 2*m_block_size));
    m_blocks_hearts.push_back(Box(3 * m_block_size,  m_block_size, 2*m_block_size, 2*m_block_size));
    m_blocks_hearts.push_back(Box(4 * m_block_size,  m_block_size, 2*m_block_size, 2*m_block_size));


    m_blocks_names_hearts.push_back("live.png");
    m_blocks_names_hearts.push_back("live.png");
    m_blocks_names_hearts.push_back("live.png");
    m_blocks_names_hearts.push_back("wallet.png");

    m_block_brush_hearts.outline_opacity = 0.0f;
    m_block_brush_hearts_debug.fill_opacity = 0.1f;
    m_block_brush_hearts.fill_opacity = 1.0f;


    SETCOLOR(m_block_brush_hearts_debug.fill_color, 0.0f, 0.0f, 1.0f);
    SETCOLOR(m_block_brush_hearts_debug.outline_color, 0.2f, 0.2f, 1.0f);

    

    //------------------------------enemies---------------------------------------------------



    enemies.emplace_back(1.0f, 5.4f, 1.0f, 1.0f, "blob.png");
    enemies.emplace_back(8.0f, 5.4f, 1.0f, 1.0f, "blob.png");
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].init();
    }


    int m_lives = 3;
    int m_wallet = 0;


}


void Level::checkCollisions()
{
    Enemy* e;
    for (auto& box : m_blocks) {
        float offset = 0.0f;
        /*if (offset = m_state->getEnemy()->intersectSideways(box)) {

            e->reverseDirection();
            e->ChangeSpritesReverse();

        }*/
        if (offset = m_state->getPlayer()->intersectDown(box)) {
            m_state->getPlayer()->m_pos_y += offset;

            m_state->getPlayer()->m_vy = 0.0f;
            break;
        }
    }

    for (auto& box : m_blocks) {
        float offset = 0.0f;
        /*if (offset = m_state->getEnemy()->intersectSideways(box)) {

            e->reverseDirection();
            e->ChangeSpritesReverse();

        }*/
        if (offset = m_state->getPlayer()->intersectSideways(box)) {
            m_state->getPlayer()->m_pos_x += offset;

            m_state->getPlayer()->m_vx = 0.0f;
            break;
        }
    }
    //----------------------------------------------INVISIBLE---------------------------------------------

    for (auto& box : m_blocks_invisible) {
        float offset = 0.0f;


        if (offset = m_state->getPlayer()->intersectSideways(box)) {

            m_state->getPlayer()->m_pos_x += offset;
            m_state->getPlayer()->m_vx = 0.0f;
            break;
        }
    }


    for (auto& box : m_blocks_invisible) {
        float offset = 0.0f;
        if (offset = m_state->getPlayer()->intersectDown(box)) {
            m_state->getPlayer()->m_pos_y += offset;

            m_state->getPlayer()->m_vy = 0.0f;
            break;
        }
    }

    //-----------------money-------------------------------------------------------------------------

    for (size_t i = 0; i < m_blocks_money.size(); i++) {
        float offset = 0.0f;
        if (offset = m_state->getPlayer()->intersectDown(m_blocks_money[i])) {
            m_state->getPlayer()->m_pos_y += offset;


            graphics::playSound(m_state->getFullAssetPath("coin.wav"), 0.5f);
            m_state->getPlayer()->m_vy = 0.0f;


            m_state->getPlayer()->addMoneyForBlock(m_blocks_names_money[i]);

            std::cout << "Player received money from block: " << m_blocks_names_money[i] << std::endl;


            m_blocks_money.erase(m_blocks_money.begin() + i);
            m_blocks_names_money.erase(m_blocks_names_money.begin() + i);
            break;
        }
    }
    for (size_t i = 0; i < m_blocks_money.size(); i++) {
        float offset = 0.0f;
        if (offset = m_state->getPlayer()->intersectSideways(m_blocks_money[i])) {
            m_state->getPlayer()->m_pos_x += offset;


            graphics::playSound(m_state->getFullAssetPath("coin.wav"), 0.5f);
            m_state->getPlayer()->m_vx = 0.0f;


            m_state->getPlayer()->addMoneyForBlock(m_blocks_names_money[i]);

            std::cout << "Player received money from block: " << m_blocks_names_money[i] << ".Prwth ekdosh" << std::endl;


            m_blocks_money.erase(m_blocks_money.begin() + i);
            m_blocks_names_money.erase(m_blocks_names_money.begin() + i);
            break;
        }
    }

    //-------------------------------------Enemies--------------------------------------


    for (Enemy& e : enemies) {
        for (auto& block : m_blocks) {
            if (e.intersectSideways(block) || e.intersectDown(block)) {
                e.reverseDirection();
                return;
            }
        }

    }

    for (Enemy& e : enemies) {
        for (auto& block : m_blocks_invisible) {
            if (e.intersectSideways(block) || e.intersectDown(block)) {
                e.reverseDirection();
                return;
            }
        }
    }


    for (int i = 0; i < enemies.size(); i++) {
        Enemy& e = enemies[i];
        float offset = 0.0f;
        if (offset = m_state->getPlayer()->intersectDown(e)) {

            m_state->getPlayer()->m_pos_y += offset;


            m_lives -= 1;

            /*if (m_state->getPlayer()->getCurrentSprite() == "specific_sprite.png") {
                e.setActive(false);
                continue;
            }*/
            m_state->getPlayer()->m_vy = 0.0f;
        }

    }

    for (int i = 0; i < enemies.size(); i++) {
        float offset = 0.0f;
        Enemy& e = enemies[i];

        if (offset = m_state->getPlayer()->intersectSideways(e)) {
            m_state->getPlayer()->m_pos_x += offset;

            m_lives -= 1;

            /*if (m_state->getPlayer()->getCurrentSprite() == "specific_sprite.png") {

                e.setActive(false);
                continue;
            }*/
            m_state->getPlayer()->m_vx = 0.0f;

        }

    }



}






//-------------------------------------------------------------------------------------------------------------
Level::Level(const std::string& name) {

}

Level::~Level() {
    for (auto p_gob : m_static_objects)
        if (p_gob) delete p_gob;

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) delete p_gob;
}



void Level::reset(){

    m_blocks.clear();
    m_blocks_hearts.clear();
    m_blocks_invisible.clear();
    m_blocks_money.clear();
    m_blocks_names_portal.clear();
    m_blocks_names_hearts.clear();
    m_blocks_names_money.clear();


}


//-----------------------------------------------------DRAWS----------------------------------------------

void Level::drawBlock(int i) {
    Box& box = m_blocks[i];
    float x = box.m_pos_x;
    float y = box.m_pos_y;
    m_block_brush.texture = m_state->getFullAssetPath(m_block_names[i]);

    graphics::drawRect(x, y, 1.8f * m_block_size, 1.8f * m_block_size, m_block_brush);

    // Αν το debugging είναι ενεργό, θα τα σχεδιάσουμε με περιγράμματα
    if (m_state->m_debugging) {
        graphics::drawRect(x, y, m_block_size, m_block_size, m_block_brush_debug);
    }
}

void Level::drawPortal(int i) {
    if (!m_blocks_names_portal.empty()) {
        int s = static_cast<int>(fmodf(1000.0f , m_blocks_names_portal.size()));
        m_block_brush_portal.texture = m_blocks_names_portal[s];
    }
    graphics::drawRect(9.18, 8.2, 1.0f, 1.0f, m_block_brush_portal);
}


void Level::drawBlockinvisible(int i) {
    Box& box = m_blocks_invisible[i];
    float x = box.m_pos_x;
    float y = box.m_pos_y;
    m_block_brush_invisible.texture = m_state->getFullAssetPath(m_block_names_invisible[i]);


    // Αν το debugging είναι ενεργό, θα τα σχεδιάσουμε με περιγράμματα
    if (m_state->m_debugging) {
        graphics::drawRect(x, y, m_block_size, m_block_size, m_block_brush_invisible_debug);
    }
}

void Level::drawBlockMoney(int i) {
    Box& box = m_blocks_money[i];
    float x = box.m_pos_x;
    float y = box.m_pos_y;
    m_block_brush_money.texture = m_state->getFullAssetPath(m_blocks_names_money[i]);
    graphics::drawRect(x, y, 1.8f * m_block_size, 1.8f * m_block_size, m_block_brush_money);

    // Αν το debugging είναι ενεργό, θα τα σχεδιάσουμε με περιγράμματα
    if (m_state->m_debugging) {
        graphics::drawRect(x, y, m_block_size, m_block_size, m_block_brush_money_debug);
    }
}

void Level::drawBlockHearts(int i) {
    Box& box = m_blocks_hearts[i];
    float x = box.m_pos_x + m_state->m_global_offset_x;
    float y = box.m_pos_y + m_state->m_global_offset_y;

    m_block_brush_hearts0.outline_opacity = 0.0f;
    m_block_brush_hearts1.outline_opacity = 0.0f;
    m_block_brush_hearts2.outline_opacity = 0.0f;
    m_block_brush_wallet.outline_opacity = 0.0f;
    m_block_brush_hearts0.texture = m_state->getFullAssetPath(m_blocks_names_hearts[0]);
    m_block_brush_hearts1.texture = m_state->getFullAssetPath(m_blocks_names_hearts[1]);
    m_block_brush_hearts2.texture = m_state->getFullAssetPath(m_blocks_names_hearts[2]);
    m_block_brush_wallet.texture = m_state->getFullAssetPath(m_blocks_names_hearts[3]);
    graphics::drawRect(m_state->getCanvasWidth() / 21.0, 1.0f, 0.8f, 0.8f, m_block_brush_wallet);
    if (m_lives == 3) {
        graphics::drawRect(m_state->getCanvasWidth() / 6.5, 0.5f, 0.5f, 0.5f, m_block_brush_hearts0);
        graphics::drawRect(m_state->getCanvasWidth() / 10.0, 0.5f, 0.5f, 0.5f, m_block_brush_hearts1);
        graphics::drawRect(m_state->getCanvasWidth() / 21.0, 0.5f, 0.5f, 0.5f, m_block_brush_hearts2);
        if (m_state->m_debugging) {
            graphics::drawRect(x, y, m_block_size, m_block_size, m_block_brush_hearts_debug);
        }
    }
    else if (m_lives == 2) {
        graphics::drawRect(m_state->getCanvasWidth() / 10.0, 0.5f, 0.5f, 0.5f, m_block_brush_hearts1);
        graphics::drawRect(m_state->getCanvasWidth() / 21.0, 0.5f, 0.5f, 0.5f, m_block_brush_hearts2);
        if (m_state->m_debugging) {
            graphics::drawRect(x, y, m_block_size, m_block_size, m_block_brush_hearts_debug);
        }
    }
    else if (m_lives == 1) {
        graphics::drawRect(m_state->getCanvasWidth() / 21.0, 0.5f, 0.5f, 0.5f, m_block_brush_hearts2);
        if (m_state->m_debugging) {
            graphics::drawRect(x, y, m_block_size, m_block_size, m_block_brush_hearts_debug);
        }
    }

}

void Level::drawWallet(int i) {

    graphics::drawText((m_state->getCanvasWidth() / 21.0) + 1, 1.0f,1, to_string(m_wallet), m_block_brush_wallet);
}

void Level::draw() {

    if (state == STARTING) {
        drawIntro();
    }
    else if (state == PLAYING) {
        drawLevel();
    }
    else if (state == HELPING) {
        drawHelp();
    }
    else if (state == MUSIC) {
        drawMusic();
    }
    else if (state == CHOOSE) {
        drawChoose();
    }
    else if (state == EXIT) {
        drawExitWindow();
    }
}

void Level::drawLevel() {
    //float w = m_state->getCanvasWidth();
    //float h = m_state->getCanvasHeight();
    graphics::Brush brush;
    brush.texture = m_state->getFullAssetPath("paris1st.png"); // Βάλτε την εικόνα του background
    graphics::drawRect(5.0f, 5.0f, 10.0f, 10.0f, brush); // Σχεδιάστε στο κέντρο
    

    if (m_state->getPlayer()->isActive()) {
        m_state->getPlayer()->draw();
    }

    for (auto enemy : enemies) {
            enemy.draw();
    }

    size_t limit = std::min(m_blocks.size(), m_block_names.size());
    for (size_t i = 0; i < limit; i++) {
        drawBlock(i);
    }
    //----------------------invisible-------------------------------------------------

    size_t limit_inv = std::min(m_blocks_invisible.size(), m_block_names_invisible.size());
    for (size_t i = 0;  i < limit_inv; i++) {
        drawBlockinvisible(i);
    }

    //-------------------money-------------------------------------------

    size_t limit_money = std::min(m_blocks_money.size(), m_blocks_names_money.size());
    for (size_t i = 0; i < limit_money; i++) {
        drawBlockMoney(i);
    }

    //-------------------------------------------------------------------

    size_t limit_hearts = std::min(m_blocks_hearts.size(), m_blocks_names_hearts.size());
    for (size_t i = 0; i < limit_hearts; i++) {
        drawBlockHearts(i);
    }

    size_t limit_portal = m_blocks_names_portal.size();
    for (size_t i = 0; i < limit_portal; i++) {
        drawPortal(i);
    }


}

void Level::drawIntro() {
    graphics::Brush BrushStartscr;
    BrushStartscr.texture = m_state->getFullAssetPath("intro_background.png");
    // Draw background
    graphics::drawRect(5.0f, 5.0f, 10.0f, 10.0f, BrushStartscr);


}

void Level::drawHelp() {
    graphics::Brush BrushHelpscr;
    BrushHelpscr.texture = m_state->getFullAssetPath("settings_photo.png");
    graphics::drawRect(5.0f, 5.0f, 10.0f, 10.0f, BrushHelpscr);
}


void Level::drawMusic() {
    graphics::Brush BrushMusicscr;
    BrushMusicscr.texture = m_state->getFullAssetPath("music_settings.png");
    // Draw background
    graphics::drawRect(5.0f, 5.0f, 10.0f, 10.0f, BrushMusicscr);

    if (graphics::getKeyState(graphics::SCANCODE_1)) {
        graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
    }
    if (graphics::getKeyState(graphics::SCANCODE_2)) {
        graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
    }
    if (graphics::getKeyState(graphics::SCANCODE_3)) {
        graphics::playSound(m_state->getFullAssetPath("hit.wav"), 0.5f);
    }
}

void Level::drawChoose(){
    graphics::Brush BrushMusicscr;
    BrushMusicscr.texture = m_state->getFullAssetPath("choose.png");
    // Draw background
    graphics::drawRect(5.0f, 5.0f, 10.0f, 10.0f, BrushMusicscr);

    if (graphics::getKeyState(graphics::SCANCODE_1)) {
        graphics::playSound(m_state->getFullAssetPath("golemsound.wav"), 0.5f);
        flagG = true;
        flagR = false;
        flagM = false;
    }
    if (graphics::getKeyState(graphics::SCANCODE_2)) {
        graphics::playSound(m_state->getFullAssetPath("minipekka.wav"), 0.5f);
        flagG = false;
        flagR = true;
        flagM = false;
    }
    if (graphics::getKeyState(graphics::SCANCODE_3)) {
        graphics::playSound(m_state->getFullAssetPath("mansoound.wav"), 0.5f);
        flagG = false;
        flagR = false;
        flagM = true;
    }
    

}


void Level::drawExitWindow() {
    graphics::Brush BrushExitscr;
    BrushExitscr.texture = m_state->getFullAssetPath("exit_screen.png");
    // Draw background
    graphics::drawRect(5.0f, 5.0f, 10.0f, 10.0f, BrushExitscr);
}

//--------------------------- UPDATES------------------------------------------------------------------------

void Level::update(float dt) {

    if (state == STARTING) {
        updateIntro();
    }
    else if (state == HELPING) {
        updateHelp();
    }
    else if (state == PLAYING) {
        updateLevel(dt);
    }
    else if (state == MUSIC) {
        updateMusic();
    }
    else if (state == CHOOSE) {
        updateChoose();
    }
    else if (state == EXIT) {
        updateExitWindow();
    }
}


void Level::updateIntro() {

    if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {

        state = PLAYING;
    }
    if (graphics::getKeyState(graphics::SCANCODE_H)) {

        state = HELPING;
    }
    if (graphics::getKeyState(graphics::SCANCODE_M)) {
        state = MUSIC;
    }
    if (graphics::getKeyState(graphics::SCANCODE_C)) {
        state = CHOOSE;
    }
}

void Level::updateHelp() {

    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {

        state = STARTING;
    }
    else {
        state = HELPING;
    }
}

void Level::updateLevel(float dt) {
    
    if (m_state->getPlayer()->isActive())
        m_state->getPlayer()->update(dt);
    
    for (auto& enemy : enemies) {
         enemy.update(dt);
    }
    
    if (m_lives == 0) {
        state = EXIT;
    }

    checkCollisions();
   
    GameObject::update(dt);
}

void Level::updateMusic() {
    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {

        state = STARTING;
    }
    else
        state = MUSIC;
}

void Level::updateChoose() {
    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
        state = STARTING;
    }
    else
        state = CHOOSE;
}   

void Level::updateExitWindow() {
    if (graphics::getKeyState(graphics::SCANCODE_RETURN)) {
        state = PLAYING;
    }
    else if (graphics::getKeyState(graphics::SCANCODE_SPACE)){
        init();
        Player* player = m_state->getPlayer();
        player->reset();

        /*for (auto& enemy : enemies) {
            enemy->reset();
        }*/
        state = STARTING;
    }
    else if (graphics::getKeyState(graphics::SCANCODE_E)) {
        exit(EXIT_FAILURE);
    }
    else if (graphics::getKeyState(graphics::SCANCODE_C)) {
        state = CHOOSE;
    }
}

void Level::resetLevel(float dt) {
    Level::init();
}

bool Level::getGolem() {
    return flagG;
}

bool Level::getMan() {
    return flagM;
}

bool Level::getRobot() {
    return flagR;
}

