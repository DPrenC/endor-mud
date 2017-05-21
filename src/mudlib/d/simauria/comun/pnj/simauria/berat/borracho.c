/*
DESCRIPCION : Elric
FICHERO     : /d/simauria/comun/pnj/simauria/berat/borracho.c
MODIFICACION: 4-11-99 [Icaro];2-6-00[Maler] retocada la desc pa que se acople mejor
eliminadas faltas de la desc (juer, este no tenía los retornos de carro ;).Sustituido
/std/npc por NPC
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create() ;
    SetStandard("Elric","humano",10,GENDER_MALE);
    SetShort("un borracho");
    SetLong(
    "Elric es un humano totalmente ebrio, que malgasta su tiempo en las tabernas "
    "de Berat.\n Su comportamiento es problemático y pocas veces se le ha visto fuera "
    "de los locales de mala fama.\n");
    SetCitizenship("berat");
  SetAlign(-200);
    SetIds(({"Elric","borracho","humano"}));
    SetAlcohol(100);
    InitChats(2,({
    "Elric eructa.\n",
    "Elric se levanta de su mesa tambaleándose y se dirije hacia la barra, pidiendo a gritos "
    "una jarra de cerveza para refrescarse el gaznate.\n",
    "Elric grita: ¡Mesonero una ronda para esta mesa!.\n",
  "¡Elric empieza a beber de su jarra de cerveza hasta que se la termina de un solo trago!\n",
    "Elric vagabundea por las mesas intentando que los clientes le paguen una ronda.\n",
  }) );
}

