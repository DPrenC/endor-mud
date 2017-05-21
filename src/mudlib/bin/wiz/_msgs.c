// Comando msgs
/*
 * the wizard command review: show player moving messages
 */
int main() {
  string *how, *who;
  mixed msg;
  object ob;

  ob = TP;
  if (!ob) return 0;

  who = ({ capitalize(ob->QueryRealName()), "Algo" });
  ob->catch_tell("Tus mensajes actuales de movimiento son:\n");
  msg = ob->QueryMsgOut();
  how = pointerp(msg) ? msg : ({ msg, "sale de la habitación" });
  ob->catch_tell ("mout:  "+who[0]+" "+how[0]+" <dirección>.\n"
         "       "+who[1]+" "+how[1]+".\n"
        );
  msg = ob->QueryMsgIn();
  how = pointerp(msg) ? msg : ({ msg, "llega" });
  ob->catch_tell ("min:   "+who[0]+" "+how[0]+".\n"
         "       "+who[1]+" "+how[1]+".\n"
        );
  msg = ob->QueryMMsgOut();
  how = pointerp(msg) ? msg : ({ msg, "desaparece" });
  ob->catch_tell ("mmout: "+who[0]+" "+how[0]+".\n"
         "       "+who[1]+" "+how[1]+".\n"
        );
  msg = ob->QueryMMsgIn();
  how = pointerp(msg) ? msg : ({ msg, "vuelve de entre los muertos" });
  ob->catch_tell ("mmin:  "+who[0]+" "+how[0]+".\n"
         "       "+who[1]+" "+how[1]+".\n"
        );
  return 1;
}