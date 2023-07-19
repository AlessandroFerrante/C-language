#include <stdio.h>
#include <string.h>

void bubbleSort(char matrix[][3][20]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3 - 1 - j; k++) {
                if (strcmp(matrix[i][k], matrix[i][k + 1]) > 0) {
                    // Scambia le stringhe
                    char temp[20];
                    strcpy(temp, matrix[i][k]);
                    strcpy(matrix[i][k], matrix[i][k + 1]);
                    strcpy(matrix[i][k + 1], temp);
                }
            }
        }
    }
}

int main() {
    char matrix[3][3][20] = {{"3", "6", "9"},
                             {"8", "10", "2"},
                             {"9", "0", "5"}};

    printf("Matrice non ordinata:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }

    bubbleSort(matrix);

    printf("\nMatrice ordinata:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
