#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int scelta;
    time_t t;
    char M[128];

    puts("Inserisci la stringa da cifrare con numero  di caratteri non superiori a 128 : \n");
    fgets(M,128,stdin);


    // MENU
    system("clear");    
    printf("\n--- MENU ---\n\n Stringa da cifrare %s\n\n1. CHIAVE CUSTOM\n2. CHIAVE RANDOM\n\n",M);
    //INPUT
    puts("Scelta : ");
    do
    {
        scanf("%d",&scelta);
    }
    while(scelta != 1 && scelta != 2);
    getchar();
    if(scelta == 1)
    {
        // chiave custom
        char cypher[128]; //stringa risultante
        char K[128]; //stringa con cui cifrare

        //INPUT + CONTROLLO
        puts("inserisci la chiave di cifratura:\t");
        do{
            fgets(K,128,stdin);
        }while(strlen(K) < strlen(M));

        printf("STRINGA DA CIFRARE: %s\n",M);
        printf("CHIAVE DI CIFRATURA: %s\n",K);

        //CIFRATURA
        for(int i=0;i<strlen(K);i++)
        {
            cypher[i] =  M[i] ^ K[i];
        }
         //stampa stringa cifrata
          puts("La stringa cifrata è:\n");
          printf("%s, HEX: %X\n",cypher,cypher);
        printf("\n");
    };

    if(scelta == 2)
    {
        //chiave casuale
        //GENERAZIONE CHIAVE
        srand((unsigned)time(&t));
        char cypher[128]; //stringa risultante
        char K[128]; //stringa con cui cifrare
        for(int i=0;i<strlen(M);i++)
        {
            K[i]=rand()%128;
        }

         printf("STRINGA DA CIFRARE: %s\n",M);
        printf("CHIAVE DI CIFRATURA: %s\n",K);

         for(int i=0;i<strlen(K);i++)
        {
            cypher[i] = M[i] ^ K[i];
        }
          //stampa stringa cifrata
          puts("La stringa cifrata è:\n");
          printf("%s, HEX: %X\n",cypher,cypher);
        printf("\n");
     };

    return 0;
}
