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
   SetName("varios cr�os kender");
   SetIds(({"ni�os","cr�os","crios","kenders"}));
   SetShort("varios cr�os kender");
   SetLong(
"Est�n todos ensimismados escuchando al viejo Velac, parecen inquietos, como "
"esperando algo.\n");
   SetRace("kender");
   SetGender (1);
   SetLevel(1);
   InitChats(3, ({
     "Uno de los ni�os dice: Hola!! Como te llamas??\n",
     "Una cr�a dice: Quiero oir un cuento sobre magiaaaa...!!!\n"
     "A lo que otro cr�o responde: Calla tonta, mejor sobre guerreros.\n",
     "Un crio grita: Velaaaac, Zirrin me ha metido un dedo en el ojoooo...!!!\n",
     "Un ni�o comienza a urgarse la nariz.\n",
     "Un ni�o se percata de tu presencia, te mira y te sonrie de oreja a oreja.\n",
     "Una ni�a dice: Velac, cuantos a�os tienes?\n"
     "A lo que Velac responed: Muchos hija mia..., muchos.\n",
     "Un cr�o dice: Me tengo que ir a comer, se me ha hecho tarde\n"
     "Ves como el cr�o se va.\n",
     "Un ni�o te dice: Vienez a ezcuchad loz cuentoz de Velaz?. (Al sonreirte te "
     "das cuenta que le faltan unos cuantos dientes)\n"}) );
   InitAChats(3,({
"El ni�o te mira con una carita de pena y con lagrimas en los ojos.\n",
                 }) );
}

DoDamage(int dmg)
{
  write(
  "Velac se levanta de su silla �gilmente y se antepone en tu camino."
  "Ves como Velac sopla en su pipa y hace que una nube de humo color verde te "
  "rodee impidiendo tus movimientos.\n");
  write("Velac te dice: Est� mal atacar a unos cr�os indefensos, deber�as saberlo.\n");
  TP->StopAttack();
  TO->StopAttack();
  return 1;
}

