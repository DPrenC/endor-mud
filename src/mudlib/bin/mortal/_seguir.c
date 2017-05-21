/*************************************************************************/
/*  Fichero: cordel.c                                                    */
/*  Fichero Modificado: _seguir.c                                        */
/*  Creacion: 4 de Noviembre de 1998                                     */
/*  Ultimas modificaciones:                                              */
/*    5 Nov, 1998. [I]  Modificadas la funcion EmpezarSeguir() para      */
/*                      no seguir a un jugador si este hace un teleport. */
/*    6 Nov, 1998. [I]  Cambiada la funcion EmpezarSeguir(). Ahora no    */
/*                      chequeara si el entorno del jugador1 es igual    */
/*                      al entorno del jugador2 para iniciar el segui-   */
/*                      miento.                                          */
/*    10 Nov, 1998 [T]  Theuzifan: cambia la funcion EmpezarSeguir, para */
/*			que tan solo sigua a un player a otras 		 */
/*			habitaciones, y pare si hace un trans. Aparte    */
/*			anyado el comando 'parar de seguir' que respeta  */
/*			el 'parar' anterior (de espiar, de perseguir...) */
/*   11 Nov, 1998.  [I]  Modificado para insertar en /bin/mortal         */
/*   16 Abr, 2001   [H] Cambiao casi todo				 */
/*                      /std/thing/moving.c, /std/player.c, /sys/moving.h*/
/*			si asin no funciona, no lo hara nunca...	 */
/*   09 Nov, 2003   [H] Hastaloscojones, lo desactivo                    */
/*   [I] Izet@Simauria.                                                  */
/*   [T] Theuzifan@Simauria.                                             */
/*   [H] Nyh@Simauria                                                    */
/*************************************************************************/
/* Nota del Nyh: Como antes parecia no rular (y he visto que usaba
   call_outs de 0, que miedo...) pos he intentao arreglarlo desde la raiz,
   usease, me he metido en el /std/thing/moving.c y he cambiao unas cositas.
   Tambien he añadio algun define en el /sys/moving.h y para poder parar de
   seguir a gusto me he metido en el /std/player.c
   Si asin no funciona... no creo que se pueda hacer funcionar...
   Cruzad los dedos, que voy al Simtest...
*/
#include <moving.h>
#include <properties.h>
#include <wizlevels.h>

int seguir(string str) {
object jugador1;

   //return notify_fail("Este comando ha sido temporalmente desactivado.\n");

   if (TP->Query(P_IS_FOLLOWER)) {//Chekeo del Nyh
      write("Ya estas siguiendo los pasos de alguien.\n");
      return 1;
   }
   if (!str) {
      write("A quien quieres seguir?\n");
      return 1;
   }
   if (!jugador1 = find_object(lower_case(str)) ) {
      write("¿A quién quieres seguir?\n");
      return 1;
   }
   if (!present(jugador1, environment(TP ) ) ) {
      write(""+capitalize(str)+" no está aquí.\n");
      return 1;
   }
   if (!interactive(jugador1) ) {
      write("No puedes seguir a 'eso'.\n");
      return 1;
   }
   if (!query_once_interactive(jugador1) ) {
      write("No puedes seguir a una estatua.\n");
      return 1;
   }
   if (jugador1 == TP ) {
      write("Persigues a tu sombra...\n");
      return 1;
   }
   write("Sigues a "+capitalize(str)+".\n");

  if(!(TP->QueryInvis() > jugador1->QuerySeeInvis()))
  {
  tell_object(jugador1,TP->QueryName()+" empieza a seguirte.\n");
	//quito lo del mensaje a la habitacion y lo de que si no
	//ve invis pone alguien empieza a seguirte
  }
  //NOTA: lo he cambiado, ahora si eres wiz te pone que le sigues
  // con FOLLOW_ALWAYS, si NO te pone que le sigues con FOLLOW_NORMAL
  jugador1->AddFollower(TP,IS_LEARNER(TP)?FOLLOW_ALWAYS:FOLLOW_NORMAL);
  return 1;
}
