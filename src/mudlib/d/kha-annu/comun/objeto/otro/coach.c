/* La diligencia en si misma */
#include "path.h"
#include <properties.h>
inherit "/obj/transporte/diligencia";

create()
{
 ::create();
  seteuid(getuid(TO));
 SetShort("la diligencia 'El Tuerto'");
 SetLong(
"Es la diligencia que recorre el camino entre Kha-annu y Nandor.\n");
 Set(P_NOGET, "Como vas a coger una diligencia? Es imposible incluso hasta para ti.\n");
 Set(P_NOSELL, "Mmm, y como has conseguido cogerla???\n");
 SetDnombre("el tuerto");
 SetDhabitacion(OTRO("intocoach"));
 SetDmensajes_entrar(
         ({"entra en la diligencia",
           "sube a la diligencia",
           "Te subes en la diligencia"}));
  SetDmensaje_llega("La diligencia Kha-annu/Nandor llega. Mmm, puntual.\n");
 SetDmensaje_seva("El conductor tuerto azuza a los caballos, y la diligencia se va.\n");
 SetRecorrido(OTRO("coach.txt"));
 SetInicio(CIUDAD+"tiendas/parada1");
 SetParadas( ({ ({CIUDAD+"tiendas/parada1",30,100}),
             ({CIUDAD+"tiendas/parada2",20,200}),
             ({CIUDAD+"tiendas/parada3",20,200}),
             ({"/d/simauria/comun/habitacion/marhalt/nandor/calle42s",35,300}),
             ({CIUDAD+"tiendas/parada3",20,200}),
             ({CIUDAD+"tiendas/parada2",20,200}),
             ({CIUDAD+"tiendas/parada1",30,100}) }) );
 SetDestinos( ({"Nandor","Kha-annu"}) );
 SetDconductor(MONS+"conductor");
 SetNombreConductor("El Tuerto");
}
