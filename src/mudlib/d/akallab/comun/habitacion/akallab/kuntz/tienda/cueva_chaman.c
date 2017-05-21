/*
DESCRIPCION : cueva del chaman
FICHERO     : /d/akallab/comun/habitacion/akallab/kuntz/tienda/cueva_chaman.c
MODIFICACION: 24-11-99 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
 ::create();
 SetIntShort("la cueva del curandera");
 SetIntLong(
   "Te encuentras en la cueva del chaman de la tribu. Al fondó de la cueva "
     "observas un monton de ramas secas que hacen las veces de cama del "
	 "chaman las noches que este no pasa en vela orando a la roca sagrada. "
     "En el centro de la cueva y sobre un lento fuego hierve lentamente el "
     "contenido de un caldero, posiblemente alguna medicina dado que el "
	 "chaman es curandero ademas del lider espiritual de la tribu. Junto "
	 "a una de las paredes se apilan varios cuencos con lo que parecen "
	 "contener varios tipos de hierbas. Un extranyo amuleto cuelga junto "
	 "a la entrada de la cueva.\n");
 AddDetail(({"cueva"}),QueryIntLong());
 AddDetail(({"ramas","cama"}),
  "Un monton de ramas secas al fondo de la cueva hacen las veces de la "
    "cama al fondo de esta cueva.\n");
 AddDetail(({"fuego"}),
  "Un pequenyo fuego arde lentamente en el centro de la cueva. Sobre el se halla "
    "un viejo caldero en el que hierve algun tipo de pocion o cura preparada "
	"por el chaman.\n");
 AddDetail(({"caldero","pocion"}),
  "Es un viejo caldero de metal posiblemente robado a los orcos. En su "
    "interior hierve algun tipo de pocion o cura preparada por el "
	"curandero.\n");
 AddDetail(({"cuencos","hierbas"}),
   "Varios cuencos que parecen contener distintos tipos de hierbas se "
     "apilan junto a una de la paredes de la cueva. Seguramente deben ser "
	 "ingredientes para las distintas pociones y curas que realiza el "
	 "chaman.\n");
 AddDetail(({"amuleto"}),
     "Un extranyo amuleto cuelga de un saliente en la roca junto a la "
     "entrada de la misma. Esta hecho con plumas y huesos de pajaro y "
	 "posiblemente sea para ahuyentar a los malos espiritus. También "
	 "identifica al propietario de la cueva como chamán y curandero.\n" //
     "El chamán es capaz de curarte a cambio de una razonable cantidad "
	 "de dinero en pago por sus servicios. Es capaz de realizar tres tipos "
     "de curas distintas:\n" //
     "  rapida   (es barata, pero solo sanas un poco)\n" //
     "  normal   (precio normal y sanas bastante)\n"     //
     "  completa (es cara, pero te cura totalmente)\n"   //
     "Para que te cure utiliza 'cura <tipo>' y para que te diga cuanto "
	 "te costara en tu estado de salud actual una cura, utiliza 'coste'.\n");

  AddExit("oeste",K_CUEVA("caverna16"));
  AddItem(PNJ("k_cueva/chaman"), REFRESH_DESTRUCT);
  AddRoomCmd("coger", "coger_cmd");

  SetIntNoise("Oyes el borboteo de la coccion en el caldero.\n");
  SetIntSmell("Huele.... a troll!!.\n");
  SetLocate("cavernas Troll en Kuntz");
  SetIndoors(1);
  SetIntBright(30);
}

int coger_cmd(string str){
 if (str=="amuleto"){
    write("El amuleto carece de mas valor que el que le da quien cree en el. "
	        "Decides dejarlo donde esta.\n");
	return 1;
    }
if ((str=="cuencos")||(str=="hierbas")){
   write("Te lo piensas un momento y decides que mejor sera no coger nada, "
           "no vaya a ser desconociendo los productos que hay aqui te lleves "
		   "un veneno en lugar de una cura. El riesgo es demasido. Si quieres "
		   "una cura con efecto garantizado mejor seria pagarla.\n");
   return 1;
   }
return 0;
}