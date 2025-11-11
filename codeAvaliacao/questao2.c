#include <stdio.h>
#include <stdlib.h>
   // QUESTAO 2

   int fatorial(int n) {


    if (n < 0) {
        return -1; 
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main (){

    int num1, num2, num3;
    int soma_fatoriais = 0;

    
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);


     int fat1 = (num1 >= 0) ? fatorial(num1) : 0;
     int fat2 = (num2 >= 0) ? fatorial(num2) : 0;
     int fat3 = (num3 >= 0) ? fatorial(num3) : 0;

    soma_fatoriais = fat1 + fat2 + fat3;

   
    printf("\nResultado dos Fatoriais:\n");
    printf("%d = %d\n", num1, fat1);
    printf("%d = %d\n", num2, fat2);
    printf("%d = %d\n", num3, fat3);
    printf("\nA soma dos tres fatoriais eh: %lld\n", soma_fatoriais);

    printf("\n");
    
return 0;
}

