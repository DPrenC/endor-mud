/* PNJ de la oficina de postas
 * [m] Mirill@simauria
 * [n] Nemesis@simauria
 * 24/01/98 Creacion
 * [n] Castellanizado. (Oct'02)
 */

#include <properties.h>
inherit NPC;
create() {
  ::create();
SetName("Bracco","humano","bracco");
SetShort("El cartero.");
SetLong("Bracco es un humano de complexión normal.\n");
SetRace("humano");
AddId("hombre","bracco","humano","cartero");
SetLevel(3);
SetCon(3);
SetStr(4);
SetInt(5);
SetDex(4);
SetMaxHP(45);
SetHP(45);
Set(P_ALIGN,100);
Set(P_AC,0);
Set(P_NOGET,"No alcanzas a cogerle.\n");
SetGender(1);
InitChats(4,({"El cartero tararea una canción.\n",
 "El hombre mira al trasluz un mensaje.\n",
 "El cartero gruñe.\n",
 "El cartero dice: 'Hmmm, esta zona no la conozco.'\n",
 "El cartero trabaja sin descanso.\n",
 "El hombre te pregunta: '¿Quieres algo?'\n",
 "El hombre dice: 'Hmm, éste se ha equivocado',\n"
 "y tira la carta a un cubo\n"}));

AddQuestion(({"nombre"}),
 "El hombre dice sin girarse: 'Me llamo Bracco'.\n");
AddQuestion(({"mensaje"}),
 "El hombre dice: 'Para enviar un mensaje a alguien escribe 'correo' seguido del\n"
 "nombre a quien quieras enviárselo'.\n");
AddQuestion(({"posada"}),
 "El hombre te dice: 'La posada está ahí enfrente.'\n");
AddQuestion(({"tienda"}),
 "El hombre te dice: 'Encontrarás la tienda siguiendo esta calle hacia la\n"
 "plaza, no tiene pérdida.'\n");
}