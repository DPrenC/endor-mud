/*
Fichero: callejon1.c
Autor: aul�
Fecha: 04/08/2013
Descripci�n: callej�n que pasa al sur del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("un callej�n");
    	SetIntLong("Est�s en un callej�n que jalona la posada del Poney Pisador por la "
    	"parte sur. Al norte se levanta dicho edificio mientras que al sur se encuentran "
    	"otras casas y huertos de los aldeanos de Bree. La calle discurre en pendiente hacia "
    	"la parte alta de la aldea, ocupada por los agujeros de los hobbits.\n"
    	"Al este te interneas en este callej�n y hacia el oeste ves el gran camino que "
    	"cruza toda la aldea hacia la puerta del sur.\n");
    	AddDetail("casas",
    	"Algunas casas de piedra o ladrillo bien construidas se asientan en la falda de la "
    	"colina, sin apelotonarse unas sobre otras, separadas por peque�os huertos y terrenos.\n");
    	AddDetail("huertos",
    	"Peque�as huertas, terrenos herbosos o jardines separan unas casas de las otras, "
    	"cerrados por setos o muros bajos de piedras irregulares.\n");
    AddDetail(({"posada", "poney pisador", "norte"}),
    "Delimitando por el norte el callej�n se alzan los tres pisos del Poney Pisador, "
    "con las ventanas de las diversas habitaciones dando sobre tu cabeza.\n"
    "Parece un edificio antiguo pero s�lido.\n");
    AddDetail(({"agujeros", "agujeros hobbits"}),
    "Desde aqu� no aciertas a verlos.\n");
    	

    AddExit("oeste", "./vias9");
     AddExit("este", "./callejon2");
    }