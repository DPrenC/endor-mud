#include <wizlevels.h>

// DEFS

// Normal Level Funcions:
#define NOCOMM  -1
#define HELP	0
#define CANCEL	1
#define FINISH	2
#define LIST	3
#define AVAIBLE ({ ({ "~ayuda", "~a", "Muestra esta ayuda." }), ({ "~cancelar", "~c", "Para cancelar el graffitti." }), ({ "~terminar", "~t", "Para indicar que se ha terminado." }), ({ "~listar", "~l", "Para ver lo que hay hecho." }) })

// High Level Functions:
#define ANONYM	-2
#define AVAIBLE_HIGH ({ ({ "~anonimo", "~an", "Para que el graffitti sea anonimo" }) })

// Private vars.
private int anonymous, lines;
private string *graffittilines;
private object place;

// main(): Main function.
main( string arg )
{
   object pl;

   anonymous = 0;
   if( arg )
   {
      pl = find_object(lower_case(arg));
      if( !pl )
      {
         notify_fail( "No encuentro ningun '" + arg + "' conectado.\n" );
         return 0;
      }
      place = environment( pl );
   }
   else
      place = environment( TP );
   write( "Escribe tu graffitti ('" + AVAIBLE[HELP][1] + "' o '" + AVAIBLE[HELP][0] + "' para ayuda):\n" );
   write( "1# " );
   lines = 1;
   graffittilines = ({ });
   input_to( "get_graffitti", 0 );
   return 1;
}

cancel_graffitti()
{
   write( "Graffitti cancelado.\n" );
   return;
}

write_graffitti()
{
   string graffitti;

   if( lines - 1 )
   {
      graffitti = "Hay un graffitti" + (anonymous?"":" escrito por " +
   		  capitalize( TP->QueryRealName() ) ) + " que dice:\n";
      graffitti += implode( graffittilines, "\n" ) + "\n";
      graffitti = funcall( graffitti );
      if( place->QueryIndoors() )
      {
         place->SetIntShort( place->QueryIntShort() + graffitti );
         place->SetIntLong( place->QueryIntLong() + graffitti );
      }
      else
      {
         place->SetShort( place->QueryShort() + graffitti );
         place->SetLong( place->QueryLong() + graffitti );
      }
      write( "Graffitti escrito.\n" );
   }
   else
      cancel_graffitti();
   return;
}

// get_graffitti(): Getting a cool graffitti ;)
get_graffitti( string str )
{
   int i, j, option;

   option = NOCOMM;

   // Scan for a normal selection.
   for( i = 0; i < sizeof( AVAIBLE ); i++ )
      if ( member(AVAIBLE[i], str ) != -1 ) option = i;

   // If no selection and level enough, scan for a high selection.
   if( option == -1 && IS_ARCH( TP ) )
      for( i = 0; i < sizeof( AVAIBLE_HIGH ); i++ )
         if ( member(AVAIBLE_HIGH[i], str ) != -1 ) option = -i-2;

   switch( option )
   {
      case CANCEL:
	cancel_graffitti();
	return;
	break;
      case FINISH:
	write_graffitti( graffittilines, place );
	return;
	break;
      case HELP:
        write( "Comando\t\tAbreviado\tAccion\n=======\t\t=========\t======\n" );
 	for( i = 0; i < sizeof( AVAIBLE ); i++ )
 	{
 	   for( j = 0; j < sizeof( AVAIBLE[i] ); j++ )
 	   {
 	      if( j ) write( (strlen(AVAIBLE[i][j-1])<8?"\t":"") + "\t" );
 	      write( AVAIBLE[i][j] );
 	   }
 	   write( "\b\n" );
 	}
 	if( IS_ARCH( TP ) )
 	for( i = 0; i < sizeof( AVAIBLE_HIGH ); i++ )
 	{
 	   for( j = 0; j < sizeof( AVAIBLE_HIGH[i] ); j++ )
 	   {
 	      if( j ) write( (strlen(AVAIBLE_HIGH[i][j-1])<8?"\t":"") + "\t" );
 	      write( AVAIBLE_HIGH[i][j] );
 	   }
 	   write( " (Arch&God)\n" );
 	}
	write( "Ademas, para poder ejecutar comandos de mud sin interrumpir el graffitti,\n" +
	       "puedes poner '!<comando>'.\n" );
 	break;
      case LIST:
        if( !( lines - 1 ) )
           write( "No has escrito nada todavia.\n" );
        else
           write( "Este es tu graffitti, por el momento:\n" );
 	for( i = 0; i < lines-1; i++ )
 	   write( " " + ( i + 1 ) + ": " + graffittilines[i] + "\n" );
      	break;
      case ANONYM:
	if( anonymous ) anonymous = 0;
	else anonymous = 1;
	write( "Modo " + (anonymous?"anonimo":"normal") + ".\n" );
	break;
      default:
	graffittilines += ({ str });
	lines++;
   }

   write( lines + "# " );
   input_to( "get_graffitti", 0 );
   return;
}