#include <iostream>
#include <math.h>

#define X 1000
#define Y 1000

using namespace std;

class Ant{
private:
    unsigned int x;
    unsigned int y;
    unsigned int ornt;
    unsigned int col;

public:
    Ant(unsigned int x_cord, unsigned int y_cord, unsigned int orientation, unsigned int colour){
        x = x_cord;
        y = y_cord;
        ornt = orientation;
        col = colour;
    }

    //getters
    void setX(unsigned int x_cord){
        x = x_cord;
    }
    void setY(unsigned int y_cord){
        y = y_cord;
    }
    void setOrnt(unsigned int orientation){
        ornt = orientation;
    }
    void setColour(unsigned int colour){
        col = colour;
    }

    //setters
    unsigned int getX(){
        return x;
    }
    unsigned int getY(){
        return y;
    }
    unsigned int getOrnt(){
        return ornt;
    }
    unsigned int getColour(){
        return col;
    }

    
    void move(){
        if(col == 0){           //white
            col = 1;
            ornt--;
            if(ornt < 2){
                ornt = 5;
            }
            switch(ornt){
                case 2:         //up
                    x--;
                    break;
                case 3:         //left
                    y--;
                    break;
                case 4:         //down
                    x++;
                    break;
                case 5:         //right
                    y++;
                    break;
            }
        }
        else if(col == 1){      //black
            col = 0;
            ornt++;
            if(ornt > 5){
                ornt = 2;
            }
            switch(ornt){
                case 2:         //up
                    x--;
                    break;
                case 3:         //left
                    y--;
                    break;
                case 4:         //down
                    x++;
                    break;
                case 5:         //right
                    y++;
                    break;
            }
        }else{
            cout << "Fatal error!" << endl;
        }
    }

};
unsigned int invert(unsigned int x){
    if(x)
        return 0;
    else
        return 1;
}


int main(){
    unsigned int grid[X][Y] = {0};

    Ant ant(200, 200, 3, 0);

    for(int i = 0; i < 11000; i++){
        if(ant.getX() <= X && ant.getY() <= Y && ant.getX() >= 0 && ant.getY() >= 0){       //checking if we are outside grid
            //saving the coordinates before moving
            unsigned int x = ant.getX();
            unsigned int y = ant.getY();
            ant.move();
            if(ant.getX() <= X && ant.getY() <= Y && ant.getX() >= 0 && ant.getY() >= 0){   //checking if we are outside grid again beacuse x and y are changed
                ant.setColour(grid[ant.getX()][ant.getY()]);                                //setting the colour of cell we are currently on
                grid[x][y] = invert(grid[x][y]);                                            //changing colour of the cell we were previously on
            }else{
                cout << "You have exited the grid!" << endl;
                break;
            }
        }else{
            cout << "You have exited the grid!" << endl;
            break;
        }
    }

    //printing a part of a grid
    cout << "Ant position: " << ant.getX() << ", " << ant.getY() << " orientation: " << ant.getOrnt() << endl;
    for(int i = 180; i < 220; i++){
        for(int j = 180; j < 220; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}