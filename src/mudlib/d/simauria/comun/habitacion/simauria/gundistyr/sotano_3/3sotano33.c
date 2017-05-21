/* ******************************************************************* */
/* *                                                                 * */
/* *       ARCHIVO: 3sotano33.c                                      * */
/* *       CREACION: [a] Articman                                    * */
/* *       MODIFICADO [a] 18-10-01 Creacion                          * */
/* *                                                                 * */
/* ******************************************************************* */

#include "path.h"

inherit SIM_ROOM;

cmd_beber(str){
 if (!str)
 {
 write ("¿Beber qué?\n");
 return 1;
 }
 else
   if(str!="agua"&&str!="agua de la charca"&&str="agua charca")
   {
    write("No encuentras "+str+" para beber.\n");
    return 1;
   }
   else
   {
   if (TP->QueryDrink()>=TP->QueryMaxDrink())
    {
     write("No puedes beber más.\n");
     say (capitalize(TP->QueryName())+" intenta beber en la charca, pero ya está lleno.\n");
     return 1;
    }
    else {
   say(capitalize(W(TP->QueryName())+" bebe agua de la charca y pone muy "
   "mala cara.\n"));
   write(W("Bebes un buen trago de agua de la charca. ¡Está asquerosa! "
         "El agua de este río te hace sentir bastante mal.\n"));
   TP->SetDrink(TP->QueryDrink()+20);
   TP->SetHP(TP->QueryHP()-20);
   return 1;
    }
  }
return 1;
}


init() {
::init();
add_action("cmd_beber","beber");
add_action("cmd_gritar","gritar");
}


create() {
::create();
SetIntLong(W("Te encuentras en las profundas cavernas de Gundistyr. Unas charca "
"se extiende delante tuyo. Parece bastante grande porque no alcanzas a ver el "
"final de ella. En las paredes de la sala cuelgan algunas viejas antorchas "
"que iluminan la sala. Hacia el norte tienes una salida que te lleva a lo "
"que parece un pasillo principal.\n"));

AddDetail(({"charca","agua"}),W("Las aguas de la charca tienen un color "
"verdoso. Hay ciertos elemento flotando sobre ella, aunque no los llegas a "
"identificar, la verdad que no parece muy saludable beber de sus aguas.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(20);

AddExit("norte","3sotano30");
}

int cmd_gritar(string str) {
  write(W("Te dispones a gritar, pero de pronto piensas que eso podría "
  "atraer a gran multitud de seres con lo que desechas la idea.\n"));
  say(W(TP->QueryName() +" parece a dispuesto a hacer algo pero "
  "se hecha atrás.\n"));
return 1;
}
