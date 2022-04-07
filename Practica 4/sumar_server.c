/*
	este template generado por RPC es donde se realiza las operaciones 
	que requiere el cliente, como en este caso la operacion suma.
	Mostrando en pantalla los parametros ingresados desde el cliente y asignadole
	el valor a la variable que se retornara con el resultado esperado
 */

#include "sumar.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;

	 printf("El procedimiento ha sido invocado remotamente\n");
	printf("parametros %d, %d\n ",argp->a, argp->b);
	result=argp->a+argp->b;
	printf("%d",result);

	return &result;
}
