/** SIMAURIA '/std/thing.c'
 *  =======================
 */

#include <classes.h>
#include <materials.h>
#include <properties.h>

inherit "/std/thing/restrictions";
inherit "/std/thing/description";
inherit "/std/thing/moving";
inherit "/std/base";

//---------------------------------------------------------------------------

private int pInvis = 0;
private string pMaterial = "";

//---------------------------------------------------------------------------

public int QueryInvis ()        { return Query(P_INWIZ)?1:pInvis; }
public int SetInvis (int i)     { return pInvis = i>0 ? 1 : 0; }

public string QueryMaterial()
{ return pMaterial; }

public string SetMaterial( mixed material )
{
   if( intp( material ) )
      if( M_MAPPING[material] )
         pMaterial = M_MAPPING[material];
      else pMaterial = M_DESCONOCIDO_TXT;
   else if( stringp( material ) ) pMaterial = material;
   return pMaterial;
}

public mixed QueryThingArticle()
{
 return (Query(P_NUMBER)?(Query(P_GENDER)==GENDER_FEMALE?"las":"los"):
                         (Query(P_GENDER)==GENDER_FEMALE?"la":"el"));
}

//---------------------------------------------------------------------------

create () {
  "*"::create();
  SetShort("Algo");
  SetLong("Algo.\n");
  AddClassId(C_THING);
  Set(P_SIZE, P_SIZE_MEDIUM);
}

init() {
  "*"::init();
}

//---------------------------------------------------------------------------
