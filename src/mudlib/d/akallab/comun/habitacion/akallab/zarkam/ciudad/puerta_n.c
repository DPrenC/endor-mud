/*
DESCRIPCION  : Puerta norte de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/puerta_n.c
MODIFICACION : 12-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>
#include <properties.h>


inherit ROOM;

#define NOMBRE (capitalize(TP->QueryName()))
#define AO     (TP->QueryGender()==GENDER_FEMALE?"a":"o")

int entrar() {
string suf;
suf=TP->QueryGender()==GENDER_FEMALE?"a":"o";

if (!TP) return 0;

// no, no hay guardia
if ((!present("rompehuesos", TO))&& (!present("masoch", TO)))
   return TP->move(Z_CIUDAD("calle_06"),M_SPECIAL,
   ({"se va hacia el sur","llega desde el norte",
   "Sin nadie que te lo impida, entras en la ciudad de Zarkam.\n"}));

// si, hay guardia
// es por el dia
if (QueryDayState()<3 || QueryDayState()>7){
   say(
      NOMBRE+" se acerca a la puerta de la ciudad de Zarkam, pero cuando se dispone "
      "a cruzarla es detenid"+AO+" por el guardia. Este da un par de vueltas a su "
      "alrededor, examinandol"+AO+" asi como a su equipo. Finalmente le deja pasar  "
      "aunque no parece muy convencido.\n",TP);
   write(
      "Cuando tratas de entrar en la ciudad de Zarkam eres detenid"+AO+" por la guardia. "
      "El guardia te dice:'¡Alto!, no tan deprisa. No todo el mundo puede entrar aqui'. "
      "El guardia da un par de vueltas a tu alrededor examinando tanto a ti como a tu "
      "equipo. Tras pensarselo un momento decide dejarte pasar, aunque por sus gestos "
      "deduces que no esta totalmente convencido. Te dice:'Adelante!, pero cuidado con "
      "lo que haces en la ciudad'.\n");
   return TP->move(Z_CIUDAD("calle_06"),M_SPECIAL,
      ({"se va hacia el sur","llega desde el norte",
      "Sin nadie que te lo impida, entras en la ciudad de Zarkam.\n"}));
   }
// es por la noche
else{
   //Es una ciudad orca
   if (TP->QueryRace()=="orco"){
      say(
         NOMBRE+" se acerca a la puerta de la ciudad de Zarkam, pero cuando se dispone "
         "a cruzarla es detenid"+AO+" por el guardia. Este da un par de vueltas a su "
         "alrededor, examinandol"+AO+" asi como a su equipo. Finalmente le hace un "
         "comentario y le deja pasar a pesar de la hora.\n",TP);
      write(
         "Cuando tratas de entrar en la ciudad de Zarkam eres detenid"+AO+" por la guardia. "
         "El guardia te dice:'¡Alto!, no tan deprisa. No todo el mundo puede entrar aqui'. "
         "El guardia da un par de vueltas a tu alrededor examinando tanto a ti como a tu "
         "equipo. Tras pensarselo un momento decide dejarte pasar, aunque por sus gestos "
         "deduces que no esta totalmente convencido. Te dice: Por ser estas horas no "
         "deberia... pero bueno, por ser tambien un orco te dejo pasar. Cuidado con lo "
         "que haces en la ciudad.\n");
      return TP->move(Z_CIUDAD("calle_06"),M_SPECIAL,
         ({"se va hacia el sur","llega desde el norte",
         "La puerta de la ciudad de Zarkam y su guardia quedan atras..."}));
     }

     //Si no eres orco necesitas un salvoconducto para entrar por la noche
     else{
        if (present("salvoconducto_zarkam", TP)){
           say(
              NOMBRE+" se acerca a la puerta de la ciudad de Zarkam, pero cuando se dispone "
              "a cruzarla es detenid"+AO+" por el guardia. Este da un par de vueltas a su "
              "alrededor, examinandol"+AO+" así como a su equipo. Tras una breve conversación " +
              TNAME + "le muestra un documento al guardia y este, de mala gana le deja pasar.\n",TP);
           write(
              "Cuando tratas de entrar en la ciudad de Zarkam eres detenid"+AO+" por la guardia. "
              "El guardia te dice:'¡Malditos extranjeros! ¡Alto!, Oye, +donde crees que vas? No "
              "todo el mundo puede entrar en Zarkam'. El guardia da un par de vueltas a tu "
              "alrededor examinando tanto a ti como a tu equipo. Tras pensarselo un momento, "
              "pide que le muestres el salvoconducto que te permite transitar por Zarkam y tu "
              "se lo ensenyas. Aunque por sus gestos deduces que no esta totalmente convencido, "
              "te deja pasar. Te dice:'¡Adelante!, pero cuidado con lo que haces en la ciudad'.\n");
           return TP->move(Z_CIUDAD("calle_06"),M_SPECIAL,
              ({"se va hacia el sur","llega desde el norte",
              "Sin nadie que te lo impida, entras en la ciudad de Zarkam.\n"}));
           }
        else{
           say(
              NOMBRE+" se acerca a la puerta de la ciudad de Zarkam, pero cuando se dispone "
             "a cruzarla es detenid"+AO+" por el guardia. Este da un par de vueltas a su "
             "alrededor, examinandol"+AO+" asi como a su equipo. Tras una breve conversacion "
             "el guardia finalmente no le deja entrar en la ciudad.\n",TP);
           write(
             "Cuando tratas de entrar en la ciudad de Zarkam eres detenid"+AO+" por la guardia. "
             "El guardia te dice:'¡Malditos extranjeros! ¡Alto!, Oye, +donde crees que vas? No "
             "todo el mundo puede entrar en Zarkam'. El guardia da un par de vueltas a tu "
             "alrededor examinando tanto a ti como a tu equipo. Tras pensarselo un momento, "
             "pide que le muestres el salvoconducto que te permite transitar por Zarkam. No lo "
             "tienes asi que el guardia no te deja pasar. El guardia te dice:'Los extranjeros "
             "indocumentados no pueden transitar por la noche por Zarkam a menos que dispongan "
             "del salvoconducto adecuado'. Piensas que seria interesante conseguir uno.\n");
           return 1;
           }
        }
   }
}



int matar_cmd(string str) {
  object co, ma;
  if (str=="Masoch" || str=="masoch" || str=="orco" || str=="guardia" || str=="soldado") {
     if (ma = present("Rompehuesos", TO)) {
         co = present("corpse", TO);
         if (ma && ma!=co) {
            write("Deberas matar a Rompehuesos primero, miserable! Ja, ja!\n");
            return 1;
         }
     }
  }
  return 0;
}


// --------------------------------------------------------------------------------
create() {
  ::create();
  SetIntShort("la puerta norte de Zarkam");
  SetIntLong(
     "Estás frente a la puerta norte de la ciudad fortificada de Zarkam. La alta "
     "muralla de piedra que rodea Zarkam tiene aquí una inmensa puerta de dos hojas de"
     "metal macizo. Junto a la puerta suele haber una guardia formada por dos "
     "corpulentos soldados orcos armados hasta los dientes que detiene e interroga a"
     "cualquiera con aspecto sospechoso que intente entrar en la ciudad. El Sendero de"
     "los Cráneos continua a partir de aqui hacia el norte.\n");

  AddDetail(({"Sendero","sendero","Sendero de los Cráneos","sendero de los cráneos"}),
     "El Sendero de los Cráneos es la mas importante via de comunicacion en la "
     "peninsula orca que recorre de norte a sur serpenteando a traves de altas "
     "cordilleras y profundos acantilados. Los esclavos capturados por los orcos en la "
     "guerra han sido obligados a construirlo para mayor gloria del Emperador orco. "
     "Los huesos de aquellos que han dejado su vida en esta construccion se mezclan "
     "con el pavimento y sus cráneos estan clavados en altos postes junto al camino "
     "como advertencia a cualquiera que pretenda enfrentarse al imperio orco...\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

  AddDetail(({"muralla"}),
     "Es una alta muralla construida con grandes bloque de piedra. Es bastante tosca, "
     "pero cumple perfectamente su cometido, que no es otro sino defender la ciudad. "
     "Te hallas a los pies de la misma.\n");

  AddDetail(({"puertas","puerta","placas"}),
     "Las puertas son dos inmensas y macizas placas de metal. Permanecen abiertas "
     "siempre y cuando la ciudad no este bajo amenaza. Por su gran tamanyo juzgas que "
     "para moverlas o bien se necesitan varios orcos o se dispone de algun mecanisno "
     "mecanico que lo haga.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);
// AddItem(PNJ("masoch"), REFRESH_DESTRUCT);
// AddItem(PNJ("rompehuesos"), REFRESH_DESTRUCT);
  AddExit("sur",SF(entrar));
  AddExit("norte",Z_CAMINO("cc_09"));
  AddRoomCmd("matar", "matar_cmd");
}
