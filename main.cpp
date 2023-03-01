#include <iostream>
#include "classes/Menu.h"
#include "const/const.h"

//绘制菜单
void DrawMenu(){
    Menu *menu =new Menu(2,Default_Weight,Default_Height);
    menu->Draw();
    menu->Refresh();
}

int main() {
    DrawMenu();
    return 0;
}
