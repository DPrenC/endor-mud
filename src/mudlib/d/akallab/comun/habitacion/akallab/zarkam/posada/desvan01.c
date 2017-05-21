/*
DESCRIPCION : desvan de la posada la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/desvan01.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int suerte; //encontrar dinero [0]no, [1]si

int inicio(){suerte=1; return 1;}

string mirar_paja(){
  object ob;
  string str;
  int cobre, plata;
  if (suerte==1){
     cobre=8+random(10);
     plata=random(3);
     ob=clone_object("/obj/money");
     ob->AdjustMoney((["cobre":cobre, "plata":plata]));
     ob->move(TP);
     suerte=0;
     call_out("inicio",120);
     str="Vaya, hoy debe ser tu dia de suerte! Rebuscando entre la paja extendida por el "
         "acabas de encontrar "+cobre+" monedas de cobre";
     plata!=0?str+=" y "+plata+" moneda"+(plata==1?"":"s")+" de plata":"";
     str+=".\nSeguro que se le debieron caer a alguien que durmio aqui.\n";
     return str;
     }
  return "Rebuscas entre la paja extendida en el suelo pero no encuentras nada de interes.\n";
}

create() {
  ::create();
  SetIntShort("el desván de la posada");
  SetIntLong(
    "Estas en el desvan de la posada. Es una amplia habitacion entre el techo de la "
    "primera planta y las inclinadas cubiertas del tejado. El suelo esta cubierto de "
    "paja y supones que a veces ha podido servir de dormitorio cuando se llenan las "
    "habitaciones. Al fondo del desvan se acumulan todo tipo de trastos viejos. Una "
    "escalera permite bajar a la primera planta de la posada.\n");

  AddDetail(({"trastos","trastos viejos"}),
  "Si tienes algun interes en ellos, deberias echarles un vistazo mas de cerca.\n");

  AddDetail(({"escalera"}),
    "Es una ancha escalera de madera que comunica las distintas plantas de la posada.\n");

  AddDetail((({"paja","suelo"})),SF(mirar_paja));

  SetIntNoise("Se oye a alguien roncar.\n");
  SetIntSmell("Hmm.. quiza alguien deberia abrir una ventana para ventilar el desvan.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("abajo",Z_POSADA("pasillo01"));
  AddExit("oeste",Z_POSADA("desvan02"));

  suerte=1;
}
