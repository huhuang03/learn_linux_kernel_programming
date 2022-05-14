echo "System release info:"

which lsb_release >/dev/null

if [ $? -eq 0 ] ; then
    lsb_release -a 2>/dev/null
else
    [ -f /etc/issue ] && cat /etc/issue
    [ -f /etc/os-release ] && cat /etc/os-release
fi


total_procs=$(ps -A | wc -l)
printf "\nTotal # of process avlie\t\t\t=%9d\n" ${total_procs}


total_thrds=$(ps -LA | wc -l)
printf "Total # of threds avlie\t\t\t=%9d\n" ${total_procs}

totla_kthrds=$(ps aux | awk '{print $11}' | grep "^\[" | wc -l)
printf "Total # of kernel threds avlie\t\t\t=%9d\n" ${total_procs}
printf "Thus, total # of usermode threds avlie\t\t\t=%9d\n" $((${totla_thrds} - ${total_kthrds}))

