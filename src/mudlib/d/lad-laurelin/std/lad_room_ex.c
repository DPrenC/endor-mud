/*
   ##################################################################
   ## lad_room.c : Habitacion estandard para Lad Laurelin.         ##
   ## Creacion : 09/05/97. [g] Guybrush (davalgal@eui.upv.es)      ##
   ##                                   (guybrush@simauria.upv.es) ##
   ##                                                              ##
   ## Modificaciones: 19/05/97 [g] Modifica el inherit, la Short,  ##
   ##                la Long y la Locate.                          ##
   ##                 09/02/99 [g] Añade sonidos por defecto para  ##
   ##		     la habitacion standard segun hora del dia.    ##
   ##                 10/02/99 [g] Añade cosillas al init(), al	   ##
   ##		     Create() y añade las funciones _player_list() ##
   ##		     y spit_the_message().			   ##
   ##		      16/02/99 [g] Ultimas modificaciones al       ##
   ##		     sistema de chats de la habitacion standard.   ##
   ##		      18/02/99 [g] Retocadas las formulas de	   ##
   ##		     decision de presentacion de chat.		   ##
   ##		      06/03/99 [g] Nuevo retoque. Mas control.	   ##
   ##################################################################
*/


#include <nightday.h>

inherit "/d/lad-laurelin/std/lad_room";

private string *street_sounds, last_sound;
private int street_importance;

/* --- FUNCIONES EXTRA --- */

public string *QueryStreetSounds()
{   return street_sounds || ({ });   }

public string *SetStreetSounds( string *sounds )
{   return street_sounds = sounds;   }

public int QueryStreetImportance()
{   return street_importance;   }

public int SetStreetImportance( int importance )
{
   if( importance < 0 ) importance = 0;
   if( importance > 100 ) importance = 100;
   return street_importance = importance;
}

// Funcion privada que devuelve los jugadores que hay en la habitacion.
private object *_player_list()
{
   object *obj, *players;
   int i;

   players = ({ });
   obj = all_inventory( TO );
   for( i = 0; i < sizeof( obj ); i++ )
      if( living( obj[i] ) && query_once_interactive( obj[i] ) )
         players += ({ obj[i] });
   return players;
}

// Esta funcion se encarga de elegir el mensaje correspondiente segun la
// hora del dia, tipo de calle, etc.
public void spit_the_message( int flag )
{
   int chance, i, j, k, hour;
   string str, *strs, aux;
   object *players, *they_can_see, *they_cant_see;

   if( !street_importance || !street_sounds || !sizeof( street_sounds ) )
      return;
   players = _player_list();
   if( sizeof( players ) )
   {
      if( !find_object( "/obj/gameclock" ) && !load_object( "/obj/gameclock" ) )
         return;
      switch( "/obj/gameclock"->QueryState() )
      {
         case ND_NIGHT: chance = 80;
         	break;
         case ND_PREDAWN: chance = 70;
         	break;
         case ND_DAWN: chance = 60;
		break;
         case ND_SUNRISE: chance = 40;
         	break;
         case ND_PRENOON: chance = 20;
		break;
         case ND_DAY: chance = 0;
 		break;
         case ND_POSTNOON: chance = 10;
		break;
         case ND_PREFALL: chance = 30;
         	break;
         case ND_FALL: chance = 50;
         	break;
         case ND_PRENIGHT: chance = 70;
         	break;
      }

      strs = ({ });

      hour = query_boot_time();
      if( hour < 1 || hour > time() )
         return;
      hour = time() - hour;

      // Se escala el tiempo segun Simauria
      hour = hour * 24 / ( DAY_LENGTH / 3600 );
      i = hour / 3600 / 24;
      hour -= i * 3600 * 24;
      hour = hour / 3600;

      for( i = 0; i < sizeof( street_sounds ); i++ )
         if( sscanf( street_sounds[i], "%%%~d%!s" ) )
         {
            j = 0;
            k = 0;
            sscanf( street_sounds[i], "%%%d%%%d%s", j, k, str );
 	    if( hour >= j && hour <= k ) strs += ({ str });
 	 }
         else strs += ({ street_sounds[i] });
      if( sizeof( strs ) && !flag )
      {
         str = strs[ random( sizeof( strs ) ) ];
         sscanf( str, "%s|%s", str, aux );
         if( aux == "|" ) aux = str;
         they_can_see = ({ });
         they_cant_see = ({ });
         for( i = 0; i < sizeof( players ); i++ )
            if( players[i]->CanSee() ) they_can_see += ({ players[i] });
            else they_cant_see += ({ players[i] });
         tell_room( TO, str, they_cant_see );
         if( aux ) tell_room( TO, aux, they_can_see );
      }
      chance += 100 - street_importance;
      chance = ( chance * 100 ) / 180;
      call_out( "spit_the_message", (chance>0?chance:1), 0 );
   }
   return;
}

create()
{
   ::create();

   // Por defecto no hay sonidos y la concurrencia de la calle es nula.
   SetStreetSounds( ({ }) );
   SetStreetImportance( 0 );
}

init()
{
   ::init();
   // Cada vez que entre un jugador en la habitación, si es el unico, entonces
   // hara el callout correspondiente para iniciar los "chats" (en caso de que
   // hayan "chats"). Si ya habian jugadores, significa que el callout ya se
   // hizo en su momento (por lo que ya no hay que hacerlo)
   if( sizeof( _player_list() ) < 2 && street_importance &&
       street_sounds && sizeof( street_sounds ) )
      call_out( "spit_the_message", 0, 1 );
}
