/**
 * SIMAURIA '/std/room/restrictions.c'
 */

#include <magia.h>
#include <sounds.h>

#include <properties.h> // Para lo del final q quiero borrar
#include <messages.h>   // Para lo del final q quiero borrar

inherit "/std/container/restrictions";

private static mapping PmagicProt = ([]);

//--- Magic restrictions and modifications -----------------------------------

public mapping QueryMagicProtection() {
  return PmagicProt;
}
public mapping SetMagicProtection(mapping m) {
  if (mappingp(m)) PmagicProt = copy(m);
  return QueryMagicProtection();
}
public string AddMagicProtection(int type, string message) {
  PmagicProt[type] = message;
  return PmagicProt[type];
}
public varargs mapping ForbidAllMagic(string str) {
  if (!stringp(str)) str = "Aquí no puedes usar magia...\n";
  SetMagicProtection(([ST_ALL:str]));
  return QueryMagicProtection();
}
public string QueryIsMagicForbidden(int type) {
  return PmagicProt && (PmagicProt[type] || PmagicProt[ST_ALL]);
}

public void notify_enter(mixed from, int method, mixed extra)
// si la habitación tiene sonido de ambiente, lo reproducimos
{
    mixed sonido;
    ::notify_enter(from, method, extra);
    if (   PO && query_once_interactive(PO) && PO->QuerySoundEnvironment()
        && sonido = TO->QuerySoundEnvironment())
    {
        play_sound(PO, funcall(sonido), 0, TO->QuerySoundEnvironmentVolume(), -1);
    }
}


public void notify_leave(mixed to, int method, mixed extra)
// quitamos el sonido de ambiente, si lo hubiese
{
    string sonido;
    ::notify_leave(to, method, extra);
    if (PO && query_once_interactive(PO) && sonido = TO->QuerySoundEnvironment())
    {
        if (PO->QuerySoundEnvironment())
        {
            stop_music(PO);
            stop_sounds(PO);
        }

    }
}




