/***************************************************************************/
/* Por Izet@Simauria, en espera a que Nemesis me la banee de Simauria :)   */
/* Fichero:      /d/Kha-annu/comun/objeto/arma/cromswrd.c                  */
/* Descripcion:  Esta es la espada del Rey Belthain (nivel 80), rey de los */
/*               Enanos. Es una espada magica, que aumenta destreza,fuerza */
/*               regeneracion de hp y hp maximo. A su vez disminuye la in- */
/*               teligencia y la regeneracion de sp.                       */
/*               Tiene WC = 17, ya que es un objeto magico. Es a dos manos */
/*               y un valor de 10.000 de cobre en las tiendas.             */
/* Creacion:     14 de Noviembre de 1998.                                  */
/* Modificacion: [I] 14 de Noviembre de 1998.                              */
/*               [Nemesis] Jun'99                                          */
/*                     Punto 1: Eliminado la parte magica.                 */
/*                     Punto 2: Bajado el WC a 14                          */
/*               [Woo] Modificada                                          */
/*                                                                         */
/***************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>

#define FUE  (TP->QueryStr())
#define DEX   (TP->QueryDex())
#define INT   (TP->QueryInt())
#define HPREG (TP->QueryRegHP())
#define SPREG (TP->QueryRegSP())
#define MAXHP (TP->QueryMaxHP())

inherit WEAPON;

create() {
   ::create();
   SetStandard(WT_ESPADA,14,P_SIZE_MEDIUM);
   SetIds( ({"espada","espada cromada"}) );
   SetAds( ({"una","la"}) );
   SetShort("la Espada Cromada");
   SetLong("\
Esta es la legendaria Espada Cromada de Belthain, el senyor de los Enanos.\n\
La empunyadura de la espada esta hecha de hueso, y cuenta la leyenda que "
"este procede del mismisimo femur del Rey de los Brujos, senyor de uno de "
"tumulos de Akallab. La hoja esta hecha de un metal conocido como adamantio, "
"y reluce con un brillo casi sepulcral. La historia dice que el que empunye "
"esta espada gozara de fuerzas superiores a lo normal.\n"
   );
   SetValue(10000);
   SetWeight(6000);
   SetMagic(1);
   SetNumberHands(2);
}

