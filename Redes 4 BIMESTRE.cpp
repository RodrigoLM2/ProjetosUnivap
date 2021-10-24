#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

    int n, i, key, x;
	char c, msg[100];
	

main()
{

	printf("=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Criptografia de César\n");	
	printf("=-=-=-=-=-=-=-=-=-=-=\n\n");
	
	printf("[1] - Criptografar um texto\n");
	printf("[2] - Descriptografar um texto\n");
	printf("[0] - Encerrar\n\n");
	
	scanf("%d", &x);
	
	switch(x){
		
		case 1:
			
			system("cls");
			printf("Texto: ");
		    gets(msg);
			fflush(stdin);
			
			printf("\n%s\n", msg);
		    
		    printf("\nKey: ");
		    scanf("%d", &key);
		    
		    printf("\nTexto Criptografado: ");
		    n = strlen(msg);
		
		    for (i = 0; i < n; i++)
		    {
		        if(msg[i] == 32)
		        {
		            printf(" ");
		        }
		        else if(isalpha(msg[i]) == 0)
		        {
		            printf("%c", c);
		        }
		        else if(islower(msg[i]) == 0)
		        {
		            c = ((msg[i] - 65) + key) % 26;
		            printf("%c", c + 65);
		        }
		        else if(isupper(msg[i]) == 0)
		        {
		            c = ((msg[i] - 97) + key) % 26;
		            printf("%c", c + 97);
		        }
		    }
		    getchar();
			break;
		
		
		default:
			x = 0;
			break;			
	}
}
