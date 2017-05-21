// Comando shutdown

public int main(string str) {
    int timer = 0;
    string reason;

    if (str == "cancelar") {
        object ob;

        if (ob = find_object("/secure/shut")) {
            destruct(ob);
            write("El shutdown ha sido cancelado.\n");
            log_file("GAME_LOG", ctime(time())+": "+capitalize(TP->QueryRealName())+" ha cancelado el shutdown.\n");
        }
        else {
            write("No hay ning�n shutdown en ejecuci�n.\n");
        }
        return 1;
    }

    if (   !str
        || !strlen(str)
        || (   sscanf(str, "tiempo %d porque %s", timer, reason) != 2
            && sscanf(str, "%d porque %s", timer, reason) != 2
            && sscanf(str, "tiempo %d %s", timer, reason) != 2
            && sscanf(str, "%d %s", timer, reason) != 2
            && sscanf(str, "tiempo %d %s", timer, reason) != 2
            && ((sscanf(str, "porque %s", reason)!=1)?1:(timer=5),0)
            && ((sscanf(str, "%s", reason)!=1)?1:(timer=5),0)
           ) // esto siguientees para evitar 'shutdown <tiempo>' sin raz�n:
        || (to_string(to_int(reason)) == reason)
        )
    {
        return notify_fail("Uso: shutdown <tiempo> <raz�n>\n"
                           "     shutdown tiempo <tiempo> <raz�n>\n"
                           "     shutdown <tiempo> porque <raz�n>\n"
                           "     shutdown tiempo <tiempo> porque <raz�n>\n"
                           "     shutdown porque <raz�n>\n"
                           "     shutdown <raz�n>\n"
                           "     shutdown cancelar\n"
                           );
    }

    if (timer <= 0) {
        write("La destrucci�n de Arda acaece inminentemente.\n");
        filter(users()-({TP}), SF(tell_object),
            capitalize(TP->QueryRealName())+" va a reinicializar Endor-Mud.\n");
        // Hecho a los players...
        call_other( users()-({TP}), "command_me", "exit");
        log_file ("GAME_LOG", ctime(time())+": "+capitalize(TP->QueryRealName())+" ha reinicializado el mud.\n");
        if (str) log_file ("GAME_LOG", "  Raz�n: "+str+"\n");
        else log_file ("GAME_LOG", "  Pas� de dar una razon...\n");
        shutdown();
    }
    else {
        object ob;
        ob = load_object(SHUTDEMON);
        write("El fin de Arda acaecer�  en "+timer+" minutos.\n");
        ob->slow_shut(timer);
        if (reason) {
          ob->set_reason(reason);
          log_file ("GAME_LOG", "  Raz�n: "+reason+"\n");
        }
        else log_file ("GAME_LOG", "  Pas� de dar una razon...\n");
    }
    return 1;
}