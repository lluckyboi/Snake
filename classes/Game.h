//
// Created by Sario's HP on 2023/3/3.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "Map.h"
#include "Menu.h"
#include "Candy.h"
#include "Snake.h"
#include "Board.h"

class Game {
private:
    int Screen_Mode;
public:
    Game(int sc){
        Screen_Mode=sc;
    }

    void Start();
};

void Game::Start(){
    //菜单绘制
    Menu *menu =new Menu(0, Default_Width, Default_Height);
    menu->Draw();
    //等待选择
    if(!menu->Start()) return;

    //绘制地图
    Map *map=new Map();
    map->Draw();

    Snake *snake = new Snake();
    while(1){
        if(!snake->Move(455,255)){
            //游戏结束
            settextcolor(RED);

            settextstyle(150,0,Default_Font);
            outtextxy(130,150,"Game Over");
            getch();
            return;
        }
        Sleep(20);
    }
}

#endif //SNAKE_GAME_H
