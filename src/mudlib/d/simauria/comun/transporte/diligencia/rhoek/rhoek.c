/***************************************************************************************
 ARCHIVO:	rhoek.c
 AUTOR:		[z] Zomax
 FECHA:		18-02-2002
 COMENTARIOS:	Diligencia Rhoek
 		Recorrido: Ishtria-Berat-Koek-Berat-Ishtria
 MODIFICACION:	23-03-2003 Cambio typos de la capital... que si no neme se enfada.
 		25-03-2003 La hago algo mas barata... que habia mucha diferencia con la
 		           Zepar.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit STAGECOACH;

create(){

  ::create();
 SetShort("la diligencia Rhoek");
  SetLong(W("Esta es la veloz diligencia que conecta la capital de Simauria, Ishtria, "
  	"con el pueblo de Koek.\n"));
  Set(P_NOGET, "Como si te fuera a caber en el bolsillo.\n");
  Set(P_NOSELL, "Primero la compras y luego me cuentas.\n");
  SetDnombre("rhoek");
  SetDhabitacion(RHOEK("drhoek"));
  SetDmensajes_entrar(({"entra en la diligencia","sube al rhoek","Subes al rhoek"}));
  SetDmensaje_llega("La diligencia Rhoek aparece más veloz que un rayo.\n");
  SetDmensaje_seva("La diligencia Rhoek se esfuma sin darte tiempo a mirarla.\n");
  SetRecorrido(RHOEK("rhoek.t"));
  SetInicio(CNS("cam36"));
  SetParadas(({({CNS("cam36"),50,2000}),
              ({RHOEHAB("koek/varios/caravanas"),50,2000})}));
  SetDestinos(({"Ishtria","Koek"}));
  SetDconductor(RHOEPNJ("/koek/varios/yarkol"));
  SetNombreConductor("Yarkol");
  Set(P_CLEAN_UP,0);
}
