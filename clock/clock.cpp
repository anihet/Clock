#include "TXLib.h"
#include "cmath"

int ugol = 180;
int ugol2 = 180;
int ugol3 = 180;
int minute = 0;
int hour = 0;

void drawClock (int x, int y, bool tic) {
    // draw clock lines
    txSetColor(TX_BLACK, 5);
    txLine(x+175, y+1, x+175, y+74);//12
    txLine(x+263, y+29, x+232, y+85);//1
    txLine(x+325, y+97, x+274, y+130);//2
    txLine(x+350, y+191, x+289, y+191);//3
    txLine(x+325, y+283, x+272, y+250);//4
    txLine(x+264, y+353, x+232, y+296);//5
    txLine(x+175, y+379, x+175, y+311);//6
    txLine(x+88, y+353, x+120, y+295);//7
    txLine(x+24, y+285, x+78, y+251);//8
    txLine(x+1, y+191, x+63, y+191);//9
    txLine(x+26, y+97, x+77, y+132);//10
    txLine(x+89, y+30, x+119, y+86);//11

    txSetColor(TX_BLACK, 3);
    txCircle(x+175, y+192, 20);

    if (tic) {
        //formuls sec
        int x2 = (295-295)*cos(ugol*M_PI/180)-(160-292)*sin(ugol*M_PI/180)+295;
        int y2 = (295-295)*sin(ugol*M_PI/180)-(160-292)*cos(ugol*M_PI/180)+292;
        //formuls min
        int x3 = (295-295)*cos(ugol2*M_PI/180)-(185-292)*sin(ugol2*M_PI/180)+295;
        int y3 = (295-295)*sin(ugol2*M_PI/180)-(185-292)*cos(ugol2*M_PI/180)+292;
        //formuls hour
        int x4 = (295-295)*cos(ugol3*M_PI/180)-(205-292)*sin(ugol3*M_PI/180)+295;
        int y4 = (295-295)*sin(ugol3*M_PI/180)-(205-292)*cos(ugol3*M_PI/180)+292;

        //sec_arrow
        txSetColor(RGB(127, 127, 127), 3);
        txLine(295, 292, x2, y2);
        ugol -= 6;
        minute += 1;

        //min_arrow
        if (minute == 60) {
            minute -= 60;
            hour += 1;
            txSetColor(RGB(127, 127, 127), 3);
            txLine(295, 292, x3, y3);
            ugol2 -= 6;
        } else {
            txSetColor(RGB(127, 127, 127), 3);
            txLine(295, 292, x3, y3);
        }

        //hour_arrow
        if (hour == 60) {
            hour -= 60;
            txSetColor(RGB(127, 127, 127), 3);
            txLine(295, 292, x4, y4);
            ugol3 -= 30;
        } else{
            txSetColor(RGB(127, 127, 127), 3);
            txLine(295, 292, x4, y4);
        }
    } else {
    }
}

int main() {
    txCreateWindow(600, 600);
    txClear();

    while(true){
        txClear();
        drawClock(120, 100, true);
        txSleep(10);
    }

    return 0;
}
