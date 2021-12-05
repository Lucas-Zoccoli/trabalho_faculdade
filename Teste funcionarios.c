#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct funcionario{
    char nome[50];
    int htrabalhadas;
    int idade;
    int id;
    }
    cad_funci[21];

FILE *doc;
char nomeEmpresa[50];
int i=0, escolha,max,id;
void limpa();              //feito
void empresa();            //feito
void menuprincipal();      //feito
void registrarfun();       //feito
void mostrarlista();       // feito
void atualizarregistro();  // QUASE FEITO
void apagarregistro();     // QUASE FEITO
void ordemhoras();         // FAZER
void ordemalfabetica();    // FAZER
void salvartxt();          //feito
void imprimirlista();      // feito


void limpa(){
system("clear || cls");
setbuf(stdin,NULL);
}

void empresa(){
printf (" Qual o nome da empresa? ");
gets(nomeEmpresa);
menuprincipal();
}

void menuprincipal(){
limpa();
printf (" Menu Principal da %s\n",nomeEmpresa);
printf ("------------------------------------------\n");
printf (" 1- Criar Registro\n");
printf (" 2- Ler Registros\n");
printf (" 3- Atualizar Registro\n");
printf (" 4- Apagar Registro\n");
printf (" 5- Mostrar por ordem de horas trabalhadas\n");
printf (" 6- Mostrar por ordem alfabetica\n");
printf (" 0- Sair do Programa\n");
printf ("------------------------------------------\n");
printf (" Operacao Desejada: ");
scanf ("%d",&escolha);
while (escolha != 0){
switch (escolha){
case 1:
    registrarfun();
    break;
case 2:
    mostrarlista();
    break;
case 3:
    atualizarregistro();
    break;
case 4:
    apagarregistro();
    break;
case 5:
    ordemhoras();
    break;
case 6:
    ordemalfabetica();
    break;
default:
    printf (" Opcao invalida.\n");
    system ("Pause");
    menuprincipal();
}
 }
  return 0;
  }  

void registrarfun(){
limpa();
printf (" Funcionario Id %d\n",id);
printf (" Nome do Funcionario: ");
gets(cad_funci[i].nome);
printf (" Horas trabalhadas: ");
scanf ("%d",&cad_funci[i].htrabalhadas);
printf (" Idade: ");
scanf ("%d", &cad_funci[i].idade);
cad_funci[i].id = id;
id++;
i++;
printf ("\n Funcionario Cadastrado Com Sucesso.\n\n");
printf("\n\t[ Pressione Qualquer Tecla Para Prosseguir ]\n");
system("pause>null");
menuprincipal();
}

void mostrarlista(){
limpa();
doc = fopen("func.txt","w");
fprintf (doc,"\tLista de funcionarios\n");
fprintf (doc,"  Id            Nome              Idade              Horas Trabalhadas\n");
fprintf (doc,"------------------------------------------------------------------\n");
printf ("\tLista de funcionarios\n");
printf ("   Id          Nome              Idade              Horas Trabalhadas\n");
printf ("------------------------------------------------------------------\n");
max=i;
for (int m=0;m<max;m++){
    fprintf (doc,"%2d  %15s                %d               %4.d   \n",cad_funci[m].id,cad_funci[m].nome,cad_funci[m].idade,cad_funci[m].htrabalhadas);
    printf ("%2d  %15s                %d               %4.d   \n",cad_funci[m].id,cad_funci[m].nome,cad_funci[m].idade,cad_funci[m].htrabalhadas);
}
printf ("\n\n Pressione qualquer tecla para retornar ao menu principal.");
system("Pause>null");
fclose(doc);
menuprincipal();
}

void atualizarregistro(){
limpa();
FILE * doc;
int atualizar;
imprimirlista();
printf ("\n\n");
printf (" Digite o ID que deseja atualizar:");
fflush(stdin);
scanf ("%d",&atualizar);

for (int y=0; y<max;y++){
    
if (atualizar == cad_funci[y].id){
   printf (" Nome do funcionario: ");
   fflush(stdin);
   gets (cad_funci[y].nome);
   printf (" Horas trabalhadas: ");
   fflush(stdin);
   scanf ("%d", &cad_funci[y].htrabalhadas);
   printf (" Idade: ");
   fflush(stdin);
   scanf ("%d", &cad_funci[y].idade);

    
   salvartxt();

   printf ("\n\n Funcionario Atualizado com sucesso");
   printf ("\n\n [ Pressione qualquer tecla para retornar ao menu principal ]");
   system("Pause>null");
   menuprincipal();
   
}}
printf ("\n\n Funcionario nao encontrado. \n");
printf ("\n\n [ Pressione qualquer tecla para retornar ao menu principal ]");
system("Pause>null");
menuprincipal();
}

void apagarregistro(){
limpa();
int apagar;
imprimirlista();
printf ("\n\n");
printf (" Digite a Id que deseja apagar: ");
scanf ("%d",&apagar);

for (int y=0; y<max;y++){
if (apagar == cad_funci[y].id){
    
    memset (cad_funci[y].nome, 0, sizeof (cad_funci[y].nome)) ;
    printf ("\n\n [ Usuario apagado com sucesso ]");
  printf ("\n\n [ Pressione qualquer tecla para retornar ao menu principal ]");
system ("Pause>>null");
menuprincipal();
}
  } 
printf ("\n\n [ Usuario nao encontrado ]");
printf ("\n\n [ Pressione qualquer tecla para retornar ao menu principal ]");
system ("Pause>>null");
menuprincipal();
  
}

void ordemhoras(){
max=i;
int h, y, aux,  numero[21];

for (h = 0; h < max; ++h){
    numero[h]=cad_funci[h].htrabalhadas;
    for (y = h + 1; y < max; ++y){
        numero[y]=cad_funci[y].htrabalhadas;
        if (numero[h]!=numero[y]){
        if (numero[h] > numero[y]){
            aux =  numero[h];
            numero[h] = numero[y];
            numero[y] = aux;
        }
      }
    }
}
printf("Numeros em ordem crescente \n");
for (h = 0; h < max; ++h){
    printf("%d\n", numero[h]);
}
printf ("Pressione qualquer tecla para retornar ao menu\n");
system ("Pause>>null");
menuprincipal();
}

void ordemalfabetica(){


}


void salvartxt(){
    doc = fopen("func.txt","w");
fprintf (doc,"\t\tLista de funcionarios\n");
fprintf (doc,"   Id         Nome              Idade              Horas Trabalhadas\n");
fprintf (doc,"------------------------------------------------------------------\n");
max=i;
for (int m=0;m<max;m++){
    fprintf (doc,"%2d  %15s                %d               %4.d   \n",cad_funci[m].id,cad_funci[m].nome,cad_funci[m].idade,cad_funci[m].htrabalhadas);
}
fclose(doc);
}

void imprimirlista(){
printf ("\t\tLista de funcionarios\n");
printf ("   Id         Nome              Idade              Horas Trabalhadas\n");
printf ("------------------------------------------------------------------\n");
max=i;
for (int m=0;m<max;m++){
    printf ("  %2d  %15s                %d               %4.d   \n",cad_funci[m].id,cad_funci[m].nome,cad_funci[m].idade,cad_funci[m].htrabalhadas);
}
 }

int main(){
   empresa();
}
