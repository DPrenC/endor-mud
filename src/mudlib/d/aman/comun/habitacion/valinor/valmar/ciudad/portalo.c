/*
Fichero: portalo.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: bajo la puerta oeste de valmar.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{    ::create();
    	SetIndoors(1);
    	SetIntBright(40);
    	    	    SetIntShort("bajo el portal occidental");
SetIntLong("Te encuentras bajo los muros exteriores de Valmar, capital de los Valar.\n"
"El gran dintel de forma semicircular, surge a ambos lados desde el suelo y se curva "
"sobre ti a gran altura. En la superficie umbría de la piedra blanca no puedes "
"encontrar ninguna juntura, hendidura o marca de cincel, pues las murallas, al igual "
"que el resto de la urbe surgieron del seno de la roca por voluntad expresa de los Valar.\n"
"Los ecos resuenan en el ancho pasaje pero la luz procedente de la ciudad que "
"vislumbras un poco más al este, hace que  no sea oscuro ni lúgubre, más al contrario, "
" una antesala a la maravilla que se extiende más allá.\n"
"Al este se abre la ciudad de Valmar y  al oeste una calzada parte del Portal "
"Occidental hacia el Anillo del Juicio y otros dominios y regiones del Reino Bendecido.\n");
AddDetail(({"valmar", "ciudad", "este"}),
"La ciudad de Valmar se extiende al este, y pese a que desde aquí vislumbras un esbozo "
"de su belleza y magnífica arquitectura, deberás de entrar para observarla en todo su "
"esplendor.\n");
AddDetail(({"calzada", "oeste"}),
"Una calzada pavimentada de mármol parte hacia el oeste desde el Portal Occidental, "
"dirigiéndose hacia el Máhanaxar, surcando la ondulante llanura verde en la que se "
"iergue Valmar.\n");
AddDetail(({"portal", "portal occidental", "occidental", "portales"}),
"Es un gran portal dorado cuyos batientes de rutilante e indestructible oro macizo "
"permanecen siempre abiertos de par en par, dando la bienvenida al viajero.\n");
AddDetail(({"máhanaxar", "mahanaxar", "anillo del juicio", "juicio", "anillo"}),
"Volviéndote hacia el oeste apenas si logras distinguirlo como un montículo verde "
"coronado de piedra blanca.\n");
AddDetail("dintel",
"El enorme dintel de piedra blanca y lisa se curva sobre ti con majestuosa grandiosidad.\n");
AddDetail(({"muros", "murallas", "muralla"}),
"Las altas e impenetrables murallas de Valmar se levantan a los lados y sobre ti, "
"atravesadas por el pasaje donde te encuentras.\n");
SetIntSmell("Hueles una suave fragancia, mezcla de verdor y aire agradablemente húmedo.\n");
SetIntNoise("Escuchas el tañir de las campanas de la ciudad, claras voces que entonan "
"canciones en honor de los Valar y el tenue rasguido de las arpas de plata élfica.\n");     	    
    	    AddExit("oeste", "./antepuertao");
    	    AddExit("este", "./gavenida1");
    	    }
    	    
public void init()
{
	::init();
	write("Te internas bajo el grandioso portal occidental.\n");
  }

