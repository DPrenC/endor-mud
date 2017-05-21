/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 07-10-98                |
 |               Ultima Modificacion.. 16-11-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <wizlevels.h>
#include <properties.h>

inherit GUARDIAN;

create()
{
  ::create();
 SetStandard("Kurts","humano",([GC_LUCHADOR:25]),GENERO_MASCULINO);
 SetIds(({"guardian","guardian humano","humano","kurts","Kurts","lider","lider de los guardianes"}));
 SetShort("Kurts, el lider de los guardianes");
 SetLong("\
Kurts es un humano más grande de lo normal, su robusta corpulencia le hacen\n\
ser un enemigo casi invulnerable. Dos grandes trenzas que le cuelgan de sus\n\
cabellos pelirrojos y su bigote del mismo color resaltan sobre su tez morena.\n\
No hace más que contemplar y mimar a su espada Cintia.\n");
 SetAlign(-400);
 SetWhimpy(0); // O mata o muere
 SetMaxHP(500);
 SetHP(500);

 AddItem(ARMA("cintia"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("coraza_acero"),REFRESH_REMOVE,SF(wearme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5),"platino":random(2)])]));

  InitChats(5,({"Kurts golpea la mesa con los dedos.\n",
                "Kurts alza su espada y contempla el filo cuidadosamente.\n",
                "Kurts afila su espada Cintia.\n",
               }));
  InitAChats(10,({"Kurts grita: ¡¡¡A mi los guardianes, a mi los guardianes!!!\n",
                  "Kurts te dice: Ahora conoceras el poder de mi espada.\n",
                  "Kurts te ataca con todas sus fuerzas y parece no cansarse.\n",
                }));
  AddQuestion(({"Lonny","lonny","estafador"}),
  "A Lonny lo to tenemos retenido en el dormitorio pero no te dejaremos verlo.\n");
}

void init() {
 add_action("ir_dormitorio","dormitorio");
}

int ir_dormitorio() {
 if (IS_WIZARD(TP)) return 0; // Deja pasar a los wizs.
 return write("Kurts te dice: Oye..¿a donde te crees que vas?\n"),1;
}
