/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-04-97                |
 |               Ultima Modificacion.. 25-01-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <moving.h>
#include <properties.h>


inherit SHOP;

int matar_(string str);

create()
{
 ::create();
 SetIntShort("la tienda de artículos de broma de Crowy");
 SetIntLong(
"Te encuentras en la tienda de articulos de broma de la ciudad de Crowy.\n\
Miras a todos lados perplejo dada la gran cantidad de cosas que ves. Desde\n\
luego, no hay mejor sitio para comprar algo si quieres gastar una broma a\n\
algún amigo o no tan amigo.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("Escuchas los sonidos que produce una caja de música.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"caja","caja de musica"}),
"Se trata de una caja de musica antigua. Está llena de polvo pero en el fondo\n\
parece bastante nueva.\n");
 AddDetail(({"tienda","tienda de jenfy"}),
"Es una tienda amplia y grande, pero que parece pequeña debido a que hay\n\
infinidad de cosas por todos lados.\n");
 AddExit("sur",CROWY("calle4"));
 SetLocate("Crowy");
 RemoveDustbin();
 CanSell(0);
 CanAppraise(0);
 CanIdentify(0);
 AddItem(PNJ("crowy/guardia_elfo"),REFRESH_DESTRUCT);
 SetShopkeeper(PNJ("crowy/jenfy"));
 ForbidAllMagic(); // Esta prohibida la magia aquí.
}

void init()
{
 ::init();
 if (TO->QueryShopkeeper()) SkSay("Hola "+TNAME+", bienvenid"+(TP->QueryGender()==GENDER_FEMALE?"a":"o")+" a mi tienda.\n");
 add_action("matar_","matar");
}

int matar_(string str)
{
 if (!str || !TO->QueryShopkeeper()) return 0;
 else {
 write("Jenfy te dice: Pero, ¿quien te has creido que eres para matar a nadie??\n");
 write("Jenfy te agarra y te echa de la tienda de un puntapie.\n");
 say("Jenfy dice: "+CAP(TNAME)+", en mi tienda no permito que se mate a nadie.\n",TP);
 say("Jenfy agarra a "+CAP(TNAME)+" y lo echa de la tienda de un puntapie.\n",TP);
 tell_room(CROWY("calle4"),CAP(TNAME)+" llega rodando por el suelo desde la tienda de jenfy.\n");
 TP->move(CROWY("calle4"),M_SILENT);
 return 1;
 }
}