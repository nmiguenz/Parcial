#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "publicacion.h"


static int proximoId();
static int buscarLugarLibre(Cliente* array,int limite);

/** \brief
 * \param array Cliente*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int cliente_mostrarDebug(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d", array[i].idCliente);
        }
    }
    return retorno;
}
int cliente_mostrar(Cliente* cliente,int LEN_CLIENTE)
{
    int retorno = -1;
    int i;
    if(LEN_CLIENTE > 0 && cliente != NULL)
    {
        retorno = 0;
        for(i=0;i<LEN_CLIENTE;i++)
        {
            if(!cliente[i].isEmpty)
                printf("[RELEASE] -Id %d -Nombre %s -Apellido %s-CUIT %.2f - %d\n",cliente[i].idCliente, cliente[i].nombre, cliente[i].apellido,cliente[i].cuit, cliente[i].isEmpty);
        }
    }
    return retorno;
}
/*
int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    float promedio;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                if(array[i].cantidadVentas!=0)
                {
                    promedio = array[i].calificacionAcum/(float)array[i].cantidadVentas;
                }
                else
                {
                    promedio=0;
                }
                printf("Id: %d - Nombre: %s - Calificacion: %g \n",array[i].idCliente, array[i].nombre, promedio);
            }

        }
    }
    return retorno;
}
*/
int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    float cuit;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es una pass","El maximo es 40",apellido,40,2))
                {
                    if(!getValidFloat("\nCuit? ","No es un cuit Valido",&cuit,0,40000000000,2))
                    {
                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        array[i].cuit = cuit;
                        //array[i].calificacionAcum = 0;
                        //array[i].cantidadVentas = 0;
                                            //------------------------------
                                            //------------------------------
                        array[i].idCliente = proximoId();
                        array[i].isEmpty = 0;
                    }

                }
            }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }
    return retorno;
}


int cliente_baja(Cliente* array,int limite, int id)
{
    int retorno = 0;
    int indiceAEliminar = cliente_buscarPorId(array, limite, id);
    if(indiceAEliminar>0)
    {
        array[indiceAEliminar].isEmpty = 1;
    }
    else
    {
        retorno=indiceAEliminar;
    }
    return retorno;
}

int cliente_baja_prof(Cliente* array,int limite, int id) //como la pasaron en el template
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}



int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    float cuit;
    indiceAModificar = cliente_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
        {
            if(!getValidString("\nApellido? ","\nEso no es una apellido","El maximo es 50",apellido,50,2))
            {
                if(!getValidFloat("\nIngrese Cuit ","Ese no es un CUIT valido",&cuit,1,40000000000,2))
                {
                    retorno=0;
                    strcpy(array[indiceAModificar].nombre, nombre);
                    strcpy(array[indiceAModificar].apellido, apellido);
                    array[indiceAModificar].cuit = cuit;
                }

            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno = -2;
        }
    }
    return retorno;
}

int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

//Retorna un entero que es = a la posicion del Id.
int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, float cuit)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            array[i].cuit = cuit;
            //strcpy(array[i].pass,pass);
            //array[i].calificacionAcum = 0;
            //array[i].cantidadVentas = 0;
            //------------------------------
            //------------------------------
            array[i].idCliente = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
int cliente_mostrar_porIdPublicacion(Publicacion* array, Cliente* clientes,int limite, int limite_clientes)
{
    int i;
    int retorno=-1;
    int indicePublicacion;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty)
            {
                indicePublicacion = publicacion_buscarPorId(array, limite, array[i].idPublicacion);
                printf("ID:%d \n", array[indicePublicacion].idPublicacion);
            }
        }
    }
    return retorno;
}
int cliente_mostrarPorIdPublicacion(Cliente* array, int limite, int idPublicacion)
{
    int i;
    int retorno=-1;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty && array[i].idCliente==idPublicacion)
            {
                printf("ID:%d -Nombre %s -Apellido %s -Cuit %f\n", array[i].idCliente,
                       array[i].nombre, array[i].apellido, array[i].cuit);
            }
        }
    }
    return retorno;
}
