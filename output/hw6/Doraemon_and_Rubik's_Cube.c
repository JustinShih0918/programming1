#include <stdio.h>
#define UP 0
#define LEFT 1
#define FRONT 2
#define RIGHT 3
#define BACK 4
#define DOWN 5

char rubiks[6][4];
char rotateIndex[6][3][4][2] = {
    {{{0, 0}, {0, 2}, {0, 3}, {0, 1}}, {{1, 0}, {2, 0}, {3, 0}, {4, 0}}, {{1, 1}, {2, 1}, {3, 1}, {4, 1}}},
    {{{1, 0}, {1, 2}, {1, 3}, {1, 1}}, {{4, 1}, {5, 2}, {2, 2}, {0, 2}}, {{4, 3}, {5, 0}, {2, 0}, {0, 0}}},
    {{{2, 0}, {2, 2}, {2, 3}, {2, 1}}, {{1, 1}, {5, 0}, {3, 2}, {0, 3}}, {{1, 3}, {5, 1}, {3, 0}, {0, 2}}},
    {{{3, 0}, {3, 2}, {3, 3}, {3, 1}}, {{2, 1}, {5, 1}, {4, 2}, {0, 1}}, {{2, 3}, {5, 3}, {4, 0}, {0, 3}}},
    {{{4, 0}, {4, 2}, {4, 3}, {4, 1}}, {{3, 1}, {5, 3}, {1, 2}, {0, 0}}, {{3, 3}, {5, 2}, {1, 0}, {0, 1}}},
    {{{5, 0}, {5, 2}, {5, 3}, {5, 1}}, {{1, 3}, {4, 3}, {3, 3}, {2, 3}}, {{1, 2}, {4, 2}, {3, 2}, {2, 2}}}
};
char colors[6] = {'W', 'O', 'B', 'G', 'Y', 'R'};
int n;

void readRubiksState() {
    char state[30];
    scanf("%d %s", &n, state);
    for (int i=0; i<6; i++) {
        for (int j=0; j<4; j++) {
            rubiks[i][j] = state[i * 4 + j];
        }
    }
}

// Pass UP/LEFT/FRONT/RIGHT/BACK/DOWN as parameters to perform the move
void move(int face) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int ax = rotateIndex[face][i][j][0];
            int ay = rotateIndex[face][i][j][1];
            int bx = rotateIndex[face][i][j+1][0];
            int by = rotateIndex[face][i][j+1][1];
            char tmp = rubiks[ax][ay];
            rubiks[ax][ay] = rubiks[bx][by];
            rubiks[bx][by] = tmp;
        }
    }
}

// Print the Rubik's Cube state for debugging purposes
void printRubiks() {
    printf("  %c%c\n  %c%c\n", rubiks[0][0], rubiks[0][1], rubiks[0][2], rubiks[0][3]);
    for (int i=1; i<5; i++) printf("%c%c", rubiks[i][0], rubiks[i][1]);
    printf("\n");
    for (int i=1; i<5; i++) printf("%c%c", rubiks[i][2], rubiks[i][3]);
    printf("\n  %c%c\n  %c%c\n", rubiks[5][0], rubiks[5][1], rubiks[5][2], rubiks[5][3]);
    printf("\n");
}

// Return 1 if the Rubik's Cube is solved, otherwise return 0
int isSolved() {
    int status = 0;
    for (int i=0; i<6; i++) {
        for (int j=1; j<4; j++) if (rubiks[i][0] != rubiks[i][j]) return 0;
        for (int j=0; j<6; j++) {
            if (colors[j] == rubiks[i][0]) {
                status |= (1<<j);
                break;
            }
        }
    }
    return ((1 << 6) - 1 == status);
}

// Return 1 if the Rubik's Cube can be solved within n moves, otherwise return 0
int solve(int n) {
    // TODO: utilize move(), printRubiks(), isSolved() to implement the function
    if(n==0){
        if(isSolved()) {
            //printf("Complete\n");
            //printRubiks();
            return 1;
        }
        else {
            //printf("Finish\n");
            //printRubiks();
            return 0;
        }
    }
    else{

        if(isSolved()) {
            //printf("Complete at n=%d\n",n);
            //printRubiks();
            return 1;
        }
        
        //do recursion
        for(int i = 1;i<=6;i++){
            switch (i)
            {
            case 1:
                //printf("At step%d, I use UP\n",n);
                move(UP);
                //printRubiks();
                if(solve(n-1)) return 1;
                break;
            case 2:
                //printf("At step%d, I use LEFT\n",n);
                move(LEFT);
                //printRubiks();
                if(solve(n-1)) return 1;
                break;
            case 3:
                //printf("At step%d, I use FRONT\n",n);
                move(FRONT);
                //printRubiks();
                if(solve(n-1)) return 1;
                break;
            case 4:
                //printf("At step%d, I use RIGHT\n",n);
                move(RIGHT);
                //printRubiks();
                if(solve(n-1)) return 1;
                break;
            case 5:
                //printf("At step%d, I use BACK\n",n);
                move(BACK);
                //printRubiks();
                if(solve(n-1)) return 1;
                break;
            case 6:
                //printf("At step%d, I use DOWN\n",n);
                move(DOWN);
                //printRubiks();
                if(solve(n-1)) return 1;
                break;
            }
        
            //reset
            switch (i)
            {
            case 1:
                move(UP);
                move(UP);
                move(UP);
                break;
            case 2:
                move(LEFT);
                move(LEFT);
                move(LEFT);
                break;
            case 3:
                move(FRONT);
                move(FRONT);
                move(FRONT);
                break;
            case 4:
                move(RIGHT);
                move(RIGHT);
                move(RIGHT);
                break;
            case 5:
                move(BACK);
                move(BACK);
                move(BACK);
                break;
            case 6:
                move(DOWN);
                move(DOWN);
                move(DOWN);
                break;
            }
        
        }
    }

    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        readRubiksState();
        printf("%s", (solve(n) ? "Yes\n" : "No\n"));
    }
    return 0;
}

//testing