//
// Created by Sario's HP on 2023/3/1.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <iostream>
#include <vector>
#include <graphics.h>
#include "../const/const.h"

#define PII pair<int,int>

using namespace std;

class Snake {
private:
    vector<vector<int>> body;
    vector<vector<int>> direction;
    int length;
public:
    Snake(){
        //初始化body与方向
        body.push_back({455,255,0,5});

        direction.push_back({0,5});//下
        direction.push_back({0,-5});//上
        direction.push_back({5,0});//右
        direction.push_back({-5,0});//左
        //初始化长度
        length=1;

        //设置填充色
        setfillcolor(RED);
        //绘制
        fillroundrect(P_Left+200,P_Top+200,P_Left+210,P_Top+210,6,6);
    }

    //移动
    bool Move(int candyx,int candyy);
    //变长
    void GrowUp();
};

void Snake::GrowUp(){
    //获取末尾元素指针
    auto p=body.end()-1;
    int x=*(p->begin());
    int y=*(p->begin()+1);
    int dirx=*(p->begin()+2);
    int diry=*(p->begin()+3);

    //新增躯干，方向与上一块躯干相同
    body.push_back({x-dirx,y-diry,dirx,diry});
    length++;

    //设置填充色
    setfillcolor(Snake_Body_Color);
    //绘制
    fillroundrect(x-dirx-5,y-diry-5,x-dirx+5,y-diry+5,6,6);
}

//边界检查
bool checkSide(int x,int y){
    if(!(x>250&&x<650&&y>50&&y<440))return false;
    return true;
}

bool Snake::Move(int candyx,int candyy) {
    int x=body[0][0];
    int y=body[0][1];
    int dirx=body[0][2];
    int diry=body[0][3];

    //清理原先方块
    clearroundrect(x-5,y-5,x+5,y+5,6,6);

    //头部先更新
    body[0][0]+=body[0][2];
    body[0][1]+=body[0][3];

    //重新绘制
    x=body[0][0];
    y=body[0][1];
    dirx=body[0][2];
    diry=body[0][3];
    setfillcolor(RED);
    fillroundrect(x+dirx-5,y+diry-5,x+dirx+5,y+diry+5,6,6);
    setfillcolor(Snake_Body_Color);

    //边界检查
    if(!checkSide(x,y))return false;

    //更新位置
    for(int i=1;i<length;i++){
        x=body[i][0];
        y=body[i][1];
        dirx=body[i][2];
        diry=body[i][3];
        //清理原先方块
        clearroundrect(x-5,y-5,x+5,y+5,6,6);
        //更新头
        body[i][0]+=body[i][2];
        body[i][1]+=body[i][3];

        //重新绘制
        x=body[i][0];
        y=body[i][1];
        dirx=body[i][2];
        diry=body[i][3];
        fillroundrect(x+dirx-5,y+diry-5,x+dirx+5,y+diry+5,6,6);
    }

    x=body[0][0];
    y=body[0][1];
    dirx=body[0][2];
    diry=body[0][3];
    //判断是否吃到糖果
    if(x>=candyx-5&&x<=candyx+5&&y>=candyy-5&y<=candyy+5) {
        //todo 清除糖果
        GrowUp();
    }
    return true;
}
#endif //SNAKE_SNAKE_H
