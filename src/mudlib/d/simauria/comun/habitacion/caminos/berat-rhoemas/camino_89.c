/***************************************************************************************
 ARCHIVO:	camino_89.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 MODIFICACION:	Cambio la descripción para indicar que al
 		sur está Azmodan -Kodex- [01-03-02]
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  SetIntLong("Observas con cuidado que te encuentras en un bello camino típico de esta"
	" zona con algo de maleza a los lados. Por las huellas que ves en la tierra"
	" jurarías que hay una diligencia que ofrece el servicio de transporte desde Ishtria"
	" y hasta Koek, en el valle de Rhoemas. Hacia el sur hay un camino"
	" alternativo que te conducirá hasta las grutas de Azmodan.\n");
  AddExit("norte",RHOECAM("camino_90"));
  AddExit("oeste",RHOECAM("camino_88"));
  AddExit("sur",CAMINO_AZMODAN("camino01"));

  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}
