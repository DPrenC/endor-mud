/*
DESCRIPCION  : La raza b�sica de orcos, tama�o medio, los utilizados en masa por Sauron y Saruman.
FICHERO      : /obj/race/base/orco-comun.c
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <bandos.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();

  SetAlign  (-50);
  SetMaxFood   (130);
  SetMaxDrink  (60);
  SetMaxAlcohol    (120);
  SetWeight (71000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_OSCURIDAD);
  AddHand("negra garra derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("negra garra izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  2);
  SetStatBonus(P_DEX, 0);
  SetStatBonus(P_INT,  -2);
  SetStatBonus(P_STR,  1);
    SetStatBonus("Cha",  -1);
      SetStatBonus(P_WIS,  -4);
SetResistance(DT_FIRE,25);
SetResistance(DT_COLD,5);
SetResistance(DT_GAS,15);
SetResistance(DT_NOAIR,15);
SetResistance(DT_WATER,-40);
                  SetResistance(DT_ACID,  3);
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es un Orco Com�n.\n"
"Ronda entre el metro cuarenta y el metro sesenta de altura y pesar� cerca de los "
"setenta kilos.\n"
"Su constituci�n es achaparrada y pesada, con largos brazos musculosos, manos dotadas de "
"fuertes u�as negras y piernas cortas, gruesas y arqueadas.\n"
"La piel de @@Nombre@@ es �spera, dura y resistente, tan negra como el espeso y "
"mugriento pelaje que la cubre.\n"
"La brutalidad que irradia se ve remarcada por su cabeza, casi naciendo de entre sus "
"anchos hombros, y su faz de bestiales rasgos, enorme mand�bula inferior con "
"sobresalientes colmillos, nariz bulbosa y crueles ojillos rojizos  bajo un enorme entrecejo.\n");
 SetRaceDescription (
  "Los orcos son una raza inmunda e infecta concebida por Morgoth en los D�as Antiguos "
  "a partir de la perversi�n de otras razas a las que mediante malas artes, tortura y "
  "odio degrad�.\n"
  "Son criaturas mal�volas, ego�stas, crueles, que disfrutan matando, destruyendo y "
  "torturando y forman el grueso de los ej�rcitos de los poderes oscuros.\n"
  "Los orcos comunes son seres achaparrados, de espaldas encorvadas, piernas cortas y "
  "arqueadas y brazos muy largos y nervudos.\n"
  "Casi desprovistos de cuello, sus cabezas poseen un cr�neo grueso, con entrecejos "
  "pronunciados sobre ojos rojos como ascuas.\n"
  "Sus facciones son brutales, con la mand�bula inferior pronunciada y grandes colmillos.\n"
  "Aman el combate y se entregan a la violencia con entusiasmo, aunque suelen ser "
  "cobardes y taimados.\n"
  "Sus armas y herramientas son toscas y desagradables pero eficientes y funcionales, "
  "pues son buenos herreros y sus remedios de curaci�n, aunque repulsivos son eficientes.\n");

}
