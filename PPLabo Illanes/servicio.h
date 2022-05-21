#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
#include "bicicleta.h"

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} eServicio;

/** \brief
 *
 * \param vec[] eServicio
 * \param tam int
 * \return int
 *
 */
int eServicio_mostrarServicios(eServicio vec[], int tam);
/** \brief
 *
 * \param vec[] eServicio
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int eServicio_cargarDescripcion(eServicio vec[], int tam, int id, char descripcion[]);


#endif // SERVICIO_H_INCLUDED
