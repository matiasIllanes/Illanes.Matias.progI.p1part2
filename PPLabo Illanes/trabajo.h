#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "bicicleta.h"
#include "fecha.h"
#include "servicio.h"


typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;


/** \brief
 *
 * \param trabajo[] eTrabajo
 * \param tamTrab int
 * \param bici[] eBicicleta
 * \param tamBici int
 * \param tipo[] eTipo
 * \param tamTipo int
 * \param color[] eColor
 * \param tamColor int
 * \param servicio[] eServicio
 * \param tamServ int
 * \param pNextId int*
 * \return int
 *
 */
int eTrabajo_alta(eTrabajo trabajo[], int tamTrab, eBicicleta bici[], int tamBici, eTipo tipo[], int tamTipo, eColor color[], int tamColor, eServicio servicio[], int tamServ, int* pNextId);
/** \brief
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \return void
 *
 */
void eTrabajo_inicializarVec(eTrabajo vec[], int tam);
/** \brief
 *
 * \param vec[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int eTrabajo_buscarLibre(eTrabajo vec[], int tam);
void eTrabajo_listarFila (eTrabajo trabajo, eServicio servicio[], int tamServ);
int eTrabajo_listar (eTrabajo trabajo[], int tamTrab, eServicio servicio[], int tamServ);

#endif // TRABAJO_H_INCLUDED
