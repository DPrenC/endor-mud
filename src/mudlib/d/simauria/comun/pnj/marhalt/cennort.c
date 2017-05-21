/* PNJ de la oficina del banco
 * [m] Mirill@simaria
 * [n] Nemesis@simauria
 *
 * 24/01/98 Creacion
 * [n] Castellanizado. (Oct'02)
 */

#include <properties.h>
#include <guild.h>
inherit NPC;

    create()
    {
    ::create();
   SetStandard("Cennort","humano",([ GC_NINGUNO:5 ]),GENERO_MASCULINO);
    SetName("Cennort");
    SetShort("Cennort, el banquero");
    SetLong("Cennort es un humano de complexión normal.\n");
    AddId(({"banquero","cennort","Cennort","humano","hombre"}));
    Set(P_ALIGN,100);
    Set(P_CANT_LURE,1);
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    InitChats(4,({"El banquero tararea una canción.\n",
  "El hombre mira el libro de cuentas.\n",
  "El banquero mira el libro de cuentas y\n\
  dice: 'Hmmm, éste se esta haciendo rico.'\n",
  "El banquero trabaja sin descanso.\n",
  "El banquero te dice: 'Si quieres saber las condiciones del banco puedes "
  "coger uno de los folletos que hay en el mostrador.'\n",
  "El hombre te pregunta: '¿Quieres algo?'\n"}));

AddQuestion(({"nombre"}),
 "El hombre dice sin girarse: 'Me llamo Cennort.'\n");
AddQuestion(({"cuenta"}),
 "El hombre dice: 'Para operar con tu cuenta, puedes coger un folleto\n"
 "de los que hay sobre el mostrador.'\n");
AddQuestion(({"posada"}),
 "El hombre te dice: 'La posada del pueblo está ahí enfrente.'\n");
AddQuestion(({"tienda"}),
 "El hombre te dice: 'Encontrarás la tienda siguiendo esta calle hacia la\n"
 "plaza, no tiene pérdida.\n");
}