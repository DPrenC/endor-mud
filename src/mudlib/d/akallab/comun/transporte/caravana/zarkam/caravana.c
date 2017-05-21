/*
DESCRIPCION : Caravana (Ruta Zarkam-Nandor)
FICHERO     : /d/akallab/comun/objeto/transporte/caravana/caravana.c
MODIFICACION:

04-02-99 [Angor@Simauria] creacion
28-10-99 [Angor@Simauria] arreglada
08-11-99 [woo] Tio tas pasao de mensajitos.. jejeje tardabas un huevo en
         llegar.. na, le he quitao unos cuantos.
15-11-01 [nemesis] Cambiado el nombre de Simauria capital a Ishtria, que es
                   el nuevo nombre oficial
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit CARAVAN;

#define PSIM "/d/simauria/comun/habitacion/marhalt/nandor/calle0"
#define PAKA Z_CIUDAD("plaza_01")

string *MensajesEntradaCaravana(string lugar)
{
 if (lugar==PAKA)
  return ({
      "\nFinalmente tras un largo viaje, la caravana llega al valle orco de "
      "Zarkam. Lentamente cruza el valle y asciende por la loma sobre la que "
      "esta situada la amurallada ciudad de Zarkam. La caravana pasa bajo "
      "las torres que forman la puerta norte de la ciudad y se adentra en "
      "ella. La caravana se detiene en la plaza mayor de la ciudad. El guia "
      "grita:'Ya hemos llegado a Zarkam'.\n",
    "La caravana procedente de @@FromParada@@ llega a la plaza central de Zarkam.\n"});

 return ({
   "\nEl guia de la caravana grita:'Hemos llegado a @@Parada@@!'\n",
   capitalize(TO->QueryShort())+" llega tras un largo viaje.\n"});
}

string *MensajesSalidaCaravana(string lugar)
{
 lugar=FromParada();
 if (lugar==PSIM)
  return ({
      "\nLa caravana se pone en marcha. Atraviesa la ciudad de Zarkam y, "
      "tras pasar bajo las torres que forman su puerta norte, deja atras "
      "esta amurallada ciudad. La caravana avanza hacia el norte en lo que "
      "sera un largo viaje.\n",
      capitalize(TO->QueryShort())+" parte de aqui para realizar un "
      "largo que la conducira hasta el territorio humano de Nandor, en "
      "el lejano norte.\n" });

return ({
    "\nLa caravana parte de @@FromParada@@ y emprende un largo viaje que "
    "la conducira hasta @@Parada@@.\n",
    capitalize(TO->QueryShort())+" parte de @@FromParada@@ hacia @@Parada@@.\n" });
}


create()
{
 ::create();
 SetIds(({"caravana","zarkam", "Zarkam","caravana Zarkam","caravana zarkam"}));
 SetShort("la caravana de Zarkam");
 SetLong("La caravana esta formada por una larga fila de carros de "
   "comerciantes que regularmente realiza la larga y peligrosa ruta que "
   "recorre de norte a sur este continente, desde territorios orcos hasta "
   "los de los humanos. Los comerciantes emplean guardias para protegerse "
   "de los salteadores y por un precio razonable suelen admitir pasajeros. "
   "La ruta de la caravana la lleva desde la ciudad orca de Zarkam hasta "
   "la humana de Nandor.\n");

 SetEnterMsgs(
   ({"se sube a la caravana de Zarkam",
     "se sube a la caravana de Zarkam",
     "Te subes a la caravana de Zarkam"}));

 SetLeaveMsgs(
   ({"se baja de la caravana de Zarkam",
     "se baja de la caravana de Zarkam",
     "Te bajas de la caravana de Zarkam"}));

 SetCaravanaEnterMsgs(SF(MensajesEntradaCaravana));
 SetCaravanaLeaveMsgs(SF(MensajesSalidaCaravana));

 /*SetCaravanaEnterMsgs(({"El lider de la caravana grita: Hemos llegado a @@FromParada@@!\n",
       "La caravana Nahlin llega de @@FromParada@@.\n"}));
   SetCaravanaLeaveMsgs(({"Nos vamos a @@Parada@@!\n",
       "La caravana Nahlin sale hacia @@Parada@@.\n"}));*/

