/* /secure/net/mwhod.c
**
** A mudwho daemon (and object to look at)
**
** Gets fed up by secure/master
**
**  04-Nov-92 [Deepthought]
**  06-Apr-93 [Pepel]
*/

#define ME this_object()

QueryShort() { return "The remote mudwho daemon"; }
QueryLong() { return "It is a strange looking box with HUGE ears.\n"; }
id(s) { return "daemon" == s || "mudwho daemon" == s; }

NewMsg(message) {
      return;
}
