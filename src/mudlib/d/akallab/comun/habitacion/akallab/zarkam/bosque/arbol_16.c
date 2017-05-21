/*
DESCRIPCION  : arbol
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/arbol_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

int pasar(){
  int x;
  if (!TP) {
    TO->move(Z_BOSQUE("arbol_17"),M_SPECIAL,
    ({"pasa sin problemas al otro arbol","llega desde el oeste",
      ""}));
    return 1;}

 x=TP->QueryDex();

 x+=10; /* No es muy dificil, no? */

 /* Penalizaciones por peso */
 if (TP->QueryWeight()>=40000) x+=1;
 if (TP->QueryWeight()>=100000) x+=1;

 if (random(x)>TP->QueryDex())
    {write(
     "Te dispones a cruzar... no alcanzas esa rama... tropiezas... te caes...\n "
     "Tu cuerpo dolorido se retuerce en el suelo, al menos no has caido al río..");

     /* A ver si me saco una formula de la manga para la energia que pierdes */
     x=TP->QueryWeight()/1000;
     if (x>(TP->QueryHP()-1)) x=(TP->QueryHP()-1);
     x=0-x;
     TP->AdHP(x);
    /* Lo siento mucho, cuanto mas pese mas fuerte sera la caida */
    /* aun asi, no quiero que se mate nadie =)                   */
  TP->move(Z_BOSQUE("bosque_16"),M_SPECIAL,
     ({"intenta cruzar al este pero cae","cae ante ti",
       ""}));
    return 1;
    }

 TP->move(Z_BOSQUE("arbol_17"),M_SPECIAL,
    ({"cruza hacia el este por encima de las ramas","llega desde el oeste",
      "Gracias a tu destreza y a un poco de suerte llegas al otro arbol"}));
 return 1;
}


create() {
  ::create();
  SetIntShort("la copa del árbol");
  SetIntLong(
"Estas en lo mas alto de un arbol, desde aqui ves el río que fluye bajo tus "
"pies, tambien tienes una buena vision del resto del bosque, puedes ver "
"como cientos de frondosos arboles se extienden hacia el noroeste hasta "
"encontrarse con la cordillera de Kova. Gracias a tu posicion privilegiada "
"divisas al norte lo que te parece una cabanya. "
"Unas anchas ramas podrian facilitarte el paso a un gran arbol vecino al "
"este, pero no parecen muy seguras.\n");
  SetIndoors(0);
  AddExit("abajo",Z_BOSQUE("bosque_16"));
  AddExit("este",SF(pasar));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"ramas"}),
  "Unas ramas comunican este arbol con otro gran arbol que se alza al otro lado "
  "del río, pero parece que necesitaras ser muy agil si quieres pasar.\n");
  AddDetail(({"cordillera","kova"}),
  "Tienes una magnifica vista de la cordillera de Kova, ves las altas montanyas "
  "del norte extendiendose de oeste a este e impidiendo el crecimiento del "
  "bosque en esa direccion.\n");
  AddDetail(({"cabanya"}),
  "No lo puedes afirmar con seguridad, pero parece que al norte, en un claro, "
  "hay una especie de cabanya.\n");
  SetIntNoise("El aire silba entre las hojas.\n");
  SetIntSmell("El olor tipico de la copa de un arbol...\n");
}

