#include <stdio.h>
void HanoiTower(int n, char start, char finish, char spare)
{
    if(n == 1)
    {
        printf("move disc from %c to %c\n", start, finish);
    }
    else
    {
        HanoiTower(n-1,start,spare,finish);
        HanoiTower(1,start,finish,spare);
        HanoiTower(n-1,spare,finish,start);
    }
}
int main()
{
    int n;
    char start = 'a', spare = 'b', finish = 'c';
    printf("enter num of disk: ");
    scanf("%i",&n);
    HanoiTower(n,start,finish,spare);
}
