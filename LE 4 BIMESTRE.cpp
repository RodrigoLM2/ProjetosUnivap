#include <stdio.h>
#include <locale.h>

char disciplinas[5];

void nomedisc(){
	
	for(int i = 0; i < 5; i++){
		
		printf("Digite o nome da %dº disciplina: ", i+1);
		scanf("%s", &disciplinas[i]);
	}
}

main(){
	
	setlocale(LC_ALL, "Portuguese");
		
	nomedisc();

}
