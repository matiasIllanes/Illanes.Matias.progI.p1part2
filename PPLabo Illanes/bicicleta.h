#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "color.h"
#include "utn.h"
#include "servicio.h"
#include "cliente.h"


typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    char material;
    int rodado;
    int isEmpty;
    int idCliente;
} eBicicleta;

/** \brief Inicializa los campos con isEmpty=1
 *
 * \param vec[] eBicicleta
 * \param tam int
 * \return void
 *
 */
void eBicicleta_inicializarVec(eBicicleta vec[], int tam);
/** \brief Busca espacio libre en la estructura
 *
 * \param vec[] eBicicleta
 * \param tam int
 * \return int
 *
 */
int eBicicleta_buscarLibre(eBicicleta vec[], int tam);
/** \brief Solicita alta
 *
 * \param vecBici[] eBicicleta
 * \param tamBici int
 * \param vecTipo[] eTipo
 * \param tamTipo int
 * \param vecColor[] eColor
 * \param tamColor int
 * \param pNextId int*
 * \return int
 *
 */
int eBicicleta_alta(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, int* pNextId, eCliente vecCliente[], int tamCliente);
/** \brief modifica bicicleta
 *
 * \param vecBici[] eBicicleta
 * \param tamBici int
 * \param vecTipo[] eTipo
 * \param tamTipo int
 * \param vecColor[] eColor
 * \param tamColor int
 * \return int
 *
 */
int eBicicleta_modificar(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

/** \brief Muestra una bicicleta
 *
 * \param
 * \param
 * \return
 *
 */
void eBicicleta_listarFila (eBicicleta vecBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);

/** \brief Muestra varias bicicletas
 *
 * \param
 * \param
 * \return
 *
 */

int eBicicleta_listar (eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);
/** \brief
 *
 * \param vecBici[] eBicicleta
 * \param tamBici int
 * \param cant int
 * \return int
 *
 */
int hardcodearBicicletas(eBicicleta vecBici[], int tamBici, int cant);
/** \brief hardcodeo de estructura
 *
 * \param vecBici[] eBicicleta
 * \param tamBici int
 * \param vecTipo[] eTipo
 * \param tamTipo int
 * \param vecColor[] eColor
 * \param tamColor int
 * \return int
 *
 */
int eBicicleta_baja(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor);
/** \brief da de baja una bicicleta
 *
 * \param vecBici[] eBicicleta
 * \param tamBici int
 * \param vecTipo[] eTipo
 * \param tamTipo int
 * \return int
 *
 */
int eBicicleta_ordenar(eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo);
/** \brief  Ordena bicicletas por tipo y rodado
 *
 * \param vec[] eBicicleta
 * \param tam int
 * \param id int
 * \return int
 *
 */
int eBicicleta_buscarBicicleta(eBicicleta vec[], int tam, int id);

void eBicicleta_listarFilaClientes (eBicicleta vecBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, eCliente vecCliente[], int tamCliente);
int eBicicleta_listarClientes (eBicicleta vecBici[], int tamBici, eTipo vecTipo[], int tamTipo, eColor vecColor[], int tamColor, eCliente vecCliente[], int tamCliente);

#endif // BICICLETA_H_INCLUDED
