#include <stdio.h>

typedef struct livro{
	char nome[30];
	char nomeAutor[30];
	int paginas;	
}Tlivro;

Tlivro livro[5];
Tlivro livro_maior[1];
int pos=0;
int ultimo =0;

void incluir();
void mostrar();
Tlivro maior();

main(){
	int op;
    do {
    	printf("\n1- Incluir");
    	printf("\n2- Mostrar");
    	printf("\n3- Maior livro" );
    	printf("\n0- Sair \n");
    	printf("Digite a opcao:");
    	scanf("%d",&op);
    	switch(op){
    		case 1:incluir(); break;
    		case 2:mostrar(); break;
    		case 3:
				livro_maior[0] = maior();
				printf("\n\nNome do livro: %s", livro_maior[0].nome);
				printf("\nNome do autor: %s", livro_maior[0].nomeAutor);
				printf("\nNumero de paginas: %d", livro_maior[0].paginas);
				break;
    		case 0: break;
    		default:printf("Opcao invalida!!");
		}
    	
	} while (op!=0);
	
	
}

void incluir(){
	int resposta;
	do{
		if(pos < 5){
			fflush(stdin);
			printf("\nDigite o nome do livro: ");
			gets(livro[pos].nome);
			fflush(stdin);
			printf("\nDigite o nome do autor: ");
			gets(livro[pos].nomeAutor);
			printf("\nDigite o numero de paginas do livro: ");
			scanf("%d", &livro[pos].paginas);
			ultimo=pos;
			pos++;
		}else{
			printf("Vetor cheio!!");
			break;
		}
		
		printf("\nDeseja adicionar outro livro? (1-sim/2-nao)");
		scanf("%d", &resposta);
		
	}while(resposta ==1);
	
}

void mostrar(){
	int i;
	if (pos !=0){
		for(i=0; i<=ultimo; i++){
			printf("\n\nNome do livro: %s", livro[i].nome);
			printf("\nNome do autor: %s", livro[i].nomeAutor);
			printf("\nNumero de paginas: %d", livro[i].paginas);
		}
	}else{
		printf("Nenhum livro cadastrado!");
	}
}


Tlivro maior(){
	int i;
	int pos_maior = 0;
	if (pos !=0){
		for(i=1; i<=ultimo; i++){
			if(livro[i].paginas > livro[pos_maior].paginas){
				pos_maior=i;
			}
		}
	}else{
		printf("Nenhum livro cadastrado!");
	}
	
	return livro[pos_maior];
}
