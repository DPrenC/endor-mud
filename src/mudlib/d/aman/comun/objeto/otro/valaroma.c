/***************************************************************************************
 ARCHIVO:	valaróma.c
 AUTOR:	Orome
 FECHA:		05/04/2013
 Descripción:el cuerno de Oromë, falta que aulë le ponga la descripción correcta
 */

#include "/secure/wizlevels.h"
#include <messages.h>
#include <rooms.h>
#include <properties.h>
#include <combat.h>
#include <sounds.h>
#include <bandos.h>
inherit WEAPON;
#define PUNTOS_ANIMACION 100
#define PUNTOS_DESANIMACION   -PUNTOS_ANIMACION/4
create () {
 ::create();
   SetStandard(WT_MAZA, 0, P_SIZE_GENERIC, M_ESPECIAL);
  SetShort("el gran cuerno Valaróma");
  SetLong("Este es el Valaróma, el gran cuerno de los Valar propiedad de Oromë, el vala "
  "Cazador y Señor de los bosques.\n"
  "Cuando Oromë se lo lleva a los labios, una gran alegría y fervor se apodera de "
  "las criaturas de bien y el valor retorna a los corazones que hayan sucumbido a la "
  "desesperanza, pues su sonido es como  el ascenso del sol envuelto en una luz "
  "escarlata o un rayo surcando las nubes.\n"
  "Su potente llamada hace que los seres malignos  sean invadidos "
  "por el más absoluto terror y huyen a esconderse en lugares recónditos.\n"
  "Es un magnífico cuerno de más de medio metro, ligeramente curvado y ribeteado con "
  "bandas de la más pura plata con extraños símbolos grabados y la boca realizada "
  "en marfil.\n"
  "El amplio pabellón está grabado simulando el espeso ramaje de un bosque en el que "
  "hasta la última y más diminuta hoja aparece perfectamente tallada.\n"
  "Una suave luz blanca, casi imperceptible, emana del cuerno revelando el gran "
  "poder que alberga.\n");
  SetIds(({"cuerno", "valaroma", "valaróma"}));
  SetAds(({"gran"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
    SetWeight(2534);
  SetValue(3000000);
SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar el gran cuerno Valaróma al suelo.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "el cuerno de los Valar.\n");
}
public void init(){
  ::init();
  add_action("ftocar", "sonar");
    add_action("ftocar", "soplar");
    add_action("ftocar", "tocar");
}
/*
 Configuración de la función ftocar
 MIN_DRINK: el mínimo de QueryDrink() que has de tener para poder soplar. ¡Al final acabas con la garganta seca!
MAX_SCREAM_LENGHT cantidad de rooms en las que se dispersa el sonido
 DRINK_DECREASE: es el número que se restará al QueryDrink() cada vez que se sople el cuerno . Esto produce sed.
 TP_DECREASE: soplar cansa. número de TPs (Tired Points) que se han de consumir con cada soplido.
*/
#define MIN_DRINK 5
#define MAX_SCREAM_LENGHT 19
#define DRINK_DECREASE 3
#define TP_DECREASE 1

/* --- FUNCIONES --- */

// Func: _advance_dir(): Función privada que traduce el movimiento from
// (si es del tipo norte, sur, este, arriba...) a coordenadas de posición
// virtuales a partir de las coordenadas virtuales almacenadas en where.
//
private int *_advance_dir( string from, int *where )
{
   string str;
   int *dirs;

   // Copiamos where en dirs, que será el que modifiquemos y devolvamos.
      dirs = ({ where[0], where[1], where[2] });

   // Comprobamos que from es una salida conocida. Si lo es, nos devolverá
   // la forma breve correspondiente. Si no es conocida, la función
   // map_brief_exit() nos devolverá el mismo valor que el que le hemos
   // pasado. En este caso, no hacemos cambios en dirs.
   str = environment( TP )->map_brief_exit( from );
   if( from == str ) return dirs;

   // Miramos primero el "eje de las x"
      switch( str[0..0] )
   {
      case "n": dirs[0]++;
                break;
      case "s": dirs[0]--;
                break;
   }

   // Ahora, comprobamos los "ejes z e y"
   if( strlen( str ) > 1 ) str = str[1..1];
   else str = str[0..0];
   switch( str )
   {
      case "e": dirs[1]++;
                break;
      case "o": dirs[1]--;
                break;
      case "r": dirs[2]++;
                break;
      case "b": dirs[2]--;
                break;
   }
   return dirs;
}

// Func: _from_where() -> Función privada que devuelve la dirección de
// procedencia del grito en un string dependiendo de la posición representada
// por las coordenadas virtuales de la variable dirs.
//
private string _from_where( int *dirs )
{
   string str;

   // No tiene mas complicación que lo enrevesado que es. Únicamente se
   // comprueban las coordenadas almacenadas en dirs y, dependiendo de
   // éstas, se construye el string de retorno.
   //
   str = "desde ";
   if( !dirs[0] && !dirs[1] )
   {
      // ¿No no hemos movido? Eso es que alguna salida de las que nos han
      // llevado hasta aquí no era conocida.
      //
      if( !dirs[2] ) str += "algún sitio";
   }
   else str += "el ";

   // Eje x.
   //
   if( dirs[0] > 0 && dirs[1] >= 0 ) str += "sur";
   if( dirs[0] > 0 && dirs[1] < 0 ) str += "sur";
   if( dirs[0] < 0 )
   {
      if( !dirs[1] ) str += "norte";
      else
         if( dirs[1] < 0 ) str += "nor";
         else str += "nor";
   }

   // Eje y.
   //
   if( dirs[1] > 0 ) str += "oeste";
   if( dirs[1] < 0 ) str += "este";

   // Eje z.
   //
   if( dirs[2] && ( dirs[0] || dirs[1] ) ) str += " y ";
   if( dirs[2] > 0 ) str += "abajo";
   if( dirs[2] < 0 ) str += "arriba";

   return str;
}


// Func: _take_around_rooms() -> Función privada que coge la lista de
// salidas de la habitación room y añade los elementos que no estén en
// vrooms al mapping mrooms si no estaban ya. También almacena con cada
// salida, la "posición virtual" de ésta y un contador indicando qué
// llamada la ha generado.
//
private void _take_around_rooms( object room, mapping mrooms, mapping vrooms, mapping tmp, int *dirs, int count )
{
   string roomname, aux, *exits;
   int i;
   mapping exdata;

   // Recogemos todos los nombres de las salidas y datos referentes a éstas.
   //
   exdata = room->QueryOpenExits();
   if (!exdata) return;
   exits = m_indices( exdata );

   // Recorremos todas las salidas.
      for( i = 0; i < sizeof( exits ); i++ )
   {
      // Arreglamos el nombre del fichero al que apunta la salida para nuestro
      // uso.
      //
      if (!stringp(exdata[exits[i], EXIT_DEST])) continue;
      roomname = resolve_file( exdata[exits[i]] );
      if( sscanf( roomname, "%s.c", aux ) ) roomname = aux;

      // Si ya estaba este nombre en la lista de habitaciones visitadas vrooms
      // o en la de habitaciones reconocidas pero pendientes de visita mrooms,
      // o en la lista temporal tmp, no se hace nada. En caso contrario se
      // añade a la lista mrooms con sus coordenadas virtuales y su contador
      // de llamada.
      //
      if( !member(vrooms, roomname ) && !member(mrooms + tmp, roomname ) )
         mrooms += ([ roomname: _advance_dir( exits[i], dirs ); count ]);
   }
   return;
}

// Func: ftocar () -> Funcion Principal.
public int ftocar( string arg )
{
   int i, unload, *dirs;
   string plname, str, str2, exit, *aux;
   mapping mrooms, vrooms, tmp;
   object room;

   // Hagamos que el usuario efectivo sea el jugador que hace sonar el cuerno, no vaya a
   // ser que nos encontremos ese feo mensaje si no esta cargado algún
   // objeto necesario.
      seteuid( getuid() );
if(!arg || (arg!="cuerno" && arg!="valaroma" && arg!="valaróma"))
        return notify_fail("¿El qué?\n", NOTIFY_NOT_VALID);

   // Comprobamos que no tiene tanta sed como para no poder soplar. En caso de ser ainu, no importa la sed que tenga, se sopla de todas maneras.
      if( TP->QueryDrink() <= MIN_DRINK && !IS_LEARNER( TP ) )
   {
      write( "Tienes la boca demasiado reseca como para que puedas hacer sonar el Valaroma.\n" );
      if(!(TP->QueryInvis() || TP->QueryInwiz())){
      say(capitalize(TNAME)+" intenta soplar "+QueryShort()+", pero no consigue emitir sonido.\n");
    }
      return 1;
   }

   // Comprobamos que no está cansado para soplar. De ser ainu, no importa el cansancio que tenga, se sopla de todas maneras.
   if( TP->QueryTP() < TP_DECREASE && !IS_LEARNER( TP ) )
   {
      write( "Necesitas descansar para poder tocar el Valaróma.\n");
      if(!(TP->QueryInvis() || TP->QueryInwiz())){
      say(capitalize(TNAME)+" se lleva "+QueryShort()+" a la boca, pero no consigue "
      "tener suficiente fuerza para hacerlo sonar.\n");
    }
      return 1;
   }

   // Si no es ainu, se le añade un poco de sed y cansancio, por eso de soplar.
      if( !IS_LEARNER( TP ) )
   {
      TP->SetDrink( TP->QueryDrink() - DRINK_DECREASE );
      TP->SetTP( TP->QueryTP() - TP_DECREASE );
   }

   // Preparamos los mensajes de la habitación donde está el jugador que ha soplado y parte de los mensajes de las otras habitaciones.
   str = "  se lleva el gran cuerno Valaróma a los labios y sopla con fuerza.\n";
   str2 = " suena ";
   plname = capitalize( TP->QueryName() );

   // En caso de que el jugador sea invisible...
      if( TP->QueryInvis() || TP->QueryInwiz())
   {
      plname = QueryShort();
      str=" suena celestialmente.\n";
      i = 2;
   }
   else i = 1;

   //si no lo lleva empuñado no puede hacerlo sonar
      if(!TO->QueryEquipped())
   {
     write("Para hacer sonar el gran cuerno Valaróma deberás de empuñarlo primero.\n");
     if(!(TP->QueryInvis() || TP->QueryInwiz())){
      say(capitalize(TNAME)+" parece que quiere hacer sonar "+QueryShort()+", pero no lo "
      "tiene bien cogido y no lo consigue.\n");
    }
      return 1;
   }
   else
   {
      write( "Te llevas el gran cuerno a los labios y soplas con fuerza.\n"
	"El Valaróma vibra en tus manos cargado de poder y su tonante llamada se hace oír "
	"sobre cualquier otro sonido.\n" );
      str += "La poderosa voz de Valaróma retumba y reververa hasta que sus ecos se pierden en la "
	"lejanía.\n";
      str2 += "profundamente ";
      play_sound(ENV(TP), SOUND_OBJETOS("cuerno"));

tell_room(ENV(TP),plname + str,({TP}));

    filter(all_inventory(ENV(TP)), (:if (living($1))
        { //modifica las propiedades de quien oye el cuerno
            switch($1->QueryBando()){
                case P_BANDO_LUZ:
       if ($1->QueryHP() < $1->QueryMaxHP())  $1->AddHP(PUNTOS_ANIMACION);
        if ($1->QuerySP() < $1->QueryMaxSP())  $1->AddSP(PUNTOS_ANIMACION);
            tell_object($1,"Tu cuerpo y alma se llena de armonía.\n");
            break;
            case P_BANDO_OSCURIDAD:
                if ($1->QueryHP() > ($1->QueryMaxHP()/2))  $1->AddHP(PUNTOS_DESANIMACION);
         $1->AddSP(PUNTOS_DESANIMACION);
         tell_object($1,"Tu cuerpo y alma nota una gran nostalgia.\n");
            break;
            default:
                if ($1->QueryHP() < $1->QueryMaxHP())  $1->AddHP(PUNTOS_ANIMACION/5);
        if ($1->QuerySP() < $1->QueryMaxSP()) $1->AddSP(PUNTOS_ANIMACION/5);
            tell_object($1,"Notas una leve armonía.\n");
            break;
        }

    }
return 0;:));



}
   // Inicializamos el mapping de habitaciones recorridas, el mapping de
   // habitaciones conocidas que faltan por recorrer y las coordenadas
      room = environment( TP );
   vrooms = ([ resolve_file( object_name( room ) ): 0 ]);
   dirs = ({ 0, 0, 0 });
   i = MAX_SCREAM_LENGHT;
   mrooms = ([ ]);
   tmp = ([ ]);
   _take_around_rooms( room, mrooms, vrooms, tmp, dirs, i - 1 );

   // Aquí empieza el cotarro... el bucle, quiero decir. La llamada dentro
   // de la guarda devuelve la lista de habitaciones conocidas por recorrer.
   // Si no tiene ningún elemento, se para.
   //
   while( sizeof( mrooms ) )
   {
      // Cogemos el primer elemento del mapping de habitaciones conocidas por
      // recorrer. La i es el número de llamada que generó ese elemento, y
      // unload es si la habitación ha de ser descargada (por defecto no).
      //
      exit = m_indices( mrooms )[0];
      i = mrooms[exit,1];
      dirs = mrooms[exit,0];
      unload = 0;

      if( !room = find_object( exit ) )
         if( room = load_object( exit ) ) unload = 1;

      // Se visitó la habitación exit, asi que se deben actualizar las listas.
            vrooms += ([ exit: unload ]);
      mrooms -= ([ exit ]);

      // Aquí, si existe la habitación, se escupe el mensaje y se examinan sus
      // salidas...
      if( room )
      {
         str = str2 + _from_where( dirs );
         exit = str;
         exit += ".\n";
         if( i )
         {
                                    _take_around_rooms( room, tmp, vrooms, mrooms, dirs, i - 1 );
            str = exit;
         }
         else str += ", pero apenas se oye ya.\n";
                  tell_room(room, "Un cuerno" + str);
                  play_sound(room,SOUND_OBJETOS("cuerno"),0,i*5);

             filter(all_inventory(room), (:if (living($1))
        {
         //modifica las propiedades de quien oye el cuerno
            switch($1->QueryBando()){
                case P_BANDO_LUZ:
       if ($1->QueryHP() < $1->QueryMaxHP())  $1->AddHP((PUNTOS_ANIMACION/MAX_SCREAM_LENGHT)*i);
        if ($1->QuerySP() < $1->QueryMaxSP())  $1->AddSP((PUNTOS_ANIMACION/MAX_SCREAM_LENGHT)*i);
            tell_object($1,"Tu cuerpo y alma siente una cierta armonía.\n");
            break;
            case P_BANDO_OSCURIDAD:
                if ($1->QueryHP() > ($1->QueryMaxHP()/2))  $1->AddHP((PUNTOS_DESANIMACION/MAX_SCREAM_LENGHT)*i);
         $1->AddSP((PUNTOS_DESANIMACION/MAX_SCREAM_LENGHT)*i);
         tell_object($1,"Tu cuerpo y alma nota una relativa nostalgia.\n");
            break;
            default:
                if ($1->QueryHP() < $1->QueryMaxHP())  $1->AddHP(((PUNTOS_ANIMACION/4)/MAX_SCREAM_LENGHT)*i);
        if ($1->QuerySP() < $1->QueryMaxSP())  $1->AddSP(((PUNTOS_ANIMACION/4)/MAX_SCREAM_LENGHT)*i);
            tell_object($1,"Notas una leve armonía lejana.\n");
            break;
        }

    }
return 0;:));



      }

      // Si ya hemos acabado de recorrer las habitaciones del mapping mrooms,
      // empezamos a recorrer las que hemos ido almacenando en tmp, que son
      // las correspondientes a las salidas de las anteriores mrooms.
      //
      if( !sizeof( mrooms ) )
      {
         mrooms = tmp;
         tmp = ([ ]);
      }
   }

   // Aquí descargamos de la memoria aquellas habitaciones que no estuvieran cargadas antes de gritar.
      aux = m_indices( vrooms );
   for( i = 0; i < sizeof( aux ); i++ )
      if( vrooms[aux[i]] ) destruct( find_object( aux[i] ) );

   return 1;
}

