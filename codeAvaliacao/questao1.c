#include <stdio.h>
#include <stdlib.h>

int main() {
 
    
    int matriz[10][10];
    int valor = 1;

    int linha_inicio = 0;
    int linha_fim = 10 - 1;
    int coluna_inicio = 0;
    int coluna_fim = 10 - 1;

    while (linha_inicio <= linha_fim && coluna_inicio <= coluna_fim) {
       
        for (int i = linha_fim; i >= linha_inicio; i--) {
            matriz[i][coluna_inicio] = valor++;
        }
        coluna_inicio++; 

       
        if (coluna_inicio > coluna_fim) break;

     
        for (int j = coluna_inicio; j <= coluna_fim; j++) {
            matriz[linha_inicio][j] = valor++;
        }
        linha_inicio++;
        
      
        if (linha_inicio > linha_fim) break;

        for (int i = linha_inicio; i <= linha_fim; i++) {
            matriz[i][coluna_fim] = valor++;
        }
        coluna_fim--; 
        
        
        if (coluna_inicio > coluna_fim) break;

        
   
        for (int j = coluna_fim; j >= coluna_inicio; j--) {
            matriz[linha_fim][j] = valor++;
        }
        linha_fim--; 
    }

  
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

return 0;

}
