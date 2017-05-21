/*
 *  /sys/player.h
 *  =============
 */

// Aqui iran las declaraciones de las funciones existentes en /std/player/*

//----------------------------------------------------------------------------
// /std/player.c
//----------------------------------------------------------------------------

public int QueryNetdead();

//----------------------------------------------------------------------------
// /std/player/soul.c
//----------------------------------------------------------------------------

void config_soul();
void ac_abofetear(object JUG, object OBJ);
void ac_apedrear(object JUG, object OBJ);
void ac_aplastar(object JUG, object OBJ);
void ac_azotar(object JUG, object OBJ);
void ac_capon(object JUG, object OBJ);
void ac_colleja(object JUG, object OBJ);
void ac_escupir(object JUG, object OBJ);
void ac_golpear(object JUG, object OBJ);
void ac_patear(object JUG, object OBJ);
void ac_pisotear(object JUG, object OBJ);
void ac_vomitar(object JUG, object OBJ);
static string yo();
static string Sust_ac(string str);
static string compl(string s);
static int modo_ac(string Maccion);
static int xdecir(string str);
static int hacer(string str);
static varargs mixed *accion(string v, string str);
static int ver_acciones();

//----------------------------------------------------------------------------
// /std/player/description.c
//----------------------------------------------------------------------------

public string SetShort(mixed s);
public varargs string Short(string what);
protected string *_long(string str);
public varargs string Long(string what);

//----------------------------------------------------------------------------
// /std/player/skills.c
//----------------------------------------------------------------------------

public int HasSkill(string name);
public int SkillIsEnabled(string name);
public int EnableSkill(string name);
public int DisableSkill(string name);
public int SetSkillLearnLevel(string name, int diff);
public int QuerySkillLearnLevel(string name);
public string SetSkillLearnMessage(string name, string str);
public string QuerySkillLearnMessage(string name);
public mapping AddSkill(string name, int initial, int max, mixed modif);
public mapping QuerySkills();
public mapping SetSkills(mapping sk);
public int SetSkillLevel(string name, int level);
public int QuerySkillLevel(string name);
public int QueryMaxSkillLevel(string name);
public int SetMaxSkillLevel(string name, int max);
public mapping RemoveSkill(string name);
public void ForgetSkills();
public void add_general_skills();

//----------------------------------------------------------------------------
// /std/player/utils.c
//----------------------------------------------------------------------------

public mixed *ResetAliases();
public mixed *QueryAliases();
public mixed *SetAliases(mixed *als);
public string QueryAlias(string str);
public int AddAlias(string str, string cmd);
public int RemoveAlias(string str);
public int HasAlias(string str);
public string *QueryHistorico();
static string HacerAlias (string verbo, string arg);
//private string HacerHistorico(string verbo, string arg);
public string parse_scan(string verbo, string str);

//----------------------------------------------------------------------------
// /std/player/saveload.c
//----------------------------------------------------------------------------

public string QueryIPName();
public string QueryIPNumber();
public int QueryPlayerStarted();
public int SetPlayerStarted(int i);
public string SetHome(string str);
public string QueryHome();
public string SetHomeTmp(string str);
public string QueryHomeTmp();
public int QueryLastSave();
public int SetLastSave(int i);
public mapping QueryInventory();
public mapping SetInventory(mapping m);
//private void reset_autoobject();
//private void save_autoobject(object ob, int destruct_autos);
protected void restore_autoobject(string file, mixed args);
static void getmailaddr(string str);
//private void _check_mailaddr();
static void acentuacion(string str);
//private void _check_charset();
static void gettty(string str);
//private void _check_stty();
protected int fortune(string str);
public int bind(string str);
protected _add_commands();
//private void actualize_containers(object ob, string name);
protected void _move_player_to_start();
start_player(str);
void restart_player(string name);
public int save();
public varargs int remove();
public int destruct_player(int force);
cmd_reiniciar(arg);

//----------------------------------------------------------------------------
// /std/player/config.c
//----------------------------------------------------------------------------

