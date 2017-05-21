/* SIMAURIA '/std/living/commands.c'
   =================================
   [x] Mateese@nightfall
   [w] Woo
   [n] Nemesis
   [t] Theuzifan
   [m] Mirill
   [g] Guybrush

   01-10-96 [x] Modificacion de este archivo.
   17-12-96 [w] Adaptacion de este archivo para el nuevo mud.
   17-12-96 [w] Creacion de la funcion msgerror_random() para que salgan
                diferentes mensajes de error por pantalla.
                Sera private, ya que solo sera accesible en este archivo.
                private string msgerror_random();
   02-05-97 [w] Anyadidas nuevas frases a los mensajes de error.
   17-10-97 [n,m,t,g] Modificacion de las frases añadidas por Woo.
   02-12-98 [t] Parche de seguridad. No puedes forzar a nada con command_me
   		ni con command. Tambien hace un log.
   10-12-98 [t] Arreglado un bug. Comprobaba si el TP y TO eran distintos
   		para hacer un log...
   04-02-99 [t] Castellanizado.
   20-02-99 [w] Faltaba un\n en '¿Qué?' y un acento.
*/


#include <config.h>

private nosave mapping *command_stack;
private nosave mixed *last_fail;

//--------------------------------------------------------------------------

public mixed QueryCommandStack() { return command_stack; }
public int QueryCmdDataStackSize () { return sizeof(command_stack); }
public mixed QueryLastNotifyFail() { return last_fail; }

private string msgerror_random()
{
// orome: quito el swicht y dejo simplemente un return.
return "Comando desconocido.\n";
}


//---------------------------------------------------------------------------
public void ExecuteRegistered (mapping frame, int unwind)

// Execute any registered functions in the given stack <frame>.

{
  mixed *values, *entry;
  int i;

  if (!sizeof(frame = frame["RegisteredFuns"]))
    return;

  values = m_values(frame);
  for (i = sizeof(values); i--; )
  {
    entry = values[i];
    if (closurep(entry[0]))
    {
      if (to_object(entry[0]))
	funcall(entry[0], entry[1], unwind);
    }
    else if (entry[0])
      call_other(entry[0], entry[1], entry[2], unwind);
  }
}

//---------------------------------------------------------------------------
public void ResetCmdDataStack ()

// Reset the command data stack.

{
  command_stack = 0;
  last_fail = 0;
}

//---------------------------------------------------------------------------
public varargs void EmptyCmdDataStack (int unwind)

// Empty the command data stack, executing all registered functions.

{
  int i;

  //dtell("nyh",sprintf("%O->EmptyCmdDataStack(%O)\n", TO, unwind));
  for (i = 0; i < sizeof(command_stack); i++)
    ExecuteRegistered(command_stack[i], unwind);
  command_stack = 0;
}

//---------------------------------------------------------------------------
public void PushCmdData ()

// Push a new 'default' entry onto the command data stack.

{
  object prev_player;

  //dtell("nyh",sprintf("%O->PushCmdData()\n", TO));
  if (command_stack)
    prev_player = command_stack[0]["ThisPlayer"];
  command_stack = ({ ([ "NotifyFail":({msgerror_random(), NOTIFY_DEFAULT })
                      , "PreviousPlayer": prev_player
                     ]) })
                  + (command_stack || ({}) );
  last_fail = ({ "Que?\n", NOTIFY_DEFAULT });
}

//---------------------------------------------------------------------------
public varargs mapping PopCmdData (int unwind)

// Pop the topmost entry from the command data stack, generating a default
// entry if the stack is empty.
// This will also execute functions registered with the popped frame.

{
  mapping rc;

  //dtell("nyh",sprintf("%O->PopCmdData(%O)\n", TO, unwind));

  if (!command_stack)
    rc = ([ "NotifyFail":({msgerror_random(), NOTIFY_DEFAULT }) ]);
  else
    rc = command_stack[0];
  last_fail = rc["NotifyFail"] + ({});
  if (sizeof(command_stack) > 1)
    command_stack = command_stack[1..];
  else
    command_stack = 0;
  ExecuteRegistered(rc, unwind);
  return rc;
}

//---------------------------------------------------------------------------
public mixed SetCmdData (string name, mixed data)

// Set an entry in the command data stack.

