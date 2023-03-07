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
    //todo 生成糖果

    //初始化贪吃蛇
    int dx=0,dy=5;
    char pre=' ';
    Snake *snake = new Snake();
    while(1){
        if(!snake->Move(455,255,dx,dy)){
            //游戏结束
            settextcolor(RED);

            settextstyle(150,0,Default_Font);
            outtextxy(130,150,"Game Over");
            getch();
            return;
        }
        if(kbhit()){
            switch (char op=getch()) {
                case 'w':
                    if(pre!='s') dx=0, dy=-5,pre=op;
                    break;
                case 'a':
                    if(pre!='d') dx=-5,dy=0,pre=op;
                    break;
                case 'd':
                    if(pre!='a') dx= 5,dy=0,pre=op;
                    break;
                case 's':
                    if(pre!='w') dx=0, dy= 5,pre=op;
                    break;
            }
        }
        Sleep(100);
    }
}

#endif //SNAKE_GAME_H
