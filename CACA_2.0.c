#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int escolha,op,j=0,tam; char palavra[];
char matriz[10][10] =  {
   {'a','b','a','c','a','x','a','b','a','a'},
   {'c','b','y','f','a','z','a','a','a','l'},
   {'i','t','a','e','h','p','e','r','o','a'},
   {'p','i','r','a','v','e','r','o','f','f'},
   {'o','z','t','a','z','m','a','s','i','f'},
   {'i','x','q','m','u','a','l','a','l','i'},
   {'t','c','w','n','u','s','u','l','g','n'},
   {'t','e','s','t','e','d','e','l','i','n'},
   {'h','o','m','a','r','o','b','o','b','a'},
   {'k','o','a','z','z','z','a','m','a','l'},
};
char matrizteclado[10][10];

void limpa();
void menuprincipal();
void matrizteste();
void criarmatrizt();
void imprimirmatriz();
void solicitapalavra();
void pesquisa();
void teste();
void esquerdadireita();
void direitaesquerda();
void cimabaixo();
void baixopracima();
//teclado
void esquerdadireitateclado();
void direitaesquerdateclado();
void cimabaixoteclado();
void baixopracimateclado();

void limpa(){
system("clear || cls");
setbuf(stdin,NULL);
	}
void menuprincipal(){
limpa();
printf ("\t Menu\n");
printf ("1- Cria matriz a partir do teclado\n");
printf ("2- Imprime a matriz criada pelo teclado\n");
printf ("3- Solicita palavra\n");
printf ("4- Pesquisa\n");
printf ("5- Teste Padrao\n");
printf ("0- Sair do programa\n");
printf ("Escolha: ");
scanf  ("%d", &escolha);
while (escolha){
switch (escolha){
case 1:
    criarmatrizt();
    break;
case 2:
    imprimirmatriz();
    break;
case 3:
    solicitapalavra();
    menuprincipal();
    break;
case 4:
    pesquisa();
    break;
case 5:
    teste();
    break;
case 0:
    system("Pause");
    return 0;
default:
    printf ("Opcao invalida.\n");
    system ("Pause");
    menuprincipal();
}
 }
  }
void matrizteste(){
   //imprimir uma matriz de teste
    printf ("\t\tMATRIZ TESTE\n");
    printf ("-------------------------------------------");
    for (int o=0;o<10;o++){
    printf ("\n");
    for (int c=0;c<10;c++){
    printf ("  %2c",matriz[j][c]);
}
 j++;
 }
    printf ("\n-------------------------------------------");
    printf ("\n\n");
    }
void criarmatrizt(){
     // criar a matriz por meio do teclado
     limpa();
     printf ("\t A MATRIZ CRIADA PELO TECLADO:\n");
     //colocar todos os termos dentro da matriz 10x10
     for (int j;j<10;j++){
     for (int k=0;k<10;k++){
        printf (" Digite o %d-%d termo da matriz: ",k,j);
        fflush(stdin);
        scanf("%c",&matrizteclado[k][j]);
}
 }
  system ("Pause");
  menuprincipal();
  }
void imprimirmatriz(){
   // imprimir a matriz que o usuario criou pelo teclado
    limpa();
    int j;
    printf ("\t\tMATRIZ TECLADO\n");
    printf ("-------------------------------------------");
    // montar a matriz que o usuario criou
    for (int o=0;o<10;o++){
    printf ("\n");
    for (int c=0;c<10;c++){
        printf ("  %2c",matrizteclado[j][c]);
}
 j++;
 }
 printf ("\n-------------------------------------------");
    printf ("\n\n");
    system("Pause");
    menuprincipal();
  }
void solicitapalavra(){
// Salvar qual palavra deseja encontrar
printf ("\nQual palavra quer encontrar: ");
fflush(stdin);
scanf ("%s",&palavra);
}
void pesquisa(){
//Menu para o usuario escolher como quer que a palavra seja procurada
printf ("1- Busca da esquerda pra direita\n");
printf ("2- Busca da direita pra esquerda\n");
printf ("3- Busca de cima pra baixo\n");
printf ("4- Busca de baixo pra cima\n");
printf ("0- Volta para o Menu Principal\n");
printf ("Escolha: ");
scanf  ("%d",&op);
while (op){
switch (op){
case 1:
    esquerdadireitateclado(palavra);
    break;
case 2:
    direitaesquerdateclado(palavra);
    break;
case 3:
    cimabaixoteclado(palavra);
    break;
case 4:
    baixopracimateclado(palavra);
    break;
case 0:
    menuprincipal(palavra);
    return 0;
default :
    printf ("Opcao invalida");
    pesquisa();
}
 }
  }
void teste(){
// executa a matriz já definida
matrizteste();
solicitapalavra();
pesquisa();
 }
