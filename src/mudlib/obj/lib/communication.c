/*
        SIMAURIA [/obj/lib/comunication.c]
        ========

          [g] Guybrush (email: guybrush@simauria.upv.es)
	  [n] Nemesis@Simauria

	30/11/98 [g] Anyade TellMASTER().
	Mar'99 [n] Castellanizado.
	17/03/99 [g] Anyade nueva función al TellMASTER().
	28/04/99 [g] Añade nuevas posibilidades al TellMASTER().

** /obj/lib/communication.c
** Used to do several things to emote, say something, etc.
**
** 19jun95 [t] Creation
**
** [t] Thragor@Nightfall
*/
#include <wizlevels.h>
#include <messages.h>

inherit STR;

public varargs string Name(int cap)
// Write this function into your file inheriting /obj/lib/communication
// to evaluate the correct name of the person emoting, speaking, etc.
// If 'cap' is !=0 the name should be returned capitalized.
{
  string name;
  name = TO->QueryName()||"alguien";
  return cap?capitalize(name):name;
}

public varargs string PlName(string cap)
// Used for process_string to determine the name of the player.
// To give 'cap' in the string use: @@PlName|1@@
{
  string name;
  name = TP?TP->QueryName():"alguien";
  return cap?capitalize(name):name;
}

public varargs string PlPronoun(string cap)
// Used for process_string to determine the pronoun of the player.
// To give 'cap' in the string use: @@PlPronoun|1@@
{
  string pron;
  pron = TP?TP->QueryPronoun():"they";
  return cap?capitalize(pron):pron;
}

public string PlPossessive(string cap)
// Used for process_string to determine the possessive pronoun of the player.
// To give 'cap' in the string use: @@PlPossessive|1@@
{
  string poss;
  poss = TP?TP->QueryPossessive():"su";
  return cap?capitalize(poss):poss;
}

public string PlObjective(string cap)
// Used for process_string to determine the objective pronoun of the player.
// To give 'cap' in the string use: @@PlObjective|1@@
{
  string obj;
  obj = TP?TP->QueryObjective():"them";
  return cap?capitalize(obj):obj;
}

/* // [Nyh] En español no hay genitivos
public string PlGenitive(string cap)
// Used for process_string to determine the objective pronoun of the player.
// To give 'cap' in the string use: @@PlGenitive|1@@
{
  string gen;
  gen = add_gen(TP?TP->QueryName():"alguien");
  return cap?capitalize(gen):gen;
}
*/

public string parse_string(string str)
{
  int pos;
  string msg;
  msg = process_string(str);
  pos = strlen(msg)-1;
  while(msg[pos--]==' ');
  msg = msg[0..pos+1];
  if (member(({'.','!','?','"',39,'>','<','\n'}),msg[<1])==-1)
    msg+=".";
  if (msg[<1]!='\n')
    msg+="\n";
  return msg;
}

