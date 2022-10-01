#include <stdio.h>
#include <math.h>

void placement(int n, int x, int y, int prev[n])
{
    // print when a solution is met
    if(y == n){
        printf("-----------\n");
        for(int i = 0; i < n; i++){
            printf("%i, %i\n", prev[i]+1, i+1);
        }
        printf("-----------\n");
    }
    // check if x and y are valid
    for(int i = 0; i < y; i++){
        if(prev[i] == -1) continue;
        if(x == prev[i]) return; // horizontal
        if(abs(x-prev[i]) == abs(y-i)) return; // diagonal
    }

    prev[y] = x;
    for(int i = 0; i < n; i++){
        placement(n, i, y+1, prev);
    }
    prev[y] = -1;
}

int main(){
    int n;
    printf("enter n: ");
    scanf("%i", &n);
    int prev[n];

    for(int i = 0; i < n; i++){
        prev[i] = -1;
    }

    for(int i = 0; i < n; i++){
        placement(n, i, 0, prev);
    }
}
