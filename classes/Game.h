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
    int speed;
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
    int fg=menu->Start();
    if(fg==0) return;
    else{
        speed=fg;
    }

    //绘制地图
    Map *map=new Map();
    map->Draw();
    //初始化糖果位置
    Candy* candy=new Candy;
    candy->Refresh();
    candy->Draw();
    //记分板
    int score=5;
    //初始化贪吃蛇
    int dx=0,dy=5;
    char pre=' ';
    Snake *snake = new Snake();
    while(1){
        int flag=snake->Move(candy->locx,candy->locy,dx,dy);
        if(flag==0){
            //游戏结束
            settextcolor(RED);

            settextstyle(150,0,Default_Font);
            outtextxy(130,150,"Game Over");
            getch();
            return;
        }else if(flag==2){
            settextstyle(70,0,Default_Font);
            settextcolor(YELLOW);
            outtextxy(700,150,"score");

            clearrectangle(650,220,770,270);
            char s[10];
            itoa(score,s,10);
            outtextxy(700,200,s);
            score+=5;

            candy->Eat();
            candy->Clear();
            candy->Refresh();
            candy->Draw();
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
        Sleep(speed*80);
    }
}

#endif //SNAKE_GAME_H
