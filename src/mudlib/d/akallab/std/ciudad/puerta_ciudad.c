/*
DESCRIPCION : puerta de la ciudad
FICHERO     : puerta_ciudad.c
MODIFICACION: 25-02-00 [Angor@Simauria] Creacion
              15-08-01 [Angor@Simauria] Modificacion
*/

#include "../../sys/akallab.h"
#include AK_MACRO
#include "puerta_ciudad.h"
inherit AK_ROOM;

string torre;
string ciudad;
string entrada;
string subir;
string bajar;
string dir_ciudad;
string dir_fuera;
string dir_torre1;
string dir_torre2;
string salida;

int tipo;

create() {
  int i,j;
  object ob;

 ::create();
 if (!tipo)
 {
    salida="salida";
 	torre="torre";
  	ciudad="ciudad";
 	entrada="entrada";
 	subir="subir";
 	bajar="bajar";
	dir_ciudad="ciudad";
	dir_fuera="fuera";
	dir_torre1="torre1";
	dir_torre2="torre2";
	tipo=PC_ESCALERA_PLANTA_BAJA;
 }

 switch(tipo)
 {
 case PC_ESCALERA_PLANTA_BAJA:
    {
    SetPreIntShort("junto a ");
    SetIntShort("el pie de la escalera exterior de la torre "+torre);
    SetIntLong(
    "Te hallas junto a los primero peldanyos de una escalera de piedra "
      "adosada a la pared exterior de la torre "+torre+", una de las dos que "
	  "forman la entrada "+entrada+" a esta ciudad de "+ciudad+". Hacia el "
	  +subir+" la escalera asciende hasta la primera planta de la parte central "
	  "del edificio que se halla entre las dos torres.\n");
	AddDetail(({"escalera"}),QueryIntLong());
    SetIndoors(0);
	break;
	}
 case PC_ESCALERA_PLANTA_0_1:
    {
    SetIntShort("en medio de la escalera exterior de la torre "+torre);
    SetIntLong(
    "Estas en la mitad de la escalera de piedra adosada a la pared exterior de "
	  "la torre "+torre+", una de las dos que forman la entrada "+entrada+" de "
	  "la ciudad. La escalera asciende hacia el "+subir+" hasta llegar a la primera "
	  "planta, y desciende hacia el "+bajar+" hasta el suelo de la ciudad.\n");
	AddDetail(({"escalera"}),QueryIntLong());
    SetIndoors(0);
	break;
	}
 case PC_ESCALERA_PLANTA_1:
    {
	SetIntShort("en la primera planta junto a la escalera exterior de la torre "+torre);
    SetIntLong(
    "Te encuentras junto al extremo superior de una larga escalera de piedra "
	  "adosada a la pared exterior de la torre "+torre+" de las dos que forman "
	  "la fortificada entrada "+entrada+" de la ciudad. La escalera desciende "
	  "hacia el "+bajar+" en direccion al suelo de la ciudad. Al "+subir+" de "
	  "aqui se halla la primera planta del cuerpo central de la puerta, una "
	  "especie de amplia balconada.\n");
    AddDetail(({"escalera"}),QueryIntLong());
	SetIndoors(0);
	break;
	 }
 case PC_PLANTA_1_CENTRO_BALCON:
    {
	SetIntShort("en la primera planta del cuerpo central junto al balcon");
    SetIntLong(
    "Ante si se extiende a primera planta del cuerpo central de la "
	  "fortificada entrada "+entrada+" de la ciudad. Es una gran estancia "
	  "cuyas paredes "+dir_torre1+" y "+dir_torre2+" son las dos torres y "
	  "a la que le falta el muro "+dir_ciudad+". En el lugar de este muro "
	  "solo hay un alto arco y una barandilla de modo que parece una gran "
	  "balconada desde la que se observa la ciudad y a cuyos extremos "
	  "llegan las escaleras exteriores de piedra adosadas a las torres que "
	  "permiten descender al nivel del suelo.\n");
    AddDetail(({"escalera"}),
	"Dos escaleras parten de aqui, una adosada a cada una de las torres, "
	  "hacia el suelo.\n");
    AddDetail(({"barandilla"}),
	"Es un muro de aproximadamente un metro de altura. Impide que la "
	  "gente se caiga de aqui al suelo.\n");
    AddDetail(({"arco"}),
	"En lugar de unirse las paredes con el techo en angulo recto, lo hacen "
	  "formando un arco ojival.\n");
    SetIndoors(0);
	break;
	}
 case PC_PLANTA_1_CENTRO_AGUJERO:
    {
	SetIntShort("en la primera planta del cuerpo central junto al agujero");
    SetIntLong(
    "Estas en el medio de la primera planta del cuerpo central de esta "
	  "edificacion que es la entrada "+entrada+" de la ciudad. Es una gran "
	  "estancia que limita al "+dir_torre1+" y al "+dir_torre2+" con las dos "
	  "torres y a la que le falta el muro "+dir_ciudad+", de forma que parece "
	  "una gran balconada. Junto a ti se halla una especie de gran agujero "
	  "rectangular en el suelo rodeado por una barandilla que permite controlar "
	  "y atacar si es necesario desde arriba a la gente que esta entrando a la "
	  "ciudad.\n");
    AddDetail(({"barandilla"}),
	"Es un muro de aproximadamente un metro de altura. Impide que la "
	  "gente se caiga de aqui al suelo.\n");
    AddDetail(({"agujero"}),
	"Es un gran agujero rectangular en el suelo rodeado de una barandilla de "
	  "piedra. A traves de el se puede observar el corredor formado por las dos "
	  "torres y el suelo que constituye el lugar por el que la gente entra a la "
	  "ciudad. Es un lugar priviliegiado para observar quien esta entrando en la "
	  "ciudad y, en caso de ataque, defender facilmente el acceso a la misma.\n");
    SetIndoors(1);
	SetIntBright(50);
	break;
	}
 case PC_PLANTA_1_CENTRO_MURO:
    {
	SetIntShort("en la primera planta del cuerpo central junto al muro");
    SetIntLong(
    "Te encuentras en el extremo de la primera planta del cuerpo central "
	  "de esta construccion, junto al muro "+dir_fuera+". Observas que en "
	  "el muro se hallan numerosas altas y estrechas troneras a traves de "
	  "las que puedes ver el territorio exterior de la ciudad que queda al "
	  +dir_fuera+". Las troneras permiten al defensor de esta puerta de la "
	  "ciudad una facil defensa de un posible atacante exterior.\n");
    AddDetail(({"tronera","troneras"}),
	"Las troneras son unas altas y estrechas aberturas en el muro a modo "
	  "de ventanas. La cara interior del muro junto a ellas ha sido biselada "
	  "para asi permitir un gran angulo de vision desde el interior, lo cual "
	  "no es posible desde el exterior dada la forma de las troneras. De esta "
	  "forma un defensor de la ciudad puede atacar con flechas a los posibles "
	  "enemigos que se encuentren en el exterior de la puerta al mismo tiempo "
	  "que estar bien protegido de ellos.\n");
    SetIndoors(1);
	SetIntBright(50);
	break;
	}
 case PC_PLANTA_1_TORRE_PUERTA:
    {
    SetIntShort("junto a la puerta de la sala");
    SetIntLong(
    "Te encuentras junto a la puerta de la amplia sala que forma la "
      "primera planta de la torre "+torre+" de la puerta de la "
      "ciudad. Esta puerta, al "+salida+" de aqui, permite salir de "
      "la torre. La sala que tienes ante ti esta amueblada austeramente "
      "con grandes y toscos muebles de madera y parece ser el lugar de "
      "la torre donde viven la mayoria de los soldados de la guardia "
      "de esta puerta de la ciudad.\n");
    AddDetail(({"muebles","sillas","literas","armarios"}),
    "En el centro de la sala se hallan dos largas mesas de madera rodeadas "
      "de sillas y adosados a las paredes varios grandes armarios y literas.\n");
    SetIndoors(1);
    SetIntBright(50);
    break;
    }
 case PC_PLANTA_1_TORRE_CENTRO:
    {
    SetIntShort("en el centro de la sala");
    SetIntLong(
    "Te hallas en el centro de la esta amplia sala de la torre "+torre+
      ". A tu alrededor hay dos largas y toscas mesas de madera no demasiado "
      "limpias rodeadas de multitud de sillas donde suelen comer los soldados "
      "de la guardia que viven aqui.\n");
   AddDetail(({"muebles","sillas","literas","armarios"}),
    "En el centro de la sala se hallan dos largas mesas de madera rodeadas "
      "de sillas y adosados a las paredes varios grandes armarios y literas.\n");
    SetIndoors(1);
    SetIntBright(50);
    break;
    }
 case PC_PLANTA_1_TORRE_CHIMENEA:
    {
    SetIntShort("en una esquina de la sala junto a la chimenea");
    SetIntLong(
    "Notas el agradable calor de las brasas que arden lentamente en la "
      "chimenea de piedra adosada a la pared de la sala. Junto a ella "
      "hay varios bajos taburetes donde los guardias pueden calentarse "
      "tras una larga y fria guardia nocturna.\n");
   AddDetail(({"chimenea","taburetes"}),
    "Adosada a la pared frente a ti se halla una baja chimenea de piedra "
      "donde calentarse y hacer de comer. En torno a la chimenea hay varios "
      "bajos taburetes de madera.\n");
    SetIndoors(1);
    SetIntBright(50);
    break;
    }
 case PC_PLANTA_1_TORRE_LITERAS:
    {
    SetIntShort("junto a unas literas");
    SetIntLong(
    "Adosadas a la pared de la sala frente a ti se hallan varias literas "
      "donde duermen los soldados que aqui viven. Las literas son unos "
      "toscos y macizos muebles de madera formados por dos camastros y una "
      "pequenya escalera de para subir al de la parte superior.\n");
    AddDetail(({"literas","camastros","escalera"}),QueryIntLong());
    SetIndoors(1);
    SetIntBright(50);
    break;
    }
 case PC_PLANTA_1_TORRE_ARMAS:
    {
    SetIntShort("junto a un gran armario");
    SetIntLong(
    "Junto a la pared de esta parte de la sala se encuentra un gran y tosco "
      "armario de madera donde los soldados que aqui viven guardan sus cosas.\n");
    if (random(2)==1) AddItem(MUEBLE("armario_armas"),REFRESH_DESTRUCT,1);
    else AddItem(MUEBLE("armario_ropa"),REFRESH_DESTRUCT,1);
    SetIndoors(1);
    SetIntBright(50);
    break;
    }
 case PC_PLANTA_1_TORRE_ESCALERA:
    {
    SetIntShort("junto al inicio de la escalera");
    SetIntLong(
    "Te hallas junto a los primeros peldanyos de una escalera de piedra que,"
      "adosada a la pared de la sala, y que hacia el "+subir+" asciende hasta "
	  "la segunda planta de esta torre.\n");
    AddDetail(({"escalera"}),QueryIntLong());
    SetIndoors(1);
    SetIntBright(50);
    break;
    }
 case PC_PLANTA_0_PUERTA:
   {
   SetIntShort("junto a la puerta");
   SetIntLong(
    "En esta parte del muro se encuentra una baja y recia puerta de hierro. "
	"Una gruesa barra tambien de hierro colocada sobre unos pasadores adosados a la "
	"puerta y a los muros bloquea la puerta e impide el acceso a este almacen "
	"desde el exterior. Supones que la puerta solo debe abrirse cuando se "
	"traen nuevos suministros a este almacen desde la ciudad, que por lo que "
	"ves aqui almacenado no debe ser mas de una vez al mes.\n");
   AddDetail(({"barra"}),
    "La gruesa barra de hierro esta colocada sobre unos pasadores bloqueando asi "
	"la puerta e impidiendo el acceso a este almacen desde el exterior. Por su "
	"tamanyo dirias que hacen falta varias personas para moverla.\n");
   AddDetail(({"puerta"}),QueryIntLong());
   SetIndoors(1);
   SetIntBright(50);
   break;
   }
 case PC_PLANTA_0_CENTRO_1:
   {
   SetIntShort("en medio del almacen");
   SetIntLong(
    "A tu alrededor se alzan varios gruesos pilares de piedra que sostienen el techo "
    "de esta amplia, baja y abovedada estancia. Sobre ellos y las recias paredes de "
    "piedra descansa el peso de esta torre. Alrededor de los pilares de encuentran "
    "multitud de barriles de pie de distintos tamanyos.\n");
    AddDetail(({"pilar", "pilares"}),
    "Hay multitud de gruesos pilares de piedra en esta baja estancia. Su grosor se "
    "debe al inmenso peso del resto del edificio que tienen encima.\n");
    AddDetail(({"barriles"}),
    "El almacen esta lleno de barriles conteniendo todo tipo de bienes necesarios "
	"para la guardia de la torre.\n");
   j=random(3)+1;
   for(i=0;i<j;i++)
   {
 	  ob=clone_object(MUEBLE("barril_abierto_suministros"));
  	  ob->move(TO);
   }
   SetIndoors(1);
   SetIntBright(50);
   break;
   }
 case PC_PLANTA_0_CENTRO_2:
   {
   SetIntShort("en medio del almacen");
   SetIntLong(
    "Varios altos barriles con conservas se alzan en torno a los gruesos pilares que "
    "sostienen el techo. Por el olor dirias que se trata de salazones... Probablemente "
    "se trate de la base del rancho de la guarnicion de soldados de este edificio. "
    "Tus pasos resuenan en la baja boveda de esta estancia a medida que avanzas.\n");
   AddDetail(({"pilar", "pilares"}),
    "Hay multitud de gruesos pilares de piedra en esta baja estancia. Su grosor se "
    "debe al inmenso peso del resto del edificio que tienen encima.\n");
   AddDetail(({"barriles"}),
    "El almacen esta lleno de barriles conteniendo todo tipo de bienes necesarios "
    "para la guardia de la torre.\n");
   j=random(3)+1;
   for(i=0;i<j;i++)
   {
      ob=clone_object(MUEBLE("barril_abierto_suministros"));
   	  ob->move(TO);
   }
   SetIndoors(1);
   SetIntBright(50);
   break;
   }
 case PC_PLANTA_0_CAJAS:
   {
   SetIntShort("un montón de cajas");
   SetIntLong(
    "En esta zona del almacen se hallan apilados grandes cajones de madera en los "
	"que sin duda se almacenan todo tipo de suministros para la guarnicion de esta "
	"torre. Algunos de los cajones estan cerrandos y por su aspecto dirias que llevan "
	"aqui largo tiempo. La pila de cajones se halla adosada a la pared y llega hasta "
	"el bajo techo.\n");
   AddDetail(({"cajas","cajones"}),
    "A tu alrededor hay apilados multitud de cajas y cajones de suministros.\n");
   j=random(3)+1;
   for(i=0;i<j;i++)
   {
      ob=clone_object(MUEBLE("caja_abierta_suministros"));
   	  ob->move(TO);
   }
   SetIndoors(1);
   SetIntBright(50);
   break;
   }
 case PC_PLANTA_0_BARRILES:
   {



   break;
   }

 case PC_PLANTA_0_LENYA:
   {
   break;
   }

 case PC_PLANTA_0_ESCALERA:
   {
   break;
   }

 case PC_PLANTA_0_1_ESCALERA:
   {
   break;
   }

 }

 AddDetail(({"torre","torres","puerta de la ciudad"}),
    "La puerta de la ciudad es un impresionante edificio de piedra. Esta formado "
	  "por dos inmensas torres de piedra con una altura de cuatro pisos y un cuerpo "
	  "central que las une. Estas altas torres permiten no solo controlar el acceso "
	  "al interior de la ciudad si no que, ademas, constituyen un privilegiado lugar "
	  "desde el que vigilar el territorio que rodea la ciudad. Las torres estan "
	  "protegidas por macizas y altas almenas e innumerables troneras desde las que "
	  "repeler a un posible atacante. En la parte baja de las torres suele haber "
	  "siempre algun tipo de almacen de forma que siempre numerosa guardia de soldados "
	  "de la la torre puede resistir durante largo tiempo cualquier tipo de asedio.\n");

SetIntNoise("No oyes nada en especial.\n");
SetIntSmell("No hueles a nada en especial.\n");
}