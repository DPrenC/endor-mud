/*
DESCRIPCION  : Ciudad de Tiinkdel
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/tiin/ciudad/suelo/puesto1.c
NOTAS        : [Ch] 03-06-98  Hay que anyadir los guardias.
               [l] 19/10/00 pienso lo mismo :)
               [l] 17/01/03 He vuelto a esto, el tiempo pasa volando!!! agregue
               detalles de descripcion en la habicacion
               [l] 18/01/03 Puse una funcion pa beber agua del barril
MODIFICACION :
*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit LAD_ROOM;

create() {
  ::create();
SetIntShort("el puesto de guardia");
SetIntLong(
"Esta pequeña estancia da cobijo a los guardias que custodian la salida norte\n"
"de la ciudad de Tiinkdel. Dispuestas por toda la pared estan colgadas las armas\n"
"y armaduras de reserva que los guardias no estan usando. El moviliario es muy\n"
"escaso, un par de sillas y una mesa. Tambien hay un pequeño barril de agua y\n"
"un pequeño armario para guardar las provisiones.\n");

AddDetail (({"arma","armas","armadura","armaduras"}),
"Dispuestas en perfecto orden se encuentran las armas y armaduras que usan los\n"
"guardias. Estan en perfecto estado y brillan magestuosamente.\n");

AddDetail (({"mesa"}),
"Como si fuese un apendice más del árbol, la mesa surge directamente desde el\n"
"suelo de la habitación. Sobre ella hay varios papeles oficiales, unos botes\n"
"de tinta y unas plumas para poder escribir.\n");

AddDetail (({"papales","papales oficiales"}),
"Son un monton de papeles sin importancia.\n");

AddDetail (({"bote","bote de tinta","tinta"}),
"Es un bote de tinta azul que usan los guardias para escribir los reportes.\n");

AddDetail (({"pluma","plumas"}),
"Son varias plumas de color blanco para escribir.\n");

AddDetail (({"silla","sillas"}),
"Son sillas de madera con tres patas y respaldo de varillas.\n");

AddDetail (({"barril","barril de agua"}),
"Es un barril de agua fresca y cristalina. El solo ver el agua te da ganas de\n"
"beber, tal ves si pruebas un poco puedas refrescarte.\n");

AddDetail (({"armario","pequenyo armario","pequeño armario"}),
"Es un armario de madera con muchas armas ordenadas dentro\n");

SetIntBright(20);
SetIntNoise(
"El mas minimo murmullo procedente de la calle se oye desde este lugar.\n");
SetIntSmell(
"El olor a savia que desprende el interior del arbol impregna todo el ambiente.\n");
SetLocate("Ciudad Tiinkdel");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("este",TCSUELO("salida1"));

}

void init(){
   ::init();
   add_action("fleer","leer");
   add_action("fbeber","beber");
}

int fbeber(string cadena){
   if((cadena != "agua de barril")||(cadena != "agua")){
      return 1;
   }
   else{
     write("Bebes el agua y te refrescas completamente\n");
     say(TP->QueryName()+" bebe agua de un barril.\n");
     /* Esta agua esta mezclada con savia, asi que te quita siempre completamente
        la sed de un sorbo */
     /*TP->Set*/
     return 1;
   }
}
