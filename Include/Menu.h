#ifndef _MENU_H
#define _MENU_H
#include "List.h"
#include <stdio.h>

void limpar_tela();
void limpar_buffer();
int menu(struct Lista *lista);
void menuFaz(int op, struct Lista *lista);
void continuar();

#endif
