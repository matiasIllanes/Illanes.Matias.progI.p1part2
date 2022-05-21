#include "bicicleta.h"



void eBicicleta_inicializarVec(eBicicleta vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int eBicicleta_buscarLibre(eBicicleta vec[], int tam)
{
    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            index=i;
        }
    }
    return index;
}



int eBicicleta_alta(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int* pNextId, eCliente vecCliente[], int tamCliente)
{
    int index;
    eBicicleta nuevaBici;
    int todoOk=0;


    index = eBicicleta_buscarLibre(vecBici, tamBici);
    if( vecBici != NULL && pNextId != NULL && vecTipo != NULL  && vecColor != NULL && tamBici > 0 && tamTipo > 0 && tamColor){
        if(index>=0)
        {


            getString(nuevaBici.marca, "Ingrese marca de la bicicleta: ", 20);


            eTipo_mostrarTipos(vecTipo, tamTipo);
            getInt(&nuevaBici.idTipo, "Ingrese ID de tipo: ", "ERROR. ", 1000, 1003);



            eColor_mostrarColores(vecColor, tamColor);
            getInt(&nuevaBici.idColor, "Ingrese ID de color: ", "ERROR. ", 5000, 5004);

            eCliente_mostrar(vecCliente, tamCliente);
            getInt(&nuevaBici.idCliente, "Ingrese ID de Cliente: ", "ERROR. ", 100, 104);

            getInt(&nuevaBici.rodado, "Ingrese Rodado de la bicicleta: ", "ERROR. ", 10, 50);


            nuevaBici.material = pedirCaracter("Ingrese Material: Carbono 'c' o Aluminio 'a' \n");
            fflush(stdin);

            nuevaBici.id = *pNextId;
            (*pNextId)++;
            nuevaBici.isEmpty = 0;

            vecBici[index] = nuevaBici;


            printf("La bicicleta fue dada de alta de forma exitosa con el ID: %d\n", vecBici[index].id);
            todoOk=1;
        }
        else
        {
            printf("No hay mas espacio para almacenar clientes.\n");
        }

    }
    return todoOk;
}


int eBicicleta_buscarIndice(eBicicleta vecBici[], int tamBici, int id)
{
    int retorno;
    for(int i=0; i<tamBici; i++)
    {
        if(vecBici[i].id == id)
        {
            retorno = i;
            break;
        }
        else
        {
            retorno=-1;
        }
    }
    return retorno;
}


void eBicicleta_listarFila (eBicicleta vecBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){
    char descripcionTipo[20];
    char descripcionColor[20];

    if(eTipo_cargarDescripcion(vecTipo, tamTipo, vecBici.idTipo, descripcionTipo) == 1 &&
       eColor_cargarDescripcion(vecColor, tamColor, vecBici.idColor, descripcionColor)==1){
            printf("%1d       %-14s      %-10d   %-10c %-15s  %6s \n", vecBici.id,
                                                                       vecBici.marca,
                                                                       vecBici.rodado,
                                                                       vecBici.material,
                                                                       descripcionTipo,
                                                                       descripcionColor);
       }

}


int eBicicleta_listar (eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor)
{
    int retorno=0;

    system("cls");
    printf("                      *** Listado de Bicicletas   ***\n");
    printf("****************************************************************************\n");
    printf("ID      Marca              Rodado      Material       Tipo             Color\n");
    printf("****************************************************************************\n");

    for(int i=0; i<tamBici; i++)
    {
        if(vecBici[i].isEmpty==0)
        {
            eBicicleta_listarFila(vecBici[i], vecTipo, tamTipo, vecColor, tamColor);
            retorno=1;
        }
    }
    return retorno;
}



int eBicicleta_modificar(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor)
{
    int idMod;
    int index;
    int opcion;
    int todoOk=0;

    if( vecBici != NULL && tamBici > 0 && vecTipo != NULL && tamTipo > 0 && vecColor != NULL && tamColor > 0)
    {
        system ("cls");

        eBicicleta_listar(vecBici, tamBici,vecTipo, tamTipo, vecColor, tamColor);

        printf("\n Ingrese ID de bicicleta para modificar: ");
        scanf("%d", &idMod);
        index = eBicicleta_buscarIndice(vecBici, tamBici, idMod);
        if(idMod==-1)
        {
            printf("ID No encontrado.");
        }
        else
        {
            printf("1- Tipo\n"
                   "2- Rodado\n"
                   "3- Volver al menu anterior\n"
                   "Ingrese opcion: \n");
            scanf("%d", &opcion);


            switch(opcion)
            {
            case 1:
                eTipo_mostrarTipos(vecTipo, tamTipo);
                getInt(&vecBici[index].idTipo, "Ingrese ID de tipo: ", "ERROR. ", 1000, 1003);
                printf("Modificacion de tipo realizada con exito.\n");
                system("pause");
                break;
            case 2:
                getInt(&vecBici[index].rodado, "Ingrese Rodado de la bicicleta: ", "ERROR. ", 10, 50);
                printf("Modificacion de rodado realizada con exito.\n");
                system("pause");
                break;

            case 3:
                break;
            default:
                break;
            }
            todoOk=1;
        }
    }
    return todoOk;
}


