#include <stdio.h>
#include <stdlib.h>
#include "bicicleta.h"
#include "trabajo.h"


#define TAMBICI 9
#define TAMTIPO 4
#define TAMCOLOR 5
#define TAMSER 4
#define TAMTRABAJO 9
#define TAMCLIENTE 5
int main()
{
    eBicicleta bici[TAMBICI];
    eTipo tipo[TAMTIPO] = {{1000, "Rutera"}, {1001, "Carrera"}, {1002, "Mountain"}, {1003, "BMX"},};
    eColor color[TAMCOLOR] = {{5000, "Gris"}, {5001, "Negro"}, {5002, "Blanco"}, {5003, "Azul"},{5004, "Rojo"}};
    eServicio servicio[TAMSER]= {{20000, "Limpieza", 30}, {20001, "Parche", 400}, {20002, "Centrado", 500}, {20003, "Cadena", 450}};
    eTrabajo trabajo[TAMTRABAJO];
    eCliente cliente[TAMCLIENTE]= {{100, "Maria", 'f', 0}, {101, "Lucas", 'm', 0}, {102, "Susana", 'f', 0}, {103, "Maria", 'f', 0}, {104, "Jorge", 'm', 0}};

    int idTrabajo=100;
    int idBici=1;
    int contBici=9;
    int contTrabajo=0;



    char option;
    int opcion2;


    eBicicleta_inicializarVec(bici, TAMBICI);
    eTrabajo_inicializarVec(trabajo, TAMTRABAJO);

    hardcodearBicicletas(bici, TAMBICI, 9);

    eBicicleta_listarClientes(bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR, cliente, TAMCLIENTE);
    system("pause");


    do
    {
        system("cls");
        printf("\n**** ABM EMPLEADOS ****\n");
        printf( "A- Alta bicicleta\n"
                "B- Modificar bicicleta\n"
                "C- Baja Bicicleta\n"
                "D- Listar bicicletas\n"
                "E- Listar tipos\n"
                "F- Listar colores\n"
                "G- Listar servicios\n"
                "H- Alta trabajo\n"
                "I- Listar trabajos\n"
                "J- INFORMES\n"
                "k- salir\n");

        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%c", &option);


        switch(option)
        {
        case 'a':
            system ("cls");

            if(eBicicleta_alta(bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR, &idBici, cliente, TAMCLIENTE)==1)
            {
                contBici++;
            }
            else
            {
                printf("\nEl alta no se pudo realizar\n");
            }

            break;

        case 'b':
            system ("cls");
            if(contBici != 0)
            {
                if(eBicicleta_modificar(bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR) ==0)
                {
                    printf("\nEl alta no se pudo realizar\n");
                }
            }
            else
            {
                printf("\nNo hay bicicleta dada de alta\n");
            }

            break;

        case 'c':
            system ("cls");
            if(contBici != 0)
            {

                if(eBicicleta_baja(bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR)==1)
                {
                    printf("\nLa Baja fue exitosa\n");
                    contBici--;
                }
                else
                {
                    printf("\nLa baja no se pudo realizar");

                }
            }
            else
            {
                printf("\nNo hay bicicleta dada de alta\n");
            }
            break;
        case 'd':
            if(contBici != 0)
            {
                system("cls");
                eBicicleta_ordenar(bici, TAMBICI, tipo, TAMTIPO);
                eBicicleta_listarClientes(bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR, cliente, TAMCLIENTE);
                system("pause");
            }
            else
            {
                printf("\nNo hay bicicleta dada de alta\n");
            }

            break;
        case 'e':

            eTipo_mostrarTipos(tipo, TAMTIPO);

            break;
        case 'f':
            eColor_mostrarColores(color, TAMCOLOR);
            break;

        case 'g':
            eServicio_mostrarServicios(servicio, TAMSER);
            break;
        case 'h':
            if(contBici!=0)
            {
                if(eTrabajo_alta(trabajo, TAMTRABAJO, bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR, servicio, TAMSER, &idTrabajo)==1)
                {
                    contTrabajo++;
                }
                else
                {
                    printf("\nEl alta no se pudo realizar\n");
                }
            }
            else
            {
                printf("No hay bicicleta dada de alta");
            }
            break;

        case 'i':
            if(contBici!=0)
            {
                if(contTrabajo!=0)
                {
                    eTrabajo_listar(trabajo, TAMTRABAJO, servicio, TAMSER);
                }
                else
                {
                    printf("\nNo hay trabajo dado de alta\n");
                }
            }
            else
            {
                printf("\nNo hay bicicleta dada de alta\n");
            }
            break;

        case 'j':
            system("cls");
            printf(
                "1- Listar bicicletas segun color\n"
                "2- Listar bicicletas segun tipo\n"
                "3- Informar si hay mas bicicletas de C o A y mostrar cantidad\n"
                "4- Listar listado de bicicletas separadas por tipo\n"
                "5- Cuantas bicicletas hay segun color y tipo?\n"
                "6- Listar colores mas elegidos\n"
                "7- Pedir una bicicleta y mostrar los trabajos que se le realizaron\n"
                "8- Pedir una bicicleta e informar la suma de los importes de los servicios que se le hicieron a la misma.\n"
                "9- Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha.\n"
                "10-Pedir una fecha y mostrar todos los servicios realizados en la misma.\n"
                "11- SALIR\n");

            printf("Ingrese una opcion: ");
            scanf("%d", &opcion2);
            do
            {

                switch(opcion2)
                {
                case 1:
                    listarBicicletasColor(bici, TAMBICI, color, TAMCOLOR, tipo, TAMTIPO);
                    break;
                case 2:
                    listarBicicletasTipo(bici, TAMBICI, color, TAMCOLOR, tipo, TAMTIPO);
                    break;
                case 3:
                    cantidadBicicletasMaterial(bici, TAMBICI, tipo, TAMTIPO, color, TAMCOLOR);
                    break;
                case 4:
                    listarBicisPorTipos(bici, TAMBICI, color, TAMCOLOR, tipo, TAMTIPO);
                    break;
                case 5:
                    cantidadBicicletasColorTipo(bici, TAMBICI, color, TAMCOLOR, tipo, TAMTIPO);
                    break;
                case 6:
                    colorMasElegido(bici, TAMBICI, color, TAMCOLOR);
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    break;
                case 11:
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
                system("pause");
            }
            while(opcion2!=11);
            break;


        default:
            printf("Opcion no valida\n");
            break;
        }
        system("pause");

    }
    while(option!='k');

    return 0;
}
