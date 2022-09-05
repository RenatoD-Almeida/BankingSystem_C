#include "Menu.h"

int menu(struct Lista *lista){
	int op = 0;
	printf("+==============================+\n");
	printf("|         MENU BANCARIO        |\n");
	printf("+==============================+\n");
	printf("| 1. Cadastrar conta bancaria  |\n");
	printf("| 2. Depositar                 |\n");
	printf("| 3. Sacar                     |\n");
	printf("| 4. Transferir                |\n");
	printf("| 5. Listar contas bancarias   |\n");
	printf("| 6. Sair.                     |\n");
	printf("+==============================+\n");
	printf("************ OPCAO *************\n");
	printf("  -> ");
	scanf("%i", &op); fflush(stdin);
	menuFaz(op, lista);
	return op;
}

void menuFaz(int op, struct Lista *lista){
	int contaSaida, agenciaSaida, contaEntrada, agenciaEntrada, valida;
	char nome[25];
	float valor;
	
	switch(op){
		case 1:
			system("cls");
			printf("Nome: ");
			fgets(nome, 25, stdin); fflush(stdin);
			printf("Digite o numero da conta: ");
			scanf("%d", &contaEntrada); fflush(stdin);
			printf("Agora o numero da agencia (2 digitos)\n");
			scanf("%d", &agenciaEntrada); fflush(stdin);
			push(lista, nome, contaEntrada, agenciaEntrada);
			printf("Conta criada: SUCESSO!.\n");
			continuar(); fflush(stdin);
			break;
		case 2:
			valida = 0;
			system("cls");
			printf("Digite a conta:\n");
			scanf("%i", &contaEntrada); fflush(stdin);
			printf("Agencia: ");
			scanf("%i", &agenciaEntrada); fflush(stdin);
			printf("O valor a ser depositado: \n");
			scanf("%f", &valor); fflush(stdin);
			valida = findDepositAccount(lista, contaEntrada, agenciaEntrada, valor);
			if(valida){
				printf("\n\nConta Encontrada: Deposito realizado com sucesso.\n");
			}else{
				printf("ERRO: Nao foi possivel realizar o deposito.\n");
			}
			continuar();
			break;
		case 3:
			valida = 0;
			system("cls");
			printf("Digite a conta:\n");
			scanf("%i", &contaSaida); fflush(stdin);
			printf("Agencia: ");
			scanf("%i", &agenciaSaida); fflush(stdin);
			printf("O valor a ser Sacado: \n");
			scanf("%f", &valor); fflush(stdin);
			valida = findWithdrawAccount(lista, contaSaida, agenciaSaida, valor);
			if(valida){
				printf("Conta Encontrada: Saque realizado com sucesso.\n");
			}else{
				printf("ERRO: Nao foi possivel realizar o saque.\n");
			}
			continuar();
			break;
		case 4:
			valida = 0;
			system("cls");
			printf("====== CONTA DE SAIDA =====\n");
			printf("Digite a conta de partida:\n");
			scanf("%i", &contaSaida); fflush(stdin);
			printf("Agencia: ");
			scanf("%i", &agenciaSaida); fflush(stdin);
			system("cls");
			printf("====== CONTA DE ENTRADA =====\n");
			printf("Digite a conta de chegada:\n");
			scanf("%i", &contaEntrada); fflush(stdin);
			printf("Agencia: ");
			scanf("%i", &agenciaEntrada); fflush(stdin);
			system("cls");
			printf("Valor para transferencia: ");
			scanf("%f", &valor); fflush(stdin);
			valida = findTransfersAccounts(lista, contaSaida, agenciaSaida, contaEntrada, agenciaEntrada, valor);
			if(valida){
				printf("Contas encontradas: Transferencia realizada com sucesso.\n");
			}else{
				printf("ERRO: Nao foi possivel realizar a transferencia.\n");
			}
			continuar();
			break;
		case 5:
			printList(lista);
			continuar();
			break;
		case 6:
			break;
	}
}

void continuar(){
	printf("ENTER PARA CONTINUAR ... \n");
	getchar(); fflush(stdin);
	system("cls");
}
