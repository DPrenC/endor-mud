#ifndef __MASTER_H__
#define __MASTER_H__

#include "/sys/config.h"
#include "/secure/userinfo.h"
#include "/secure/wizlevels.h"
#include "/secure/wizlist.h"
#include "/sys/driver_hook.h"
#include "/sys/erq.h"
#include "/secure/womsets.h"
#include "/sys/actions.h"

#undef ACCESS_DEBUG
#undef DEBUG_GET_PATH
#undef DEBUG_MASTER


#ifndef SIMUL_EFUN_FILE
#define SIMUL_EFUN_FILE       "secure/simul_efun"
#endif

#ifndef REMOVER
#define REMOVER "/secure/remover"
#endif

#define PATH_ARRAY(x) (explode(x, "/")-({"","."}))
#define ARRAY_PATH(x) (implode(x, "/"))

//#define LOG_VALID_READ
//#define LOG_VALID_WRITE

/* DTELL() is a simul_efun. Resolve it at run time. */
#define DTELL(pl,msg) funcall(symbol_function(SYM(dtell)),pl,msg)

/* first the ones that are applied by the GD */
int privilege_violation(string what, mixed who, mixed where, mixed how);
int query_allow_shadow(object ob);
int valid_exec(string name, object ob, object obfrom);
int valid_query_snoop(object wiz);
int valid_seteuid(object ob, string neweuid);
int valid_snoop(object snooper, object snoopee);
int valid_trace (string what, mixed arg);
mixed prepare_destruct(object ob);
mixed valid_read(string path, string euid, string fun, object obj);
mixed valid_write(string path, string euid, string fun, object obj);
object connect();
void disconnect(object o);
string *define_include_dirs();
string *epilog(int eflag);
string get_wiz_name(mixed str);
string get_bb_uid();
string get_ed_buffer_save_file_name(string file);
string get_master_uid();
string get_simul_efun();
string get_wiz_name(string file);
void destruct_environment_of(object ob);
void external_master_reload();
void flag(string str);
void move_or_destruct(object what, object to);
void preload(string file);
void runtime_error(string err ,string prg, string curobj, int line);

/* then the public service functions for the mudlib */
object load_obj (mixed obj);
int get_wiz_level(string user);
void log_error(string file,string message);
int query_wiz_level(mixed player);
int retrieve_ed_setup(object who);
int save_ed_setup(object who, int code);
int test_dir(string *dir, string path);
int update_password(string old,string new);
int update_wiz_level(mixed user,int lev);
private int _verify_create_wizard( object wiz, string victima, int rango );
#ifdef DEBUG_MASTER
mapping dump_userlist();
#endif
mixed *find_userinfo(mixed user);
varargs string *full_path_array(string path, string user);
varargs string make_path_absolute(string path, string user);
//string make_path_absolute(string str);
string master_create_wizard(string owner, int rank, object caller );
int CheckPasswd(string user, string pw);
int SetPassword(string user, string old, string new);
void daily_jobs(int just_loaded);

string backtrace();
void save_wiz_file();
string *error_logfile (string file);
static void unwind_cmd_stack(object pl);

#define BACKBONE_WIZINFO_SIZE 6
#define BOOTTIME_INDEX 5

/* and some internal aux functions */
static string *explode_files(string file);
static void save_userinfo(mixed* userinfo);

#define log_file(file, str) catch(write_file("/log/"+file, str))

#define USERNAME(x) getuid(x)
#define CAP_NAME(x) capitalize(USERNAME(x))

#define TP          efun::this_player()
#define TI          efun::this_interactive()
#define PO          efun::previous_object()
#define TO          efun::this_object()

#define CANSEEUSERS ({CHRONOS, QUESTMASTER, CHANNELMASTER})

/* the purpose of the next two macros is to avoid the hash-tick notation,
 * which would confuse emacs c-mode indent engine _sigh_
 */
#define SF(x)       #'x // ' // Emacs-Hack
#define SYM(x)      'x  // ' // Emacs-Hack
#define CL_PROGN    #', // ' // Emack-Hack. SF(,) peta de mala manera.

#endif // __MASTER_H__