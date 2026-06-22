#include<ncurses.h>
#include<iostream>
#include<unistd.h>
using namespace std;

int main(){

    initscr();
    cbreak();
    noecho();
    curs_set(0);

    mvprintw(0,0,"SysteM MonitoR");
    mvprintw(8,5,"Press q to quit");
    refresh();

    sleep(3);
    endwin();;
    
return 0;

}