/****************************************************************************
Fichero: ciudad_base.c
Autor: Kastwey
Creación: 24/07/2005
Descripción: Habitación base para la ciudad de annufam
[t] 25/02/2009: Cambiado SERVER_ANNUFAM->QueryState() por NIGHTDAY->QueryState() para que se enciendan las antorchas por la noche.
****************************************************************************/

#include "./path.h"
#include <nightday.h>
#define SILENT          1
#define NECESITO_LUZ ({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE})
// etapas del día en las que se necesita luz de las antorchas



inherit BASE_ANNUFAM;

int pAntorchas; // si hay antorchas estará a 1
int pEstadoAntorchas; // 1 encendido, 0 apagadas ( típico, en? :P)
int pLuzAntorchas; // luz residual de antorchas cercanas
int pEstadoLuzAntorchas; // si hay o no hay luz residual

public int QueryAntorchas() { return pAntorchas; }
public varargs int SetEstadoAntorchas(int i, int silent)
{
    // ajustamos la luz dependiendo de si la antorcha se apaga o se enciende
    SetIntBright((i?30:0));
    if (!silent)
    // si no es silencioso, lanzamos el mensaje del soldado
    {
        tell_room(TO,W("Llega un soldado y " + (i? "enciende":
                                                "apaga") +
                           " las antorchas de la pared.\n"
                           "El soldado se va.\n"));
    }
    return pEstadoAntorchas = i;
}

public int QueryEstadoAntorchas() { return pEstadoAntorchas; }


public int QueryLuzAntorchas() { return pLuzAntorchas; }

public varargs int SetEstadoLuzAntorchas(int i, int silent)
// luz residual de antorchas cercanas
{
    // ajustamos la luz dependiendo de si las antorchas cercanas se apagan o
    // se encienden
    SetIntBright((i?15:0));
    if (!silent)
    // si no es silencioso, lanzamos el mensaje de que aumenta la luz
    {
        if (i)
        {
            tell_room(TO,W("Se encienden algunas antorchas cercanas, "
                           "proporcionando algo de luz a este lugar.\n"));
        }
        else
        {
            tell_room(TO,W("Observas como poco a poco, se van apagando las "
                           "antorchas de la ciudad.\n"));
        }
    }
    return pEstadoLuzAntorchas = i;
}


public int QueryEstadoLuzAntorchas() { return pEstadoLuzAntorchas; }
public varargs void ActualizaEstadoLuz(int silent)
{
    // si no hay antorchas en la room, y tampoco luz residual de otras
    // antorchas cercanas, fuera
    if (!pAntorchas && !pLuzAntorchas) return;
    // si es denoche, o casi
//    if (member(NECESITO_LUZ,SERVER_ANNUFAM->QueryState()) >= 0)
    if (member(NECESITO_LUZ,NIGHTDAY->QueryState()) >= 0)
    // si no están encendidas, se encienden
    {
        if (pAntorchas && !pEstadoAntorchas)
        {
            SetEstadoAntorchas(1,silent);
        }

        if (pLuzAntorchas && !pEstadoLuzAntorchas)
        {
            SetEstadoLuzAntorchas(1,silent);
        }
        return;
    }
    // es dedía, así que, si están encendidas, se apagan
    if (pAntorchas && pEstadoAntorchas)
    {
        SetEstadoAntorchas(0,silent);
    }

    if (pLuzAntorchas && pEstadoLuzAntorchas)
    {
        SetEstadoLuzAntorchas(0,silent);
    }
}



int cmd_encender_apagar(string str)
{
    int accion = (query_verb() == "encender" ? 1 : 0);
    if (!pAntorchas) return 0;
    if (!str || str != "antorchas")
    {
        return notify_fail("¿" + (accion?"Encender":"Apagar") + " qué?\n");
    }
    if (accion == pEstadoAntorchas)
    {
        write(W("Las antorchas ya están " +
                (accion ? "encendidas" : "apagadas") + ".\n"));
        return 1;
    }
    write(W("¿De verdad crees que eres la persona más indicada para "
            "encender o apagar las antorchas de la ciudad?\n"));
    return 1;
}




    public void create()
{
    ::create();
    SetLocate("ciudad de Annufam");
    SetIndoors(0);
    AddRoomCmd(({"encender","apagar"}),"cmd_encender_apagar");
    ActualizaEstadoLuz();
}

public int AddAntorchas()
// añade antorchas a la ciudad
{
    if (pAntorchas) return 0;
    pAntorchas = 1;
    ActualizaEstadoLuz();
    AddDetail(({"antorchas","antorcha"}),
              (:W("Son unos recipientes de metal abiertos pero con un techo a "
                  "unos cuatro centímetros de los mismos para prevenir que puedan "
                  "mojarse con las lluvias. Se llenan de algún combustible y por "
                  "la noche se encienden. Ahora están " +
                  (pEstadoAntorchas ? "encendidas" : "apagadas") + ".\n"):));
    return 1;
}

public int AddLuzAntorchas()
// añade luz residual de antorchas cercanas en la ciudad
{
    if (pLuzAntorchas) return 0;
    pLuzAntorchas = 1;
    ActualizaEstadoLuz();
    AddDetail("antorchas",(:(pEstadoLuzAntorchas == 1?
                               W("Aquí no ves ninguna antorcha, aunque la luz "
                                 "de alguna cercana vasta para "
                                 "alumbrar el lugar.\n"):0):));
    return 1;
}


public int AddSuelo()
// añade el detalle de suelo de la ciudad
{
    mapping details;
    if ((details = QueryDetails()) && member(details,"suelo")) return 0;
    AddDetail("suelo",W("El suelo no está muy cuidado, pero sí lo mínimo "
                        "para que no sea difícil que carretas y viandantes "
                        "pasen por él. Es de tierra, pero sin piedras que "
                        "entorpezcan el camino.\n"));
    return 1;
}


public void notify_state_change(int state)
{
    if (!pAntorchas && !pLuzAntorchas) return;
    ActualizaEstadoLuz();
}





public void init()
{
    ::init();
    ActualizaEstadoLuz(SILENT);
}
