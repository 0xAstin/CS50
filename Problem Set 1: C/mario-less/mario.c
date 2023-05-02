#include <stdio.h>

int get_height(void);

int main(void)
{
    // prompt the user for the pyramid height
    int height = get_height();

    // print the pyramid
    for (int row = 0; row < height; row++)
    {
        // print spaces
        for (int col = 0; col < height - row - 1; col++)
        {
            printf(" ");
        }
        // print hashes
        for (int col = 0; col < row + 1; col++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    } while (height <= 0 || height > 8);
    return height;
}
