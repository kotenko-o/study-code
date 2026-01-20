#include <stdio.h>

int main() {
    const int A_INDEX = 65;
    for (int i = 8; i >= 1; i--) 
    {
        for (int j = 0; j < 8; j++) 
        {
            printf("%c%d ", A_INDEX + j, i);
        }
        printf("\n");
    }
    return 0;
}