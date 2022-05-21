#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

/** \brief
 *
 * \param vec[] eTipo
 * \param tam int
 * \return int
 *
 */
int eTipo_mostrarTipos(eTipo vec[], int tam);
/** \brief
 *
 * \param vec[] eTipo
 * \param tam int
 * \param id int
 * \param descripcion[] char
 * \return int
 *
 */
int eTipo_cargarDescripcion(eTipo vec[], int tam, int id, char descripcion[]);



#endif // TIPO_H_INCLUDED