public void Emote(mixed message)
// The head of the message will be the result of Name():
// <Name> <message>.\n.
// If no punctuation-mark and no newline is given ".\n"
// will be appended, if just the newline is missing this
// will be appended.
// sizeof(<message>):
// 1: it's handled as if it is just a string;
// 2: the first message is printed to the player and the
//    second one to her/his environment;
// 3: the first message is printed to the player, the second
//    one to all persons in the environment who can see and
//    the third one to all who can't;
// 4: the first message is printed to the player if (s)he can
//    see, the second one if (s)he can't, the third one to
//    the environment who can see and the last one to the
//    environment who can't.
// If the message is a closure, this will be called and the
// result interpreted in the way mentioned above.
// The closure function will be called with TP and
// Name() as arguments.
// If the function called already handled the output, it should
// return 0 as result, else a string or an array of strings.
{
  mixed ms;
  if (!TP) return;
  if (closurep(message))
    ms = funcall(message,TP,Name());
  else
    ms = message;
  if (stringp(ms))
    write(Name()+" "+ms);
  else
    if (pointerp(ms))
      {
        switch(sizeof(ms))
	  {
	   case 0:
	    break;
	   case 1:
	    write(ms[0]?wrap(Name(1)+" "+parse_string(ms[0]),0,3):"");
	    break;
	   case 2:
	    write(wrap(Name(1)+" "+parse_string(ms[0]),0,3));
	    say(ms[1]?wrap(Name(1)+" "+parse_string(ms[1]),0,3):"");
	    break;
	   case 3:
	    write(ms[0]?wrap(Name(1)+" "+parse_string(ms[0]),0,3):"");
	    tell_room(environment(TP), ({ MSG_SEE
	                                , ms[1]?wrap(Name(1)+" "+parse_string(ms[1]),0,3):""
	                                , ms[2]?wrap("Alguien "+parse_string(ms[2]),0,3):""}), ({ TP }));
	    break;
	   default:
	    tell_object(TP, ({ MSG_SEE
	                     , ms[0]?wrap(Name(1)+" "+parse_string(ms[0]),0,3):""
	                     , ms[1]?wrap("Alguien "+parse_string(ms[1]),0,3):""}));
	    tell_room(environment(TP), ({ MSG_SEE
	                                , ms[2]?wrap(Name(1)+" "+parse_string(ms[2]),0,3):""
	                                , ms[3]?wrap("Alguien "+parse_string(ms[3]),0,3):""}), ({ TP }));
	  }
      }
}

public void Say(mixed message)
// The message will be printed like the rules of Emote(), but you may
// just give one string as argument.
// The result of Name() and " says: " will be printed in front of the
// message.
{
  string ms;
  if (!TP||!environment(TP)) return;
  if (closurep(message))
    ms = funcall(message,TP,Name());
  else
    ms = message;
  if (stringp(ms))
    {
      tell_object(TP, ({ MSG_SEE
                       , wrap(Name(1)+" dice: "+parse_string(ms),0,3)
                       , wrap("Alguien dice: "+parse_string(ms),0,3)}));
      tell_room(environment(TP), ({ MSG_SEE
                                  , wrap(Name(1)+" dice: "+parse_string(ms),0,3)
                                , wrap("Alguien dice: "+parse_string(ms),0,3)}), ({ TP }) );
    }
}

// TellMASTER(): Dice los mensajes para cada tipo de receptor (jug a jugadores,
//               wiz a wizards y nove a jugadores que no ven)
public varargs void TellMASTER( mixed jug, mixed wiz, mixed nove, mixed lugar, object pl )
{
   object *lista, aux;
   int i, straux;

   if( !lugar ) lugar = environment( TP );
   else
   {
      if( !objectp( lugar ) )
      {
         aux = find_object( lugar );
         if( !aux ) if( !( aux = find_object( lower_case((string)lugar) ) ) ) return 0;
         lugar = aux;
      }
      if( living( lugar ) )
      {
         if( pl ) return 0;
         pl = lugar;
         lugar = environment( TP );
      }
   }
   if( !pl ) pl = TP;
   if( jug == 0 || !jug ) jug = "";
   if( jug == 1 ) jug = wiz;
   if( jug == 2 ) jug = nove;
   if( wiz == 0 || !wiz ) wiz = "";
   if( wiz == 1 ) wiz = jug;
   if( wiz == 2 ) wiz = nove;
   if( nove == 0 || !nove ) nove = "";
   if( nove == 1 ) nove = jug;
   if( nove == 2 ) nove = wiz;
   lista = all_inventory( lugar );

   for( i = 0; i < sizeof( lista ); i++ )
   {
      if( find_object( lista[i]->QueryRealName()||"" ) )
      {
         if( lista[i] != pl )
            if( !IS_LEARNER( lista[i] ) )
            {
               if( lista[i]->CantSee()&&nove )
                  tell_object( lista[i], wrap( nove,78 ) );
               if( lista[i]->CanSee()&&jug )
                  tell_object( lista[i], wrap( jug,78 ) );
            }
            else
               if( wiz ) tell_object( lista[i], wrap( wiz,78 ) );
      }
   }
   return;
}
