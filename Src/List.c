#include "List.h"
#include <stdlib.h>

void iniciarLista(struct Lista *L){
	L->topo_da_lista = NULL;
}

void push(struct Lista *lista, char nome[], int conta ,int agencia){
	struct No *novo_No = (struct No*)malloc(sizeof(struct No));
	if(novo_No){
		novo_No->banco = criarBanco(nome, conta, agencia);
		novo_No->proximo = NULL;
		if(!lista->topo_da_lista){
			lista->topo_da_lista = novo_No;
		}else{
			struct No *aux = lista->topo_da_lista;
			while(aux->proximo){
				aux = aux->proximo;
			}
			aux->proximo = novo_No;
		}
	}
}

void printList(struct Lista *lista){
	struct No *aux = lista->topo_da_lista;
	while(aux){
		imprimirBanco(aux->banco);
		aux = aux->proximo;
	}
}

int findDepositAccount(struct Lista *lista, int conta, int agencia, float valor){
	int contaEncontrada;
	if(lista->topo_da_lista == NULL){
		return 0;
	}else{
		struct No *aux = lista->topo_da_lista;
		while(aux){
			contaEncontrada = procuraBanco(aux->banco, conta, agencia);
			if(contaEncontrada){
				depositar(&aux->banco, valor);
				break;
			}
			aux = aux->proximo;
		}
		if(contaEncontrada){
			return 1;
		}else{
			return 0;
		}
	}
}

int findWithdrawAccount(struct Lista *lista, int conta, int agencia, float valor){
	int contaEncontrada, validaSaque;
	if(lista->topo_da_lista == NULL){
		return 0;
	}else{
		struct No *aux = lista->topo_da_lista;
		while(aux){
			contaEncontrada = procuraBanco(aux->banco, conta, agencia);
			if(contaEncontrada){
				validaSaque = sacar(&aux->banco, valor);
				if(validaSaque){
					return 1;
				}else{
					return 0;
				}
			}
			aux = aux->proximo;
		}
		return 0;
	}
}

int findTransfersAccounts(struct Lista *lista, int contaSaida, int agenciaSaida, int contaEntrada, int agenciaEntrada, float valor){
	int bancoSaidaEncontrada, bancoEntradaEncontrada;
	if(lista->topo_da_lista == NULL){
		return 0;
	}else{
		struct No *aux = lista->topo_da_lista, *bancoSaida, *bancoEntrada;
		while(aux){
			bancoSaidaEncontrada = procuraBanco(aux->banco, contaSaida, agenciaSaida);
			if(bancoSaidaEncontrada){
				bancoSaida = aux;
			}
			bancoEntradaEncontrada = procuraBanco(aux->banco, contaEntrada, agenciaEntrada);
			if(bancoEntradaEncontrada){
				bancoEntrada = aux;
			}
			if(bancoSaidaEncontrada && bancoEntradaEncontrada){
				break;
			}else{
				aux = aux->proximo;
			}
		}
		if(bancoSaida != bancoEntrada){
			int validaSaque = sacar(&bancoSaida->banco, valor);
			if(validaSaque){
				depositar(&bancoEntrada->banco, valor);
				return 1;
			}
		}else{
			return 0;
		}
	}
}

void desalocaTudo(struct Lista *lista){
	struct No *ptr, *del;
	ptr = del = lista->topo_da_lista;
	if(lista->topo_da_lista){
		while(ptr){
			ptr = ptr->proximo;
			free(del);
			del = ptr;
		}
	}else{
		return;
	}
}