{
  //dtell("nyh",sprintf("%O->SetCmdData(%O, %O)\n", TO, name, data));
  if (!command_stack)
  {
    command_stack = ({ ([ "NotifyFail": ({msgerror_random(), NOTIFY_DEFAULT }) ]) });
    last_fail = command_stack[0]["NotifyFail"]+({});
  }
  ////dtell("nyh",sprintf("command_stack = %O\n", command_stack));
  return command_stack[0][name] = data;
}

//---------------------------------------------------------------------------
public mixed QueryCmdData (string name)

// Set an entry in the command data stack.

{
  //dtell("nyh",sprintf("%O->QueryCmdData(%O) = %O\n", TO, name, command_stack?command_stack[0][name]:0));
  if (!command_stack)
    return 0;
  return command_stack[0][name];
}

//---------------------------------------------------------------------------
public varargs void NotifyFail (mixed msg, int pri)

// Set a notify_fail message.

{
  if (!command_stack)
    command_stack = ({ ([ "NotifyFail":({ msg, pri }) ]) });
  else if (command_stack[0]["NotifyFail"][1] <= pri) {
    command_stack[0]["NotifyFail"][0] = msg;
    command_stack[0]["NotifyFail"][1] = pri;
  }
  last_fail = command_stack[0]["NotifyFail"]+({});
}

//---------------------------------------------------------------------------
public varargs void RegisterCmdFun (mixed funarg, mixed args)

// Register a function to be executed after this command.

{
  mixed entry;
  string key;
  mapping m;
  int i;

  if (closurep(funarg))
  {
    key = sprintf("%O", funarg);
    key[0..1] = "/";
    entry = ({ funarg, args });
  }
  else if (stringp(funarg))
  {
    if (-1 == (i = strstr(funarg, "->")))
    {
      key = to_string(PO)+"->"+funarg;
      entry = ({ PO, funarg, args });
    }
    else
    {
      key = resolve_file(funarg[0..i-1], PO);
      entry = ({ key, funarg[i+2..], args });
      key += funarg[i..];
    }
  }
  else if (pointerp(funarg))
  {
    entry = funarg+({ args });
    key = to_string(funarg[0])+"->"+funarg[1];
  }

  if (!command_stack)
  {
    command_stack = ({ ([ "NotifyFail":({msgerror_random(), NOTIFY_DEFAULT }) ]) });
    m = ([]);
  }
  else if (!(m = command_stack[0]["RegisteredFuns"]))
    m = ([]);

  m[key] = entry;
  command_stack[0]["RegisteredFuns"] = m;
}

//--------------------------------------------------------------------------
public int command_me (string cmd)

// Let the living execute a command.
// The /secure/simul_efun and /secure/master will call the routines
// to handle the notify_fail stack.

{
    int oldsize, rc;
    int w;
    w=0;
    //dtell("nyh",sprintf("[33mPO: %O, TP: %O did %O->did command_me[39m(%O)\n", PO, TP, TO, cmd));


    oldsize = sizeof(command_stack);

    // Si procede, mando mensajes de quien me ha forzado.
    if (TO != TI && query_wiz_level(TI)) {
        if (TI) TO->catch_msg(TI->QueryName()+" te fuerza a "+cmd+".\n");
        else if (!TI && getuid(PO) != getuid(TO))
            TO->catch_msg(getuid(PO)+" te fuerza a "+cmd+".\n");
    }

    // Si procede, logeo y chekeo si tiene derechos para forzarme
    if (TI && TI != TO) {
        if (query_once_interactive(TI) && query_once_interactive(TO)) {
            log_file("COMMAND_ME", ctime() + ": " + capitalize(TI->QueryRealName()||"")
                + " fuerza a " + capitalize(TO->QueryRealName()||"") + " a '" + cmd +"'. ");
            if (query_wiz_level(TI)<=query_wiz_level(TO)) {
                log_file("COMMAND_ME", "FALLÓ: No tiene suficiente nivel.\n");
                TO->catch_msg(capitalize(TI->QueryRealName()||"")
                    + " ha fallado al forzarte a '" + cmd + "'.\n");
                return 0;
            }
            w=1;
        }
    }
    rc = command(cmd);

    // If this command_me() call was a successful force, we have to
    // clean up the stack manually. HASS!
    if (sizeof(command_stack)) last_fail = command_stack[0]["NotifyFail"]+({});
    else last_fail = ({msgerror_random(), NOTIFY_DEFAULT });
    while (sizeof(command_stack) > oldsize) PopCmdData();

    if (w==1) log_file("COMMAND_ME", "Ok. Tiempo: "+rc+".\n");

    return rc;
}

/***************************************************************************/
