#include <iostream>
#include "classes/Menu.h"
#include "const/const.h"

//绘制菜单
void DrawMenu(){
    Menu *menu =new Menu(0, Default_Width, Default_Height);
    menu->Draw();
    menu->Refresh();
}

int main() {
    DrawMenu();
    system("pause");
    return 0;
}
