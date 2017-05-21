/**
 * SIMAURIA '/std/npc/moving.c'
 */

//------------------------------------------------------------------------------

#include <living.h>
#include <moving.h>

//------------------------------------------------------------------------------

inherit "/std/living/moving";

//------------------------------------------------------------------------------

private nosave int pGoChance;
private nosave string *WalkZones = ({});

//------------------------------------------------------------------------------

public void DropHeart(int user); // std/living/heart
public void GetHeart(int user);  // std/living/heart
public int CheckHeart(int user); // std/living/heart
public int QueryHeart();         // std/living/heart

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Query / Set
//------------------------------------------------------------------------------

public int QueryGoChance()    { return pGoChance; }
public int SetGoChance(int i) {
    if (i>0) {
        GetHeart(HEART_MOVING);
        pGoChance = i;
    }
    else {
        DropHeart(HEART_MOVING);
        pGoChance = 0;
    }
    return pGoChance;
}

//------------------------------------------------------------------------------

// Devuelve todas las zonas de paseo actuales.
public string *QueryWalkZones()     { return copy(WalkZones); }

// Establece las zonas permitidas de paseo.
// ({ }) para indicar todas, "" para indicar ninguna.
public string *SetWalkZones( mixed zones ) {
   if( !WalkZones ) WalkZones = ({ });
   if( !pointerp( zones ) ) {
      if( !stringp( zones ) ) return WalkZones;
      else zones = ({ zones });
   }
   else {
      filter(zones, SF(stringp));
   }

   WalkZones -= zones;
   WalkZones += zones;

   return WalkZones;
}

// Anyade una zona ( "path/archivo" ) o mas ( array de "path/archivo" )
public string *AddWalkZones( mixed zones ) {
   int i;

   if( !WalkZones ) WalkZones = ({ });
   if( !pointerp( zones ) ) {
      if( stringp( zones ) ) zones = ({ zones });
      else return WalkZones;
   }
   return SetWalkZones( WalkZones + zones );
}

// Elimina una zona ( "path/archivo" ) o mas ( array de "path/archivo" )
public string *RemoveWalkZones( mixed zones ) {
   int i;

   if( !WalkZones ) return ({ });
   if( !pointerp( zones ) ) {
      if( !stringp( zones ) ) return WalkZones;
      else zones = ({ zones });
   }
   return SetWalkZones( WalkZones - zones );
}

// Comprueba si hay "zonas de paseo" definidas antes de efectuar el movimiento.
// Si puede andar al destino devuelve >0, si no puede devuelve 0.
// Me he pencado el permitir el comodin *, si alguien se queja lo repondre.
public int QueryIsWalkZone(mixed dest) {
  return sizeof(WalkZones) ?
             sizeof( filter( WalkZones, (: strstr($2, resolve_file($1))==0 :),
                     resolve_file( stringp(dest)?dest:object_name(dest) ) ) )
         : 1;
}

//--------------------------------------------------------------------------
// Fin Query/Set
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Move
//--------------------------------------------------------------------------

public varargs int move(mixed dest, int method, mixed extra)
{
    if ((method == M_GO) && !QueryIsWalkZone(dest)) return ME_NO_LEAVE;
    return ::move(dest, method, extra);
}

//--------------------------------------------------------------------------
// Fin Move
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
// Init y Heart_Beat
//--------------------------------------------------------------------------

private static int _moves_done; // Movimientos que quedan hasta pararnos
#define MAX_MOVES   5

// Cada vez que entramos en contacto con un player reseteamos el _moves_left
init() {
    if (TP && interactive(TP)) {
        _moves_done = 0;
        GetHeart(HEART_MOVING);
    }
}

heart_beat() {

    if (!CheckHeart(HEART_MOVING)) return;

    if (!QueryGoChance() || _moves_done >= MAX_MOVES) {
        DropHeart(HEART_MOVING);
        return;
    }

    if (QueryGoChance() > random(1000)) {
        if (GoAway() && ++_moves_done >= MAX_MOVES) DropHeart(HEART_MOVING);
    }
}

//--------------------------------------------------------------------------
// Fin Init y Heart_Beat
//--------------------------------------------------------------------------
