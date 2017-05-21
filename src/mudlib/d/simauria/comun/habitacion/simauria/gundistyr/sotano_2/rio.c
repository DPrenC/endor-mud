/* ************************************************** */
/* *                                                * */
/* *       ARCHIVO: rio.c                           * */
/* *       CREACION: [a] Articman                   * */
/* *       MODIFICADO [a] 18-10-01 Creacion         * */
/* *                                                * */
/* ************************************************** */

#include "path.h"
#include <properties.h>

inherit SIM_ROOM;


int cmd_gritar(string str) {
	write(
"Te dispones a gritar, pero de pronto piensas que eso podría atraer a gran "
"multitud de seres con lo que desechas la idea.\n");
	say(TP->QueryName() +" parece a dispuesto a hacer algo pero se "
"hecha atrás.\n");
return 1;
}


haz_beber(str){
 if (!str)
 {
 write ("¿Beber qué?\n");
 return 1;
 }
 else
   if(str!="agua"&&str!="agua del rio"&&str="agua rio")
   {
    write("No encuentras eso para beber.\n");
    return 1;
   }
   else
   {
   if (TP->QueryDrink()>=TP->QueryMaxDrink())
    {
     write("No puedes beber más.\n");
     say (capitalize(TP->QueryName())+" intenta beber en el rio, pero ya está lleno.\n");
     return 1;
    }
    else {
   say(capitalize(TP->QueryName())+" bebe agua del rio. Parece refrescante...\n");
   write("Bebes un buen trago de agua del rio. "
         "Parece refrescante y tonificante\n");
   TP->SetDrink(TP->QueryDrink()+4);
   TP->SetHP(TP->QueryHP()+1);
   if (TP->QueryHP()>TP->QueryMaxHP())
       TP->SetHP(TP->QueryMaxHP());
   return 1;
    }
  }
return 1;
}


init() {
::init();
add_action("haz_beber","beber");
add_action("cmd_gritar","gritar");
}


create() {
::create();
SetIntLong(
"Te encuentras en las profundas cavernas de Gundistyr. Aquí puedes ver un "
"río subterráneo que discurre por las cuevas y que muy posiblemente fue el "
"creador de las mismas. Al norte tienes una salida que se adentra en las "
"cuevas. No ves nada más de interés.\n");

AddDetail(({"rio","rio subterraneo"}),
"Es un rio subterraneo que discurre por estas cuevas. A él se debe el rumor "
"que escuchas desde hace tiempo. Parece que puedes beber agua de el sin "
"problemas.\n");
SetIntSmell("No hueles más que humedad a tu alrededor.\n");
SetIntNoise("Escuchas el ligero correr del rio que tienes a tu lado.\n");

AddExit("norte","2sotano79");
}