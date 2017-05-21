/**
 * SIMAURIA '/std/npc/chat.c'
 */

// [Nyh] Nadie sabe como funciona esto. Habra que investigarlo a fondo
//       cuando tenga tiempo.

#include <config.h>
#include <living.h>
#include <search.h>

public string QueryName();                   // std/living/description
public void   CallOut(mixed fun, int delay); // std/living/heart
public int    FindCallout(mixed fun);        // std/living/heart
public int    RemoveCallout(mixed fun);      // std/living/heart

/*--------------------------------------------------------------------------*/

public void OneChat (int justSched);  // Forward
public void InitChats (int chance, mixed *strs); // Forward

/*--------------------------------------------------------------------------*/

private int     pChatChance, pAChatChance;
private mixed   *pChats, *pAChats;
private mapping pQuestions;
private string  *pTalkMatch, *pTalkType;
private mixed   *pTalkFun;
private mixed   pTalkObj;
private int     *pTalkDelay;
private mixed   pShrugMsg;

private string *_buffer;  // An experiment
private int    _sema;     // Mutex for catch_tell.
private int    _by_cmsg;  // Not-Mutex for catch_tell by catch_msg.

/*--------------------------------------------------------------------------*/

public int SetByCMsg (int i)      { return _by_cmsg = i; }
public int QueryByCMsg ()         { return _by_cmsg; }

public int QueryChatChance ()     { return pChatChance; }
public int SetChatChance (int i)  {
  pChatChance = i;
  OneChat(1);
  return pChatChance;
}

public mixed *QueryChats ()        { return pChats; }
public mixed *SetChats (mixed c1, mixed *c2)
{
  if (pointerp(c2))
  {
    log_file("COMPAT", sprintf("%O: %O->SetChats(a,b)\n", TO, PO));
    InitChats(c1, c2);
    return QueryChats();
  }
  return pChats = c1;
}

public int QueryAChatChance ()     { return pAChatChance; }
public int SetAChatChance (int i)  { return pAChatChance = i; }

public mixed *QueryAChats ()        { return pAChats; }
public mixed *SetAChats (mixed *c)  { return pAChats = c; }

public mapping QueryQuestions ()         { return pQuestions; }
public mapping SetQuestions (mixed c)
{
  mapping q;
  int i, j;

  // Special for compatibility: convert alists.
  if (pointerp(c) && sizeof(c) == 2 && pointerp(c[0]) && pointerp(c[1]))
    return pQuestions = mkmapping(c[0], c[1], allocate(sizeof(c[1])));

  if (!pointerp(c))
    return pQuestions = c;
  q = m_allocate(0, 2);
  for (i = 0; i < sizeof(c); i += 2)
  {
    if (!pointerp(c[i]))
      q[c[i]] = c[i+1];
    else
      for (j = 0; j < sizeof(c[i]); j++)
        q[c[i][j]] = c[i+1];
  }
  return pQuestions = q;
}

public varargs void AddQuestion (mixed q, mixed a, int silent) {
  int i;

  if (silent && !pointerp(a))
    a = ({ a, 0 });
  if (!pointerp(q))
  {
    if (!pQuestions)
      pQuestions = ([q:a]);
    else
      pQuestions[q] = a;
  }
  else
  {
    for (i = sizeof(q); i--; )
      if (!pQuestions)
        pQuestions = ([q[i]:a]);
      else
        pQuestions[q[i]] = a;
  }
}

public mixed QueryShrugMsg ()      { return pShrugMsg; }
public mixed SetShrugMsg (mixed s) { return pShrugMsg = s; }

public int *QueryTalkDelay ()      { return pTalkDelay; }
public int *SetTalkDelay (int *d)  { return pTalkDelay = d; }

public string *QueryTalkMatch ()         { return pTalkMatch; }
public string *SetTalkMatch (string *c)  { return pTalkMatch = c; }

public string *QueryTalkType ()         { return pTalkType; }
public string *SetTalkType (string *c)  { return pTalkType = c; }

public mixed *QueryTalkFun ()        { return pTalkFun; }
public mixed *SetTalkFun (mixed *c)  { return pTalkFun = c; }

public mixed QueryTalkObj ()        { return pTalkObj; }
public mixed SetTalkObj (mixed c)  { return pTalkObj = c; }

//-----------------------------------------------------------------------

public void InitChats (int chance, mixed *strs) {
  pChatChance = chance;
  pChats = pointerp(strs) ? strs : ({ strs });
}

public void InitAChats (int chance, mixed *strs) {
  pAChatChance = chance;
  pAChats = pointerp(strs) ? strs : ({ strs });
}

public varargs void InitMatch ( mixed *fun
                              , string *type
                              , string *match
                              , int    *delay
                              , mixed  ob) {

  if (sizeof(fun) != sizeof(type) || sizeof(match) != sizeof(type))
    return;
  pTalkObj = ob || TO;
  pTalkFun = fun;
  pTalkType = type;
  pTalkMatch = match;
  pTalkDelay = delay;
}

public varargs void AddMatch ( mixed  fun
                             , string type
                             , string match
                             , int    delay
                             )
{
  pTalkFun   = (pTalkFun  ||({})) + ({ fun });
  pTalkType  = (pTalkType ||({})) + ({ type });
  pTalkMatch = (pTalkMatch||({})) + ({ match });
  pTalkDelay = (pTalkDelay||({})) + ({ delay });
}

//-----------------------------------------------------------------------

public void DoChat () {
  mixed chat;

  if (TO->CheckHeart(HEART_COMBAT) || !pChats || !sizeof(pChats))
    return;
  chat = pChats[random(sizeof(pChats))];
  if (closurep(chat))
    chat = apply(chat, 0);
  if (chat)
    tell_room(environment(), chat, ({ TO }));
}

