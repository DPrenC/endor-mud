/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-06-97                |
 |               Ultima Modificacion.. 06-06-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>

inherit SHOP;

create()
{
 ::create();
 SetIntShort("la tienda de libros del viejo Josue");
 SetIntLong(
"Estás en la tienda del viejo Josue, el encargado de mantener la cultura en\n\
esta ciudad donde lo que menos abundan son personas de letras y sabiduria.\n\
Es muy querido por todos los ciudadanos, especialmente por los que hacen algo\n\
de arte. Miles de libros te rodean, algunos parece que lleven aqui miles de\n\
años por la cantidad de polvo que tienen. Josue además es capaz de arreglarte\n\
cualquier libro, por muy dañado que esté.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("Solo escuchas el silencio de la tienda.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");
 AddDetail(({"tienda","tienda de Josue"}),
"Es enorme, pero parece minúscula y te sientes agobiado dada la gran cantidad\n\
de libros que hay. Decenas de estanterias distribuidas por temas. Si buscas\n\
algún libro seguro que lo encuentras aquí.\n");
 AddDetail(({"josue","Josue"}),
"Es un viejo agradable con una historia de su vida alucinante, quizás debieras\n\
preguntarle sobre ella.\n");
 AddExit("norte",CROWY("calle8"));
 SetLocate("crowy");
 RemoveDustbin();
 SetShopkeeper(0,
     ([P_SHORT:"El viejo Josue",
       P_LEVEL:50]));
}

void init()
{
 ::init();
 SkSay("Hola "+TNAME+", bienvenid"+(TP->QueryGender()==GENDER_FEMALE?"a":"o")+" a mi tienda.\n");
}

do_sell(string str)
{
 say("Josue le comenta algo a "+TNAME+".\n");
 write("Josue te dice: Lo siento "+TNAME+", pero yo no compro cosas.\n");
 return 1;
}
