/**
 * SIMAURIA '/std/wizard/perception.c'
 */

#include "/secure/wizlevels.h"

inherit "/std/living/perception";

//----------------------------------------------------------------------------

public int QueryNowiz(); // std/wizard/description

//----------------------------------------------------------------------------

public int QuerySeeInvis()  { return QueryNowiz()?(::QuerySeeInvis()):1; }
public int QuerySeeHidden() { return QueryNowiz()?(::QuerySeeHidden()):100; }

//----------------------------------------------------------------------------
