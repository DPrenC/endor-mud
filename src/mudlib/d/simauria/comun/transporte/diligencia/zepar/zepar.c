/* SIMAURIA '/obj/transporte/diligencia.c'
   =======================================
   [w] cheto@simauria

   19-11-98 [c] pos eso.. una diligencia que va de Nandor a Simauria pasando
   por el puerto de Gorat, agradecimiento especial a woo por aguantarme.
   25-03-2003 [z] Cambio la parada de Ishtria escribiendola bien porque si no el pasaje es
   		  gratis y cosas más raras aún que pasan.
*/
#include "./path.h"
#include <properties.h>

inherit STAGECOACH;

create()
{
    seteuid(getuid(TO));
    ::create();
    SetShort("la diligencia Zepar");
    SetLong("La diligencia Zepar que une las ciudades de Nandor con el puerto de Gorat "
        "y la capital del dominio de Simauria, Isthria.\n");
    Set(P_NOGET, "Pero tío... ¿cómo quieres coger la diligencia?\n");
    Set(P_NOSELL, "Jejeje... ¿intentando vender una diligencia?\n");
    SetDnombre("zepar");
    SetDhabitacion(ZEPAR("habzepar"));
    // ({<hab_destino>,<hab_estas>,<a_ti>})
    SetDmensajes_entrar(
        ({"entra en la diligencia",
        "sube al zepar",
        "Subes al zepar"}));
    SetDmensaje_llega("La diligencia Zepar aparece rauda como el viento.\n");
    SetDmensaje_seva("La diligencia Zepar prosigue su camino y se esfuma.\n");
    SetRecorrido(ZEPAR("zepar.txt"));
    SetInicio(MARH("nandor/calle42s"));
    SetParadas(({({MARH("nandor/calle42s"),40,1000}),
        ({BETWA "gorat/calles/callec1",35,1000}),
        ({CNS("cam36"), 40,1000})}));
    //AddAtacantes(,60,
    //             ({"jejeje","jejeje2"}));
    SetDestinos(({"Nandor","Gorat","Ishtria"}));
    SetDconductor("/d/simauria/comun/pnj/diligencia/zepar");
    SetNombreConductor("Jezabel");
}
