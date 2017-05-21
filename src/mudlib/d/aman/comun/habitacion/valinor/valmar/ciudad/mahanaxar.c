/*
Fichero: mahanaxar.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: El anillo del juicio donde los Valar se reúnen a parlamentar sobre 
los destinos del mundo y a juzgar a quienes osen retar su poder.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{    ::create();
    	SetLocate("Valmar");
    	SetIndoors(0);
    	    SetIntShort("el Máhanaxar");
    SetIntLong("Este es el Máhanaxar, el Anillo del Juicio, donde los Valar se "
    "reúnen para  parlamentar sobre el gobierno de Arda.\n"
"Aquí, los Poderes han debatido durante eones bajo la égira de Manwë y Varda y "
"atendiendo al juicio de Mandos, señor de los muertos, el destino y sumo juez de "
"los Valar.\n"
"Fue  aquí donde Melkor Morgoth, el vala oscuro fue juzgado tres veces y por "
"último, expulsado al Vacío Exterior, y también aquí fue donde se decidió lanzar  la "
"Maldición sobre los Noldor, y casi seiscientos años del Sol más tarde, fue este el "
"lugar donde Eärendil suplicó piedad y ayuda para los Elfos y Hombres vencidos por "
"el Enemigo.\n"
"El Máhanaxar es un anillo elevado sobre varios amplios escalones que soportan una "
"plataforma de mármol de inmaculada blancura.\n"
"Varios tronos rodean el círculo con los dos mayores, los de Manwë, Rey Supremo de Arda "
"y Señor de los Vientos, y su esposa, Varda, Reina de Arda y Creadora de las estrellas, "
"presidiéndolo todo.\n"
"El anillo puede acoger una gran multitud, y muchos son los Maia y  Elfos que acuden a "
"los concilios que aquí tienen lugar.\n");
AddDetail("tronos",
"Son varios altos tronos, cada uno de los cuales está destinado a un vala en particular.\n"
"El de Manwë posee dos águilas de piedra blanca formando el respaldo, el de Varda "
"tiene la parte posterior cuajada de magníficas joyas rutilantes talladas como estrellas, "
"el de Ulmo  el respaldo y los brazos tallados como las ondas marinas, el de Yavanna, "
"un entramado de piedra verde cincelado como un tupido velo de hojas, tallos y flores...\n");
AddExit("este", "./calzadao3");

}