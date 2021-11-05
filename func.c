#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>


struct funcionario{
    char nome[50];
    int htrabalhadas;
    int idade;
    }
    cad_funci[21];

char nomeEmpresa[50], apagar[50];
int i=0, escolha,max;
void limpa();
void empresa();
void menuprincipal();
void registrarfun();
void mostrarlista();
void atualizarregistro();
void apagarregistro();
void ordem();



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
printf (" 0- Sair do Programa\n");
printf ("------------------------------------------\n");
printf (" Operação Desejada: ");
scanf ("%d",&escolha);
while (escolha!=0){
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
}}
// atualizar registro
// apagar registro

}

void registrarfun(){
limpa();
printf (" Nome do Funcionário: ");
gets(cad_funci[i].nome);
printf (" Horas trabalhadas: ");
scanf ("%d",&cad_funci[i].htrabalhadas);
printf (" Idade: ");
scanf ("%d", &cad_funci[i].idade);
i++;
menuprincipal();
}


void mostrarlista(){
limpa();
printf ("Lista de funcionários\n");
printf ("            Nome              Idade              Horas Trabalhadas\n");
printf ("------------------------------------------------------------------\n");
max=i;
for (i=0;i<max;i++){
    printf (" %15s                %d               %4.d   \n",cad_funci[i].nome,cad_funci[i].idade,cad_funci[i].htrabalhadas);
}
printf ("\n\n\n\n\n\n");
system("Pause");
menuprincipal();
}


void atualizarregistro(){
limpa();



}

void apagarregistro(){
limpa();
printf ("Lista de funcionários\n");
printf ("            Nome              Idade              Horas Trabalhadas\n");
printf ("------------------------------------------------------------------\n");
max=i;
for (i=0;i<max;i++){
    printf (" %15s                %d               %4.d   \n",cad_funci[i].nome,cad_funci[i].idade,cad_funci[i].htrabalhadas);
}
printf ("\n\n");
printf (" Qual registro deseja apagar? ");
gets(apagar);

for (i=0; i<max;i++){
if (apagar==cad_funci[i].nome){
    cad_funci[i]= default_delete ;
}}


}

void ordem(){
limpa();
for (int j=0;j<max;i++){


}


}



int main(){
   setlocale(LC_ALL,"Portuguese");
   empresa();
}
