/*
	ENDOR: "/bin/mortal/_gritar"
	===============================================
          Sintaxis  : gritar [<string>]
	     [<string>] : Es opcional. Se trata de lo
	                  que quieres gritar. Si no
	                  pones nada, simplemente
	                  gritas.
	cambiar los mensajes de la funci�n main para personalizarlo a endor-mud
	*/

// Includes:
//
#include "/secure/wizlevels.h"
#include <messages.h>
#include <rooms.h>

/*
 Configuraci�n del _gritar.c
 MIN_DRINK: el m�nimo de QueryDrink() que has de tener para poder gritar. �Al final acabas con la garganta seca!
 MAX_DEPTH_RECURSION: cu�ntas habitaciones se recorre tu grito (para evitar
 que se oiga el mismo grito m�s de una vez en la misma habitaci�n)
 DRINK_DECREASE: es el n�mero que se restar� al QueryDrink() cada vez que se grite. Esto produce sed.
 TP_DECREASE: Gritar cansa. S�, pru�balo y ver�s. As� que esto es el
 n�mero de TPs (Tired Points) que se han de consumir con cada grito.
*/
#define MIN_DRINK 5
#define MAX_SCREAM_LENGHT 3
#define DRINK_DECREASE 3
#define TP_DECREASE 1

/* --- FUNCIONES --- */

