//garita.c
//Hecho por Ghandor
//2 de Diciembre de 1997

#include "./path.h"
#include <rooms.h>

inherit KHA_ROOM;

create() {
 ::create();

 SetIntShort("la Garita de Seguridad de Ingeniería");

 SetIntLong(
"Entras en la garita de seguridad de la Escuela de Ingenieria. Es una habitacion "
"pequenya, con las paredes vacias. Delante tuyo hay un cubiculo bastante "
"minusculo, donde parece imposible que quepa el anciano enano que hay dentro.\n"
"Hay un cartel encima de la garita. Unas antorchas iluminan el sitio.\n");

 SetIndoors(1);

 SetIntBright(80);

 SetIntNoise("La tos del anciano enano rompe todo silencio.\n");
 SetIntSmell("La medicina del viejo se te impregna en la nariz.\n");

 AddDetail(({"garita","caja de seguridad"}),
 "Es una garita sucia. Esta hecha de madera con un cristal enorme que llega al "
 "techo.\n");
 AddDetail(({"antorchas","luces"}),
 "Son unas antorchas hechas de mithril. En su cumbre arden unas brasas que dan "
 "una luz impresionante.\n");
 AddDetail(({"cristal","cristal de la garita"}),
 "Es un cristal extremadamente duro con un simple agujero para que puedas hablar "
 "con el viejo.\n");

 AddExit("sur",INGE+"entrada");

 AddReadMsg(({"cartel","placa"}),
 "Lees el cartel, escrito con mala gana:\n"
 " Mi trabajo es de darte un ticket si quieres entrar.\n"
 " Asi que ya sabes, dame tu DNI o simplemente dime tu nombre, "
 " y te apuntare en el registro. No me molestes para nada mas.\n");

 AddItem(MONS+"marthuknez",REFRESH_DESTRUCT,1);

 SetLocate("ingenieria");
}
