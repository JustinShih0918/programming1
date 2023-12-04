#include <stdio.h>
#include <stdlib.h>
#define N 100001

int cable[N][2], neighborCount[N], *neighbor[N];
int n;

void readGraph() {
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &cable[i][0], &cable[i][1]);
        neighborCount[cable[i][0]]++;
        neighborCount[cable[i][1]]++;
    }
    for (int i=1; i<=n; i++) {
        neighbor[i] = (int*)malloc(neighborCount[i] * sizeof(int));
    }
    int neighborIndex[N] = {};
    for (int i=0; i<n-1; i++) {
        int u = cable[i][0], v = cable[i][1];
        neighbor[u][neighborIndex[u]++] = v;
        neighbor[v][neighborIndex[v]++] = u;
    }
}

int dfs(int location,int from){
    int len = 0;
    if(neighborCount[location]==1&&neighbor[location][0]==from){
        return len;
    }
    int maxdistance = -1;
    for(int i = 0;i<neighborCount[location];i++){
        int x = neighbor[location][i];
        if(x==from) continue;
        len = dfs(x,location)+1;
        if(len>maxdistance) maxdistance = len;
    }
    return maxdistance;
}

int main() {
    readGraph();
    int minL = 10000;
    int ansLocation = 0;
    for(int i = 1;i<n;i++){
        int k = dfs(i,0);
        if(minL>k) {
            ansLocation = i;
            minL = k;
        }
    }
    printf("%d\n",ansLocation);
    return 0;
}