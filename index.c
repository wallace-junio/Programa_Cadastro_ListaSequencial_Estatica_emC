/*
  Wallace Junio - Sistema de Informação 3º período
  Faculdade Única/Ipatinga
  Matéria: Lista estática sequencial em c -  Estrutura de Dados
*/
//bibliotecas
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 100

//Estrutura de aluno
typedef struct aluno {
	char nome[30];
	int matricula;
	char curso[30];
	int idade;
	
}tipo_aluno;

//Estrutura da Lista
typedef struct lista {
	int size;
	tipo_aluno alunos[MAX];	
}tipo_lista;


//Assinatura de funçoes
tipo_lista* cria_lista();
int insere_aluno_final(tipo_lista* li);
int exibir_lista_cadastrados(tipo_lista* li);
int ordenar_lista(tipo_lista* li);

//Função que cria lista 
tipo_lista* cria_lista() {
	
	tipo_lista* li;
	li = (tipo_lista*) malloc(sizeof(tipo_lista));
	
	if(li == NULL)
		return 0;
		
	li->size = 0;
	
	return li;
}



//Função que insere no final da lista
int insere_aluno_final(tipo_lista* li) {
	
		if(li == NULL){
			printf("\nErro na alocacao da Lista.");
			getch();
			return 0;
		}
	
		if(li->size == MAX-1){
			system("cls");
			printf("\nLista Cheia.");
			getch();
			return 0;
		}
		
		
		int i = li->size;
		
		system("cls");
		printf("\n-------------");
		printf("\n [ Cadastrar ]");
		printf("\n-------------");
		printf("\nNome: ");
		gets(li->alunos[i].nome);
		printf("\nIdade: ");
		scanf("%d",&li->alunos[i].idade);
		fflush(stdin);
		printf("\nCurso: ");
		gets(li->alunos[i].curso);
		printf("\nMatricula: ");
		scanf("%d",&li->alunos[i].matricula);
		fflush(stdin);
		
		li->size++;
		return 1;
}


//função responsavel por pesquisar aluno na lista pelo nome
int pesquisar_aluno_nome(tipo_lista* list) {
	
		if(list->size == 0) {
			system("cls");
			printf("\n Lista Vazia!");
			getch();
			return 0;
		}
			
		char nome_p[30];
		
		int k = list->size;
		int j=0;
		
		system("cls");
		printf("\n-------------");
		printf("\n [ Pesquisar ]");
		printf("\n-------------");
		printf("\nNome: ");
		gets(nome_p);
		
		for( ;j < k;j++) {
			
			if(strcmp(list->alunos[j].nome,nome_p)  == 0 ){
					system("cls");
					printf("\n-------------");
					printf("\n [ Aluno ]");
					printf("\n-------------");
					printf("\nNome: %s",list->alunos[j].nome);
					printf("\nIdade: %d",list->alunos[j].idade);
					printf("\nCurso: %s",list->alunos[j].curso);
					printf("\nMatricula: %d \n\n",list->alunos[j].matricula);
					getch();
					return 1;
			}		
		} 
		
		printf("\nAluno nao possue cadastro!\n\n");
		getch();
}


//Funçao exibe lista completa de cadasrtados
int exibir_lista_cadastrados(tipo_lista* li) {
	int qtde = li->size -1;
	int i=0;
	if(li == NULL)
		return 0;
	
	if(li->size == 0) {
		system("cls");
		printf("\nLista vazia!");
		getch();
		return 0;
	}
	
	
		system("cls");
		printf("\n----------------------");
		printf("\n [ Lista de Alunos ]");
		printf("\n----------------------");
		
		for(;i <= qtde; i++) {
		
			printf("\n-------------------\n");
			printf("\nNome: %s",li->alunos[i].nome);
			printf("\nIdade: %d",li->alunos[i].idade);
			printf("\nCurso: %s",li->alunos[i].curso);
			printf("\nMatricula: %d \n",li->alunos[i].matricula);
		
		}
	
	getch();
	return 1;		
}


//Funçao que ordena em ordem alfabética os cadastrados
int ordenar_lista(tipo_lista* li) {
	
	if(li->size == 0) {
		system("cls");
		printf("\nLista vazia!");
		getch();
		return 0;
	}
	
	
	int qtde = li->size;
	tipo_aluno aux;
	
	int x,y;
	
	for(x=0;x<qtde;x++) {
		for(y=x;y<qtde;y++) {
			
			if(strcmp(li->alunos[x].nome,li->alunos[y].nome) > 0 ) {
				aux = li->alunos[x];
				li->alunos[x] = li->alunos[y];
				li->alunos[y] = aux;	
			}
			
			
			 	
		}
	}
	
	
}


//programa principal
int main() {
	int op;
	
	tipo_lista* list;//ponteiro para lista
	
	list = cria_lista();
	
		
	do{
		system("cls");
		printf("\n-------------");
		printf("\n [ MENU ]");
		printf("\n-------------");
		printf("\n1-Cadastrar");
		printf("\n2-Pesquisar");
		printf("\n3-Exibir Lista completa");
		printf("\n4-Ordenar Lista");
		printf("\n5-Sair");
		printf("\nOpcao: ");
		scanf("%d",&op);
		fflush(stdin);
		
		
		if(op == 1) {
			insere_aluno_final(list);
		}	

		if(op == 2) {
			pesquisar_aluno_nome(list);
		}
		
		
		if(op == 3) {
			exibir_lista_cadastrados(list);
		}
		
		if(op == 4) {
			
			ordenar_lista(list);	
		}
				
	}while(op != 5);	
	
}

