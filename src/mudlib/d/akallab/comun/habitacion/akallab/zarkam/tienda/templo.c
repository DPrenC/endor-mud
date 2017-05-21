/*
DESCRIPCION : templo de Kavar
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/templo.c
MODIFICACION: 16-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 object ob;

 ::create();
 SetIntShort("el templo de Kavar");
 SetIntLong(
    "Te hallas en el interior del templo dedicado a Kavar, el dios orco de la guerra. "
    "En su parte central se alza un amplio altar circular sobre las estatuas de tres "
    "orcos que, rodilla en tierra, cargan con el sobre sus espaldas. Sobre el altar "
    "se halla una gran estatua que representa a Kavar. Rodeando al altar hay varias "
    "piras sobre las que arde lentamente algun tipo de hierba aromatica. Al fondo del "
    "templo y en un segundo plano, puedes observar un extranyo monolito.\n");

  AddDetail(({"pira","piras"}),
    "Son una especie de cuencos de metal en cuyo interior arde lentamente algun tipo "
    "de hierba aromatica, creando una estrecha columna de humo que se eleva hacia el "
    "techo del templo. Los cuencos se apoyan sobre unos soportes formados por tres "
    "delgadas patas de metal.\n");

  AddDetail(({"altar"}),
    "El altar es una especie de gruesa plancha de forma circular. Esta sobre el nivel "
    "del suelo apoyandose en las tres estatuas de los orcos. Sobre el se halla la "
    "gran estaua que representa a Kavar y rodeandolo hay una serie de piras "
    "humeantes.\n");

  AddDetail(({"estatuas","orcos"}),
    "El altar del templo se apoya sobre las espaldas de tres estauas que representan "
    "a tres orcos agachados con una rodilla en tierra en acto de sumision. Los orcos "
    "van armados y tienen un gesto feroz como si fuesen los guardianes del dios.\n");

  AddDetail(({"Kavar","kavar","estatua"}),
    "La gran estatua que se encuentra sobre el altar representa a Kavar, el poderoso "
    "dios orco de la guerra. Es un corpulento orco bien armado al que una gran "
    "cicatriz le recorre diagonalmente toda la cara. Su gesto es severo y su vision "
    "no resulta muy tranquilizadora.\n");

SetIntNoise("Oyes el lento crepitar de las hierbas al quemarse en las piras.\n");
SetIntSmell("Hmm.. el ambiente es calido huele a hierbas aromaticas.\n");
SetLocate("ciudad de Zarkam");
SetIndoors(1);
SetIntBright(50);

AddExit("sur",Z_CIUDAD("calle_13"));

ob=clone_object("/obj/monolito");
ob->SetRaza("orco");
ob->move(TO);
AddItem(OTRO("en_obras"),REFRESH_ALWAYS,3);
}
