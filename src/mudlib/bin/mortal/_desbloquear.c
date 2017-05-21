// comando desbloquear para las puertas

public int main(string str)
{
    object env;
    if (!TP) return 0;
    env = environment(TP);
    if (!env) return 0;
    return env->flock_unlock_door(str);
}

