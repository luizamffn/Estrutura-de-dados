#include <stdio.h>
typedef struct aluno{
	int mat;
	float nota;
	char nome[30];
	
}Taluno;

Taluno v[5];
int pos=0;
int  ultimo;

void incluir();
void formatacao();
void mostrar();
void maior_nota();
void menor_nota();

main(){
	int op;
    do {
    	printf("\n1- Incluir");
    	printf("\n2- Mostrar");
    	printf("\n3- Maior nota" );
    	printf("\n4- Menor nota" );
    	printf("\n0- Sair \n");
    	printf("Digite a opcao:");
    	scanf("%d",&op);
    	switch(op){
    		case 1:incluir(); break;
    		case 2:mostrar(); break;
    		case 3:maior_nota(); break;
    		case 4:menor_nota(); break;
    		case 0: break;
    		default:printf("Opcao invalida!!");
		}
    	
	} while (op!=0);
	
}

void incluir(){
	int resp;
	do{
		if (pos<5){
    		printf("Digite a matricula:");
	        scanf("%d",&v[pos].mat);
     	    fflush(stdin);
     	    printf("Digite o nome:");
    	    gets(v[pos].nome);
    	    printf("Digite a nota:");
    	    scanf("%f",&v[pos].nota);
    	    ultimo = pos;
    	    pos++;
    	    
		}
		else {
            printf("Vetor Cheio!");
            break;
		}
        printf("Deseja incluir outro (1-Sim 2-Nao)?");
	    scanf("%d",&resp);	
	}while (resp==1);
}

//Mostrar os dados formatados
void formatacao(int posicao){
		printf("\n\nMatricula:%d",v[posicao].mat);
		printf("\nNome       :%s",v[posicao].nome);
		printf("\nNota       :%.2f",v[posicao].nota);
}

void mostrar(){
	if (pos !=0){
		int i;
		for(i=0;i<pos;i++){
			formatacao(i);
		}
	}else{
		printf("\nNenhum aluno matriculado!");
	}
}



void maior_nota(){
	int pos_maior=0;
	int i;
	if(ultimo !='\0'){
		for (i=1; i<=ultimo;i++){
			if(v[i].nota > v[pos_maior].nota){
				pos_maior = i;
			}
		}
	}else{
		printf("\nNenhum aluno existente!");
	}
	
	formatacao(pos_maior);
}

void menor_nota(){
	int pos_menor=0;
	int i;
	if(ultimo !='\0'){
		for (i=1; i<=ultimo; i++){
			if(v[i].nota < v[pos_menor].nota){
				pos_menor = i;
			}
		}
	}else{
		printf("\nNenhum aluno existente!");
	}
	
	formatacao(pos_menor);
}

