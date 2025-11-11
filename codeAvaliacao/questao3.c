#include <stdio.h>
#include <stdlib.h>
int main(){

    int vetor[10];
    int i;
    int maior_valor, menor_valor;
    int indice_maior = 0;
    int indice_menor = 0;


    printf("Digite 10 numeros :\n");
    for (i = 0; i < 10; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

   
    printf("\nVetor Original:\n");
    for (i = 0; i < 10; i++) {
        printf("%d,  ", vetor[i]);
    }


    maior_valor = vetor[0];
    menor_valor = vetor[0];
    
    for (i = 1; i < 10; i++) {
        if (vetor[i] > maior_valor) {
            maior_valor = vetor[i];
            indice_maior = i;
        }
        if (vetor[i] < menor_valor) {
            menor_valor = vetor[i];
            indice_menor = i;
        }
    }

    
    int temp = vetor[0];       
    vetor[0] = menor_valor;     
    vetor[indice_menor] = temp; 
    
    for (i = 0; i < 10; i++) {
        if (vetor[i] == maior_valor) {
            
            indice_maior = i;
            break; 
        }
    }

    
    temp = vetor[9];           
    vetor[9] = maior_valor;
    vetor[indice_maior] = temp;

    
    printf("\n Vetor mexido :\n ");
    for (i = 0; i < 10; i++) {
        printf("%d , ", vetor[i]);
    }
    return 0;
}

