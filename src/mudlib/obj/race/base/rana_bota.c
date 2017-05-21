/*
DESCRIPCION  : una rana dentro de una bota
FICHERO      : /obj/race/base/rana_quest_en_bota.c
BASADO       : /obj/race/base/rana_quest_en_bota.c del Maler
MODIFICACION : cuando me rote la hago
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>

inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();


  SetAlign  (0);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (100);
  SetSize(P_SIZE_SMALL);

  SetWeight (5000);
  AddHand   ("anca derecha", DT_BLUDGEON, WEAPON_CLASS_OF_HANDS);
  AddHand   ("anca izquierda", DT_BLUDGEON, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, -50);
  SetStatBonus   (P_DEX, 0);
  SetStatBonus   (P_INT, -50);
  SetStatBonus   (P_STR, -50);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(W("Es una bota marrón, como de pescador, te sorprende el hecho de "
"que no deja de dar saltitos hacia todos los lados, parece que la bota "
"no anda muy bien de la vista, aunque que se puede esperar de una bota? "
".\n"));
  SetRaceDescription(W(" Los ranas son la raza mas patetica de todas. No hay nada "
"en el mundo de Simauria  no pueda aplastar una rana. Aunque no tienen "
"poderes especiales cuando comienzan, tampoco tienen ninguna desventaja,"
"aparte de ser tontas, canijas, debiles, y verdes. Todas las razas las "
"desprecian o incluso los odian.\n"));
}

