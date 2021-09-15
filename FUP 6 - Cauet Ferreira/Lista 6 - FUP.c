/*Declare uma estrutura C capaz de guardar dados relativos a um prontuário médico; Declare o tipo Paciente; Crie uma lista de estruturas;
  Crie funções para inicializar a lista; inserir, imprimir, editar (buscar por nome) e apagar prontuários (buscar por id);
  Crie funções para dar a média de idade dos pacientes; Dar o prontuário do paciente mais pesado;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	
	int id;
	char nome[50];
	float alt;
	float peso;
	int idade;
	
} Paciente;

void pacLido(Paciente pacX){
	
	printf("\n----------------- Prontuario -----------------\n");
	
	printf("\nIdentidade: %d\n", pacX.id);
	printf("\nNome: %s\n", pacX.nome);
	printf("\nAltura: %.2f\n", pacX.alt);
	printf("\nPeso: %.2f\n", pacX.peso);
	printf("\nIdade: %d\n", pacX.idade);

}

Paciente Leitura(){
	
	Paciente lerInfo;
		
	printf("\n----------------- Inserir -----------------\n");
		
	printf("\nDigite a identidade: ");
	scanf("%d", &lerInfo.id);
	
	printf("Nome: ");
	scanf("%s", lerInfo.nome);
	
	printf("Altura: ");
	scanf("%f", &lerInfo.alt);
	
	printf("Peso: ");
	scanf("%f", &lerInfo.peso);
	
	printf("Idade: ");
	scanf("%d", &lerInfo.idade);
	
	return lerInfo;
	    
}
	
void Menu(){
	
	printf("\n----------------- MENU -----------------\n");
	printf("\t1 - Inicializar lista\n");
    printf("\t2 - Inserir prontuario\n");
    printf("\t3 - Imprimir prontuario\n");
    
    printf("\t4 - Editar prontuario\n");
    printf("\t5 - Apagar prontuario\n");
    
    printf("\n\t6 - Media de idades\n");
    printf("\t7 - Paciente mais pesado\n");
    
    printf("\n-1 para sair do programa\n");

}

void listaInc(Paciente listaPac[], int tam){
	
	int i;
	for(i = 0; i < tam; i++){
		listaPac[i].id = -1;
	}
	
	printf("\nLista inicializada!\n");
	
}

void addPac(Paciente listaPac[], int tam){
	int i, confer = 0;
	
	for(i = 0; i < tam; i++){
		if(listaPac[i].id == -1){
			Paciente pacX = Leitura();
			listaPac[i] = pacX;
			
			i = tam;
			
			confer = 1;
		}
	}
	
	if(confer == 1){
		printf("\nProntuario inserido com sucesso!\n");
	}
	else{
	    printf("\nFalha na insercao...\n");
	}
	
}

void impriPac(Paciente listaPac[], int tam){
	int i, confer = 0;
	
	for(i = 0; i < tam; i++){
		if(listaPac[i].id != -1){
			pacLido(listaPac[i]);
			
			confer = 1;
		}
	}
	
	if(confer == 0){
		printf("\nLista vazia...\n");
	}
}

void editPac(Paciente listaPac[], int tam){
	char busPac[50];
	int i, confer = 0;
	
	printf("Digite sua busca por nome: ");
	scanf("%s", busPac);
	
	for(i = 0; i < tam; i++){
		if(strcmp(listaPac[i].nome, busPac) == 0){
			
			pacLido(listaPac[i]);
			
			int idty = listaPac[i].id;
			Paciente editPront = Leitura();
			
			editPront.id = idty;
			listaPac[i] = editPront;
			
			confer = 1;
		}
	}
	
	if(confer == 1){
		printf("\nEditado com sucesso!\n");
	}
	else{
	    printf("\nFalha na edicao...\n");
	}
	
}

void delPac(Paciente listaPac[], int tam){
	int i, delet, confer = 0;
	
	printf("Digite a identidade do prontuario a ser apagado: ");
	scanf("%d", &delet);
	
	for(i = 0; i < tam; i++){
		if(listaPac[i].id == delet){
			listaPac[i].id = -1;
			
			confer = 1;
		}
	}
	
	if(confer == 1){
		printf("\nDeletado com sucesso!\n");
	}
	else{
	    printf("\nFalha na exclusao...\n");
	}
	
}

void medIdade(Paciente listaPac[], int tam){
	int i = 0, cont = 0;
	int confer = 0, soma = 0, med = 0;
	
	while(i < tam){
		if(listaPac[i].idade > 0 && listaPac[i].idade < 200){
			cont = cont + 1;
			
			soma += listaPac[i].idade;
			
			confer = 1;
		}
		
		i++;
	}
	
	if(confer == 1){
	    med = soma/cont;
	    
	    printf("\n----------------- MEDIA DE IDADES -----------------\n");
	    printf("\nMedia: %d\n", med);
    }
    else{
    	printf("\nFalha na definicao...\n");
	}
}
    
void maiorPeso(Paciente listaPac[], int tam){
	int i = 0, j = 0;
	int confer = 0;
	
	while(i < tam){	
		if(listaPac[j].peso >= listaPac[i].peso){
			
			confer = 1;
		}
		else if(listaPac[i].peso > listaPac[j].peso){
            
            j++;
            
			confer = 2;
		}
		
		i++;
	}
	
	if(confer == 1){
        pacLido(listaPac[j]);
    }
    else if(confer == 2){
        pacLido(listaPac[j]);
    }
    else{
    	printf("Lista vazia...");
	}
}

int main(){
	int tam;
	
	printf("Defina o tamanho da lista: ");
	scanf("%d", &tam);
	
	system("cls");
	
	Paciente listaPac[tam];
	int opc;
	
	while(opc != -1){
		Menu();
		
		printf("\nDigite a opcao: ");
        scanf("%d", &opc);
        
        system("cls");
        
        if(opc == 1){
            listaInc(listaPac, tam);
		}
		
		else if(opc == 2){
			addPac(listaPac, tam);
		}
			
		else if(opc == 3){
		    impriPac(listaPac, tam);
		}
		
		else if(opc == 4){
		    editPac(listaPac, tam);
		}
		
		else if(opc == 5){
		    delPac(listaPac, tam);
		}
		
		else if(opc == 6){
		    medIdade(listaPac, tam);
		}
		
		else if(opc == 7){
		    maiorPeso(listaPac, tam);
		}
    } 
	
    return 0;
}


