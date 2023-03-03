//
// Created by Sario's HP on 2023/3/1.
//

#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "../const/const.h"

#define FO(i,n) for(int i=0;i<n;i++)

class Map {
private:
    int    GameMap[400][400];
public:
    Map(){
        //初始化地图数组
        memset(GameMap,0,sizeof GameMap);
        //设置边界
        FO(i,400){
            GameMap[0][i]=1;
            GameMap[i][0]=1;
            GameMap[399][i]=1;
            GameMap[i][399]=1;
        }
    };
    //绘制地图
    void Draw();
};

void Map::Draw() {
    //清屏
    cleardevice();

    //设置背景模式-透明
    setbkmode(TRANSPARENT);

    //设置填充色为默认填充色
    setfillcolor(Default_Bottom_Color);
    setlinecolor(Default_Bottom_Color);

    //设置偏移度
    int p_w=P_Left,p_h=P_Top;

    //绘制地图
    FO(i,400){
        FO(j,400){
            if(i==0||j==0||i==399||j==399) fillrectangle(i+p_w-1,j+p_h-1,i+p_w,j+p_h);
        }
    }
}

#endif //SNAKE_MAP_H
