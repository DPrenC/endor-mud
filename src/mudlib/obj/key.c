/*
DESCRIPCION : una llave (standard) para objetos contenedores cerrables
              con /std/lock.c como /obj/chest y quienes lo heredan
FICHERO     : /obj/key.c
MODIFICACION:
  05-Oct-92  [Mateese]
  21-Jan-93  [Mateese] KeyCode now optional to allow generic keys.
  25-Mar-94  [Deepthought] Keycode back in id() to allow use of keycode
  18-Jul-94  [Mateese] Adapted for new lock mechanism.
  09-Sep-94  [Mateese] Made P_IDS and P_KEYIDS more distinct.
  29-11-97   [Guybrush] Traduccion. Anyade genero.
  11-03-00   [Angor]   Anyade numero y la usa con /std/lock.c
*/

#include <properties.h>
inherit THING;

private static string * Pkeyids;
private static mixed Pkeycode;

//-------------------------------------------------------------------------

public mixed SetKeyCode (mixed i) { return Pkeycode = i; }
public mixed QueryKeyCode() { return Pkeycode; }

public string * SetKeyIds (mixed ids) {
  return Pkeyids = pointerp(ids) ? ids : ({ ids });
}
public string * QueryKeyIds () { return Pkeyids; }
public string * AddKeyId (string ids) {
  if (!Pkeyids)
    Pkeyids = ({ ids });
  else if (-1 == member(Pkeyids, ids))
    Pkeyids += ({ ids });
  return Pkeyids;
}

//-------------------------------------------------------------------------
// id() has to recognize P_IDS as well as P_KEYIDS.

public int id (string str) {
  string *kids;

  return    thing::id(str)
         || (    sizeof(kids = QueryKeyIds())
              && member(kids, str) != -1
            )
        ;
}

//-------------------------------------------------------------------------
// Initialize us.

create () {
  ::create();
  SetShort("una llave");
  SetLong("Una simple llave.\n");
  SetValue(10);
  SetWeight(50);
  AddId("llave");
  Set( P_GENDER, GENDER_FEMALE);
  Set( P_NUMBER, NUMBER_SINGULAR); //[a] anyadido
}

/*************************************************************************/
