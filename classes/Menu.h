//
// Created by Sario's HP on 2023/3/1.
//
#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#pragma once           //保证头文件只被编译一次
#include <windows.h>
#include <iostream>
#include <conio.h>

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
        va_start(next,Screen_Mode);
        width= va_arg(next,int);
        height=va_arg(next,int);
    };

    void Draw();

    void Refresh();
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
void PrintMenu(){
    printf("                                                                                          \n"
           "                        ____                                                                            \n"
           "                      ,'  , `.                    .--.--.                                ,-.            \n"
           "                   ,-+-,.' _ |                   /  /    '.                          ,--/ /|            \n"
           "                ,-+-. ;   , ||                  |  :  /`. /      ,---,             ,--. :/ |            \n"
           "               ,--.'|'   |  ;|                  ;  |  |--`   ,-+-. /  |            :  : ' /             \n"
           "              |   |  ,', |  ':     .--,         |  :  ;_    ,--.'|'   |  ,--.--.   |  '  /      ,---.   \n"
           "              |   | /  | |  ||   /_ ./|          \\  \\    `.|   |  ,\"' | /       \\  '  |  :     /     \\  \n"
           "              '   | :  | :  |,, ' , ' :           `----.   \\   | /  | |.--.  .-. | |  |   \\   /    /  | \n"
           "              ;   . |  ; |--'/___/ \\: |           __ \\  \\  |   | |  | | \\__\\/: . . '  : |. \\ .    ' / | \n"
           "              |   : |  | ,    .  \\  ' |          /  /`--'  /   | |  |/  ,\" .--.; | |  | ' \\ \\'   ;   /| \n"
           "              |   : '  |/      \\  ;   :         '--'.     /|   | |--'  /  /  ,.  | '  : |--' '   |  / | \n"
           "              ;   | |`-'        \\  \\  ;           `--'---' |   |/     ;  :   .'   \\;  |,'    |   :    | \n"
           "              |   ;/             :  \\  \\                   '---'      |  ,     .-./'--'       \\   \\  /  \n"
           "              '---'               \\  ' ;                               `--`---'                `----'   \n"
           "                                   `--`                                                                 "
           "                                                   __                         __                     __      \n"
           "                                                 /\\ \\__                   /\\ \\__               /\\ \\__   \n"
           "            _____   _ __    __    ____    ____   \\ \\ ,_\\   ___         ___\\ \\ ,_\\    __    _ __\\ \\ ,_\\  \n"
           "           /\\ '__`\\/\\`'__\\/'__`\\ /',__\\  /',__\\   \\ \\ \\/  / __`\\      /',__\\ \\ \\/  /'__`\\ /\\`'__\\ \\ \\/  \n"
           "           \\ \\ \\L\\ \\ \\ \\//\\  __//\\__, `\\/\\__, `\\   \\ \\ \\_/\\ \\L\\ \\    /\\__, `\\ \\ \\_/\\ \\L\\.\\\\ \\ \\/ \\ \\ \\_ \n"
           "            \\ \\ ,__/\\ \\_\\\\ \\____\\/\\____/\\/\\____/    \\ \\__\\ \\____/    \\/\\____/\\ \\__\\ \\__/.\\_\\ \\_\\  \\ \\__\\\n"
           "             \\ \\ \\/  \\/_/ \\/____/\\/___/  \\/___/      \\/__/\\/___/      \\/___/  \\/__/\\/__/\\/_/\\/_/   \\/__/\n"
           "              \\ \\_\\                                                                                     \n"
           "               \\/_/                                                                                     \n");


}
//绘制菜单
void Menu::Draw() {
    if(Screen_Mode==2){
        target = GetConsoleWindow(); //获得cmd窗口句柄
        if (target != NULL && target != INVALID_HANDLE_VALUE) {
            // 获取顶层窗口句柄
            parent = GetParent(target);
            while (parent != NULL && parent != INVALID_HANDLE_VALUE) {
                target = parent;
                parent = GetParent(target);
            }
        }
        //获取窗口原始大小
        RECT rect;
        GetWindowRect(target, &rect);

        //重新绘制窗口
        MoveWindow(target, rect.left, rect.top, width, height, true);
    }else {
        printf("%d",Screen_Mode);
        //全屏模式
        full_screen();
    }

    //输出菜单
    PrintMenu();
}

//刷新窗口
void Menu::Refresh() {
    //检测任意按下的任意键 不带回显
    getch();
    //清屏
    system("cls");
}
#endif //SNAKE_MENU_H