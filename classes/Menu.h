//
// Created by Sario's HP on 2023/3/1.
//
#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#pragma once           //保证头文件只被编译一次
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <graphics.h>
#include "Map.h"
#include "../const/const.h"

#define FO(i,n) for(int i=0;i<n;i++)

using namespace std;

class Menu {
private:
    HWND target{};         // 目标窗口句柄
    HWND parent{};         // 目标父窗口句柄
    INT  width, height;  // 窗口新宽高
    INT  Screen_Mode{};    //窗口模式 2自定义，0全屏
public:
    //可变参数方式进行配置 2自定义，0全屏
    explicit Menu(int S_C,...){
        Screen_Mode=S_C;
        //可变参数列表
        va_list next;
        va_start(next,S_C);
        width= va_arg(next,int);
        height=va_arg(next,int);
    };

    void Draw();
    bool Start();
    void PrintMenu();
};

//全屏模式
void full_screen()
{
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* 获取窗口信息 */
    /* 设置窗口信息 最大化 取消标题栏及边框 */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

//菜单打印
void Menu::PrintMenu(){
    //改颜色
    system("color 02");
    //如果是全屏模式，调整一下菜单位置
   if (Screen_Mode==0){
       FO(i,20)printf("\n");
       printf("                                                                                                                                      \n"
              "                                                            ____                                                                            \n"
              "                                                          ,'  , `.                    .--.--.                                ,-.            \n"
              "                                                       ,-+-,.' _ |                   /  /    '.                          ,--/ /|            \n"
              "                                                    ,-+-. ;   , ||                  |  :  /`. /      ,---,             ,--. :/ |            \n"
              "                                                   ,--.'|'   |  ;|                  ;  |  |--`   ,-+-. /  |            :  : ' /             \n"
              "                                                  |   |  ,', |  ':     .--,         |  :  ;_    ,--.'|'   |  ,--.--.   |  '  /      ,---.   \n"
              "                                                  |   | /  | |  ||   /_ ./|          \\  \\    `.|   |  ,\"' | /       \\  '  |  :     /     \\  \n"
              "                                                  '   | :  | :  |,, ' , ' :           `----.   \\   | /  | |.--.  .-. | |  |   \\   /    /  | \n"
              "                                                  ;   . |  ; |--'/___/ \\: |           __ \\  \\  |   | |  | | \\__\\/: . . '  : |. \\ .    ' / | \n"
              "                                                  |   : |  | ,    .  \\  ' |          /  /`--'  /   | |  |/  ,\" .--.; | |  | ' \\ \\'   ;   /| \n"
              "                                                  |   : '  |/      \\  ;   :         '--'.     /|   | |--'  /  /  ,.  | '  : |--' '   |  / | \n"
              "                                                  ;   | |`-'        \\  \\  ;           `--'---' |   |/     ;  :   .'   \\;  |,'    |   :    | \n"
              "                                                  |   ;/             :  \\  \\                   '---'      |  ,     .-./'--'       \\   \\  /  \n"
              "                                                  '---'               \\  ' ;                               `--`---'                `----'   \n"
              "                                                                       `--`                                                                 "
              "                                                                                                                                           \n"
              "                                                                                     /\\ \\__                   /\\ \\__               /\\ \\__           \n"
              "                                                _____   _ __    __    ____    ____   \\ \\ ,_\\   ___         ___\\ \\ ,_\\    __    _ __\\ \\ ,_\\  \n"
              "                                               /\\ '__`\\/\\`'__\\/'__`\\ /',__\\  /',__\\   \\ \\ \\/  / __`\\      /',__\\ \\ \\/  /'__`\\ /\\`'__\\ \\ \\/  \n"
              "                                               \\ \\ \\L\\ \\ \\ \\//\\  __//\\__, `\\/\\__, `\\   \\ \\ \\_/\\ \\L\\ \\    /\\__, `\\ \\ \\_/\\ \\L\\.\\\\ \\ \\/ \\ \\ \\_ \n"
              "                                                \\ \\ ,__/\\ \\_\\\\ \\____\\/\\____/\\/\\____/    \\ \\__\\ \\____/    \\/\\____/\\ \\__\\ \\__/.\\_\\ \\_\\  \\ \\__\\\n"
              "                                                 \\ \\ \\/  \\/_/ \\/____/\\/___/  \\/___/      \\/__/\\/___/      \\/___/  \\/__/\\/__/\\/_/\\/_/   \\/__/\n"
              "                                                  \\ \\_\\                                                                                     \n"
              "                                                   \\/_/                                                                                     \n");
   }else {

   }
}

//绘制菜单
void Menu::Draw() {
    if(Screen_Mode==2){
        //窗口模式
        ShowWindow(target,SW_HIDE);
        initgraph(width, height, 0);
        setbkcolor(Default_BK_Color);
        cleardevice();
    }else {
        //全屏模式
        full_screen();
    }

    //输出菜单
    PrintMenu();
}

//绘制按钮
void DrawBottom(int x,int y,int w,int h,char* text,int bt_color,int font_color){
    //设置背景模式-透明
    setbkmode(TRANSPARENT);

    //设置填充色为默认填充色
    setfillcolor(bt_color);

    //绘制圆角矩阵
    fillroundrect(x,y,x+w,y+h,10,10);

    //字体设置
    LOGFONT f;
    gettextstyle(&f);
    settextstyle(30,0,Default_Font);
    settextcolor(font_color);
    f.lfQuality = ANTIALIASED_QUALITY;//打磨字体 使字体变得更加光滑

    //绘制文字
    int tx = x + (w - textwidth(text)) / 2;
    int ty = y + (h - textheight(text)) / 2;
    outtextxy(tx, ty, text);
}

//按钮消息
int BottomMsg(){
    ExMessage msg; //声明一个消息指针
    while (true) {
        //鼠标行为
        if (peekmessage(&msg, EM_MOUSE)) {
            switch (msg.message)
            {
                //鼠标按键
                case WM_LBUTTONDOWN:
                    //开始游戏
                    if (msg.x >= 400 && msg.x <= 400 + 180 && msg.y >= 80 && msg.y <= 80 + 40)
                    {
                        return 1;
                    }
                    //设置游戏
                    if (msg.x >= 400 && msg.x <= 400 + 180 && msg.y >= 200 && msg.y <= 200 + 40){
                        outtextxy(0,0,"input speed level 1-5");
                        int c=getch();
                        return c;
                    }
                    //退出游戏
                    if (msg.x >= 400 && msg.x <= 400 + 180 && msg.y >= 320 && msg.y <= 320 + 40)
                        return 0;
                //鼠标悬停
                case WM_MOUSEMOVE:
                    if (msg.x >= 400 && msg.x <= 400 + 180 && msg.y >= 80 && msg.y <= 80 + 40)
                        DrawBottom(400,80,180,40,"start game",Default_Bottom_Color,Selected_Font_Color);
                    else if (msg.x >= 400 && msg.x <= 400 + 180 && msg.y >= 200 && msg.y <= 200 + 40)
                        DrawBottom(400,200,180,40,"setting game",Default_Bottom_Color,Selected_Font_Color);
                    else if (msg.x >= 400 && msg.x <= 400 + 180 && msg.y >= 320 && msg.y <= 320 + 40)
                        DrawBottom(400,320,180,40,"quit game",Default_Bottom_Color,Selected_Font_Color);
                    else {
                        DrawBottom(400,80,180,40,"start game",Default_Bottom_Color,WHITE);
                        DrawBottom(400,200,180,40,"setting game",Default_Bottom_Color,WHITE);
                        DrawBottom(400,320,180,40,"quit game",Default_Bottom_Color,WHITE);
                    }
                    break;
                default:
                    break;
            }
        }
    }

}
//开始窗口
bool Menu::Start() {
    //检测任意按下的任意键 不带回显
    getch();
    //隐藏cmd
    ShowWindow(target,SW_HIDE);

    if(Screen_Mode==0){
        initgraph(Default_Width, Default_Height, 0);
        setbkcolor(Default_BK_Color);
        cleardevice();
    }

    //绘制开始按钮
    DrawBottom(400,80,180,40,"start game",Default_Bottom_Color,WHITE);
    //绘制设置按钮
    DrawBottom(400,200,180,40,"setting game",Default_Bottom_Color,WHITE);
    //绘制退出按钮
    DrawBottom(400,320,180,40,"quit game",Default_Bottom_Color,WHITE);

    //开始获取行为消息
    return BottomMsg();
}


#endif //SNAKE_MENU_H
