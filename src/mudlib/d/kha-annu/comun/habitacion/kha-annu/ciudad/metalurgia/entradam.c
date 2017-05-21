//entradam.c
//Hecho por Ghandor
//2 de Diciembre de 1997

#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("la entrada a la Escuela de Metalurgia");

 SetIntLong(
"Estas en la Escuela de Metalurgia. Aqui los enanos de la ciudad vienen a "
"comprobar las nuevas combinaciones de metales y otros materiales. Es un "
"sitio muy concurrido. Aqui vienen muchos herreros para hacer nuevos materiales.\n"
"Ves unas escaleras hechas de mithril que llevan al piso de arriba. Hay "
"un cartel a pie de escaleras. Unas antorchas iluminan la sala. Hay unos "
"cuantos cuadros de antiguos de mezclas entre madera y acero. Al norte "
"hay una garita de seguridad, quiza has de pasar por alli antes de moverte.\n");

 SetIndoors(1);

 SetIntBright(80);

 SetIntNoise("Silencio sepulcral, mejor no hagas mucho ruido.\n");

 AddDetail(({"escaleras","escalones"}),
 "Son unas escaleras hechas a base de mithril que llevan al piso de arriba.\n");
 AddDetail(({"antorchas","luces"}),
 "Son unas antorchas hechas de mithril. En su cumbre arden unas brasas que dan "
 "una luz impresionante.\n");
 AddDetail(({"cuadros","fotos"}),
 "Son dibujos de armas con combinaciones de madera y acero. Aun no existia el "
 "mithril.\n");

// AddExit(META+"este",(SALIDA));
AddExit("norte",META+"garitam");
AddExit("oeste",CIUDAD+"rurik6");
 AddExit("arriba",META+"arriba1m");

 AddReadMsg(({"cartel","placa"}),
 "Lees el cartel:\n"
 " Bienvenido a la Escuela de Metalurgia.\n"
 " Aqui podra Ud. aprender, ver, y enterarse "
 " de las nuevas combinaciones de diversos materiales "
 " que salgan al mercado. No nos pierda de vista, seguro que "
 " le iremos sorprendiendo muy a menudo. Gracias por su "
 " visita. Atentamente, "
 " _____________ "
 " La Direccion.\n"
 " ~~~~~~~~~~~~~\n");

}
