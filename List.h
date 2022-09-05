#ifndef _LIST_H
#define _LIST_H
#include "Banco.h"

struct No{
	Banco banco;
	struct No *proximo;
};

struct Lista{
	struct No *topo_da_lista;
};

void iniciarLista(struct Lista *L);
void push(struct Lista *lista, char nome[], int conta ,int agencia);
void printList(struct Lista *lista);
int findDepositAccount(struct Lista *lista, int conta, int agencia, float valor);
int findWithdrawAccount(struct Lista *lista, int conta, int agencia, float valor);
int findTransfersAccounts(struct Lista *lista, int contaSaida, int agenciaSaida, int contaEntrada, int agenciaEntrada, float valor);
void desalocaTudo(struct Lista *lista);


#endif
