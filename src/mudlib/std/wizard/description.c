/**
 * SIMAURIA '/std/wizard/description.c'
 */

#include "/secure/wizlevels.h"

inherit "/std/player/description";

//----------------------------------------------------------------------------

private int pInwiz; // Si el Wizard esta escondido vale 1
private int pNowiz; // Si vale 1 el wizard se comporta como jugador

//----------------------------------------------------------------------------

public int QueryInwiz()      { return pInwiz; }
public int SetInwiz(int i)   { return pInwiz = i?1:0; }

public int QueryNowiz()      { return pNowiz; }
public int SetNowiz(int i)   { return pNowiz = i?1:0; }

//----------------------------------------------------------------------------

public int QueryInvis()     { return QueryInwiz()?1:(::QueryInvis()); }

//----------------------------------------------------------------------------
