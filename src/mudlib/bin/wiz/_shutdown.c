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
            write("No hay ningún shutdown en ejecución.\n");
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
           ) // esto siguientees para evitar 'shutdown <tiempo>' sin razón:
        || (to_string(to_int(reason)) == reason)
        )
    {
        return notify_fail("Uso: shutdown <tiempo> <razón>\n"
                           "     shutdown tiempo <tiempo> <razón>\n"
                           "     shutdown <tiempo> porque <razón>\n"
                           "     shutdown tiempo <tiempo> porque <razón>\n"
                           "     shutdown porque <razón>\n"
                           "     shutdown <razón>\n"
                           "     shutdown cancelar\n"
                           );
    }

    if (timer <= 0) {
        write("La destrucción de Arda acaece inminentemente.\n");
        filter(users()-({TP}), SF(tell_object),
            capitalize(TP->QueryRealName())+" va a reinicializar Endor-Mud.\n");
        // Hecho a los players...
        call_other( users()-({TP}), "command_me", "exit");
        log_file ("GAME_LOG", ctime(time())+": "+capitalize(TP->QueryRealName())+" ha reinicializado el mud.\n");
        if (str) log_file ("GAME_LOG", "  Razón: "+str+"\n");
        else log_file ("GAME_LOG", "  Pasó de dar una razon...\n");
        shutdown();
    }
    else {
        object ob;
        ob = load_object(SHUTDEMON);
        write("El fin de Arda acaecerá  en "+timer+" minutos.\n");
        ob->slow_shut(timer);
        if (reason) {
          ob->set_reason(reason);
          log_file ("GAME_LOG", "  Razón: "+reason+"\n");
        }
        else log_file ("GAME_LOG", "  Pasó de dar una razon...\n");
    }
    return 1;
}