SetParadas(([0:PSIM;"Nandor",1:PAKA;"Zarkam"]));

 AddMoveScene(PAKA, PSIM, "Estas saliendo del valle de Zarkam.\n", 2);
// AddMoveScene(PAKA, PSIM, "Empiezas a subir por las montañas.\n", 5);
 AddMoveScene(PAKA, PSIM, "Sigues avanzando por valles encajonados entre montañas.\n", 10);
// AddMoveScene(PAKA, PSIM, "Las montañas y los valles se suceden sin fin.\n", 10);
 AddMoveScene(PAKA, PSIM, "Las montañas parecen suavizarse progresivamente.\n", 10);
// AddMoveScene(PAKA, PSIM, "Llegas a una llanura costera.\n", 10);
 AddMoveScene(PAKA, PSIM, "Cruzas el itsmo de Sorquer y dejas atras los territorios orcos.\n", 10);
// AddMoveScene(PAKA, PSIM, "Sigues avanzando junto a la llanura costera.\n", 10);
 AddMoveScene(PAKA, PSIM, "Cruzas un gran bosque.\n", 10);
 AddMoveScene(PAKA, PSIM, "Sigues avanzando junto a la llanura costera.\n", 10);
// AddMoveScene(PAKA, PSIM, "Abandonas la costa y te dirijes hacia el norte.\n", 10);
 AddMoveScene(PAKA, PSIM, "El camino bordea un caudaloso río.\n", 10);
 AddMoveScene(PAKA, PSIM, "Pasas junto a Ishtria, la capital del territorio humano.\n", 10);
// AddMoveScene(PAKA, PSIM, "Continuas bordeando un caudaloso río.\n", 10);
 AddMoveScene(PAKA, PSIM, "Estas entrando en Nandor.\n", 10);

 AddMoveScene(PSIM, PAKA, "Estas saliendo de Nandor.\n", 2);
 AddMoveScene(PSIM, PAKA, "El camino bordea un caudaloso río.\n", 10);
// AddMoveScene(PSIM, PAKA, "Pasas junto a Ishtria, la capital del territorio humano.\n", 10);
 AddMoveScene(PSIM, PAKA, "Continuas bordeando un caudaloso río.\n", 10);
// AddMoveScene(PSIM, PAKA, "Alcanzas la costa y te dirijes bordeandola hacia el sur.\n", 10);
// AddMoveScene(PSIM, PAKA, "Sigues avanzando junto a la llanura costera.\n", 10);
 AddMoveScene(PSIM, PAKA, "Cruzas un gran bosque.\n", 5);
 AddMoveScene(PSIM, PAKA, "Sigues avanzando junto a la llanura costera.\n", 5);
// AddMoveScene(PSIM, PAKA, "Cruzas el itsmo de Sorquer y dejas atras los territorios humanos.\n", 10);
 AddMoveScene(PSIM, PAKA, "Abandonas la llanura costera en direccion a las montañas.\n", 5);
 AddMoveScene(PSIM, PAKA, "Las montañas se hacen mas abruptas progresivamente.\n", 5);
// AddMoveScene(PSIM, PAKA, "Las montañas y los valles se suceden sin fin.\n", 15);
 AddMoveScene(PSIM, PAKA, "Sigues avanzando por valles encajonados entre montañas.\n", 5);
// AddMoveScene(PSIM, PAKA, "Comienzas a descende hacia un gran valle.\n", 15);
 AddMoveScene(PSIM, PAKA, "Llegas al valle de Zarkam.\n", 5);

 SetCaravanaCost(500);

// Al contrario que los barcos las caravanas solo tienen una habitacion.
 AddDeck(CAR_ZARKAM("interior_caravana"));

 SetMsgCost("No tienes suficiente dinero para unirte a la caravana.\n");
}
