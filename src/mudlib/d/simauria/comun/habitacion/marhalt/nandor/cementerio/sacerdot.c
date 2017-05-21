//
//               sacerdot.c
//             Creado por: Jessy@simauria
//             Fecha: 19-11-01
// Modificaciones:
// [n] nemesis@simauria
//        16-05-02 [n] Retocadas las descripciones y chats.
//                     ¡Ah! Y las armas
// NOTAS:
//       [n] Cambiar el emblema del medallón por algo más... adecuado


	

inherit NPC;

#include <combat.h>
#include <properties.h>
#include "./path.h"

create() {
  ::create();
 SetName("sacerdote");
  SetShort("un sacerdote de Sharanna");
  SetLong(W(
          "Es un sacerdote de aspecto bonachón. Algo calvete, con los mofletes"
	  "sonrojados y con una incipiente barriga. Parece muy nervioso y no se"
	  "está quieto con las manos, que esconde constantemente bajo las anchas"
	  "mangas de su amplia túnica negra. En una de ellas lleva unos papeles."
	  "Colgando del pecho tiene un medallón que reconoces como emblema de los"
	  "sacerdotes de la Señora de la Muerte, la gran diosa Sharanna.\n"));
  SetIds(({"sacerdote","sacerdote de Sharanna","cura"}));
/*
  AddSubDetail(({"medallón","emblema"}),W(
	           "Es un hermoso colgante de obsidiana, en el que aparece tallada una rosa"
                   "rodeada por granates que simulan gotas de sangre. Está ribeteado por una"
                   "cadena de oro.\n"));
*/
  AddSubDetail(({"medallón","emblema"}),W(
	           "Es un hermoso colgante de obsidiana, en el que aparece tallado el emblema"
                   "de Sharanna.\n"));

  SetRace("humano");
  SetLevel(25);
  SetAlign(300);
  SetGender(GENDER_MALE);
  SetStr(30);
  SetSmell("Huele a incienso. Sus ropas se deben de haber impregnado del olor.\n");
  SetAC(4);
  SetSize(P_SIZE_MEDIUM);

  AddQuestion(({"papeles"}),W(
              "El sacerdote te mira entristecido y te dice: es el inventario de lo que "
              "tenemos en el templo. Falta de todo, sobre todo vino para celebrar las misas. "
              "El ayuntamiento no nos da muchos fondos para mejorar el estado del templo. "
              "Por eso dependemos tanto de la gente del pueblo de Nandor, que nos deja limosnas "
              "en el cepillo del exterior.\n"));

  AddQuestion(({"ghoul"}),W(
              "El sacerdote te mira entristecido y te dice: 'Es un ser malvado que "
              "se ha instalado en nuestro cementerio alterando su paz, y que ronda "
	      "por entre las tumbas. ¿Podrías ayudarme de alguna manera para que "
	      "deje tranquilo el lugar? Creo que en el pueblo también están"
              "preocupados. Dicen algo de matarlo.'\n"));
  AddQuestion(({"matar ghoul","cabeza de ghoul","matar"}),W(
              "El sacerdote te dice: 'Ir en su busca para matarlo es muy peligroso. "
              "Sólo si tienes fe en que lo que vas a hace está bien, vencerás. Ten cuidado. "
              "La diosa Sharanna, la señora de la Muerte velará por ti'.\n"));
  AddQuestion(({"lápidas", "lápida","lapida","lapidas","tumbas"}),W(
              "El sacerdote sonríe y dice: 'Aquí se encuentran enterrados los "
              "habitantes de Nandor. La gente ya viene a visitar las tumbas. La "
              "presencia del ghoul les atemoriza. Solían ponerles velas y flores frescas'.\n"));
  AddQuestion(({"flores","flores frescas"}),W(
              "El sacerdote sonríe alegremente y dice: 'He recogido del bosque unas cuantas "
              "muy hermosas y que huelen muy bien. Si quieres puedes disponer de ellas para "
              "alegrar un poco el lugar. Yo iba a dejar unas cuantas en la tumba de nuestro "
              "héroe Blackrider. Si quieres puedes ayudarme y llevárselas tú.'\n"));
  AddQuestion(({"vela","velas"}),W(
              "El sacerdote dice: 'Es una pena que no nos queden. Se nos ha acabado la cera para "
              "poder fabricarlas. Lo que sí que tenemos es cordel para la mecha'.\n"));
  AddQuestion(({"cera"}),W(
              "El sacerdote dice: 'Se puede comprar, aunque puede que encuentres "
              "abejas dispuestas a darte un poco'.\n"));
  AddQuestion(({"cordel"}),W(
              "El sacerdote suspira y te dice: 'Si, creo que quedaba algo por el almacén. Mira "
              "por ahí y seguro que encuentras algo.\n"));
  AddQuestion(({"Jessy", "jessy"}),W(
              "El sacerdote dice: 'Sí, Jessy. Es una guardabosques de gran renombre. Valiente y "
              "de gran corazón. La señora Sharanna le tiene un gran aprecio, ya que "
              "se ha encargado en numerosas ocasiones de proteger el templo de saqueadores. "
              "Si la ves en tus viajes mándale un cálido saludo de mi parte'.\n"));

  InitChats(7,({W(
    "El sacerdote se rasca la cabeza y murmura: '¿Cómo querrán que mantenga en buen estado "
    "el templo y el cementerio si me falta lo más básico? Flores, velas, y vino... sobre todo "
    "vino...'\n")}) );

  InitChats(6,({W(
    "El sacerdote mira al techo y dice: 'Oh mi diosa Sharanna aquí tienes a tu siervo que está "
    "abrumado por el trabajo acumulado y no tiene a nadie que le ayude a poner alegría "
    "al lugar.\n")}) );

  InitChats(7,({W(
    "El sacerdote ojea el inventario que tiene en sus manos y dice: 'Aquí falta de todo. Con un "
    "poco de ayuda podría hacer que las tumbas se encontraranen mejor estado. Con unas flores "
    "por aquí y unas velas por allá todo quedaría mejor y alegraría a nuestra señora Sharanna'.\n")}) );


  SetHands(({
             ({"mano izquierda",0,6}),
             ({"mano derecha",0,6})
             }));

  AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
    ([P_SHORT: "un mazo de plata",
      P_LONG: "Un pequeño mazo de plata. Tiene unos extraños signos grabados. Parecen runas.\n",
      P_IDS: ({"mazo","mazo de palta"}),
      P_ADS: ({"pequeño"}),
      P_WC: 12,
      P_SIZE:P_SIZE_MEDIUM,
      P_NUMBER_HANDS: 2,
      P_RESET_QUALITY: 95,
      P_WEIGHT: 30000,
      P_VALUE:  1000,
      P_WEAPON_TYPE: WT_MAZA,
      P_DAM_TYPE: DT_BLUDGEON]) );

  AddItem("/std/armour",REFRESH_REMOVE,SF(wearme),
    ([P_SHORT: "túnica",
      P_LONG:  "Una pesada túnica que aunque no parece muy resistente, puede haber sido reforzada"
               "por métodos... no muy ordinarios....\n",
      P_IDS: ({"túnica","tunica"}),
      P_ADS: ({"de tela","pesada","una"}),
      P_ARMOUR_TYPE:AT_ARMOUR,
      P_AC: 1,
      P_SIZE:P_SIZE_LARGE,
      P_RESET_QUALITY: 90,
      P_WEIGHT: 2000,
      P_VALUE: 80]) );
}
