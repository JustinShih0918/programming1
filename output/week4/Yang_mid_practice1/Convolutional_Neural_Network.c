#include <stdio.h>
#include <string.h>


int main(void){
    int T;
    scanf("%d",&T);
    int times = 1;
    while(times<=T){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int image[n][n];
        int filter[m][m];
        memset(image,0,sizeof(image));
        memset(filter,0,sizeof(filter));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                scanf("%d",&image[i][j]);
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<m;j++){
                scanf("%d",&filter[i][j]);
            }
        }


        //Horizontally flip the input image to enable the CNN to handle images with varying orientation.
        int temp = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n/2;j++){
                temp = image[i][j];
                image[i][j] = image[i][n-1-j];
                image[i][n-1-j] = temp;
            }
        }

        //Apply convolution using a filter to the flipped image.
        //judge how many values exceed the given threshold k
        int c[n-m+1][n-m+1];
        int amount = 0;
        memset(c,0,sizeof(c));
        for(int i = 0;i<n-m+1;i++){
            for(int j = 0;j<n-m+1;j++){
                for(int x = 0;x<m;x++){
                    for(int y = 0;y<m;y++){
                        c[i][j] += image[i+x][j+y]*filter[x][y];
                    }
                }
                if(c[i][j]>k){
                    amount++;
                }
            }
        }
        
        //print and answer

        printf("%d\n",amount);
        times++;
    }
}
