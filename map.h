#ifndef MAP_H
#define MAP_H
#include <cstring>
#include "block.h"
const int ROW_COUNT = 20;
const int COL_COUNT = 10;

enum occupation {
    VIDE=0,BLOCK=1,BLOCK_P=2
};

class map{
//private:
public:
    int status[ROW_COUNT][COL_COUNT];
    block block_p;
    block block_next;
    int blockCenter[2]={0,0};
    bool endOfGame=false;

    map();
    void show();
    bool nextBlock();
    bool down();
    bool left();
    bool right();
    bool rotation();
    void removeRaw();
};

map::map(){
    std::memset(status,VIDE,sizeof(status));
    blockCenter[1] = 5;
    //std::cout << block_p.statu << " " << block_p.code << std::endl;
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=BLOCK_P;
}

void map::show(){
    for (int i=0;i<ROW_COUNT;i++){
        for (int j=0;j<COL_COUNT;j++)
            std::cout << status[i][j];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool map::down(){
    for (int i=0;i<4;i++){
        if(status[1+blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]==BLOCK
           ||1+blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]>=ROW_COUNT)
        return false;
    }

    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=VIDE;
    for (int i=0;i<4;i++)
        status[1+blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=BLOCK_P;
    blockCenter[0]++;
    return true;
}

bool map::left(){
    for (int i=0;i<4;i++){
        if(status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][-1+blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]==BLOCK
           ||blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]-1<0)
        return false;
    }
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=VIDE;
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][-1+blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=BLOCK_P;
    blockCenter[1]--;
    return true;
}

bool map::right(){
    for (int i=0;i<4;i++){
        if(status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][1+blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]==BLOCK
           ||blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]+1>=COL_COUNT)
           {
            for (int j=0;i<4;i++)
                status[blockCenter[0]+blocks[block_p.code][block_p.statu][j][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][j][1]]=BLOCK;
            return false;
           }

    }
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=VIDE;
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][1+blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=BLOCK_P;
    blockCenter[1]++;
    return true;
}

bool map::rotation(){
    int statu_next;
    if (block_p.statu==3) statu_next=0;
    else statu_next=1+block_p.statu;

    for (int i=0;i<4;i++){
        if(status[blockCenter[0]+blocks[block_p.code][statu_next][i][0]][blockCenter[1]+blocks[block_p.code][statu_next][i][1]]==BLOCK
           ||blockCenter[1]+blocks[block_p.code][statu_next][i][1]>=COL_COUNT
           ||blockCenter[1]+blocks[block_p.code][statu_next][i][1]<0
           ||blockCenter[0]+blocks[block_p.code][statu_next][i][0]>=ROW_COUNT
           ||blockCenter[0]+blocks[block_p.code][statu_next][i][0]<0)
        return false;
    }
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=VIDE;
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][statu_next][i][0]][blockCenter[1]+blocks[block_p.code][statu_next][i][1]]=BLOCK_P;
    block_p.statu=statu_next;
    return true;
}

void map::removeRaw(){
 for (int i = ROW_COUNT-1; i >= 0; i--){
        int x = 0;
        for (int j = 0; j < COL_COUNT; j++)
            x +=status[i][j];
        if (x == COL_COUNT*BLOCK){
            for (int m = i; m >= 0; m--)
                for (int n = 0; n < COL_COUNT; n++)
                    if (m==0)status[m][n]=0;
                    else
                    status[m][n] = status[m - 1][n];
            ++i;
        }
    }
}

bool map::nextBlock(){
    blockCenter[1] = 5;
    blockCenter[0] = 0;
    block_p=block_next;
    block_next.newBlock();
    for (int i=0;i<4;i++){
        if(status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]==BLOCK)
        {
            endOfGame=true;
            return false;
        }
    }
    for (int i=0;i<4;i++)
        status[blockCenter[0]+blocks[block_p.code][block_p.statu][i][0]][blockCenter[1]+blocks[block_p.code][block_p.statu][i][1]]=BLOCK_P;
    return true;
}

#endif // MAP_HPP_INCLUDED
