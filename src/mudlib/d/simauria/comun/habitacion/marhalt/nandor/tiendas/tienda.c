/*
 tienda.c
La tienda de Nandor.

[c] Cheto@simauria
[n] Nemesis@simauria
[k] Karu@simauria
[z] Zomax@simauria

 Creacion: 02-06-97 [c]
 Modificaciones:
   16-11-98 [c] Añadido el objeto caña de pescar.
   Abr'02 [n,k] Adaptada para el quest del lenguarón.
   15-04-02 [z] Hago mudanza de funciones de Leyma al recien creado fichero de
   		Leyma por ¿neme?. De paso hago que no se chive con un entra
   		alguien si es learner o más y está invis.
   06-05-03 [n] Quitada el arma aleatoria. Lo he cambiado por algo un poco
                más sofisticado: función pa sacar un arma aleatoriamente y
		luego la muevo al almacén.
   14-07-03 [n] Añadidas unas cuantas mochilas.
*/

#include <wizlevels.h>
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
#include <colours.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;


private object arma_random() {
  // elegirá un arma aleatoriamente y la meterá en el almacén
  // En realidad, se elimina el antiguo arma_rnd y se cambia por
  // esto.
  object ob;

  switch(random(4)) {
    case 0: ob = clone_object(ARMA("florete"));
    case 1: ob = clone_object(ARMA("maza_madera"));
    case 2: ob = clone_object(ARMA("garfio"));
    case 3: ob = clone_object(ARMA("vara_madera"));
  }

  return ob;
}

object art1, art2, art3;

 create()
{
    ::create();
    SetIntShort("la tienda de Nandor");
    SetIntLong(
    "Estás en la tienda de Nandor, aquí puedes comprar casi cualquier cosa que "
    "puedas encontrar en una ciudad como Nandor, Desde comida hasta utensilios "
    "de cocina, la tienda la regenta la buena de Leyma, que está, "
    "como siempre, detrás del mostrador esperando a los clientes.\n");
    SetIndoors(1);
    SetIntBright(35);
    SetIntSmell(
    "Huele un poco raro, pero puedes distinguir claramente un fuerte olor a "
    "resinas o algo así.\n");

 // Una cierta cosa para que sea más difícil que se quede sin pasta...
    SetDynamic(100); // Véase aquí debajo...
    SetMinCash(500000); // Si tenemos menos de esta cantidad de dinero,
		     // añadimos más dependiendo del 'factor dinámico'.
		     // En este caso, el dinero será reseteado (en el
		     // siguiente reset, claro está) si es menor de
		     // 500000 UMS y el nuevo valor será 500000*100/100,
		    // o lo que es lo mismo, 500000.

    SetDustbin(0,
    ([P_SHORT:"un cubo de basura",
    P_LONG:"Está un poco sucio, pero total, para lo que sirve...\n",
    P_ADS:({"sucio"})
    ]));
    AddExit("sur","../calle2");
AddDoor("sur", "la puerta de la calle",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la calle", "puerta del sur", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));


// creamos tres objetos directamente...

    art1=clone_object("/std/weapon");
    art1->SetStandard(WT_CUCHILLO, 1, P_SIZE_MEDIUM, M_ACERO);
    art1->SetShort("un cuchillo de cocina");
    art1->SetLong("Un cuchillo de cocina con empuñadura de madera.\n");
    art1->SetDamType(DT_PIERCE);

    art2=clone_object("/std/weapon");
    art2->SetStandard(WT_HACHA, 5, P_SIZE_MEDIUM, M_ACERO);
    art2->SetShort("un hacha de leñador");
    art2->SetLong("Una simple hacha de leñador, bien afilada, con la que puedes cortar árboles.\n");

    art3=clone_object("/std/weapon");
    art3->SetStandard(WT_MAZA, 4, P_SIZE_MEDIUM, M_MADERA);
   art3->SetShort("una maza de madera");
   art3->SetLong("Una maza de madera, útil para clavar clavos.\n");

    AddArticle(art1, REFRESH_REMOVE, 2);
    AddArticle(art2, REFRESH_REMOVE,1);
   AddArticle(art3, REFRESH_REMOVE, 2);

// Y metemos unos cuantos más pre-creados:
// Armas...
    AddArticle(ARMA("cadena"));
    AddArticle(ARMA("vara"));
    AddArticle(ARMA("latigo"));
    AddArticle(SF(arma_random),REFRESH_REMOVE,d4());
    AddArticle(OTRO("escoba"), REFRESH_REMOVE, 3);


// ...armaduras...
    AddArticle(PROT("amuleto"), REFRESH_REMOVE, d4());
    AddArticle(PROT("anillo"));
    AddArticle(PROT("guantes"), REFRESH_REMOVE, 2);

// ... y objetos misceláneos...
    AddArticle(OTRO("cuerda"), REFRESH_REMOVE,2);
    AddArticle("/obj/torch", REFRESH_REMOVE,d6());
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,d4());
    AddArticle("/obj/lighter", REFRESH_REMOVE, d3());
    AddArticle(OTRO("canya"),REFRESH_REMOVE,d3());
    AddArticle("/obj/bandage",REFRESH_REMOVE,random(5)+1);
   AddArticle("/obj/vialv",REFRESH_REMOVE,4);
    AddArticle("/obj/vialm",REFRESH_REMOVE,4);
    AddArticle("/obj/vial",REFRESH_REMOVE,2);

    AddArticle("/obj/mochila",REFRESH_REMOVE,5);
    AddArticle(OTRO("mochilac"),REFRESH_REMOVE,2);
    AddArticle("/obj/candle", REFRESH_REMOVE,d4());
    AddArticle(OTRO("marhalt/nandor/carboncillo"), REFRESH_REMOVE, d2());
    AddDetail(({"tienda","tienda de Nandor"}),
    "La tienda es como cualquier tienda de un pueblo pequeño: una especie de "
    "supermercado. Pero ten cuidado, que las apariencias engañan.\n");
    SetLocate("Aldea de Nandor");
    SetShopkeeper(PNJ("marhalt/leyma"));
    SetNotifyExits("sur");
    SetLastDest("../calle2");
    SetThrowOutMsg("Leyma exclama: ¡venga, venga! ¡Que ya es hora de cerrar!\n");
    SetRoomClosedMsg("Intentas abrir la puerta pero no puedes. Al mirarla, observas un cartel pegado "
                 "en el que se puede leer: " + TC_YELLOW + "¡CERRADA!" + TC_NORMAL);
    SetNotifyCloseMsg("@name@ sale de la tienda y la cierra, sin mirar a nadie cruza la "
    "calle y se mete en la casa del sur.\n");
    SetNotifyOpenMsg("@name@ sale de la casa del sur, cruza la calle y abre la "
    "tienda entrando velozmente.\n");
}

init(){
    ::init();

    if (IS_LEARNER(TP) && TP->QueryInvis()) {}
    else SkSay("Hola "+TNAME+", bienvenid"+(TP->QueryGenderEndString())+" a mi tienda.\n");
}
