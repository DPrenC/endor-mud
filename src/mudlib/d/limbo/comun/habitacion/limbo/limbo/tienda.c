/*
DESCRIPCION : tienda del poblado de pescadores
FICHERO     : /d/limbo/comun/habitacion/limbo/limbo/tienda.c
MODIFICACION: 17-07-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <wizlevels.h>
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <combat.h>

inherit SHOP;

#define NOMBRE          (TP->QueryName())
#define NOMBRE_M        (capitalize NOMBRE)
#define SUF             (TP->QueryGenderEndString())
#define SUF2            (TP->QueryGender()==2?"a":"e")

int matar_(string str);

create()
 {
  ::create();
  SetIntShort("la tienda del poblado del pescadores");
  SetIntLong(
 "Est�s en la tienda de Vertim, la �nica que hay en este poblado. Aqu� puedes "
 "encontrar un poco de todo, comprar y vender cosas. La tienda es un peque�o "
 "local repleto de estanterias con los m�s variados productos y te preguntas como "
 "habr�n podido llegar muchos de ellos a un lugar como este.\n");

 AddDetail(({"tienda","local"}),QueryIntLong());

 AddDetail(({"estanterias","productos"}),
 "Las estanterias ocupan gran parte de las paredes y del interior de la tienda. "
 "Est�n construidas con listones de madera y en sus lejas puedes obserbar los m�s "
 "variados productos, muchos de los cuales son desconocidos incluso para ti. Por "
 "la capa de polvo que los cubre, dirias que hay objetos que deben llevar aqu� "
 "a�os, mientras que otros parecen recien colocados en sus estantes. "
 "Si quieres conocer que tipo de objetos estan disponibles, teclea 'lista'.\n");

AddItem(PNJ("vertim"),REFRESH_DESTRUCT,1);

SetIntNoise("No escuchas nada interesante.\n");
SetIntSmell("Huele a cosas almacenadas durante mucho tiempo.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);

AddExit("oeste",LIMBO("calle02"));

CanAppraise(0); //No se valoran objetos
CanIdentify(0); //No se identifican objetos

RemoveDustbin();
SetShopkeeper(0,([P_SHORT:"Ibem, la tendera",P_LONG:"Es la tendera.\n",
                P_IDS:({"tendera","Ibem","ibem","humana"})]));

//articulos a la venta
AddArticle("/std/weapon",REFRESH_REMOVE,2,
([P_SHORT: "un cuchillo de cocina",
P_LONG:  "Un cuchillo de cocina con empu�adura de madera.\n",
P_IDS: ({"cuchillo","cuchillo de cocina"}),
P_WC: 1,
P_WEIGHT: 300,
P_VALUE: 150,
P_NUMBER_HANDS: 1,
P_WEAPON_TYPE:CS_CUCHILLO,
P_DAM_TYPE:DT_PIERCE]));

AddArticle("/std/weapon",REFRESH_REMOVE,1,
([P_SHORT: "un hacha de le�ador",
P_LONG:  "Un simple hacha de le�ador, bien afilada con la que puedes cortar un �rbol.\n",
P_IDS: ({"hacha de le�ador","hacha"}),
P_WC: 4,
P_WEIGHT: 3000,
P_VALUE: 275,
P_NUMBER_HANDS: 1,
P_WEAPON_TYPE:CS_HACHA,
P_DAM_TYPE:DT_SLASH]));

AddArticle("/std/weapon",REFRESH_REMOVE,2,
([P_SHORT: "una maza de madera",
P_LONG:"Una maza de madera, �til para usar de martillo o para clavar clavos\n",
P_IDS: ({"maza de madera","maza"}),
P_WC: 5,
P_WEIGHT: 3000,
P_GENDER: 2,
P_VALUE: 350,
P_NUMBER_HANDS: 1,
P_WEAPON_TYPE:CS_MAZA,
P_DAM_TYPE:DT_BLUDGEON]));

AddArticle("/obj/cuerda", REFRESH_REMOVE,3);
AddArticle("/obj/torch", REFRESH_REMOVE,6);
AddArticle("/obj/oil_bottle",REFRESH_REMOVE,5);
AddArticle("/obj/lighter",REFRESH_REMOVE,2);
SetCloseTime(({ND_NO_STATES}));
}

void init()
{
  (::init());

  if (present("vertim") && TP && query_once_interactive(TP))
   {
  write("Vertim te saluda al entrar en la tienda: 'Hola, bienvenid"+SUF+" a mi tienda. "
        "Ibem!, sal que hay que atender a este cliente'. Al momento Ibem, sale del almac�n "
        "donde deb�a estar ordenando alguna cosa y te saluda: 'Quer�a alguna cosa?'.\n");

  say(  "Vertim saluda a "+NOMBRE_M+" cuando est"+SUF2+" entra en la tienda y llama a "
        "a su hija Ibem para que le atienda.\n",TP);
  add_action("matar_cmd","matar");
  }
}

int matar_cmd(string s)
{
  if (!s) return 0;
  else if ((s=="Vertim")||(s=="vertim")||(s=="Ibem")||(s=="ibem")||(s=="tendera")||(s=="duenya")){
      write("Cuando est�s dispuest"+SUF+" a atacar te das cuenta de un peque�o detalle: �vas "
            "a atacar a uno de los siervos de los dioses en la propia isla de los dioses? "
            "Mejor no tentar a la suerte... En ese momento la anciana Vertim te clava una "
            "fria y penetrante mirada y, como si te hubiese leido el pensamiento te dice: 'Si "
            "quieres desahogarte, en el norte de esta isla hay una zona de entrenamiento con "
            "multitud de alima�as que matar. Puedes vender luego aqu� sus pieles.'\n");
      say(  NOMBRE+" parece dispuest"+SUF+" a hacer algo, pero en el �ltimo momento parece cambiar "
            "de opini�n. La anciana Vertim con gesto severo le dice a "+NOMBRE+" que en el "
            "norte de esta isla hay una zona de entrenamiento con animales y que aqui en la "
            "tienda se compran las pieles de algunos de ellos.\n",TP);
      return 1;
      }
}