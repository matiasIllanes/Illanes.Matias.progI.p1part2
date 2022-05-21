#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
        int id;
        char nombre[30];
        char sexo;
        int isEmpty;
}eCliente;

int eCliente_mostrar(eCliente vec[], int tam);
int eCliente_cargarNombre(eCliente vec[], int tam, int id, char nombre[]);


#endif // CLIENTE_H_INCLUDED
