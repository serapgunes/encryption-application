#include <stdio.h>
#include <stdlib.h>

int basamali_sayi_5() {
    int sayi;
    char str[2];
    printf("-------------------------------------------------------------------------------------\n");
    printf("*********************************Sifreleme Programi**********************************\n");
    printf("-------------------------------------------------------------------------------------\n");

    do {
        printf("Lutfen 5 basamakli bir sayi giriniz: ");
        scanf("%d", &sayi);
    } while (sayi < 10000 || sayi > 99999); // Girilen sayının 5 basamaklı olup olmadığını kontrol ediyoruz.
    // 5 basamaklı bir sayı, 10000 den küçük olamaz ve 99999'dan büyük olamaz.Eğer ki sayı beş basamaklı değilse tekrar sorulacak.

    printf("Sayi girisi basarili,sayiyi sifrelemek icin P ye cikmak icin E ye basiniz!\n");
    scanf("%s",str);

    if(str[0] == 'P' || str[0] == 'p') {// burada [0] sıfırıncı indexi kullanmamın sebebi str için girilecek olan stringin ilk kısmını almak.
        // p yada e girilince otomatikmen sıfırıncı indexi alınmış olur bu da s veya c harfleri olmalıdır aksini kabul etmeyecek.

        int birler, onlar, yuzler, binler, onbinler, onbinler_1, binler_1, yuzler_1, onlar_1, birler_1;//değişkenleri tanımladım.

        // bu kısımda önce basamaklara ayırmamın sebebi rakama dönüştürmek ki daha sonradan rakam olarak algılansın.
        birler = sayi % 10;
        sayi /= 10;
        onlar = sayi % 10;
        sayi /= 10;
        yuzler = sayi % 10;
        sayi /= 10;
        binler = sayi % 10;
        sayi /= 10;
        onbinler = sayi % 10;

        // burada da ayrılan her bir basamagi 9 ile toplayıp ve 10 ile modunu aldım ve yukarıda oluşan rakamlarla, tanımladığım öteki
        // değişkenleri şifreleyecek şekilde eşleştirdim onbinler basamağı ile şifrelenecek olan sayının yüzler basamağını
        // binler ile onlar basamağını vs.daha sonra sayı şifrelenmiş oluyor.
        birler_1 = (birler + 9) % 10;
        onlar_1 = (binler + 9) % 10;
        yuzler_1 = (onbinler + 9) % 10;
        binler_1 = (onlar + 9) % 10;
        onbinler_1 = (yuzler + 9) % 10;

        // yeni sayi değişkeni oluşturdum.yukarıda rakama dönüşüp modu alınan rakamları bir sayı haline getirmek için
        // bunun için de onbinler basamağını 10000 ile binler basamağını 1000 ile çarparak vs.en sonun da da sayı oluşuyor.
        int yeni_sayi = onbinler_1 * 10000 + binler_1 * 1000 + yuzler_1 * 100 + onlar_1 * 10 + birler_1;
        return yeni_sayi;
    }

    else if(str[0] == 'E' || str[0] == 'e'){//bu kısımda eğerki str kısmına c harfi girilir ise çıkış yapılacak
        printf("Cikis yapiliyor...");
        exit(0);//programı bitirmek için exit kodunu araştırarak kullandım.
        }
    else{//eğerki str kısmına s veya c haricinde bir string girilirse geçersiz sayılacak ve
        // return ile fonksiyonun başına gidecek işlemler tekrardan yapılacak.
        printf("Gecersiz giris yaptiniz. Lutfen tekrar deneyin.\n");
        return basamali_sayi_5();
    }

}

int main() {
    int yeni_sayi = basamali_sayi_5();

    printf("Sifrelenmis Sayiniz: %d\n", yeni_sayi);

    return 0;
}






