// Func: _advance_dir(): Funci�n privada que traduce el movimiento from
// (si es del tipo norte, sur, este, arriba...) a coordenadas de posici�n
// virtuales a partir de las coordenadas virtuales almacenadas en where.
//
private int *_advance_dir( string from, int *where )
{
   string str;
   int *dirs;

   // Copiamos where en dirs, que ser� el que modifiquemos y devolvamos.
      dirs = ({ where[0], where[1], where[2] });

   // Comprobamos que from es una salida conocida. Si lo es, nos devolver�
   // la forma breve correspondiente. Si no es conocida, la funci�n
   // map_brief_exit() nos devolver� el mismo valor que el que le hemos
   // pasado. En este caso, no hacemos cambios en dirs.
   str = environment( TP )->map_brief_exit( from );
   if( from == str ) return dirs;

   // Miramos primero el "eje de las x"
   //
   switch( str[0..0] )
   {
      case "n": dirs[0]++;
                break;
      case "s": dirs[0]--;
                break;
   }

   // Ahora, comprobamos los "ejes z e y"
   //
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

// Func: _from_where() -> Funci�n privada que devuelve la direcci�n de
// procedencia del grito en un string dependiendo de la posici�n representada
// por las coordenadas virtuales de la variable dirs.
//
private string _from_where( int *dirs )
{
   string str;

   // No tiene mas complicaci�n que lo enrevesado que es. �nicamente se
   // comprueban las coordenadas almacenadas en dirs y, dependiendo de
   // �stas, se construye el string de retorno.
   //
   str = "desde ";
   if( !dirs[0] && !dirs[1] )
   {
      // �No no hemos movido? Eso es que alguna salida de las que nos han
      // llevado hasta aqu� no era conocida.
      //
      if( !dirs[2] ) str += "alg�n sitio";
   }
   else str += "el ";

   // Eje x.
   //
   if( dirs[0] > 0 && dirs[1] >= 0 ) str += "sur";
   if( dirs[0] > 0 && dirs[1] < 0 ) str += "sud";
   if( dirs[0] < 0 )
   {
      if( !dirs[1] ) str += "norte";
      else
         if( dirs[1] < 0 ) str += "nord";
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


// Func: _take_around_rooms() -> Funci�n privada que coge la lista de
// salidas de la habitaci�n room y a�ade los elementos que no est�n en
// vrooms al mapping mrooms si no estaban ya. Tambi�n almacena con cada
// salida, la "posici�n virtual" de �sta y un contador indicando qu�
// llamada la ha generado.
//
private void _take_around_rooms( object room, mapping mrooms, mapping vrooms, mapping tmp, int *dirs, int count )
{
   string roomname, aux, *exits;
   int i;
   mapping exdata;

   // Recogemos todos los nombres de las salidas y datos referentes a �stas.
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
      // a�ade a la lista mrooms con sus coordenadas virtuales y su contador
      // de llamada.
      //
      if( !member(vrooms, roomname ) && !member(mrooms + tmp, roomname ) )
         mrooms += ([ roomname: _advance_dir( exits[i], dirs ); count ]);
   }
   return;
}

// Func: main() -> Funcion Principal.
int main( string scream )
{
   int i, unload, *dirs;
   string plname, str, str2, exit, *aux;
   mapping mrooms, vrooms, tmp;
   object room;

   // Hagamos que el usuario efectivo sea el jugador que grita, no vaya a
   // ser que nos encontremos ese feo mensaje si no esta cargado alg�n
   // objeto necesario.
      seteuid( getuid() );

   // Comprobamos que no tiene tanta sed como para no poder gritar. En caso
   // de ser Wizard, no importa la sed que tenga, se grita de todas maneras.
      if( TP->QueryDrink() <= MIN_DRINK && !IS_LEARNER( TP ) )
   {
      write( "Tienes demasiada sed y tu garganta est� demasiado seca como para que "
      "puedas gritar y solo emites un desagradable graznido.\n" );
      say(capitalize(TNAME)+" parece que quiere gritar, pero solo le sale un rid�culo graznido.\n");
      return 1;
   }

   // Comprobamos que no est� cansado para gritar. De ser Wizard, no importa
   // el cansancio que tenga, se grita de todas maneras.
   if( TP->QueryTP() < TP_DECREASE && !IS_LEARNER( TP ) )
   {
      write( "Tu agotamiento es tal que no tienes fuerzas ni para gritar.\n" );
      say(capitalize(TNAME)+" hace un amago de gritar, pero no emite ning�n sonido.\n");
      return 1;
   }

   // Si no es Wizard, se le a�ade un poco de sed y cansancio, por eso de
   // gritar.
      if( !IS_LEARNER( TP ) )
   {
      TP->SetDrink( TP->QueryDrink() - DRINK_DECREASE );
      TP->SetTP( TP->QueryTP() - TP_DECREASE );
   }

   // Preparamos los mensajes de la habitaci�n donde est� el jugador que
   // ha gritado y parte de los mensajes de las otras habitaciones.
   str = " grita";
   str2 = " grita ";
   plname = capitalize( TP->QueryRealName() );

   // En caso de que el jugador sea invisible...
   //
   if( TP->QueryInvis() )
   {
      plname = "(" + plname + ")";
      i = 2;
   }
   else i = 1;

   // Dependiendo si hay que gritar alguna frase, se oir� una cosa u otra.
   //
   if( scream && scream != "" )
   {
      write( "Tomas aire y gritas: " + scream + "\n" );
      str += ": " + scream + "\n" ;
   }
   else
   {
      write( "Tomas aire y lanzas un grito desgarrador.\n" );
      str += " muy fuerte.\n";
      str2 += "muy fuerte ";
   }

   tell_room(ENV(TP),({MSG_SEE,plname + str, ({MSG_HEAR, "Alguien" + str})}),({TP}));

   // Inicializamos el mapping de habitaciones recorridas, el mapping de
   // habitaciones conocidas que faltan por recorrer y las coordenadas,
   // entre otras cosas.
      room = environment( TP );
   vrooms = ([ resolve_file( object_name( room ) ): 0 ]);
   dirs = ({ 0, 0, 0 });
   i = MAX_SCREAM_LENGHT;
   mrooms = ([ ]);
   tmp = ([ ]);
   _take_around_rooms( room, mrooms, vrooms, tmp, dirs, i - 1 );

   // Aqu� empieza el cotarro... el bucle, quiero decir. La llamada dentro
   // de la guarda devuelve la lista de habitaciones conocidas por recorrer.
   // Si no tiene ning�n elemento, se para.
   //
   while( sizeof( mrooms ) )
   {
      // Cogemos el primer elemento del mapping de habitaciones conocidas por
      // recorrer. La i es el n�mero de llamada que gener� ese elemento, y
      // unload es si la habitaci�n ha de ser descargada (por defecto no).
      //
      exit = m_indices( mrooms )[0];
      i = mrooms[exit,1];
      dirs = mrooms[exit,0];
      unload = 0;

      if( !room = find_object( exit ) )
         if( room = load_object( exit ) ) unload = 1;

      // Se visit� la habitaci�n exit, asi que se deben actualizar las listas.
      //
      vrooms += ([ exit: unload ]);
      mrooms -= ([ exit ]);

      // Aqu�, si existe la habitaci�n, se escupe el mensaje y se examinan sus
      // salidas...
      if( room )
      {
         str = str2 + _from_where( dirs );
         exit = str;
         exit += ( scream?": " + scream:"." ) + "\n";
         if( i )
         {
            _take_around_rooms( room, tmp, vrooms, mrooms, dirs, i - 1 );
            str = exit;
         }
         else str += ", mas no aciertas a discernir ninguna palabra con claridad.\n";
         // dtell("orome",sprintf("plname es %s, exit es %s, y str es %s.\n",plname, exit, str));
         tell_room(room, "Alguien" + str);
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

   // Aqu� descargamos de la memoria aquellas habitaciones que no estuvieran
   // cargadas antes de gritar.
   //
   aux = m_indices( vrooms );
   for( i = 0; i < sizeof( aux ); i++ )
      if( vrooms[aux[i]] ) destruct( find_object( aux[i] ) );

   return 1;
}