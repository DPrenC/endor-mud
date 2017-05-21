/***************************************************************************************
 ARCHIVO:	cuero.c
 AUTOR:		[k] Korsario
 FECHA:		08-04-1998
 COMENTARIOS:	Tienda donde hacen cosas de cuero.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
inherit SHOP;

create()
{
    ::create();
    SetIndoors(1);
    SetIntBright(50);
    SetLocate("Flenton");
    SetIntNoise("Escuchas un pequeño ruido proveniente del almacén, ratones quizás.\n");
    SetIntSmell("Huele a cuero.\n");
    SetIntShort("el taller del artesano");
    SetIntLong("Es el taller del artesano de cuero de Flenton. Por todos lados ves piezas de "
        "cuero y de artesanía. La mayoría están sin terminar. En un lado hay un montón de "
        "pieles de diversos tamaños y colores. Hay una mesa con herramientas y los utensilios "
        "necesarios para trabajar el cuero.\n");
    AddDetail(({"pieles","piel"}),"Ves pieles de animales colgadas de las paredes, "
  	    "parecen todas de calidad.\n");
    AddDetail(({"piezas","piezas de cuero"}),"Ves varios objetos de cuero sin terminar.\n");
    AddDetail(({"monton","monton de pieles","montón","montón de pieles"}),"Ves un montón "
      	"de pieles apiladas en una esquina.\n");
    AddDetail(({"mesa"}),"Ves la mesa de trabajo del artesano.\n");
    AddDetail(({"herramientas","utensilios"}),"La mesa del artesano esta llena de "
      	"herramientas y utensilios que utiliza en su labor.\n");
    AddDetail(({"tienda","tienda de cuero"}),"Es una tienda de cuero de bastante renombre. "
        "Viene gente importante de muy lejos a comprar a esta tienda.\n");
    AddRoomCmd("matar","fmatar");
    AddExit("sur",FLENHAB+"calles/kendarg_02");
    AddArticle(FLENPRT+"malla", REFRESH_REMOVE, 3);
    AddArticle(FLENPRT+"jubon", REFRESH_REMOVE, 2);
    AddArticle(FLENPRT+"botas", REFRESH_REMOVE, 3);
    AddArticle(FLENPRT+"escudo", REFRESH_REMOVE, 3);
    AddArticle(FLENPRT+"pantalon", REFRESH_REMOVE, 3);
    AddArticle(FLENPRT+"guantes", REFRESH_REMOVE, 3);
    RemoveDustbin();
    SetShopkeeper(FLENPNJ+"poblado/arkos");
}

int fmatar(string str)
{
	  if(!str) return 0;
	  write("El tendero pone cara de pocos amigos y de una patada en el trasero "
    		"te pone de patitas en la calle.\nEl tendero grita: ¡Aquí no se mata a "
    		"nadie! ¡Este es un establecimiento decente!.\n");
	  say("El tendero echa a "+CATP+".\n");
	  TP->move(FLENHAB+"calles/kendarg_02",M_GO);
	  return 1;
}
