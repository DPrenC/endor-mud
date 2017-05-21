//entrada.c
//Hecho por Ghandor
//2 de Diciembre de 1997

#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("la entrada a la Escuela de Ingeniería");

 SetIntLong(
"Estas en la Escuela de Ingenieria. Aqui los enanos de la ciudad vienen a "
"comprobar las nuevas creaciones de armas y armaduras. Es uno de los sitios "
"mas concurridos por los guerreros de la ciudad. Muchos mercaderes vienen "
"tambien a ver que novedades pueden ofrecer para sus mejores clientes. En esta "
"sala ves unas escaleras hechas de mithril que llevan al piso de arriba. Hay "
"un cartel a pie de escaleras. Unas antorchas iluminan la sala. Hay unos "
"cuantos cuadros de antiguas armas mas rudimentarias que una piedra. Al norte "
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
 "Son dibujos de armas antiguas, rudimentarias y bastas, nada comparable a lo "
 "hoy existente.\n");

// AddExit("oeste",(SALIDA));
 AddExit("norte",INGE+"garita");
 AddExit("oeste",CIUDAD+"rurik2");
 AddExit("arriba",INGE+"arriba1");

 AddReadMsg(({"cartel","placa"}),
 "\nLees el cartel:\n "
 " Bienvenido a la Escuela de Ingenieria.\n"
 " Aqui podra Ud. aprender, ver, comprar y enterarse "
 " de las nuevas invenciones, ingenios y maquinas que "
 " salgan al mercado. No nos pierda de vista, seguro que "
 " le iremos sorprendiendo muy a menudo. Gracias por su "
 " visita. Atentamente, "
 " ____________ "
 " La Directiva "
 " ~~~~~~~~~~~~\n");

 SetLocate("ingenieria");
}