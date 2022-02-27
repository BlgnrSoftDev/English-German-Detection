#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


const char matrix_bigram_strings[10][3] = { "th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te" };

const char matrix_trigram_strings[10][4] = { "the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die" };

const char languages[2][8] = { "english", "german" };

const float frequency_eng[20] = { 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
const float frequency_germ[20] = { 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };

float calculated_frequencies[20];
int index_frequinces = 0; //calculated frequencies dizisinin indislerini tutan değişken.
float distances[2] = { 0,0 };

void filter_str(char str[])
{
	int i = 0;
    bool result;
	while (str[i]!='\0')
	{
        result = ((str[i]>= 'A' && str[i]<= 'Z') || (str[i]>= 'a' && str[i]<= 'z'))? false : true;
        if(result) str[i]=' ';
        ++i;
    /* burada bool veri tipindeki result değişkenine;
    eğer dizinin i'inci indisindeki karakter istediğimiz aralıktaysa false değilse true değerini verdik,
    ve bu değerlerle if koşulunu çalıştırı true olduðu deðerlerde indise boşluk karakterini atadık. */
	}

    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\ttext is scanning...\n \t %d characters",i);
    printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n\n");
	printf("\tReceived text:\n\t");
	puts(str);
}

void calculate_frequencies_bi(char str[])
{
    int counter;
    char bigram [3];
    bigram[2]= '\0';
    printf("\n\t");
        for(int j=0;j<10;++j)
        {
            counter =0;
            for(int i = 0; str[i]!= '\0'; ++i)
            {
                bigram[0]= str[i];
                bigram[1]= str[i+1];

                if(check_string(bigram,matrix_bigram_strings[j]))
                   counter += 1;
               /*kullanıcıdan aldığımız metinden bigram oluşturuyoruz
                oluşturduğumuz bigram verilen trigramla karşılaştırıyoruz
                aynı ise counter'ı bir arttırıp aramaya devam ediyoruz
                metnin sonuna geldiğimizde bigramı ve counter'ı yazdırıp diğer bigramlarla devam ediyoruz.
                10 bigramda aranıp yazdırılınca fonksyon sonlanıyor.
                */
            }
            printf("%s  :: %d ",matrix_bigram_strings[j],counter);
            calculated_frequencies[index_frequinces]=counter;
            index_frequinces+=1;
        }
}

void calculate_frequencies_tri(char str[])
{
    int counter;
    char trigram [4];
    trigram[3]= '\0';
    printf("\n\t");

        for(int j=0;j<10;++j)
        {
            counter =0;
             for(int i = 0; str[i]!= '\0'; ++i)
            {
                trigram[0]= str[i];
                trigram[1]= str[i+1];
                trigram[2]= str[i+2];

                if(check_string(trigram,matrix_trigram_strings[j]))
                   counter += 1;
               /*kullanıcıdan aldığımız metinden trigramlar oluşturuyoruz
                oluşturduğumuz trigramları verilen trigramla karşılaştırıyoruz
                aynı ise counter'ı bir arttırıp aramaya devam ediyoruz
                metnin sonuna geldiğimizde trigramı ve counter'ı yazdırıp diğer trigramlarla devam ediyoruz.
                10 trigramda aranıp yazdırılınca fonksyon sonlanıyor.
                */
            }
            printf("%s :: %d ",matrix_trigram_strings[j],counter);
            calculated_frequencies[index_frequinces]=counter;
            index_frequinces+=1;
        }
}

void calculate_distances()
{
    float total_eng,total_germ; //hesaplanan uzaklıkların tutulacağı değişkenler

    for(int i=0; i<20 ; ++i)
        total_eng += pow((calculated_frequencies[i] - frequency_eng[i]),2);
    total_eng = sqrt(total_eng);

    for(int i=0; i<20 ; ++i)
        total_germ += pow((calculated_frequencies[i] - frequency_germ[i]),2);
    total_germ = sqrt(total_germ);

    distances[0] = total_eng;
    distances[1] = total_germ;
}

void detect_lang()
{

    int x = (distances[0]<distances[1])?
        printf("\tThe answer which my AI determine is %s :)",languages[0]):
            printf("\tThe answer which my AI determine is %s :)",languages[1]);
    //distances dizisindeki değerlere bakarak dilin ne olduðunu tahmin edip yazdıran karşılaştrımalı koşul ifadesi
}

void do_lowercase(char str[])
//alınan string dizisinin tüm harflerini küçük harf yapan fonksiyon
{
    for (int i=0;str[i]!='\0';++i)
    {
        if(str[i]>= 65 && str[i]<= 90)
            str[i] += 32;
    }
}

int length(char str[])
//alınan string dizisinin boyutunu hesaplayan fonksyon
{
    int i;
    for (i=0;str[i]!='\0';++i)
        ;
    return i;
}

int check_string(char str1[],char str2[])
//alınan iki string dizisini karşılaştıran aynı ise 1 farklı ise 0 dönen fonksyon
{
    int x;
    if(length(str1) != length(str2))
        return 0;
    else
        for(int i=0;str1[i]!='\0';++i)
            if(str1[i]!=str2[i])
                return 0;
    return 1;
}

int main()
{
	printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
	   printf("\n\
        #########  #######         ####      ###########     ####            ####      #########  ###      ###    \n\
        #########  ########        ####     ###########      ####            ####     #########   ###      ###    \n\
        ###        ####  ####      ####    ####              ####            ####    ###          ###      ###    \n\
        ###        ####   ####     ####   ####               ####            ####     ###         ###      ###    \n\
        #########  ####    ####    ####  ####    #########   ####            ####      ###        ############    \n\
        #########  ####     ####   ####  ####    ##########  ####            ####       ###       ############    \n\
        ###        ####      ####  ####  ####          ####  ####            ####        ###      ###      ###    \n\
        ###        ####       #### ####   ###         ####   ####            ####         ###     ###      ###    \n\
        #########  ####        ########    ##############    ##############  ####   ########      ###      ###    \n\
        #########  ####         #######     ############     ##############  ####  ########       ###      ###    \n"
);
printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
   printf("\n\
     ###########     ##########    ########    #######               #######      ########      #######        ####  \n\
    ###########      ##########   ##########   ########             ########     ##########     ########       ####  \n\
   ####              ###         ####    ###   #### ####           #### ####    ####    ####    #### ####      ####  \n\
  ####               ###         ####    ###   ####  ####         ####  ####   ####      ####   ####  ####     ####  \n\
 ####    #########   ##########  ####  ####    ####   ####       ####   ####  ################  ####   ####    ####  \n\
 ####    ##########  ##########  ########      ####    ####     ####    ####  ################  ####    ####   ####  \n\
 ####          ####  ###         #### ####     ####     ####   ####     ####  ####        ####  ####     ####  ####  \n\
  ###         ####   ###         ####  ####    ####      #### ####      ####  ####        ####  ####      #### ####  \n\
   ##############    ##########  ####   ####   ####       #######       ####  ####        ####  ####       ########  \n\
    ############     ##########  ####    ####  ####        #####        ####  ####        ####  ####        #######  \n"
);

printf("\n-----------------------------------------------------------------------------------------------------------------------\n");

    char text[256];

	printf("\n\tEnter the text:\n\t");
	gets(text);

    filter_str(text);
    do_lowercase(text);

    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\tbigram and trigram frequencies:\n");

	calculate_frequencies_bi(text);
	calculate_frequencies_tri(text);

    printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n\n");


	calculate_distances();
	detect_lang();

    printf("\n\n\n\n\n\n\n\n\n");
	return 0;
}
