/**
 * SIMAURIA '/std/player/description.c'
 */

#include "/secure/wizlevels.h"

inherit "/std/living/description";

//----------------------------------------------------------------------------

public string SetShort(mixed s) {
  string rc;
  if (   !TI
      || TI == TO
      || IS_ARCH(TI)
      || object_name(TI)[0..7] == "/secure/"
      || !s
      || s == capitalize(getuid(TO))
     )
    rc = ::SetShort(s);
  else rc = ::QueryShort();
  return rc;
}

public varargs string Short(string what) {
    string rc;
    int i;

    rc = ::Short(what);
    if (!rc || what || !query_once_interactive(TO)) return rc;

    if (rc == QueryName()) rc = QueryPresay()+rc+" "+QueryTitle();
    /* else we're a frog, a ghost, or something else non-natural */

    if (interactive()) { // Estamos conectados
        i = query_idle(TO) / 60;
        if (IS_WIZARD(TP)) rc += (i?" ("+i+" min. pasivo)":"");
        else rc += (i > 4?" (pasivo)":"");
    }
    else { // No estamos conectados
        rc += " (desconectado)";
    }

    return rc;
}

protected string *_long(string str) {
    string * rc;
    int i;
    rc = ::_long(str);
    if (interactive()) { // Estamos conectados
        if (i = query_idle(TO) / 60) {
            rc[2] = rc[2][0..<3]; // Cut off trailing ".\n"
            if (IS_WIZARD(TP)) rc[2] += ", pero no hace nada desde hace "+i+" minutos";
            else if (i > 4) rc[2] += ", pero no hace nada desde hace tiempo";
            rc[2] += ".\n";
        }
    }
    else { // No estamos conectados
        rc[2] += ", pero está desconectado.\n";
    }
    return rc;
}

public varargs string Long(string what) {
    if (QueryGhost())
        return (Short() ? "Ves " : "No ves ")+(Short()||"nada")+".\n";
    return ::Long();
}

//----------------------------------------------------------------------------
