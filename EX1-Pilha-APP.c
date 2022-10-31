#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EX1-Pilha-tad.h"

int converte(Pilha p, int num, int base)
{
     Pilha aux = cria_pilha();
    int resto;
    while(num>0){

    resto = num % base;
    num = num/base;

     push(&p,resto);

    }

    while(pilha_vazia(p)!=1)
    {
        pop(&p,&resto);
            printf("%x",resto);
            push(&aux,resto);
    } while(pilha_vazia(aux)!=1)
    {
        pop(&aux,&resto);
        push(&p,resto);
    }

    return 1;
}

int main()
{
    Pilha p;
    int a;
   // int resto;
    int op=0,num,b,c;
       int base;

    p = cria_pilha();


    if(p != NULL){
        printf("Alocaçao da pilha nao foi bem sucedida \n");
        return 0;
    }
    printf("-=-=-=-=-=-=-=-=-=-MENU-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("1 - Binário[B]\n");
    printf("2 - Octal[O]\n");
    printf("3 - Hexadecimal[H]\n");
    printf("Obs: Digite um numero negativo para encerrar\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");


    while(op>=0){
         printf("\nDigite uma opção: ");
         scanf("%d",&op);

        if(op < 4 && op>0){
         printf("Digite um número: ");
         scanf("%d",&num);
        }
        if(num < 0){
            break;
        }
        else if(op==1)
         {
            base = 2;
           a = converte(p,num,base);

           if(a==1)
           printf("\nSucesso na conversão para binário\n");
           else
            printf("Não foi possivel converter para binário");
        }
//-------------------------------------------------------------------------------------
        else if(op==2)
        {
              base = 8;
                 b = converte(p,num,base);
                 if(b==1)
                    printf("\nSucesso na conversão para octal\n");
             else
                    printf("Falha na conversão para octal\n");
        }
//-------------------------------------------------------------------------------------
        else if(op==3)
        {
            base = 16;
            c = converte(p,num,base);
                if(c==1)
                    printf("\nSucesso na conversão para hexadecimal\n");
                else
                    printf("Falha na conversão para hexadecimal\n");
        }
//--------------------------------------------------------------------------------------
    }
    printf("\nPROGRAMA ENCERRADO, VOLTE SEMPRE\n");
    return 0;
}
