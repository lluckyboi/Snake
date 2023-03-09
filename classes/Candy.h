//
// Created by Sario's HP on 2023/3/1.
//

#ifndef SNAKE_CANDY_H
#define SNAKE_CANDY_H


#include <ctime>

class Candy {
private:
    bool isExt;
public:
    int  locx;
    int  locy;
    bool IsExt(){return isExt;}
    Candy(){
        srand(time(0));
        locx=0;
        locy=0;
        isExt= false;
    }
    void Refresh(){
        if(isExt) return;
        locx=P_Left+rand()%330;
        locy=P_Top+rand()%330;
        isExt= true;
    }
    void Eat(){
        isExt= false;
    }
    void Draw(){
        setfillcolor(YELLOW);
        fillcircle(locx,locy,5);
    }
    void Clear(){
        clearcircle(locx,locy,6);
    }
};


#endif //SNAKE_CANDY_H
