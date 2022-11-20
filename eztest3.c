#include <stdio.h>

struct Pos
{
	int x;
	int y;
};
void horse(struct Pos steps[], int x, int y, int stepCount)
{
    int isValidPos = 0;
    int i;
    if (stepCount == 64)
    {
         printf("||\n");
         for (i = 0; i < 64; i++)
         {
             printf("%c, %i\n", steps[i].x+97, steps[i].y+1);
         }
         printf("||");
    }
    else
    {

        for (i = 0; i < stepCount-1; i++)
        {
            if (steps[i].x == x && steps[i].y == y)
                break;
        }

        if (x < 8 && x >= 0 && y < 8 && y >= 0 && i == stepCount-1)
        {
            isValidPos = 1;

            //printf("%i, %i - %i\n", x, y, stepCount);
            steps[stepCount].x = x;
            steps[stepCount].y = y;
			
            stepCount++;
			
            horse(steps, x + 2, y + 1, stepCount);
            horse(steps, x + 2, y + -1, stepCount);
            horse(steps, x + 1, y + 2, stepCount);
            horse(steps, x + 1, y - 2, stepCount);
            horse(steps, x - 2, y + 1, stepCount);
            horse(steps, x - 2, y + -1, stepCount);
            horse(steps, x - 1, y + 2, stepCount);
            horse(steps, x - 1, y - 2, stepCount);
        }
    }
}
int main()
{

    struct Pos steps[64];
    for (size_t i = 0; i < 64; i++)
    {
        steps[i].x = 0;
        steps[i].y = 0;
    }

    for (int i = 0; i < 8; i++)
    { 
        for (int j = 0; j < 8; j++)
        {
            printf("%i, %i\n", i, j);

            horse(steps, i, j, 1);
        }
    }
}
