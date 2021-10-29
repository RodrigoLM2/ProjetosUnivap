#include <stdio.h>
#include <locale.h>

int diciplinas[5]

void nomedisc (){
	
	for(int i = 0; i < 4; i++){
		
		printf("Digite o nome da %dº disciplina: ", i);
		scanf("%c", &disciplinas[i]);
	}
}

main(){
	
	setlocale(LC_ALL, "Portuguese");	
	nomedisc();
	
	
}
