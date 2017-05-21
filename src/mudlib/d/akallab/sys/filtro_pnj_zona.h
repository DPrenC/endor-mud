/*
DESCRIPCION  : Funcion de filtro para PNJ de una zona
FICHERO      : /d/akallab/comun/sys/filtro_pnj_zona.h
MODIFICACION : 03-02-00 [Angor@Simauria] Creacion
USO          :

1. Incluye este fichero en tu habitacion
#include FILTRO_PNJ_ZONA

2. En la habitacion define dos macros:
#define DESTINO "habitacion_a_donque_conduzca_la_salida"
//#define MARCA_PNJ_ZONA "id_de_marca_que_llevaran_los_pnj_de_la_zona"

3. Anyade la salida filtrada a la habitacion
AddExit("sudeste",SF(FiltroPnjZona));

----------------------------------------------------------------------------
*/
#include <moving.h>

int FiltroPnjZona()
{
//int ok;
//ok=0;
//if (this_player()->QueryIsPlayer() ok=1; //los PJ pasan sin problemas
//else
//	if (obj->QueryIds())
//	    if (member(this_player()->QueryIds(), MARCA_PNJ_ZONA)==-1) ok=1;
//
//if (ok==1) return this_player()->move(DESTINO,M_GO)
//else return 1;


if ((this_player()->QueryIsPlayer())||(this_player()->Query("pnj_zona")==0))
	return this_player()->move(DESTINO,M_GO);
else return 1;
}
