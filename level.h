#pragma once

#include "gameobject.h"
#include <sgg/graphics.h>
#include <string>
#include <vector>
#include "players.h"
#include <list>
#include "gamestate.h"
#include "Enemy.h"

class Level : public GameObject {
private:
    graphics::Brush m_brush_background;
    const float m_block_size = 0.5f;
    float m_center_x = 5.0f;
    float m_center_y = 10.0f;
    int m_lives = 3;
    int m_wallet = 0;

    

    //-------------------------------------------------------------
    graphics::Brush m_block_brush;
    graphics::Brush m_block_brush_debug;
                                                        //kanonika blocks
    std::vector<Box> m_blocks;
    std::vector<string> m_block_names;

    //-----------------------------------------------------------

    graphics::Brush m_block_brush_invisible;            //aorata
    graphics::Brush m_block_brush_invisible_debug;

    std::vector<Box> m_blocks_invisible;
    std::vector<string> m_block_names_invisible;

    //--------------------------------------------------------

    graphics::Brush m_block_brush_money;
    graphics::Brush m_block_brush_money_debug;
                                                        //lefta
    std::vector<Box> m_blocks_money;
    std::vector<string> m_blocks_names_money;


    //--------------------------------------------------------


    graphics::Brush m_block_brush_hearts;
    graphics::Brush m_block_brush_hearts_debug;
    graphics::Brush m_block_brush_hearts0;
    graphics::Brush m_block_brush_hearts1;
    graphics::Brush m_block_brush_hearts2;
    graphics::Brush m_block_brush_wallet;
                                                    //kardies
    std::vector<Box> m_blocks_hearts;
    std::vector<string> m_blocks_names_hearts;
    
    
    //----------------------------------------------------------------

    std::vector<string> m_blocks_names_portal;
    std::vector<Box> m_blocks_portal;
    graphics::Brush m_block_brush_portal;           //ISIA PORTALS
    graphics::Brush m_block_brush_portal_debug;



    //--------------------------------------------------------
    std::vector<float> m_background_positions; // Θέσεις για κάθε background

    //----------------------------------------------------------------------------------



    // Γενικές στατικές και δυναμικές οντότητες
    std::vector<GameObject*> m_static_objects;
    std::list<GameObject*> m_dynamic_objects;

    bool flagR = false;
    bool flagM = false;
    bool flagG = false;



    void drawBlock(int i);
    void drawPortal(int i);
    void drawBlockinvisible(int i);
    void drawBlockMoney(int i);
    void drawBlockHearts(int i);
    void drawWallet(int i);
 

    void checkCollisions();

    void updateIntro();
    void updateLevel(float dt);
    void updateHelp();
    void updateMusic();
    void updateChoose();
    void updateExitWindow();

    void drawIntro();
    void drawLevel();
    void drawHelp();
    void drawMusic();
    void drawChoose();
    void drawExitWindow();

    typedef enum { STARTING, PLAYING, HELPING, MUSIC, EXIT, CHOOSE } status_t;

    status_t state = STARTING;

     std::vector<Enemy> enemies;

public:

    void update(float dt) override;
    void init() override;
    void addEnemy(float m_pos_x, float m_pos_y);
    void draw() override;
    Level(const std::string& name = "Level0");
    ~Level();

    void reset();

    void resetLevel(float dt);


    bool getGolem();
    bool getMan();
    bool getRobot();
    // Μέθοδοι για την κίνηση των backgrounds

};