void esquerdadireita(char palavra[]){
int limite=0;
//ver quantas letras tem a palavra
tam = strlen( palavra );
for (int k=0;k<10;k++){
for (int q=0;q<10;q++){
int cont=0;
while (matriz[k][q+cont]==palavra[cont] && matriz[q][q+cont]!= '\0' && cont!= tam && (q+cont)!= 10){
//compara a letra da linha com a primeira letra da matriz, essa comparacao nao pode chegar no ultimo termo pois é "invisivel" '\0'
//percorrer a linha, alterando a coluna depois que achar a primeira letra correspondente
// contar quantas vezes as palavras ficaram de acordo com a condição
cont++;
if(cont==tam){
//imprimir as palavras que achar
printf ("\n Achou %s",palavra);
printf ("\n Esquerda ---> Direita: Linha %d Coluna: %d",k,q);
limite++;
}
 }
  }
   }
   system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (limite == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void direitaesquerda( char palavra[] ){
    //mesma logica da esquerda pra direita
    int n=0;
   tam = strlen( palavra );
   for (int k=0;k<10;k++){
    for (int q=9;q>=0;q--){
        int cont=0;
        while (matriz[k][q-cont] == palavra[cont]  && cont!= tam && (q-cont)!= -1){
            cont++;
            if(cont==tam){
                printf ("\n Achou %s",palavra);
                printf ("\n  Direita---> Esquerda: Linha %d Coluna: %d",k,q);
                n++;
}
 }
  }
   }
   system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (n == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void cimabaixo(char palavra[]){
int n=0; int cont=0;
tam = strlen(palavra);
for (int c=0;c<10;c++){
for (int i=0;i<10;i++){
while (matriz[i+cont][c]==palavra[cont]&&matriz[i+cont][c]!='\0'&&cont!=tam&&(i+cont)!=10){
// percorre a coluna a partir da primeira letra correspondente encontrada
cont++;
if(cont==tam){
printf("\nAchou %s",palavra);
printf ("\n Cima---> Baixo lin %d coluna %d",i,c);
n++;
}
 }
  }
   }
  system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (n == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void baixopracima(char palavra[]){
int n=0; int cont=0;
tam = strlen (palavra);
for (int k=0;k<10;k++){
for ( int h=9;h>=0;h--){
while (matriz[h-cont][k]== palavra[cont] && cont != tam && (h-cont)!=10){
cont++;
if(cont == tam){
printf ("\n Achou %s",palavra);
printf ("\n Baixo--> Cima linha %d coluna %d ",h,k);
n++;
}
 }
  }
   }
   system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (n == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void esquerdadireitateclado(char palavra[]){
int limite=0;
//ver quantas letras tem a palavra
tam = strlen( palavra );
for (int k=0;k<10;k++){
for (int q=0;q<10;q++){
int cont=0;
while (matrizteclado[k][q+cont]==palavra[cont] && matrizteclado[q][q+cont]!= '\0' && cont!= tam && (q+cont)!= 10){
//compara a letra da linha com a primeira letra da matriz, essa comparacao nao pode chegar no ultimo termo pois é "invisivel" '\0'
//percorrer a linha, alterando a coluna depois que achar a primeira letra correspondente
// contar quantas vezes as palavras ficaram de acordo com a condição
cont++;
if(cont==tam){
//imprimir as palavras que achar
printf ("\n Achou %s",palavra);
printf ("\n Esquerda ---> Direita: Linha %d Coluna: %d",k,q);
limite++;
}
 }
  }
   }
   system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (limite == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void direitaesquerdateclado( char palavra[] ){
    //mesma logica da esquerda pra direita
    int n=0;
   tam = strlen( palavra );
   for (int k=0;k<10;k++){
    for (int q=9;q>=0;q--){
        int cont=0;
        while (matrizteclado[k][q-cont] == palavra[cont]  && cont!= tam && (q-cont)!= -1){
            cont++;
            if(cont==tam){
                printf ("\n Achou %s",palavra);
                printf ("\n  Direita---> Esquerda: Linha %d Coluna: %d",k,q);
                n++;
}
 }
  }
   }
   system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (n == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void cimabaixoteclado(char palavra[]){
int n=0; int cont=0;
tam = strlen(palavra);
for (int c=0;c<10;c++){
for (int i=0;i<10;i++){
while (matrizteclado[i+cont][c]==palavra[cont]&&matrizteclado[i+cont][c]!='\0'&&cont!=tam&&(i+cont)!=10){
// percorre a coluna a partir da primeira letra correspondente encontrada
cont++;
if(cont==tam){
printf("\nAchou %s",palavra);
printf ("\n Cima---> Baixo lin %d coluna %d",i,c);
n++;
}
 }
  }
   }
  system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (n == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
void baixopracimateclado(char palavra[]){
int n=0; int cont=0;
tam = strlen (palavra);
for (int k=0;k<10;k++){
for ( int h=9;h>=0;h--){
while (matrizteclado[h-cont][k]== palavra[cont] && cont != tam && (h-cont)!=10){
cont++;
if(cont == tam){
printf ("\n Achou %s",palavra);
printf ("\n Baixo--> Cima linha %d coluna %d ",h,k);
n++;
}
 }
  }
   }
   system ("\nPause");
   menuprincipal();
   // se o contador limite estiver zerado, significa que nao teve nenhuma correspondencia
   if (n == 0){
      printf("\n A palavra nao encontrada");
      system ("\npause");
      menuprincipal();
    }
     }
int main(){
menuprincipal();
}


