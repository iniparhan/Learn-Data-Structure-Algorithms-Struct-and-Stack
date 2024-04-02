#include <stdio.h>

// Fungsi twoStacks untuk menghitung jumlah elemen maksimum yang bisa diambil
int twoStacks(int maxSum, int array_1[], int banyak_array_1, int array_2[], int banyak_array_2) {
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;

    // Loop untuk menjumlah angka di dalam array pertama, dan akan trus berjalan jika kurang dari banyak_array_1 dan blum lebih dari maxSum
    printf("Langkah 1: mengambil elemen dari tumpukan A hingga melebihi max jumlah atau mencapai akhir:\n");
    while(i < banyak_array_1 && sum + array_1[i] <= maxSum) {
        sum += array_1[i];  // Menjumlahkan sum dengan array pertama
        printf("%d ", array_1[i]); 
        i++;
    }
    count = i; // Jumlah elemen yang diambil dari tumpukan A

    printf("\nTumpukan A: ");
    for(int a = 0; a < i; a++){
        printf("%d ", array_1[a]);
    }
    printf("\nTumpukan B: ");
    for(int b = 0; b < j; b++){
        printf("%d ", array_2[b]);
    }
    printf("\n\n");

    // Loop untuk Menjumlahkan sum dengan array kedua, dan akan trus berjalan jika j kurang dari banyak_array_2 dan i lebih dari sama dengan nol
    while(j < banyak_array_2 && i >= 0) {
        sum += array_2[j];  // Menjumlahkan sum dengan array kedua
        j++;

        // Loop untuk mengurangkan sum dengan array sesuai dengan i supaya tidak lebih dari maxSum
        while(sum > maxSum && i > 0) {
            i--;
            sum -= array_1[i];
        }
        
         // Membandingkan jika sum jika kurang sama dengan dari maxSum dan i + j lebih dari count, maka akan menjumlah i dan j dalam variabel count
        if(sum <= maxSum && i + j > count) {
            count = i + j;
        }

        // mengambil elemen dari tumpukan B
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
    int g;  // variabel banyaknya berapa kali dilakukan permainan ini
    printf("Masukkan Angka\n");
    scanf("%d", &g);

    // Dibawah ini merupakan perulangan permainan
    while(g--) {
        int banyak_array_1;  // Variabel banyak_array_1 -> banyaknya array pertama

        int banyak_array_2;  // Variabel banyak_array_2 -> banyaknya array kedua

        int maxSum;   // Variabel maxSum -> maximal jumlah angka yang ditentukan

        scanf("%d %d %d", &banyak_array_1, &banyak_array_2, &maxSum);

        int array_1[banyak_array_1]; // Variabel array_1 -> array pertama sebanyak banyak_array_1

        int array_2[banyak_array_2]; // Variabel array_2 -> array kedua sebanyak banyak_array_2

        // Perulangan untuk menginput angka pada array pertama sesuai dengan banyaknya array yang diinput
        for(int i=0; i<banyak_array_1; i++)
            scanf("%d", &array_1[i]);

        // Perulangan untuk menginput angka pada array kedua sesuai dengan banyaknya array yang diinput
        for(int i=0; i<banyak_array_2; i++)
            scanf("%d", &array_2[i]);

        // Proses pemanggilan fungsi sekaligus mencetak outputnya
        printf("%d\n", twoStacks(maxSum, array_1, banyak_array_1, array_2, banyak_array_2));
    }
    return 0;
}
