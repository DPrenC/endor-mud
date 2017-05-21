/* Y cuando se haga podemos ponerle la enfermedad Vampirismo pa quien muerda
 CREACION: Alura (Junio del 2001)
 UBICACION: /d/lad-laurelin/comun/pnj/tiin/lago/vampiresa.c
 DESCRIPCION: pues es una gran vampiresa
*/

#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include <combat.h>
#include <spellmonster.h>
#include <colours.h>

inherit "/d/lad-laurelin/comun/pnj/tiin/lago/stdvampi";

int car;
int mirada_ardiente();

mirada_ardiente(mapping sp, object *vic){
   object *en,ene;
   en=QueryEnemies()||({});
   if (sizeof(en)) {
     ene=en[random(sizeof(en))];
     ene->SetDexBonus(-2);
     vic=({ene});
   }
   return sp;
}

create() {
seteuid(getuid());
car=random(4);
::create();
AddAdjective("bella");
SetIds(({"vampiro","vampiresa","vampira"}));
SetStandard("una vampiresa","no-muerto",22+car,2);
SetShort("una vampiresa");
SetLong(" Es una de las mujeres mas atractivas que has visto nunca. Su piel pálida está\n"
"maquillada y su voluptuoso cuerpo lleva ceñidas las prendas más exquisitas.\n");
SetSize(P_SIZE_MEDIUM);
SetNoGet(1);
SetWeight(60000);
SetInt(22+car);
SetDex(22+car);
SetStr(22+car*2);
SetHands(({({"la mano izquierda",0,6}),({"la mano derecha",0,7}),({"los colmillos",1,8})}));
SetAlign(-200);
SetWhimpy(20);
InitChats(2,({"Una vampiresa te observa con desdén.\n",
"La vampiresa te pregunta: -Vamos a hacer una fiesta, te apuntas?\n",
"Una vampiresa se relame los labios.\n"}));

AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "túnica de vampiresa",
      P_LONG:  "Una túnica de mujer adornada que brilla levemente.\n",
      P_ARMOUR_TYPE:AT_ARMOUR, //GLOVES,CLOAK,ARMOUR,RING,BOOTS,SHIELD,TROUSERS
      P_IDS: ({"tunica","túnica brillante","túnica"}),
      P_AC: 2, //
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 100,
      P_WEIGHT: 350,
      P_VALUE: 800]) );

 AddSpell("miradaArdiente",
           ([
             S_CHANCE:20,
             S_COMBAT_DELAY:1,
             S_DELAY:2,
             S_SIMULT:1,
             S_VICTIMS:1,
             S_DAMTYPE:DT_PSYCHO,
             S_MINDAM:0,
             S_MAXDAM:0,
             S_FUN:SF(mirada_ardiente),
             S_GLOBAL_ENVMSG:(TC_BLUE"Los ojos de la vampiresa se tornan rojos.\n"TC_NORMAL),
             S_ENVMSG:([
                       MSG_NORMAL:
                       ("La vampiresa mira fijamente a @@VicName@@ y este titubea.\n")]),

             S_VICMSG:([
                      MSG_NORMAL:
                      ("La vampiresa te mira y de repente sus ojos despiden un fulgor rojizo que te\n"
                      "produce un temblor en tus actos. Te sientes menos hábil.\n")
           ]),


          ])
  );

}
