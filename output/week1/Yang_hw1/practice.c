#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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




int anslocation=-1, ansdistance=INT_MAX;
int main() {
    readGraph();
    for (int i=1;i<=n;i++)
    {
        int maxdistance=dfs(i,0);
        if (maxdistance<ansdistance)
        {
            ansdistance=maxdistance;
            anslocation=i;
        }
    }
    printf("%d\n", anslocation);
    return 0;
}



int  dfs(int location, int from)
{
    if (neighborCount[location]==1&&neighbor[location][0]==from)
    {
        return 0;
    }
    int distance=0;
    int maxdistance=-1;
    for (int i=0;i<neighborCount[location];i++)
    {
        int x=neighbor[location][i];
        if (x==from) continue;
        distance=dfs(x, location)+1;
        if (distance>maxdistance)
        {
            maxdistance=distance;
        }
    }
    return maxdistance;
}