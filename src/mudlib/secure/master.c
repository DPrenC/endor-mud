/**
 * SIMAURIA '/secure/master.c'
 */

/*  MASTER (#define in config.h as secure/master.c)
**
** The master is the gateway between the gamedriver and the mudlib to perform
** actions with mudlib specific effects.
** Calls to the master by the gamedriver have an automatic catch() in effect.
**
** Note that the master is loaded first of all objects. Thus it is possible,
** you shouldn't inherit an other object (as most files expect the master
** to exist), nor is the compiler able to search include files
** (read: they must be specified with full path).
*/

#pragma strict_types

//----------------------------------------------------------------------------

#include "/secure/master.h"
#include "/sys/sounds.h"
//----------------------------------------------------------------------------

static string last_filename; // Used by the errorlog functions.
static string last_loader;   // Used by the errorlog functions.
static string last_env;      // Used by the errorlog functions.
static int    last_lived;    // Used by the errorlog functions.

static string *last_log_file; // Used by the errorlog functions.
static int    last_log_time;  // Used by the errorlog functions.

static string *last_heart_file;// Used by the errorlog functions.
static int    last_heart_time; // Used by the errorlog functions.

static string *last_runt_file;// Used by the errorlog functions.
static int    last_runt_time; // Used by the errorlog functions.

static string last_save_fname;// Used by the errorlog functions.

//===========================================================================
//  Initialisation
//===========================================================================
#include "/secure/master/initialisation.ic" // Initialisation

//===========================================================================
// Handling of player connections
//===========================================================================
#include "/secure/master/connections.ic" // Handling of player connections

//===========================================================================
// Runtime Support
//===========================================================================
#include "/secure/master/runtime.ic" // Runtime Support

//===========================================================================
// Error Handling
//===========================================================================
#include "/secure/master/error.ic" // Error Handling

//===========================================================================
// Security and Permissions
//===========================================================================
#include "/secure/master/permisions.ic" // Security and Permissions

//===========================================================================
// Userids and depending Security
//===========================================================================
#include "/secure/master/userids.ic" // Userids and depending Security

//===========================================================================
// End ed() Support
//===========================================================================
#include "/secure/master/ed.ic" // ed() Support

//===========================================================================
// End parse_command() Support  (!compat, SUPPLY_PARSE_COMMAND defined)
//===========================================================================
#include "/secure/master/parse.ic" // parse_command() Support

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

/*****************************************************************************/
/* user information handling                                                 */
/*****************************************************************************/
#include "/secure/master/userinfo.ic"

//---------------------------------------------------------------------------

//#include "/secure/master/wizards.ic"

/***************************************************************************/

/* Return a printable backtrace of who called us why */
string backtrace() {
    int i;
    string str = "";
    object ob;

    if (query_verb()) str += "  Command '"+query_verb()+"'.\n";
    else str += "\n";

    for (i=0; ob = previous_object(i); i++) {
        if (!i) str += "   PrevObj: \t";
        else    str += "            \t";

        if (!ob) { str += "?\n"; break; }
        else {
            str += object_name(ob)+" ["+getuid(ob)+"]";
            if (!query_once_interactive(ob)) str += "\n";
            else if (!interactive(ob)) str += " netdead.\n";
            else if (query_idle(ob)) str +=" idle "+(query_idle(ob))+" sec.\n";
            else str += " interactive.\n";
        }
    }

    str += "   Player: \t";

    if (!TP) str += "?\n";
    else str += object_name(TP)+" ["+getuid(TP)+"]\n";

    str += "   Interactive: ";

    if (!TI) str += "?\n";
    else str += object_name(TI)+" ["+getuid(TI)+"]\n";

    return str;
}


