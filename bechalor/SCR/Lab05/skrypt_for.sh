#!/bin/bash 

trap 'echo "Nie uśmiercisz mnie tak łatwo, próbuj dalej SIGINT"' SIGINT 
trap 'echo "Nie uśmiercisz mnie tak łatwo, próbuj dalej SIGQUIT"' SIGQUIT 
trap 'echo "Nie uśmiercisz mnie tak łatwo, próbuj dalej SIGFPE"' SIGFPE 
trap 'echo "Nie uśmiercisz mnie tak łatwo, próbuj dalej SIGILL"' SIGILL 
trap 'echo "Nie uśmiercisz mnie tak łatwo, próbuj dalej SIGKILL"' SIGKILL 


while true
do 
	echo "cos `date +"%c"`"
	sleep 1
done
