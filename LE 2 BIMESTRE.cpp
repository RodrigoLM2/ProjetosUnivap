#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ins, idade, nota, x, aprovados, candidatos, porcent, mni=0, mna=0, mne=0;
char nome[50], curso[10], mci[50], mca[50], mce[50], resp[1];

/*

	Projeto 1 de Linguagem Estruturda

Turma: 1FID
Materia: LE

ALUNO 1: Rodrigo Lopes Marques
ALUNO 2: Gustavo Otac?lio Jacinto Ramos
ALUNO 3: Henrique Curtis Correa Marques

*/

main(){

    while (x==0){
    	
        printf("Digite o numero da inscricao: ");
        scanf("%d", &ins);

        printf("Digite o nome do candidato: ");
        scanf("%s", &nome);

        printf("Digite a idade do candidato: ");
        scanf("%d", &idade);

        printf("Digite a nota do candidato: ");
        scanf("%d", &nota);

           printf("Informe o curso escolhido pelo candidato: \n\n (informatica/ administracao/ eletronica)\n");
        scanf("%s", &curso);


        if((nota>=7) && (idade >= 18)){
            printf("\nCanditado Aprovado!\n");
            aprovados++;
            candidatos++;
        }else{
            printf("\nCanditado Reprovado!\n");
            candidatos++;
        }


        if(strcmp(curso, "informatica")==0){
            if(nota>mni){
                strcpy(mci, nome);
                mni = nota;
            }
        }else{
            if(strcmp(curso, "administracao")==0){
                if(nota>mna){
                    strcpy(mca, nome);
                    mna = nota;
                }
            }else{
                if(strcmp(curso, "eletronica")==0){
                    if(nota>mne){
                        strcpy(mce, nome);
                        mne = nota;
                    }
                }
            }
        }

        printf("\nDeseja digitar os dados de outro canditado s/n \n");
        scanf("%s", &resp);

        if(strcmp(resp, "n")==0){
            x++;
        }
        
		system("cls");        
        
    }

    porcent = (aprovados*100)/candidatos;
    
	printf("==================================================\n");
	
    printf("\nCandidatos foram aprovados: %d", aprovados);
    
    printf("\nPorcentagem de aprovacao: %%%d\n", porcent);
    if(mni != 0){
        printf("\nO melhor candidato de Informatica eh: %s e sua nota foi %d", mci, mni);
    }

    if(mna != 0){
        printf("\nO melhor candidato de Adiminstracao eh: %s e sua nota foi %d", mca, mna);
    }

    if(mne != 0){
        printf("\nO melhor candidato de Eletronica eh: %s e sua nota foi %d", mce, mne);
    }

}