//-----------------------------------------------------------------------

public void OneChat (int justSched)

// If it's time, do one chat and restart call_out.

{
  int delay;

  if (justSched < 0 && FindCallout("OneChat") != -1)
    return;
  while (RemoveCallout("OneChat") != -1);
  if (!pChatChance)
    return;
  if (!justSched)
    DoChat();
  if (1 < sizeof(filter((environment()?all_inventory(environment()):({}))
                              +all_inventory(TO), SF(living)))
     )
  {
    for (delay = 0; delay < 4000 && random(100) >= pChatChance; delay += 2);
    CallOut("OneChat", delay);
  }
}

//-----------------------------------------------------------------------

public void DoAttackChat (object enemy) {
  mixed achat;

  if (random(100) >= pAChatChance || !pAChats || !sizeof(pAChats))
    return;
  achat = pAChats[random(sizeof(pAChats))];
  if (closurep(achat))
    achat = apply(achat, enemy);
  if (achat)
    tell_room(environment(), achat, ({ TO }));
}

//-----------------------------------------------------------------------

static void _call_talk_ob (mixed obj, mixed fun, mixed str) {
  if (closurep(fun))
    apply(fun, str);
  else
    call_other(obj, fun, str);
}

public mixed TestMatch (string str) {
  string who, str1, type, match;
  mixed fun;
  int i, delay;

  for (i = 0; i < sizeof(pTalkMatch); i++) {
    type = pTalkType[i] || "";
    match = pTalkMatch[i] || "";
    if (pTalkFun[i]) fun = pTalkFun[i];
    if (   2 == sscanf(str, "%s " + type + match + " %s\n", who, str1)
        || 1 == sscanf(str, "%s " + type + match + "\n", who)
        || 2 == sscanf(str, "%s " + type + match + "%s\n", who, str1)
        || 1 == sscanf(str, "%s " + type + " " + match + "\n", who)
        || 2 == sscanf(str, "%s " + type + " " + match + " %s\n", who, str1)
        || 2 == sscanf(str, "%s " + type + " " + match + "%s\n", who, str1)
       )
    {
      if (pointerp(pTalkDelay) && (delay = pTalkDelay[i]) > 0) {
        if (closurep(fun)) call_out(fun, delay, str);
        else call_out(SF(_call_talk_ob), delay, pTalkObj, fun, str);
        return delay;
      }
      if (closurep(fun)) return apply(fun, str);
      return call_other(pTalkObj, fun, str);
    }
  }
  return 0; // [Nyh] Puesto para q no de warning
}

//-----------------------------------------------------------------------

varargs int fask (string str, int inh) {
  string whom, what, tmp;
  mixed answer;

  notify_fail("Preguntar a quien sobre que??\n", NOTIFY_NOT_OBJ);
  if (!str || !stringp(str))
    return inh ? ASK_NO_ARG : 0;

  // make the input more flexible by stripping of multiple blanks
  // and converting all characters in lower case chars
  str = norm_id(str);

  if (    !str[0]
       || (   2 != sscanf(lower_case(str), "a %s sobre %s", whom, what)
           && 2 != sscanf(lower_case(str), "a %s por %s", whom, what)
          )
     )
    return inh ? ASK_CANT_PARSE : 0;
  if (TO != TP->Search(whom, SEARCH_ENV_INV|SEARCH_OBJECT|SEARCH_IGNLIGHT))
     return inh ? ASK_CANT_PARSE : 0;
  if (pQuestions && (answer = pQuestions[what]))
    answer = funcall(answer, what);
  if (pointerp(answer) && ("" == (answer[1] || "")))
    say( TP->QueryName()+" habla a "+QueryName()+".\n", ({ TP, TO}));
  else
    say( TP->QueryName()+" pregunta a "+QueryName()+" sobre "+what+".\n"
       , ({ TP, TO}));
  if (!answer) {
   answer =    funcall(QueryShrugMsg(), what)
             || capitalize(QueryName())+" te mira sin contestar.\n";
    if (inh) {
      notify_fail(answer, NOTIFY_NOT_VALID);
      return ASK_SHRUG;
    }
  }
  if (answer) {
    tmp = funcall(pointerp(answer) ? answer[0] : answer, what);
    if (tmp && tmp != "")
      write(tmp);
    tmp = funcall(pointerp(answer) ? answer[1] : answer, what);
    if (tmp && tmp != "")
      say(tmp, ({ TO, TP }));
  }

  return ASK_OK;
}

//-----------------------------------------------------------------------

public void catch_tell (string str) {
//  log_file("/MESSAGES",sprintf("[%O] %O llamo a %O->catch_tell(%O)\n\t_by_cmsg: %O\n",ctime(time()),PO,TO, str, _by_cmsg ));
//  dtell("nyh", sprintf("[%O] %O llamo a %O->catch_tell(%O)\n\t_by_cmsg: %O\n",ctime(time()),PO,TO, str, _by_cmsg ));
    if (!pTalkObj || (!_by_cmsg && PO == TO)) return;

    str = tcfstr(str); // Para quitar las cosas raras.

    _by_cmsg = 0;

    if (_sema) {
        if (!_buffer) _buffer = ({});
        _buffer += ({ str });
        return;
    }

    _sema = 1;

    do {
        TestMatch(str);
        if (sizeof(_buffer)) {
            str = _buffer[0];
            _buffer = _buffer[1..];
        }
        else str = 0;
    } while (str);

    _sema = 0;
}

public void ResetSema () { _sema = 0; _buffer = 0; }

//-----------------------------------------------------------------------

init() {
  OneChat(1);
  add_action("fask", "preguntar");
}

/****************************************************************************/
