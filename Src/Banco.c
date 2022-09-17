#include "Banco.h"
#include <string.h>
#include <stdio.h>

Banco criarBanco(char nome[], int conta ,int agencia){
	Banco banco;
	strcpy(banco.nome, nome);
	banco.conta = conta;
	banco.agencia = agencia;
	banco.saldo = 0;
	return banco;
}

void depositar(Banco *b, float valor){
	b->saldo += valor;
}

int sacar(Banco *b, float valor){
	if(b->saldo < valor){
		return 0;
	}else{
		b->saldo -= valor;
		return 1;
	}
}

int transferir(Banco *saida, Banco *entrada, float valor){
	int validaSaque = sacar(saida, valor);
	if(validaSaque){
		depositar(entrada, valor);
		return 1;
	}else{
		return 0;
	}
}

void imprimirBanco(Banco banco){
	printf("\nTitular: %s", banco.nome);
	printf("Conta: %i\n", banco.conta);
	printf("Agencia: %i\n", banco.agencia);
	printf("Saldo: RS%.2f\n\n", banco.saldo);
}

int procuraBanco(Banco banco, int conta, int agencia){
	if((banco.conta == conta && banco.agencia == agencia)){
		return 1;
	}else{
		return 0;
	}
}



