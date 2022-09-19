# DIRETÓRIOS
APP = ./app
OBJ = ./Object
SRC = ./Src
BIN = ./bin
INCLUDE = ./Include

#Compilador
CC = gcc

#Dependências
Compiler = Banco.o List.o Menu.o

All:	libed  log_b $(BIN)/Execute log_end

libed:	log_o $(Compiler)

$(BIN)/Execute:	$(APP)/Main.c
	$(CC) $(OBJ)/*.o $< -I $(INCLUDE) -o $@

%.o:	$(SRC)/%.c $(INCLUDE)/%.h
	$(CC) -c $< -I $(INCLUDE) -o $@
	mv *.o $(OBJ)

log_o:
	@ echo ' '
	@ echo '--------- Gerando arquivos .o ---------'
	@ echo ' '

log_b:
	@ echo ' '
	@ echo ' ---- Gerando Arquivo Binário ---------'
	@ echo ' '

log_end:
	@ echo ' '
	@ echo '---------- Compilation Ends -----------'
	@ echo ' '
	@ tree .
run:
	$(BIN)/Execute
clear:	
	rm $(OBJ)/*.o $(BIN)/*
