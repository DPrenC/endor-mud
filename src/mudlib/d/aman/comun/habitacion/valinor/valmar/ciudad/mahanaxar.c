/*
Fichero: mahanaxar.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: El anillo del juicio donde los Valar se re�nen a parlamentar sobre 
los destinos del mundo y a juzgar a quienes osen retar su poder.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{    ::create();
    	SetLocate("Valmar");
    	SetIndoors(0);
    	    SetIntShort("el M�hanaxar");
    SetIntLong("Este es el M�hanaxar, el Anillo del Juicio, donde los Valar se "
    "re�nen para  parlamentar sobre el gobierno de Arda.\n"
"Aqu�, los Poderes han debatido durante eones bajo la �gira de Manw� y Varda y "
"atendiendo al juicio de Mandos, se�or de los muertos, el destino y sumo juez de "
"los Valar.\n"
"Fue  aqu� donde Melkor Morgoth, el vala oscuro fue juzgado tres veces y por "
"�ltimo, expulsado al Vac�o Exterior, y tambi�n aqu� fue donde se decidi� lanzar  la "
"Maldici�n sobre los Noldor, y casi seiscientos a�os del Sol m�s tarde, fue este el "
"lugar donde E�rendil suplic� piedad y ayuda para los Elfos y Hombres vencidos por "
"el Enemigo.\n"
"El M�hanaxar es un anillo elevado sobre varios amplios escalones que soportan una "
"plataforma de m�rmol de inmaculada blancura.\n"
"Varios tronos rodean el c�rculo con los dos mayores, los de Manw�, Rey Supremo de Arda "
"y Se�or de los Vientos, y su esposa, Varda, Reina de Arda y Creadora de las estrellas, "
"presidi�ndolo todo.\n"
"El anillo puede acoger una gran multitud, y muchos son los Maia y  Elfos que acuden a "
"los concilios que aqu� tienen lugar.\n");
AddDetail("tronos",
"Son varios altos tronos, cada uno de los cuales est� destinado a un vala en particular.\n"
"El de Manw� posee dos �guilas de piedra blanca formando el respaldo, el de Varda "
"tiene la parte posterior cuajada de magn�ficas joyas rutilantes talladas como estrellas, "
"el de Ulmo  el respaldo y los brazos tallados como las ondas marinas, el de Yavanna, "
"un entramado de piedra verde cincelado como un tupido velo de hojas, tallos y flores...\n");
AddExit("este", "./calzadao3");

}