/** ENDOR-MUD '/obj/raceobj.c'
 *  =========================
 */

//------------------------------------------------------------------------------

#pragma no_clone

//------------------------------------------------------------------------------

#include <config.h>
#include <races.h>
#include <attributes.h>
#include <moving.h>
#include <description.h>
#include "/secure/wizlevels.h"

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------

private nosave string  pRaceDescription = "";  /* The race description */

private nosave int     pAlign = 0;
private nosave int     pIVision = 0;
private nosave int     pMaxAlcohol = 0;
private nosave int     pMaxDrink = 0;
private nosave int     pMaxFood = 0;
private nosave int     pSize = 0;
private nosave int     pBando = 0;
private nosave int     pUVision = 0;
private nosave int     pWeight = 0;

private nosave string  pLong = "";


private nosave mapping pResistances = ([]);
private nosave mapping pStatBonuses = ([]);

private nosave mixed   pHands = ({});

private nosave mapping pHairColors = D_ALL_HAIR_COLOUR;
private nosave mapping pEyesColors = D_ALL_EYES_COLOUR;

//------------------------------------------------------------------------------

create_blueprint()
{

}

//------------------------------------------------------------------------------

public string QueryRaceDescription()   { return pRaceDescription; }
public void   SetRaceDescription(string s) { pRaceDescription = s; }

//------------------------------------------------------------------------------

public int     QueryAlign      () { return pAlign     ; }
public int     QueryIVision    () { return pIVision   ; }
public int     QueryMaxAlcohol () { return pMaxAlcohol; }
public int     QueryMaxDrink   () { return pMaxDrink  ; }
public int     QueryMaxFood    () { return pMaxFood   ; }
public int     QuerySize       () { return pSize      ; }
public int     QueryBando       () { return pBando      ; }

public int     QueryUVision    () { return pUVision   ; }
public int     QueryWeight     () { return pWeight    ; }

public string  QueryLong       () { return pLong   ; }


public mapping QueryResistances() { return deep_copy(pResistances); }
public mapping QueryStatBonuses() { return deep_copy(pStatBonuses); }

public mapping QueryHairColors()  {return deep_copy(pHairColors); }
public mapping QueryEyesColors()  {return deep_copy(pEyesColors); }

public mixed   QueryHands      () { return deep_copy(pHands      ); }

public int     QueryResistance(mixed m) { return pResistances[m]; }
public int     QueryStatBonus(string s) { return pStatBonuses[s]; }

//------------------------------------------------------------------------------

public varargs void AddHand (string dsc, int type, int wc) {
  pHands += ({ ({ dsc, type, wc }) });
}

//------------------------------------------------------------------------------

public int     SetMaxAlcohol(int i) { return pMaxAlcohol = i; }
public int     SetAlign     (int i) { return pAlign      = i; }
public int     SetMaxDrink  (int i) { return pMaxDrink   = i; }
public int     SetMaxFood   (int i) { return pMaxFood    = i; }
public int     SetIVision   (int i) { return pIVision    = i; }
public int     SetSize      (int i) { return pSize       = i; }
public int     SetBando      (int i) { return pBando       = i; }
public int     SetUVision   (int i) { return pUVision    = i; }
public int     SetWeight    (int i) { return pWeight     = i; }
public string  SetLong(string s) { return pLong = s; }

public int     SetResistance(mixed m, int i) { return pResistances[m] = i; }
public int     SetStatBonus(string s, int i) { return pStatBonuses[s] = i; }

public mapping SetHairColors(mapping m)  {return pHairColors = deep_copy(m); }
public mapping SetEyesColors(mapping m)  {return pEyesColors = deep_copy(m); }

//------------------------------------------------------------------------------
