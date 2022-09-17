#ifndef _BANCO_H
#define _BANCO_H

typedef struct banco{
	char nome[25];
	int conta;
	int agencia;
	float saldo;
}Banco;

//Funções do Banco
Banco criarBanco(char nome[], int conta ,int agencia);
void depositar(Banco *b, float valor);
int sacar(Banco *b, float valor);
int transferir(Banco *saida, Banco *entrada, float valor);
void imprimirBanco(Banco banco);
int procuraBanco(Banco banco, int conta, int agencia);

#endif
