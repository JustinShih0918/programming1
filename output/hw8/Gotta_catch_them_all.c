#include <stdio.h>
#include <stdlib.h>
int p[105][105] = {}, vis[105][105] = {};
int current_x = 1, current_y = 1, current_way;
int snake_x = 1, snake_y = 1, snake_way = 1;
int target_x, target_y;
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n, m, s;
int check(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}
void teleport() {
	int teleport_x = 1, teleport_y = 1, mn = 100000;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(!vis[i][j] && (abs(p[i][j] - p[current_x][current_y]) < mn || (abs(p[i][j] - p[current_x][current_y]) == mn && p[i][j] < p[teleport_x][teleport_y]))) {
				mn = abs(p[i][j] - p[current_x][current_y]);
				teleport_x = i, teleport_y = j;
			}
		}
	}
	current_x = teleport_x, current_y = teleport_y;
	s--;
}
int snake_move() {
	if(check(snake_x, snake_y + dy[snake_way]) == 0) snake_way = (snake_way + 1) % 2;
	snake_y += dy[snake_way];
}
int search(int x, int y, int way) {
	while((x != snake_x || y != snake_y) && check(x, y)) {
		x += dx[way], y += dy[way];
	}
	return (x == snake_x && y == snake_y);
}
int main() {
	/* read input */
    scanf("%d %d %d", &n, &m, &s);
	int mx = 0, mn = 1000000;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &p[i][j]);
            if(p[i][j] > mx) mx = p[i][j], current_x = i, current_y = j;
            if(p[i][j] < mn) mn = p[i][j], snake_x = i, snake_y = j;
        }
    }
	/* road roller */
	int state = 0;
	while(s != 0 && (current_x != snake_x || current_y != snake_y)) {
		vis[current_x][current_y] = 1;
        if(state == 0) {// searchlight
            for(int i = 0; i < 8; ++i) {
				if(search(current_x, current_y, i) == 1) {
					target_x = snake_x, target_y = snake_y, state = 2;
					current_way = i;
					break;
				}
            }
			if(state == 0) state = 1;
        }
        else if(state == 1) {//teleport
			teleport();
			snake_move();
			state = 0;
        }
        else {//move in direction(current_way)
			if(current_x == target_x && current_y == target_y) state = 0;
			else {
				current_x += dx[current_way], current_y += dy[current_way];
				s--;
				snake_move();
			}
        }
    }
    printf("%d\n", s);
	if(current_x == snake_x && current_y == snake_y) {
        printf("Gotcha!\n");
    }
    else {
        printf("NO Snake QQ~\n");
    }
}
