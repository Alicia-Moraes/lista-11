#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    int ini, fim, ehPrimo = 0, i = 0;
    if(argc != 3) return 1;
    ini = atoi(argv[1]);
    fim = atoi(argv[2]);
  
    for(i = ini; i < fim; i++){
        ehPrimo = 1;
        if(i <= 1){
            ehPrimo = 0;
        }else{
        for(int j = 2; j < i && ehPrimo == 1; j++){
                if(i % j == 0){
                    ehPrimo = 0;
                }
            }
        }
        if(ehPrimo == 1){
            printf("%d ", i);
    }
}
        getchar();
        return(0); 

}
