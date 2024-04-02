#include <stdio.h>

int twoStacks(int maxSum, int array_1[], int banyak_array_1, int array_2[], int banyak_array_2) {
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;

    printf("Langkah 1: mengambil elemen dari tumpukan A hingga melebihi max jumlah atau mencapai akhir:\n");
    while(i < banyak_array_1 && sum + array_1[i] <= maxSum) {
        sum += array_1[i];
        printf("%d ", array_1[i]); 
        i++;
    }
    count = i;

    printf("\nTumpukan A: ");
    for(int a = 0; a < i; a++){
        printf("%d ", array_1[a]);
    }
    printf("\nTumpukan B: ");
    for(int b = 0; b < j; b++){
        printf("%d ", array_2[b]);
    }
    printf("\n\n");

    while(j < banyak_array_2 && i >= 0) {
        sum += array_2[j]; 
        j++;
        while(sum > maxSum && i > 0) {
            i--;
            sum -= array_1[i];
        }
        if(sum <= maxSum && i + j > count) {
            count = i + j;
        }
        printf("Langkah %d: mengambil elemen dari tumpukan B hingga melebihi max jumlah atau mencapai akhir\n", j + 1);
        printf("Tumpukan A: ");
        for(int a = 0; a < i; a++){
            printf("%d ", array_1[a]);
        }
        printf("\nTumpukan B: ");
        for(int b = 0; b < j; b++){
            printf("%d ", array_2[b]);
        }
        printf("\n\n");
    }
    return count;
}

int main() {
    int g; 
    printf("Masukkan Angka\n");
    scanf("%d", &g);

    while(g--) {
        int banyak_array_1;
        int banyak_array_2;
        int maxSum;
        
        scanf("%d %d %d", &banyak_array_1, &banyak_array_2, &maxSum);
        
        int array_1[banyak_array_1];
        int array_2[banyak_array_2];

        for(int i=0; i<banyak_array_1; i++)
            scanf("%d", &array_1[i]);

        for(int i=0; i<banyak_array_2; i++)
            scanf("%d", &array_2[i]);

        printf("%d\n", twoStacks(maxSum, array_1, banyak_array_1, array_2, banyak_array_2));
    }
    return 0;
}