int hardcodearBicicletas(eBicicleta vecBici[], int tamBici, int cant){
        int todoOk=0;

        eBicicleta bicicletas[9] = {{1, "Uno", 1000, 5000, 'c', 21, 0, 100},
                                    {2, "Dos", 1003, 5004, 'a', 22, 0, 101},
                                    {3, "Tres", 1001, 5001, 'c', 19, 0, 102},
                                    {4, "Cuatro", 1002, 5003, 'c', 15, 0, 102},
                                    {5, "Cinco", 1003, 5003,'a', 24, 0, 103},
                                    {6, "Seis", 1001, 5001, 'a', 25, 0, 101},
                                    {7, "Siete", 1000, 5000, 'c', 22, 0, 104},
                                    {8, "Ocho", 1001, 5001, 'a', 21, 0, 100},
                                    {9, "Nueve", 1002, 5003, 'a', 22, 0, 103}};


        if(vecBici!=NULL && tamBici>0 && tamBici<= 9 && cant <=tamBici){
            for(int i=0; i<cant; i++){
                vecBici[i] = bicicletas[i];
            }

            todoOk=1;
        }
        return todoOk;
    }


int eBicicleta_baja(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor){

        int todoOk=0;
        int flag=0;
        int id;
        int index;
        char rta;

        if(eBicicleta_listar(vecBici, tamBici,vecTipo, tamTipo, vecColor, tamColor)==1){
            flag=1;
        }

        if( vecBici != NULL && tamBici > 0 && vecTipo != NULL && tamTipo > 0 && vecColor != NULL && tamColor > 0 && flag==1){
            id = getEntero("Ingrese ID a dar de baja: ");
            index= eBicicleta_buscarIndice(vecBici, tamBici, id);


            if(index==-1){
                printf("No se encontro el ID para la baja. \n");
            }
            else{
                rta = pedirCaracter("Desea efectuar la baja? s/n: ");

                while(rta != 's' && rta != 'n'){
                    rta = pedirCaracter("ERROR. Desea efectuar la baja? s/n: ");
                }
                if(rta == 's'){
                    vecBici[index].isEmpty=1;
                    todoOk = 1;
                    printf("\nLa baja fue exitosa\n");
                }
                else{
                    printf("\nLa baja no fue efectuada.\n");
                }
            }
        }
        return todoOk;
    }


int eBicicleta_ordenar(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo)
{
    int todoOk = 0;
    eBicicleta auxBici;
    char descripcion1[20];
    char descripcion2[20];

    if(vecBici != NULL && tamBici > 0 && vecTipo != NULL && tamTipo > 0)
    {

        for(int i=0; i < tamBici - 1; i++)
        {


            for(int j= i+1; j < tamBici; j++)
            {
                eTipo_cargarDescripcion(vecTipo, tamTipo, vecBici[i].idTipo, descripcion1);
                eTipo_cargarDescripcion(vecTipo, tamTipo, vecBici[j].idTipo, descripcion2);

                if(strcmp(descripcion1, descripcion2) > 0 || (strcmp(descripcion1,descripcion2) == 0 && vecBici[i].rodado > vecBici[j].rodado)){

                    auxBici = vecBici[i];
                    vecBici[i] = vecBici[j];
                    vecBici[j] = auxBici;
                }
            }
        }



        todoOk = 1;
    }
    return todoOk;
}



int eBicicleta_buscarBicicleta(eBicicleta vec[], int tam, int id)
{
    int index = -1;

    for(int i = 0; i<tam; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty==0)
        {
            index=i;
            break;
        }
    }

    return index;
}







void eBicicleta_listarFilaClientes (eBicicleta vecBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, eCliente vecCliente[], int tamCliente){
    char descripcionTipo[20];
    char descripcionColor[20];
    char descripcionCliente[20];


    if(eTipo_cargarDescripcion(vecTipo, tamTipo, vecBici.idTipo, descripcionTipo) == 1 &&
       eColor_cargarDescripcion(vecColor, tamColor, vecBici.idColor, descripcionColor)==1 &&
       eCliente_cargarNombre(vecCliente, tamCliente, vecBici.idCliente, descripcionCliente)==1){
            printf("%1d       %-14s      %-10d   %-10c %-15s  %6s   %10s \n", vecBici.id,
                                                                              vecBici.marca,
                                                                              vecBici.rodado,
                                                                              vecBici.material,
                                                                              descripcionTipo,
                                                                              descripcionColor,
                                                                              descripcionCliente);
       }

}


int eBicicleta_listarClientes (eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, eCliente vecCliente[], int tamCliente)
{
    int retorno=0;

    system("cls");
    printf("                      *** Listado de Bicicletas   ***\n");
    printf("***************************************************************************************************\n");
    printf("ID      Marca              Rodado      Material       Tipo             Color           Cliente\n");
    printf("***************************************************************************************************\n");

    for(int i=0; i<tamBici; i++)
    {
        if(vecBici[i].isEmpty==0)
        {
            eBicicleta_listarFilaClientes(vecBici[i], vecTipo, tamTipo, vecColor, tamColor, vecCliente, tamCliente);
            retorno=1;
        }
    }
    return retorno;
}











