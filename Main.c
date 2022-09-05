#include "Menu.h"

int main(){
	int continua = 0;
	struct Lista listaDeContasBancarias;
	iniciarLista(&listaDeContasBancarias);
	
	do{
		continua = menu(&listaDeContasBancarias);
	}while(continua != 6);
	
	desalocaTudo(&listaDeContasBancarias);
	return 0;
}
