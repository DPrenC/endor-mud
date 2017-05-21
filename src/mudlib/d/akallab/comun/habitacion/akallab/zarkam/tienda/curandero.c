/*
DESCRIPCION : casa del curandero
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/curandero.c
MODIFICACION: 13-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("la casa del curandero");
 SetIntLong(
    "Estas en consulta de la casa de un curandero. Es una habitacion de tamanyo medio "
    "sobre cuyas paredes se apoya una banda casi continua de estanterias repletas de "
    "frascos y botellas con los mas extranyos productos. Hay una mesa en medio de la "
    "habitacion repleta de utensilios donde el curandero prepara sus pociones. El "
    "aire tiene una extranya mezcla de intensos olores. Hay una nota pegada a la "
    "pared junto a la puerta. Deberias echarle un vistazo.\n");

  AddDetail(({"estanterias"}),
    "Sobre la mayor parte de la superficie de las paredes de apoya una estateria "
    "repleta de cajones y estantes. En ellas el curandero guarda los medicamentos que "
    "emplea en sus curas asi como los ingredientes para hacerlos.\n");

  AddDetail(({"frascos","botellas"}),
    "Las estanterias estan repletas de frascos y botellas de los mas distintos "
    "tamanyos en cuyo interior el curandero guarda todo tipo de sustancias que le son "
    "necesarias para su trabajo. Ves que hay liquidos de los mas variados colores y "
    "texturas asi como frascos rellenos de plantas, semillas o lo que parecen ser "
    "trozos de algunos animales conservados en alcohol.\n");

  AddDetail(({"mesa"}),
     "Es una ancha mesa de madera colocada en el medio de la habitacion. En ella el "
     "curandero prepara las medicinas que necesita con los ingredientes que almacena "
     "en las estanterias.\n");

  AddDetail(({"nota"}),
     "El curandero es capaz con sus medicamentos de curarte a cambio de una razonable "
     "cantidad de dinero en pago por sus servicios. Es capaz de realizar tres tipos "
     "de curas distintas: "
     "  rapida   (es barata, pero solo sanas un poco) "
     "  normal   (precio normal y sanas bastante) "
     "  completa (es cara, pero te cura totalmente) "
     "Para que te cure utiliza 'cura <tipo>' y para que te diga cuanto te costara en "
     "tu estado de salud actual una cura, utiliza 'coste'.\n");

  SetIntNoise("Apenas se oye el ruido de la gente en la calle.\n");
  SetIntSmell("Hay una extranya mezcla de olores en el ambiente.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("norte",Z_CIUDAD("calle_15"));
  AddItem(PNJ_Z_CIUDAD("curandero"), REFRESH_DESTRUCT);
  AddRoomCmd("coger", "coger_cmd");
}

int coger_cmd(string str){
 if ((!str)||((str!="frascos")&&(str!="botellas")&&(str!="medicinas")&&(str!="medicina"))) return 0;
 write(
   "Te lo piensas un momento y decides que mejor sera no coger nada, no vaya a ser "
   "desconociendo los productos que hay aqui te lleves un veneno en lugar de una "
   "medicina. El riesgo es demasido. Si quieres una pocion con un efecto garantizado "
   "lo mejor sera comprarla en algun sitio.\n");
 return 1;
}