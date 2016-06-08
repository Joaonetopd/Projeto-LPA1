#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum erro{				//tratamento de erro
	ERR_INCIAR 1,
	ERR_ARQUIVO_INVALIDO 2,
	ERR_ARQUIVO_ERRADO 3,
};

struct lembrete{   			//struct para salvar o lembrete
	char lembre[];
	int hora[];
};

int opcao(){   // função da operação
	char op[];
	char sair[]="sair";
	char reiniciar[]="reiniciar";
	char logoff[]="logoff";
	int ret;

	fscanf(file, "\n%s", &op);				//opção para executar a função certa no system não testada	
	ret = int strcmp(op,sair );
	if (ret = 0){
		system("shutdown /s");
	}else{
		ret = int strcmp(op,reiniciar);
		if(ret == 0){
			system("shutdown /r");
		}
	}else{
		ret = int strcmp(op,logoff);
		if(ret == 0){
			system("shutdown /l");
		}
	}
	return 0;
}

int temporizador(int hr, int min, int sec){  //função do temporizador melhorada e testada
	const int a=1;
	while(a>0){
		printf(" \n\t %dh:%dmin:%ds", hr, min, sec);	
		sleep(1);
		system("cls");
		sec--;
		if(sec==0 && min!=0){
			sec=59;
			min--;
		}
		if(sec==0 && min==0 && hr!=0){
			hr--;
			min=59;
			sec=59;
		}
		if(hr==0 && min==0 && sec==0){
			printf("\n\n\t\t\tSeu tempo acabou!\n\n\n");
			break;
		}
	}
	return 0;
}

int verificador(){ 				//função do verificador de hora do system que eu acho que iremos fazer ela separada
	int fixo=1;
	for (fixo =1; fixo < 1000; fixo ++){
	time_t data_hora_segundos; // guarda os segundos deste 01/01/1970
	struct tm *timeinfo = localtime(&data_hora_segundos);; // declara uma estrutura tm e preenche a estrutura timeinfo
	time(&data_hora_segundos); // preenche a variável data_hora_segundos
  	}
  	return 0;

}

int main (int argc, int *argv[]){					//    /s=sair(/hybrid), /l=logoff, /r=reiniciar, /t xxx(em seg)= tempo antes do desligamento

	// ver interação com programa específico para verificar a hora atual do sistema 
	
	struct lembrete Lembrete1;			//criação das struct
	struct lembrete Lembrete2;
	int *hr;
	int *min;				//criação das variaveis
	int *sec;
	char lembre1[]="Lembrete1.txt";
	char lembre2[]="Lembrete2.txt"; 					
	char tempo[]="Temporizador.txt";
	FILE *file;
	FILE *arquivo1;
	FILE *arquivo2;
	if(file || arquivo1 || arquivo2 != NULL){ 						//verificação se executou os arquivos corretamente
		
		file=fopen(tempo, "r");
		fscanf(file, "%d %d %d", &hr, &min, &sec);
		printf("\n\t\tO tempo acabou!");
		
		arquivo1=fopen(lembre1, "r");
		fscanf(file, "%s", &lembrete1.lembre);
		fscanf(file, "\n%d %d %d", &lembrete1.hora);
		fscanf("%s", lembrete1.lembre);
		printf("%d", lembrete1.hora);
		
		arquivo2=fopen(lembre2, "r");
		fscanf(file, "%s", &lembrete2.lembre);
		fscanf(file, "\n%d %d %d", &lembrete2.hora);
		printf("%s", lembrete2.lembre);
		printf("%d", lembrete2.hora);

		if (horaverificador == lembrete1.hora){
			printf("Lembrar %s da hora %d", lembrete1.nome, lembrete1.hora);
		}
		if (horaverificador == lembrete2.hora){
			printf("Lembrar %s da hora %d", lembrete2.nome, lembrete2.hora);
		}
		
		temporizador(hr, min, sec);
		opcao();
	
		fclose(file);
		return 0;
	}else{					// usando o tratamento de erro!
		printf("Não foi possível abrir o arquivo!");
		return 1;
	}else{
		printf("O arquivo aberto está inválido!");
		return 2;
	}else{
		printf("O arquivo que foi aberto não é o correto!");
		return 3;
	}
}