/*
 
	El codigo del cliente es un template generado por la herramienta 
	RPC en donde podemos colocar la operacion que necesitemos realizar
	En este caso una operacion suma mediante estructuras en donde verificamos
	que los datos ingresados sean correctos, asi como evitar errores


 */

#include "sumar.h"
#include "stdio.h"


void
calculadora_1(char *host,int a, int b)
{
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, Calculadora, Calculadora_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */


	suma_1_arg.a=a;
	suma_1_arg.b=b;
	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("resultado=%d\n",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	int a,b;
	if (argc!= 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
	
	host = argv[1];

	if((a=atoi(argv[2]))==0 && *argv[2]!='0'){
		fprintf(stderr,"invalid value:%s\n",argv[2]);
		exit(1);
	}
	if((a=atoi(argv[3]))==0 && *argv[3]!='0'){
		fprintf(stderr,"invalid value:%s\n",argv[3]);
		exit(1);
	}

	calculadora_1 (host,atoi(argv[2]),atoi(argv[3]));
exit (0);
}
