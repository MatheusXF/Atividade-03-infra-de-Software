#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <pthread.h>

void *media(void *arg)
{
    int *array = (int*)(arg);
    int quant = array[0], soma = 0;
    int media = 0;

    for(int i = 1; i <= quant; i++)
        soma += array[i];
    
    media = soma/quant;
    printf("\nThe average value is %d", media);
}

void *menor(void *arg)
{
    int *array = (int*)(arg);
    int quant = array[0];
    int menor = 0;

    for(int i = 1; i <= quant; i++) {
        if (i == 1)
            menor = array[i];
        else {
            if (array[i] < menor)
                menor = array[i];
        }
    }
    printf("\nThe minimum value is %d", menor);
}

void *maior(void *arg)
{
    int *array = (int*)(arg);
    int quant = array[0];
    int maior = 0;

    for(int i = 1; i <= quant; i++) {
        if (i == 1)
            maior = array[i];
        else {
            if (array[i] > maior)
                maior = array[i];
        }
    }
    printf("\nThe maximum value is %d", maior);
}


int main()
{
    int quant;
    scanf("%d", &quant);
    int array[quant +1];
    array[0] = quant;

    for(int i = 1; i < quant + 1; i++) {
        scanf("%d", &array[i]);
    }

    pthread_t t1,t2,t3;

    pthread_create(&t1, NULL, media, &array);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, menor, &array);
    pthread_join(t2, NULL);

    pthread_create(&t3, NULL, maior, &array);
    pthread_join(t3, NULL);

    return 0;
}