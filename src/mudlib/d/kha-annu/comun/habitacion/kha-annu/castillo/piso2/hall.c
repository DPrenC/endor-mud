/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "./path.h"

inherit KHA_ROOM;
create() {
  ::create();
  SetIntShort("el Salón del Trono");
  SetIntLong(
"Te encuentras en el Salon del Trono de Belthain, Rey de los Enanos. Al "
"fondo de la sala ves un gran sillon con los emblemas de la ciudad y la "
"corona de Kha-annu. Rodeando el salon puedes ver algunas estatuas que "
"parecen ser las mismas que habia en el jardin de la entrada al castillo.\n"
"El suelo esta hecho del mas fino marmol, y las paredes parecen de oro.\n"
"Te empiezas a preguntar de donde salen todos estos materiales maravillosos "
"y tan caros.\n");

  SetIndoors(1);

  SetIntBright(100);

  AddExit("norte",PISO2+"piso2_10");
  AddExit("sur",PISO2+"piso2_11");

  AddDetail( ({"trono","sillon"}),
"Observas el inmenso sillon del trono, parece muy comodo. Sobre el ves el "
"escudo con los emblemas de la ciudad y la coronas de Kha-annu.\n");
  AddDetail("suelo","Puedes ver el reflejo de las lamparas sobre el suelo\n");
  AddDetail( ({"lampara","lamparas"}),
"Ves lamparas de diamante que cuelgan del techo y que despiden una luz "
"azulada.\n");
  AddDetail(({"paredes","pared"}),
"Al fijarte bien notas que las paredes, realmente, estan hechas de oro!\n");

  AddDetail(({"estatua","estatuas",}),
"Las estatuas rodean la estancia. Son las imagenes de los antiguos reyes "
"de Kha-annu.\n");

  AddDetail("escudo",
"Un antiguo grabado en el escudo representa las armas y el estandarte de "
"de Kha-annu... Dos hachas cruzadas.\n");

  AddItem(MONS+"belthain",REFRESH_DESTRUCT,1);
/*
  AddItem(MONS+"guardaespalda",REFRESH_DESTRUCT,5);
*/
  AddItem(MONS+"sirviente",REFRESH_DESTRUCT,2);
}