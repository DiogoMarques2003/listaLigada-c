#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ListaLigada.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista *li;
	
	li = cria_lista();
	
	int tamanhoLista = tamanho_lista(li);
	printf("O tamanho da lista é: %d.\n", tamanhoLista);
	
	if (lista_cheia(li)) {
		printf("A lista está cheia.\n");
	}
	
	if (lista_vazia(li)) {
		printf("A lista está vazia.\n");
	}
	
	struct aluno al = {1, "Diogo", 9, 8, 10};
	
	if (insere_lista_inicio(li, al)) {
		printf("Aluno introduzino com sucesso no inicio da fila.\n");
	} else {
		printf("Ocorreu algum erro a introduzir o aluno no fim da fila.\n");
	}
	
	al.matricula = 2;
	if (insere_lista_final(li, al)) {
		printf("Aluno introduzido com sucesso no fim da fila.\n");
	} else {
		printf("Ocorreu algum erro a introduzir o aluno no fim da fila.\n");
	}
	
	al.matricula = 3;
	if (insere_lista_ordenada(li, al)) {
		printf("Aluno introduzido com sucesso ordenadamente.\n");
	} else {
		printf("Ocorreu algum erro a introduzir o aluno ordenadamente.\n");
	}
	
	if(remove_lista_inicio(li)) {
		printf("Primeiro aluno removido com sucesso.\n");
	} else {
		printf("Ocorreu algum erro a remover o primeiro aluno.\n");
	}
	
	if (remove_lista_final(li)) {
		printf("Ultimo aluno removido com sucesso.\n");
	} else {
		printf("Ocorreu algum erro a remover o ultimo aluno.\n");
	}
	
	if (remove_lista(li, 2)) {
		printf("Aluno removido com sucesso.\n");
	} else {
		printf("Ocorreu algum erro a remover o aluno.\n");
	}
	
	insere_lista_inicio(li, al);
	
	struct aluno *al1;	
	if (consulta_lista_pos(li, 1, &al1)) {
		printf("Aluno encontrado.\n");
	} else {
		printf("Não foi possivel encontrar o aluno.\n");
	}
	
	if (consulta_lista_mat(li, 3, &al1)) {
		printf("Aluno encontrado.\n");
	} else {
		printf("Não foi encontrado nenhum aluno com essa matricula.\n");
	}
	
	liberta_lista(li);
	
	return 0;
}
