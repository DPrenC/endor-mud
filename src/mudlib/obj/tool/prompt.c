/*  -*- LPC -*-  */
/* New prompt tool */

#include <properties.h>
#include <wizlevels.h>

#define USER     (TP||environment())
#define USAGE(x) write("Usage: " + (x) + "\n")||0

inherit "/std/thing";


int hidden;

private void set_my_prompt(mixed prompt)
{
  mixed oldprompt;

  if(TP != environment())
    return;
  if (!IS_LEARNER(TP)) return 0;
  if((oldprompt = set_prompt(prompt)) == "> ")
    return;

  if(sprintf("%O\n",oldprompt)[2..strlen(object_name())+1] !=
     object_name())
       return;

  set_prompt(oldprompt);
}

private string insert_single_value(string arg)
{
  string tmp, *path;

  if(!arg || arg == "") return "";
  switch(arg[0]) {
/*
  case 'm':
    return (strlen(MUDNAME)?MUDNAME:"NoMud") + arg[1..];
  case 'u':
    return capitalize(getuid(USER)) + arg[1..];
 */
  case 't':
    return ctime(time())[<13..<6] + arg[1..];
  case 'T':
    return ctime(time())[<13..<9] + arg[1..];
  case 'h':
    return to_string(USER->Query(P_HP)) + arg[1..];
  case 'H':
    return to_string(USER->Query(P_MAX_HP)) + arg[1..];
  case 's':
    return to_string(USER->Query(P_SP)) + arg[1..];
  case 'S':
    return to_string(USER->Query(P_MAX_SP)) + arg[1..];
  }
  if(IS_LEARNER(USER)) {
    switch(arg[0]) {
/*
      case 'w':
      return (USER->Query(P_CURRENTDIR)||
	     "/" + WIZARDDIR + "/" + getuid(USER)) +
	       arg[1..];
*/
    case 'p':
      tmp = USER->prettyfile(USER->Query(P_CURRENTDIR));
      if((path = explode(tmp,"/"))[0] ==
	 "~" + getuid(USER))
	return implode(({"~"}) + path[1..],"/") + arg[1..];
      return tmp + arg[1..];
    case 'P':
      return explode(USER->prettyfile(USER->Query(P_CURRENTDIR)),"/")[<1] +
	     arg[1..];
    }
  }
  return "\\" + arg;
}

private string insert_values(string part)
{
  int pos;

  if((pos = strstr(part, "\\")) == -1) return part;

  return part[0..pos-1] +
    implode(map(explode(part[pos..],"\\"),
                      SF(insert_single_value)),"");
}

string create_prompt()
{
  string currentprompt;

  if(!stringp(currentprompt = Query(P_AUTOOBJECT))) {
    if(pointerp(currentprompt)) {
      Set(P_AUTOOBJECT,"> ");
      write("New version of prompt. Please LOOK at it.\n");
    }
    return "> ";
  }

  return implode(map(explode(currentprompt,"\\\\"),
                           SF(insert_values)), "\\");
}

void create()
{
  ::create();
  AddId("tool");
  AddId("prompt");
  AddId("prompttool");
  AddId("prompt tool");
  Set(P_SHORT,"a prompt change tool");
  Set(P_LONG,"Just LOOK at it.\n");
  hidden = 0;
}

remove_me() {
  remove();
  if (TO) destruct(TO);
}

void init()
{
  ::init();
  if (TP == environment()) {
    if  (!IS_LEARNER(TP)) call_out("remove_me",1);
    set_my_prompt(SF(create_prompt));
    add_action("hide","hide");
    add_action("unhide","unhide");
    add_action("_prompt", "prompt");
    add_action("get_help","help");
    add_action("get_help","man");
    add_action("new_prompt","update");
  }
}

int hide(string str)
{
  if(!str || present(str) != TO) return 0;
  if(hidden) {
    notify_fail("It is already hidden!\n");
    return 0;
  }
  SetShort(0);
  hidden = 1;
  return 1;
}

int unhide(string str)
{
  if(!str || present(str) != TO) return 0;
  if(!hidden) {
    notify_fail("It isn't hidden!\n");
    return 0;
  }
  SetShort("A prompt change tool");
  hidden = 0;
  return 1;
}

// prompt command

// _subst_prompt() -- substitute prompt macros
// takes a string and returns matching macro value
private string _subst_prompt(string str)
{
  switch(str)
    {
    case "\\m": return strlen(MUDNAME)?MUDNAME:"NoMud";
	      case "\\u": return capitalize(getuid(USER));
	      default: return str;
	      }
}

// _prompt() -- change the current prompt
int _prompt(string args)
{
  string *pargs;

  args = args || "> ";
  if(args[0]=='"') args = args[1..<2];

  if(!sizeof(pargs = regexplode(args, "\\\\[mu]")))
    return USAGE("prompt \"<newprompt>\"");

  Set(P_AUTOOBJECT, implode(map(pargs, SF(_subst_prompt)), ""));
  set_my_prompt(SF(create_prompt));
  return 1;
}

int remove()
{
  if (environment() && environment()->QueryIsPlayer() && interactive(environment()))
    set_prompt("> ", environment());
  return ::remove();
}

void PlayerNetdead(int i)
{
  if (environment() && environment()->QueryIsPlayer() && !i)
  {
    set_prompt(SF(create_prompt), environment());
  }
}

string Long()
{
  return "\
This tool changes your prompt.\n\
Syntax: prompt <string>\n\
This sets the the prompt to <string>.\n\n\
Special sequences get replaced by context sensitive information:\n\n\
  \\m - the Mud's name (e.g. Nightfall)\n\
  \\u - your username\n\
  \\t - the current time (format hh:mm:ss)\n\
  \\T - the current time (format hh:mm)\n" +
    ((IS_LEARNER(USER||TO))?"\
  \\w - your current working directory\n\
  \\p - a shortened version of your current working directory\n\
  \\P - a very short version of your current working directory\n":"") + "\
  \\h - your current hitpoints\n\
  \\H - your maximal hitpoints\n\
  \\s - your current spellpoints\n\
  \\S - your maximal spellpoints\n\n" +
    ((IS_LEARNER(USER||TO))?"\
\\w, \\p and \\P aren't available for players.\n":"") + "\
\"\\\\\" gets replaced by \"\\\".\n\
To get a space after your prompt ('> ' instead of '>') put your argument\n\
into \"-signs (double quotes): prompt \"> \"\n--\n\
You may 'hide' or 'unhide' your prompt.\n";
}

int get_help(string arg)
{
  if(!arg)
    return 0;

  if(present(arg,USER) != TO)
    return 0;

  write(Long());
  return 1;
}

int new_prompt(string arg)
{
  mixed prompt;
  object new;

  if(!arg)
    return 0;

  if(present(arg,USER) != TO) {
    notify_fail("Usage: update prompt\n");
    return 0;
  }

  blueprint(TO)->remove();
  new = clone_object(blueprint());
  new->move(USER);
  prompt = Query(P_AUTOOBJECT);
  remove();
  new->_prompt(prompt);
  return 1;
}
