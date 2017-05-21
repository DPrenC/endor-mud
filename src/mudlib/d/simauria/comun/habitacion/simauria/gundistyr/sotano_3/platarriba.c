/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: platarriba.c                                          * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 28/01/02 [a] Creación                              * */
/* *                                                                     * */
/* *********************************************************************** */


#include "path.h"
#include <moving.h>

inherit SIM_ROOM;

escribir(int i){
switch (i) {
 case 1: write("La plataforma comienza a ascender.\n");
  call_out("escribir",2,2);
  break;
 case 2: write("Continuas tu ascenso en la plataforma.\n");
  call_out("escribir",3,3);
  break;
 case 3: write("Levantas la cabeza y observas como te acercas a tu "
  "destino.\n");
  call_out("escribir",3,4);
  break;
 default : write(W("Finalmente la llegas al final, hasta la superfecie. "
  "Sales de la plataforma, pero al soltar la cuerda la plataforma cae de "
  "nuevo.\n"));
  TP->move(GSUP("torre15"),M_SILENT);
   break;
  return 1;}}
init() {
::init();
{
call_out("escribir",2,1);
return; }
	}
create() {
::create();
SetIndoors(1);
SetIntShort("la plataforma");
SetIntBright(20);

SetIntLong(W("Estás sobre una plataforma de madera contruida a base de "
"troncos de árboles atados fuertemente por cuerdas. La plataforma está "
"ascendiendo hacia la superficie, dejando bajo de tí las cuevas de las "
"ruinas de Gundistyr. Estás ascendiendo debido al impulso que se "
"consigue estirando la cuerda que hay en uno de los laterales y que está "
"atada a la base de la plataforma.\n"));

AddDetail(({"suelo","plataforma"}),W("Bajo tus pies hay una plataforma de "
"madera hecha de troncos de árboles atados por una dura cuerda que impide "
"que se separen.\n"));

AddDetail(({"pared","paredes"}),W("Las paredes de estás cuevas son bastante "
"altas y están formadas de dura piedra caliza.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza no hay absolutamente nada "
"mas que aire.\n"));

AddDetail(({"soga"}),W("En uno de los lados ves una cuerda que sube hacia "
"arriba.\n"));

SetSmell(W("Aspiras el aire, y si aunque no detectas nada en especial, "
"notas como te relajas.\n"));
SetNoise(W("Lo único que escuchas es un leve pero permanente ruido "
"melodioso.\n"));
AddDetail(({"pared","paredes",}),W("Es una pared circular de piedra. "
" No observas nada que te pueda indicar el origen de la fuerza que te "
"sostiene.\n"));
AddDetail(({"plataforma"}),W("Bajo tus pies hay una plataforma de "
"madera hecha de troncos de árboles atados por una dura cuerda que impide "
"que se separen.\n"));
}