public string SetHome(string str);
public string QueryHome();
public int SetTiflo(int i) ;
public int QueryTiflo();
public string SetMailaddr(string str);
public string QueryMailaddr();
public string SetTTY(string str);
public string QueryTTY();
public int QueryCharset();
public int SetCharset(int k);
public int QueryConsoleWidth();
public int QueryConsoleHeight();
public int SetConsoleWidth(int to);
public int SetConsoleHeight(int to);
public int SetPageSize(int size);
public int QueryPageSize();
public void negotiate(int cmd, int option, int *args);
public mapping SetColours(mapping m);
public mapping QueryColours();
public void RestoreColours();
public void SetColour(string key, string colour);
void catch_tell(string str);

//----------------------------------------------------------------------------
// /std/player/comm.c
//----------------------------------------------------------------------------

public string FancyPrompt();
public int QueryPrompt();
public int SetPrompt(int to);
public int QueryIgnoreAll();
public int SetIgnoreAll(int i);
public string QueryAway();
public string SetAway(string s);
public int QueryChLine();
public int SetChLine(int i);
public int SetEchoMode(int i);
public int QueryEchoMode();
public mapping SetIgnored(mapping i);
public mapping QueryIgnored();
public void AddIgnored(string name, int until);
public void RemoveIgnored(string name);
public int CheckIgnored(string name);
public int SetEarmuffs(int i);
public void echo_txt(string msg);
varargs int check_ignore(string type, object by);
int ear (string msg, string type);
int _tell_ear (object ob, string msg, string type);
void SetChannels(string *chs);
string *QueryChannels();
void ChannelOn(string ch);
void ChannelOff(string ch);
int sendmsg(string msg);
int sendemote(string msg);
//private string *BuildChannelList();
int chann(string str);
int chon(string str);
int choff(string str);
string filter_listeners(object who, string ch);
mixed filter_invis(object who);
int chwho_bak(string str);
int channels(string str);
public int AddMensaje(string quien, string que);
static add_comm_commands();
_earmuffs(e);
_all_communicate(object *obj, string name, string what);
_communicate(str);
_whisper(str);
static _converse();
static _converse_more(str);
_tell_mudlink (string text);
string mkstr (int len);
string ladjust (string str, int len);
string radjust (string str, int len);
_rpeers();
_rdict(string str);
static _echoto(str);
_inet_tell(who,msg);
string * _handle_abbrev_names (string arg);
_tell(str);
int _away(string arg);

//----------------------------------------------------------------------------
// /std/player/restrictions.c
//----------------------------------------------------------------------------

static void announce_light_changed_to(int l);
public void light_outside(int l);

//----------------------------------------------------------------------------
// /std/player/body.c
//----------------------------------------------------------------------------

public int QueryMaxLevel();
public int QueryGuildLevel();
public int SetGuildLevel(int l);
public int QueryRealLevel ();
public int QueryLevel();
public int SetRealLevel(int i);
public int SetLevel(int i);
SetQuests(q);
QueryQuests();
public string QueryExplored();
public string SetExplored();
public int QueryKills();
public int AddKill();
public int QueryDeaths();
public int AddDeath();
protected varargs void update_age(int enforce);
public int QueryAge();
public int SetAge(int i);
public string AgeString();
protected varargs void autosave(int initial);
public varargs void Die(mixed silent);
#ifdef LOG_KILLS
//private void _log_kill();
#endif
protected int another_life();

//----------------------------------------------------------------------------
// /std/player/spells.c
//----------------------------------------------------------------------------

public int HasSpell(string name);
public int SpellIsEnabled(string name);
public int EnableSpell(string name);
public int DisableSpell(string name);
public int SetSpellLearnLevel(string name, int diff);
public int QuerySpellLearnLevel(string name);
public int SetSpellLevel(string name, int level);
public int QuerySpellLevel(string name);
public int QueryMaxSpellLevel(string name);
public int SetMaxSpellLevel(string name, int max);
public string SetSpellLearnMessage(string name, string str);
public string QuerySpellLearnMessage(string name);
public int QuerySpellChance(string name);
public mixed QuerySpellModifier(string name);
public mapping AddSpell(string name, int chance, int max_chance, mixed modif);
public int AddPlayerSpell(string name, int l_learned, int l_max, mixed modif);
public mapping QuerySpells();
public mapping SetSpells(mapping p);
public mapping RemoveSpell(string name);
int SpellModifyByStats(int perc);
public varargs UseSpell(string name, int scroll, int diff);
public int AdvanceLearned(string name);
public void ForgetSpells();
