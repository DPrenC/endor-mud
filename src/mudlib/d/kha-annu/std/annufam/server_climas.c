/****************************************************************************
Fichero: server_estados.c
Autor: Kastwey
Creación: 25/07/2005
Descripción: Un servidor que controla las notificaciones del cambio de
             estado para las diferentes habitaciones de Annufam

****************************************************************************/

#include "./path.h"
#include <nightday.h>


inherit "/obj/nightday";

private mixed *pNtfObjects = ({});

void CleanNotifications() { pNtfObjects -= ({0}); }

public int AddNotification(object ob)
// añade el objeto al array de habitaciones
// para ser notificadas con el evento notify_state_change
{
    if (!ob) return 0;
    if (member(pNtfObjects,ob) >= 0) return 1; // ya estaba en el mapping
    pNtfObjects += ({ob});
    return 1;
}

public int RemoveNotification(object ob)
{
    if (!ob || member(pNtfObjects,ob) < 0) return 0;
    pNtfObjects -= ({ob});
    return 1;
}


public object *SetNotifications(object *obs) { return pNtfObjects = obs; }

public object *QueryNotifications() { return pNtfObjects; }

public varargs int SetState (int new, int no_callout)
// sobrecargo esto para notificar a las habitaciones que lo necesiten del
// cambio de estado
{
    object *usuarios, *hab_usuarios = ({});
    ::SetState(new, no_callout);
    // limpiamos los objetos que se hayan descargado de memoria
    CleanNotifications();
    // obtenemos los usuarios
    usuarios = users();
    // pasamos a hab_usuarios las rooms de los usuarios que estén en annufam
    filter(usuarios,(:object env;
                      if (strstr(object_name((env = environment($1))),
                                 HABITACION "annufam/") > -1)
                      {
                          $2 += ({env});
                          return 1;
                      }
                      return 0;
                      :),&hab_usuarios);
    // notificamos a esas rooms
    filter(hab_usuarios,(:call_other($1,"notify_state_change",$2):),new);
    // hacemos lo mismo con los objetos, cuidando de no repetir notificaciones
    // de las habs anteriores
    filter(pNtfObjects,(:(member($2,$1) < 0?
                          call_other(!objectp($1) ? load_object($1):$1,
                                     "notify_state_change",$3):0):),
           hab_usuarios,new);
}
