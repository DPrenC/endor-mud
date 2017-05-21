/***************************************************************************************
 ARCHIVO:	rhoek.c
 AUTOR:		[z] Zomax
 FECHA:		18-02-2002
 COMENTARIOS:	Diligencia Rhoek
 		Recorrido: Ishtria-Berat-Koek-Berat-Ishtria
 MODIFICACION:  23-03-2003 Cambio typos de la capital. La h donde toca.
 ***************************************************************************************/

#include "path.h"
inherit ROOM;

create(){
  ::create();
 SetIntShort("la diligencia Rhoek");
  SetIntLong("Estás dentro de la diligencia Rhoek, que suele hacer el recorrido "
  	"Ishtria-Koek y vuelta. Es una diligencia bastante decente de madera "
  	"que te evita un largo y angustioso camino por lo desconocido.\n");
  SetIntBright(50);
}
