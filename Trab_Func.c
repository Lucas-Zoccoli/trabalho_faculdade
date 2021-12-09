#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct funcionario{
    char nome[50];
    int htrabalhadas;
    int idade;
    int id;
    char nomeordenado[50];
    }
    cad_funci[21];

FILE *doc; //FILE *ordenado; FILE *txtfinal;
char nomeEmpresa[50];
int i=0, escolha,max ,id,k;
void limpa();              // feito
void empresa();            // feito
void menuprincipal();      // feito
void registrarfun();       // feito
void mostrarlista();       // feito
void atualizarregistro();  // feito
void apagarregistro();     // QUASE FEITO
void ordemhoras();         // feito
void ordemalfabetica();    // QUASE FEITO
void salvartxt();          // feito
void imprimirlista();      // feito

void limpa(){
system("clear || cls");
setbuf(stdin,NULL);
}

void empresa(){
printf ("\t Qual o nome da empresa? ");
gets(nomeEmpresa);
menuprincipal();
}

void menuprincipal(){
limpa();
printf ("\t Menu Principal da %s\n",nomeEmpresa);
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
    ordemalfabetica(max, cad_funci);
    break;
default:
    printf (" Opcao invalida.\n");
    system ("Pause");
    menuprincipal();
}
 }
  return 0;
/*doc = fopen("testefunc.txt","r");
ordenado = fopen("testefunc.txt","r");
txtfinal = fopen("testefunc.txt","a");
juntar_txt(txtfinal,doc);
juntar_txt(txtfinal,ordenado);
*/
  }  

void registrarfun(){
limpa();
printf ("\t Funcionario Id %d\n",id);
printf (" Nome do Funcionario: ");
fflush(stdin);
gets(cad_funci[i].nome);
printf (" Horas trabalhadas: ");
scanf ("%d",&cad_funci[i].htrabalhadas);
printf (" Idade: ");
scanf ("%d", &cad_funci[i].idade);
cad_funci[i].id = id;
id++;
i++;
salvartxt();
printf ("\n Funcionario Cadastrado Com Sucesso.\n\n");
printf("\n\t[ Pressione Qualquer Tecla Para Prosseguir ]\n");
system("pause>null");
menuprincipal();
}

void mostrarlista(){
limpa();
max=i;
imprimirlista();
printf ("\n\n[ Pressione qualquer tecla para retornar ao menu principal. ]");
system("Pause>null");
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
fflush(stdin);
scanf ("%d",&apagar);

for (int y=0; y<max;y++){
if (apagar == cad_funci[y].id){
   for(int j = 0;j<max;j++){
       setbuf(stdin,NULL);
       cad_funci[y].htrabalhadas=NULL;
       memset(cad_funci[y].nome, 0 , sizeof cad_funci[y].nome);
       cad_funci[y].idade= NULL;
       cad_funci[y].id= NULL;

   }
printf ("\n\n\t [ Funcionario apagado com sucesso ]");
printf ("\n\n\t [ Pressione qualquer tecla para retornar ao menu principal ]");
system ("Pause>>null");
menuprincipal();
}
  } 
printf ("\n\n [ Id nao encontrado ]");
printf ("\n\n [ Pressione qualquer tecla para retornar ao menu principal ]");
system ("Pause>>null");
menuprincipal();
  
}

void ordemhoras(){
limpa();
FILE * ordenado;
ordenado = fopen("testeordenado.txt","w");
int n=i,comparativo;
int h, p, aux,  numero[21];
for (h = 0; h < n; ++h)
    numero[h]= cad_funci[h].htrabalhadas;
for (h = 0; h < n; ++h){
    for (p = h + 1; p < n; ++p){
        if (numero[h] > numero[p]){
            aux =  numero[h];
            numero[h] = numero[p];
            numero[p] = aux;
}
 }
  }
printf("\tOrdenados por horas trabalhadas\n\n");
printf ("   Id         Nome              Idade              Horas Trabalhadas\n");
printf ("------------------------------------------------------------------\n");
fprintf(ordenado,"\tOrdenados por horas trabalhadas\n\n");
fprintf (ordenado,"   Id         Nome              Idade              Horas Trabalhadas\n");
fprintf (ordenado,"------------------------------------------------------------------\n");
for (h = 0; h < n; ++h){   
    comparativo = numero[h];
    for (int v=0;v<n;v++){
    if (comparativo==cad_funci[v].htrabalhadas){ 
    printf ("  %2d  %15s                %d               %4.d   \n",cad_funci[v].id,cad_funci[v].nome,cad_funci[v].idade,numero[h]);
    fprintf (ordenado,"  %2d  %15s                %d               %4.d   \n",cad_funci[v].id,cad_funci[v].nome,cad_funci[v].idade,numero[h]);
    }
    }
}
system ("Pause");
menuprincipal();
}

void ordemalfabetica(){
limpa();
max = i;
printf ("\n%d",max);
char copia[100]; 
for(int j=0;j<(max);j++){
       strcpy((cad_funci[j].nomeordenado),(cad_funci[j].nome));
       //strcpy((cad_funci[k].nomeordenado),(cad_funci[j+1].nome));

    //printf ("\n%s NOME ORDENADO J",cad_funci[j+1].nomeordenado);
    //printf ("\n%s NOME ORDENADO K",cad_funci[k].nomeordenado);
}
for (int l = 0; l < max ; l ++ ) {
    //printf ("Dentro do primeiro for\n");
   for(int k = l; k < max ; k ++ ){
       //printf ("DENTRO DO SEGUNDO FOR\n");
      if ( strcmp ( cad_funci[l].nomeordenado, cad_funci[k+1].nomeordenado ) != 0 ){
        //printf ("\ndentro do if\n");              
         strcpy (copia, cad_funci[l].nomeordenado );
         strcpy (cad_funci[l].nomeordenado, cad_funci[k].nomeordenado);   
         //printf ("\n%s\n",cad_funci[l].nomeordenado);
         strcpy (cad_funci[k].nomeordenado, copia);
         //printf ("\n%s VARIAVEL NOME ORDENADO K",cad_funci[k].nomeordenado);
         //printf ("\n%s VARIAVEL NOME ORDENADO L",cad_funci[l].nomeordenado);
         //printf ("\n%s VARIAVEL COPIA",copia);
} 
 } 
  }
printf ("\t \nORDEM ALFABETICA\n");
for (int l=0;l<max;l++){
    //printf ("DENTRO DO ULTIMO FOR");
    printf ("%s\n",cad_funci[l].nomeordenado);
}
system("Pause");
menuprincipal();

} 

void salvartxt(){
doc = fopen("testefunc.txt","w");
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

/*void juntartxt(FILE *base, FILE *copiado){
     char leitor [1000];

    while (fgets (leitor, sizeof leitor, copiado) != NULL)
    {
        fputs (leitor, base);
    }
}
*/
int main(){
   limpa();  
   empresa();
}
