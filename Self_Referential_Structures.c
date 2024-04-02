#include <stdio.h>

// Self Referential Structures ->  struct yang menunjuk pada jenis struct yang sama dan punya sifat merujuk dirinya sendiri

// Mendefinisikan Struct bernama KALIMAT yang memiliki variabel alphabet bertipe char, dan link yang merupakan pointer ke struct yang sama, yaitu KALIMAT.
struct KALIMAT{
    char alphabet;
    struct KALIMAT *link;
};

int main(){

    // Variabel dengan tipe struct KALIMAT
    struct KALIMAT l1, l2, l3, l4, l5, l6, l7, l8, l9;

    // Menginisialisasi anggota link dari l1 menjadi NULL dan alphabet menjadi 'F', Dan seterusnya.
    l1.link = NULL;
    l1.alphabet = 'F';

    l2.link = NULL;
    l2.alphabet = 'M';

    l3.link = NULL;
    l3.alphabet = 'A';

    l4.link = NULL;
    l4.alphabet = 'I';

    l5.link = NULL;
    l5.alphabet = 'K';

    l6.link = NULL;
    l6.alphabet = 'T';

    l7.link = NULL;
    l7.alphabet = 'N';

    l8.link = NULL;
    l8.alphabet = 'O';

    l9.link = NULL;
    l9.alphabet = 'R';

    // Dibawah ini membuat linking antar node, dalam hal ini dimulai pada huruf N, yang berlokasi di l7. Sehingga, l7.link = &l1; membuat l7 menunjuk ke l1. Dan Seterusnya
    l7.link = &l1;
    l1.link = &l8;
    l8.link = &l2;
    l2.link = &l5;
    l5.link = &l3;
    l3.link = &l6;
    l6.link = &l9;
    l9.link = &l4;
    l4.link = &l7;

    // Dibawah ini mencetak karakter yang dimulai dari l3. Mengikuti seberapa banyak langkah yang dilakukan untuk baris-baris berikutnya dengan jumlah yang berbeda untuk mencetak kata “INFORMATIKA”.
    printf("%c", l3.link->link->link->alphabet); // Output: "I"
    printf("%c", l3.link->link->link->link->alphabet); // Output: "N"
    printf("%c", l3.link->link->link->link->link->alphabet); // Output: "F"
    printf("%c", l3.link->link->link->link->link->link->alphabet); // Output: "O"
    printf("%c", l3.link->link->alphabet); // Output: "R"
    printf("%c", l3.link->link->link->link->link->link->link->alphabet); // Output: "M"
    printf("%c", l3.alphabet); // Output: "A"
    printf("%c", l3.link->alphabet); // Output: "T"
    printf("%c", l3.link->link->link->alphabet); // Output: "I"
    printf("%c", l3.link->link->link->link->link->link->link->link->alphabet); // Output: "K"
    printf("%c", l3.alphabet); // Output: "A"

    return 0;
}
