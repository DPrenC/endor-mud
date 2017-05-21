/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 03-02-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

int do_oeste();
int do_entrar();

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"Estás en una de las calles de la parte norte de la ciudad de Crowy. La gente\n\
pasa a tu lado sin fijarse lo más minimo en ti. Hacia el Este hay una zona que\n\
parece tranquila y solitaria, debe tratarse de un callejón aunque no puedes\n\
ver mucho porque está oscuro. Los muros de la ciudad te impiden ir hacia el\n\
norte. Te llama la atención un enorme cartel a la entrada de lo que parece ser\n\
un parque o zona verde.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"muros","muro"}),
"Son los muros que rodean a la ciudad. Son enormes y tienen aspecto de ser muy\n\
sólidos.\n");
 AddDetail(({"gente","gentes"}),"Hay mucha y toda parece tener prisa.\n");
 AddDetail(({"cartel"}),"Será mejor que lo leas.\n");

 AddExit("este",CROWY("callejon"));
 AddExit("oeste",CROWY("parque2"));
 AddExit("sur",CROWY("calle2"));
 AddRoomCmd("oeste","do_oeste");

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+1);
 AddItem(PNJ("crowy/guardia_humano"),REFRESH_DESTRUCT);

 AddReadMsg(({"cartel","pancarta"}),"\n\
        ENTREN, PASEN Y VEAN LO NUNCA VISTO. Decenas, cientos, miles\n\
    de animalejos de toda condición esperando a que les mates. Utilice\n\
    sus técnicas más sangrientas y las armas más terribles para eliminar\n\
    de la faz de este mundo a estas pobres criaturas huerfanas de padres\n\
    y madres, hambrientas de sufrimiento, desechos de la escoria y masocas\n\
    hasta la saciedad.\n\n\
                           ¡¡¡ ATENCION !!!\n\
           NO PUEDEN ENTRAR AQUELLOS QUE SUPEREN EL NIVEL 4\n\n");

 SetLocate("crowy");
}

int do_oeste()
{
 if (TP->QueryLevel()>4 || TP->QueryIsNPC())
  return write("No pretenderás infringir las normas del parque, ¿verdad?\n"),1;

 return 0;
}

