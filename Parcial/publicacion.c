#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "utn.h"


static int proximoId();
static int buscarLugarLibre(Publicacion* array,int limite);

/** \brief
 * \param array Publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(Publicacion* array,int limite)
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
/*
int publicacion_mostrarDebug(Publicacion* array, Cliente* cliente,int limite, int limite_cliente)
{
    int i;
    int retorno=-1;
    int indiceCliente;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            indiceCliente = cliente_buscarPorId(cliente, limite_cliente, array[i].idCliente);
            printf("\n\n");
            printf("ID:%d - Nombre: %s - Precio: %g - Vendidos: %d - Stock: %d - Cliente: %s\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock,
                       cliente[indiceCliente].nombre);
        }
    }
    return retorno;
}
*/
/*
int publicacion_mostrarPorIdCliente(Publicacion* array, int limite, int idCliente)
{
    int i;
    int retorno=-1;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty && array[i].idCliente==idCliente)
            {
                printf("ID:%d - - Precio: %g - Vendidos: %d - Stock: %d\n", array[i].idPublicacion,
                       array[i].nombre, array[i].precio, array[i].cantidadVendida, array[i].stock);
            }
        }
    }
    return retorno;
}
*/
int publicacion_mostrar(Publicacion* array, Cliente* clientes,int limite, int limite_clientes)
{
    int i;
    int retorno=-1;
    int indiceCliente;
    if(limite>0)
    {
        for(i=0;i<limite;i++)
        {
            retorno = 0;
            if(!array[i].isEmpty)
            {
                indiceCliente = cliente_buscarPorId(clientes, limite_clientes, array[i].idCliente);
                printf("ID:%d \n", array[indiceCliente].idPublicacion);
            }
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* array, Cliente* cliente,int limite, int limiteClientes)
{
    int retorno = -1;
    int i, auxEstado, idCliente;
    int rubro;
    char auxAviso[64];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nId del cliente? ","\nEso no es un id",&idCliente,0,1000,2))
            {
                if(cliente_buscarPorId(cliente, limiteClientes, idCliente)>=0)
                {
                    if (!getValidInt("\nIngrese rubro","No es un rubro valido",&rubro,1,10,2))
                    {
                        if(!getValidString("\nAviso? ","\nEso no es un nombre","El maximo es 40",auxAviso,64,2))
                        {
                            if(!getValidInt("\nEstado?", "\nEso no es un stock", &auxEstado,0,10000,2))
                            {
                                retorno = 0;
                                array[i].idCliente = idCliente;
                                array[i].rubro = rubro;
                                strcpy(array[i].aviso,auxAviso);
                                array[i].estado = auxEstado;

                                array[i].idPublicacion = proximoId();
                                array[i].isEmpty = 0;

                            }

                        }
                    }
                }
            }
        }
    }
    else
    {
        retorno = -3;
    }
    return retorno;
}

int publicacion_bajaPorIdCliente(Publicacion* array, int limite, int idCliente)
{
    int retorno = 0;
    int i;
    for(i=0;i<limite;i++)
    {
        if(!array[i].isEmpty && array[i].idCliente==idCliente)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{
    int retorno = 0;
    int indiceAEliminar = publicacion_buscarPorId(array, limite, id);
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
int publicacion_cambiarEstado(Publicacion* array,int limite, int id)
{
    int retorno = 0;
    int respuesta;
    int indiceAModificar;
    indiceAModificar = publicacion_buscarPorId(array, limite, id);
    getChar("Desea cambiar de Estado la publicacion [S/N]?");
         if (respuesta = 's')
         {
            if(array[id].estado>0)
            {

                array[id].estado = 0;
            }
         }
    return retorno;
}
// Publicacion del template
int publicacion_baja_prof(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/*
int publicacion_modificacion(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    float precio;
    int stock;
    indiceAModificar = publicacion_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
    {
        if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&precio,0,100000,2))
        {
            if(!getValidInt("\nStock? ","\nEso no es un stock",&stock,0,1000,2))
            {
                retorno=0;
                array[indiceAModificar].precio = precio;
                array[indiceAModificar].stock = stock;
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
*/
/*
int publicacion_ordenar(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

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
*/
static int buscarLugarLibre(Publicacion* array,int limite)
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


int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
/*
int publicacion_comprar(Publicacion* publicaciones, Cliente* cliente, int limite_pub, int limite_user, int idPublicacion)
{
    int retorno=-1;
    int indiceAComprar, indiceCliente;
    int calificacion;
    indiceAComprar = publicacion_buscarPorId(publicaciones, limite_pub, idPublicacion);
    if(indiceAComprar>=0)
    {
        if(publicaciones[indiceAComprar].stock>0)
        {
            if(!getValidInt("\nCalificacion", "No es una calificacion", &calificacion, 0, 10,1))
            {
                publicaciones[indiceAComprar].stock--;
                publicaciones[indiceAComprar].cantidadVendida++;
                indiceCliente = usuario_buscarPorId(cliente, limite_user, publicaciones[indiceAComprar].idCliente);
                cliente[indiceCliente].calificacionAcum+=calificacion;
                cliente[indiceCliente].cantidadVentas++;
                retorno =0;
            }
        }
    }
    return retorno;
}
*/
int publicacion_altaForzada(Publicacion* array,int limite,int idCliente,char* aviso,int rubro, int estado)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].aviso,aviso);
            array[i].rubro = rubro;
            array[i].idCliente=idCliente;
            //array[i].precio = precio;
            //array[i].stock = stock;
            array[i].estado = estado;
            //array[i].cantidadVendida=0;
            //------------------------------
            //------------------------------
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

