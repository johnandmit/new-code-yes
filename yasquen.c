#include <stdio.h>
#include <math.h>

void placement(int n, int x, int y, int prev[n])
{
    // check if x and y are valid
    for(int i = 0; i < y; i++){
        if(x == prev[i]) return; // horizontal
        if(abs(x-prev[i]) == abs(y-i)) return; // diagonal
    }

    prev[y] = x;
    // print when a solution is met
    if(y == n-1){
        printf("-----------\n");
        for(int i = 0; i < n; i++){
            printf("%i, %i\n", i+1, prev[i]+1);
        }
        printf("-----------\n");
    }else{
        for(int i = 0; i < n; i++){
            placement(n, i, y+1, prev);
        }
    }
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%i", &n);
    int prev[n];

    for(int i = 0; i < n; i++){
        placement(n, i, 0, prev);
    }
}
