/***************************************************************************************
 ARCHIVO:	cendaf_06.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Calle Cendaf de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/cendaf_05"));

    AddExit("norte",RHOEHAB("koek/calles/cendaf_05"));
    AddExit("sudeste",RHOECAM("camino_92"));

    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT,2);
    map[neu,des]= "Estás en la entrada del pueblo de Koek, en el valle de "
  	"Rhoemas. La calle en la que te encuentras atraviesa el pueblo de "
  	"sur a norte, mientras que al sudeste un camino se aleja de él. "
  	"En uno de los laterales del camino rodeado por pequeños arbustos "
  	"observas un pequeño tablón. ";
  	
    AddDetail(({"tablon","tablón"}),"Un viejo tablón de madera está clavado "
   	"en la tierra, aunque se encuentra ligeramente torcido. En el puedes "
   	"leer[36m Koek[0m.\n");
   	
    AddDetail(({"arbustos"}),"Hay unos retorcidos arbustos a un lado del camino, "
  	"casi tapando por completo un pequeño tablón.\n");

    AddDetail(({"camino"}),"Un serpenteante camino se aleja de la cuidad por "
  	"el sudeste, saliendo del valle.\n");
}