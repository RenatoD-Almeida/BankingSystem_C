all:	Menu.o
	@ gcc ./Object/*.o ./bin/Main.c -I ./Include/ -o ./app/Execute
	
Menu.o:	List.o
	@ gcc -c ./Src/Menu.c -I ./Include/ -o ./Object/Menu.o
	
List.o:	Banco.o
	@ gcc -c ./Src/List.c -I ./Include/ -o ./Object/List.o

Banco.o:
	@ gcc -c ./Src/Banco.c -I ./Include/ -o ./Object/Banco.o
	
run:
	./app/Execute
