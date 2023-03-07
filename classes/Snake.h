//
// Created by Sario's HP on 2023/3/1.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <iostream>
#include <vector>
#include <graphics.h>
#include <deque>
#include "../const/const.h"

#define PII pair<int,int>

using namespace std;

class Snake {
private:
    //双向队列
    deque<vector<int>> body;
    int length;
public:
    Snake(){
        //初始化body
        //{0,5}下
        //{0,-5}上
        //{5,0}}右
        //{-5,0}}左
        body.push_front({455,255,0,5});

        //初始化长度
        length=1;

        //设置填充色
        setfillcolor(RED);
        //绘制
        fillroundrect(P_Left+200,P_Top+200,P_Left+210,P_Top+210,6,6);
    }

    //移动
    bool Move(int candyx, int candyy, int dirctx, int dircty);
    //变长
    void GrowUp();
    //检查
    bool checkBody();
};

void Snake::GrowUp(){
    if(length==1){
        int x=body.back()[0];
        int y=body.back()[1];
        int dx=body.back()[2];
        int dy=body.back()[3];
        body.push_back({x-dx,y-dy});
        length++;
        //设置填充色
        setfillcolor(Snake_Body_Color);
        //绘制
        fillroundrect(x-dx-5,y-dy-5,x-dx+5,y-dy+5,6,6);
    }else{
        auto ed1=body.end()-1;
        auto ed2=body.end();
        int x=(*ed1)[0];
        int y=(*ed1)[1];
        int dx=(*ed1)[0]-(*ed2)[0];
        int dy=(*ed1)[1]-(*ed2)[1];

        //新增躯干
        body.push_back({x-dx,y-dy});
        length++;

        //设置填充色
        setfillcolor(Snake_Body_Color);
        //绘制
        fillroundrect(x-dx-5,y-dy-5,x-dx+5,y-dy+5,6,6);
    }
}

//边界检查
bool checkSide(int x,int y){
    if(!(x>245&&x<650&&y>50&&y<440))return false;
    return true;
}

//检查是否咬到蛇身
bool Snake::checkBody(){
    int hx=body.front()[0];
    int hy=body.front()[1];
    for(auto i=body.begin()+2;i<body.end();i++){
        if( abs(hx-(*i)[0])<2 && abs(hy-(*i)[1]) <2) return false;
    }
    return true;
}

bool Snake::Move(int candyx,int candyy,int dirctx,int dircty) {
    //清除队尾
    int x=body.back()[0];
    int y=body.back()[1];
    clearroundrect(x-6,y-6,x+6,y+6,0,0);
    //弹出队尾
    body.pop_back();

    //压入队首
    x=body.front()[0];
    y=body.front()[1];
    body.push_front({x+dirctx,y+dircty,dirctx,dircty});
    //绘制新队首
    setfillcolor(Snake_Body_Color);
    fillroundrect(x-5,y-5,x+5,y+5,0,0);
    setfillcolor(RED);
    fillroundrect(x+dirctx-5,y+dircty-5,x+dirctx+5,y+dircty+5,6,6);

    //边界检查
    if(!checkSide(x,y))return false;
    //咬到蛇身检查
    if(!checkBody())   return false;

    x=body.front()[0];
    y=body.front()[1];
    //判断是否吃到糖果
    if(x>=candyx-5&&x<=candyx+5&&y>=candyy-5&y<=candyy+5) {
        //todo 清除糖果
        GrowUp();
    }
    return true;
}
#endif //SNAKE_SNAKE_H
