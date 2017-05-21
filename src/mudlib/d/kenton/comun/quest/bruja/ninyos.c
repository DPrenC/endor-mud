/*
O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O
/                                                                     /
O                      - ninyo kender -                               O
\     [K] Un ninyo kender.                                            \
O---------------------------------------------------------------------O
/   [K] Korsario@Simauria                                             /
O---------------------------------------------------------------------O
\   Kreacion.............. 05/04/98                                   \
O   Ultima modificacion... 08/10/00 [Kr]                              O
/                                                                     /
O   14/04/98 [K] Kreacion.                                            O
/                                                                     /
O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O/O\O
*/

#include <combat.h>
#include "./path.h"

inherit NPC;

create ()
{
   ::create();
   SetName("varios críos kender");
   SetIds(({"niños","críos","crios","kenders"}));
   SetShort("varios críos kender");
   SetLong(
"Están todos ensimismados escuchando al viejo Velac, parecen inquietos, como "
"esperando algo.\n");
   SetRace("kender");
   SetGender (1);
   SetLevel(1);
   InitChats(3, ({
     "Uno de los niños dice: Hola!! Como te llamas??\n",
     "Una cría dice: Quiero oir un cuento sobre magiaaaa...!!!\n"
     "A lo que otro crío responde: Calla tonta, mejor sobre guerreros.\n",
     "Un crio grita: Velaaaac, Zirrin me ha metido un dedo en el ojoooo...!!!\n",
     "Un niño comienza a urgarse la nariz.\n",
     "Un niño se percata de tu presencia, te mira y te sonrie de oreja a oreja.\n",
     "Una niña dice: Velac, cuantos años tienes?\n"
     "A lo que Velac responed: Muchos hija mia..., muchos.\n",
     "Un crío dice: Me tengo que ir a comer, se me ha hecho tarde\n"
     "Ves como el crío se va.\n",
     "Un niño te dice: Vienez a ezcuchad loz cuentoz de Velaz?. (Al sonreirte te "
     "das cuenta que le faltan unos cuantos dientes)\n"}) );
   InitAChats(3,({
"El niño te mira con una carita de pena y con lagrimas en los ojos.\n",
                 }) );
}

DoDamage(int dmg)
{
  write(
  "Velac se levanta de su silla ágilmente y se antepone en tu camino."
  "Ves como Velac sopla en su pipa y hace que una nube de humo color verde te "
  "rodee impidiendo tus movimientos.\n");
  write("Velac te dice: Está mal atacar a unos críos indefensos, deberías saberlo.\n");
  TP->StopAttack();
  TO->StopAttack();
  return 1;
}

