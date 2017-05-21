/**
 * SIMAURIA '/std/room/description.c'
 */

#include <properties.h>
#include <nightday.h> // nightday
#include <weather.h> // weather
#include <files.h>
#include <config.h> // MAX_SUNBRIGHT, q movida...
#include <sounds.h>

inherit "/std/container/description";

//--- global variables ------------------------------------------------------

private static mixed Pexplorable;

private static mixed Pserver = NIGHTDAY;
private static string PclimateServer = CHRONOS;
private static int Pindoors = 1, Psunbright = MAX_SUNBRIGHT, Psafe = 0;
private static mixed pSoundEnvironment;
private static int pSoundEnvironmentVolume = SOUND_ENV_VOLUME;
private static string *pServerNotifications;

//---------------------------------------------------------------------------

//--- the querying and setting functions ------------------------------------

public int QueryIndoors()    { return Pindoors; }
public int SetIndoors(int i) { return Pindoors = i; }

public int QuerySafe()       { return Psafe; }
public int SetSafe(int i)    { return i?Psafe=1:Psafe=0; }

public mixed QueryExplorable()         { return Pexplorable; }
public mixed SetExplorable(mixed m)    { return Pexplorable = m; }

public string QueryServer()  { return Pserver; }
public string SetServer (mixed sv) {
    if (objectp(sv)) sv = object_name(sv);
    return Pserver = sv;
}

public varargs mixed QueryOutdoors() { return QueryIndoors() ? 0 : Pserver; }
public mixed SetOutdoors(mixed i) {
    if (i && intp(i)) i = NIGHTDAY;
    SetIndoors(!i);
    return SetServer(i);
}

public mixed * QueryDayData() {
    if (!Pserver) return 0;
    return Pserver->QueryStateData();
}

public int QueryDayState() {
    if (!Pserver) return 0;
    return Pserver->QueryState();
}

public string QueryDayDesc() {
    if (!Pserver) return "";
    return Pserver->QueryStateDesc();
}

public int QuerySunBright()     { return Psunbright; }
public int SetSunBright(int s)  { return Psunbright = s; }

public int QuerySunLight() {
  mixed in;
  return (in = QueryOutdoors())
           ? (QuerySunBright() * in->QuerySunLight()) / MAX_SUNBRIGHT
           : 0;
}

public varargs int QueryIntLight(int nosun) {
    if (nosun) return ::QueryIntLight();
//    return max(::QueryIntLight(), QuerySunLight());
// Ahora ha cambiado y hago la suma de todo...
    return ::QueryIntLight() + QuerySunLight();
}

public string SetClimateServer(mixed sv)
{
    if (!sv) return PclimateServer;
    if (objectp(sv)) sv = object_name(sv);
    return PclimateServer = sv;
}
public string QueryClimateServer() { return PclimateServer; }
public varargs mixed SetSoundEnvironment(mixed sound, int volume)
{
    if (sound && !stringp(sound) && !closurep(sound)) return pSoundEnvironment;
    pSoundEnvironment = sound;
    if (volume)
    {
        if (volume > 100) volume = 100;
        else if (volume < 1) volume = 1;
        pSoundEnvironmentVolume = volume;
    }
    return pSoundEnvironment;
}
public string QuerySoundEnvironment() { return pSoundEnvironment; }

public int SetSoundEnvironmentVolume(int v) { return pSoundEnvironmentVolume = v; }
public int QuerySoundEnvironmentVolume() { return pSoundEnvironmentVolume; }

public string *SetServerNotifications(string *s) { return pServerNotifications = s; }
public string *QueryServerNotifications() { return copy(pServerNotifications); }

public int AddServerNotification(string room)
{
    room = resolve_file(room);
    if (room[<2..] == ".c") room = room[..<3];
    if (pServerNotifications && member(pServerNotifications, room) >= 0) return 0;
    if (file_size(room + ".c") == FSIZE_NOFILE) return 0;
    if (!pServerNotifications) pServerNotifications = ({room});
    else pServerNotifications += ({room});
    return 1;
}
public int RemoveServerNotification(string room)
{
    room = resolve_file(room);
    if (!pServerNotifications || member(pServerNotifications, room) < 0) return 0;
    pServerNotifications -= ({room});
    return 1;
}


//--- Exploration -----------------------------------------------------

public mixed AddExplorable (mixed new)
{
  if (!Pexplorable) return Pexplorable = new;
  if (!pointerp(Pexplorable)) return Pexplorable = ({ Pexplorable, new });
  return Pexplorable += ({ new });
}

public varargs int DoExplore(mixed arg)
{
    if (   !Pexplorable
      || (!pointerp(Pexplorable) ? (arg != Pexplorable)
                                 : (-1 == member(Pexplorable, arg))
         )
      || !TP
      || (-1 == member(deep_inventory(TO), TP))
     )
    return 0;
    TP->SetExplored();
  return 1;
}
// Notificaciones del clima:

public void NotifyDayStateChange(mixed data, int newstate)
{
    if (!Pindoors && data) tell_room(TO, data[WD_CDESC]);
}

