#!/bin/bash

    RED='\033[0;31m'
    GREEN='\033[0;32m'
	VIOLET='\033[0;35m'
	BLUE='\033[0;34m'
    NO_COLOR='\033[0m'
	declare -g count=0
	

test_command() {
	CMD=$1

	mkdir -p temp
	touch temp/temp.txt
	touch temp/temp2.txt
	touch temp/valgrind.txt
  	bash -c "$CMD" > temp/temp2.txt 2>&1 
    BASH_STATUS=$?
	BASH_OUTPUT=$(cat temp/temp2.txt | head -n 1 | tr -d '\0' | awk -F':' '{print $NF}')

	# valgrind --track-fds=yes --trace-children=yes --suppressions=valgrind.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=temp/valgrind.txt 
	echo $CMD | /home/anferre/Documents/Our_Minishell/minishell > temp/temp.txt 2>&1
	MINISHELL_STATUS=$?
	MINISHELL_OUTPUT=$(grep -a -v '^minishell \$ >>' temp/temp.txt | head -n 1 | tr -d '\0' | awk -F':' '{print $NF}')
	
	# # Initialize messages for different types of memory issues
	# definitely_lost="Not checked"
	# indirectly_lost="Not checked"
	# possibly_lost="Not checked"
	# still_reachable="Not checked"

	# # Check for "definitely lost" bytes and update the message
	# if grep -q "definitely lost:" temp/valgrind.txt; then
	# 	definitely_lost=$(grep "definitely lost:" temp/valgrind.txt)
	# fi

	# # Check for "indirectly lost" bytes and update the message
	# if grep -q "indirectly lost:" temp/valgrind.txt; then
	# 	indirectly_lost=$(grep "indirectly lost:" temp/valgrind.txt)
	# fi

	# # Check for "possibly lost" bytes and update the message
	# if grep -q "possibly lost:" temp/valgrind.txt; then
	# 	possibly_lost=$(grep "possibly lost:" temp/valgrind.txt)
	# fi

	# # Check for "still reachable" bytes and update the message
	# if grep -q "still reachable:" temp/valgrind.txt; then
	# 	still_reachable=$(grep "still reachable:" temp/valgrind.txt)
	# fi

	# # Check for Valgrind errors
	# valgrind_errors=0
	# error_message=""

	# # Check each type of memory issue and update valgrind_errors if any errors are found
	# if [[ "$definitely_lost" != "0 bytes" && "$definitely_lost" != "Not checked" ]]; then
	# 	valgrind_errors=1
	# 	error_message+="Definitely Lost: $definitely_lost\n"
	# fi
	# if [[ "$indirectly_lost" != "0 bytes" && "$indirectly_lost" != "Not checked" ]]; then
	# 	valgrind_errors=1
	# 	error_message+="Indirectly Lost: $indirectly_lost\n"
	# fi
	# if [[ "$possibly_lost" != "0 bytes" && "$possibly_lost" != "Not checked" ]]; then
	# 	valgrind_errors=1
	# 	error_message+="Possibly Lost: $possibly_lost\n"
	# fi
	# if [[ "$still_reachable" != "0 bytes" && "$still_reachable" != "Not checked" ]]; then
	# 	valgrind_errors=1
	# 	error_message+="Still Reachable: $still_reachable\n"
	# fi

	# # Output based on whether Valgrind errors were found
	# if [[ $valgrind_errors -eq 0 ]]; then
	# 	echo -e "${GREEN}OK${NO_COLOR} - No Valgrind errors detected."
	# else
	# 	echo -e "${RED}KO${NO_COLOR} - Valgrind Memory Analysis:\n$error_message"
	# fi

	rm -rf temp/temp.txt temp/temp2.txt temp/valgrind.txt

	((count++))

	CMD=$(echo -E "$CMD" | sed ':a;N;$!ba;s/\n/\\n/g')

    if [[ "$BASH_OUTPUT" == "$MINISHELL_OUTPUT" && "$BASH_STATUS" == "$MINISHELL_STATUS" ]]; then
        echo -e  -n "${GREEN}OK${NO_COLOR} - "
		echo -E "Command n°$count '$CMD'"
		echo -e "Output : ${GREEN}"$MINISHELL_OUTPUT" ${NO_COLOR} and exit status : ${GREEN}"$MINISHELL_STATUS"${NO_COLOR} are the same${NO_COLOR}\n"
    else
        echo -e -n  "${RED}KO${NO_COLOR} - "
		echo -E "Command n°$count '$CMD'"

		# Compare the output
        if [[ "$BASH_OUTPUT" != "$MINISHELL_OUTPUT" ]]; then
            echo "Outputs differ"
            echo -e "Bash output: ${BLUE} \$$BASH_OUTPUT\$ ${NO_COLOR}"
            echo -e "Minishell output: ${BLUE} \$$MINISHELL_OUTPUT\$ ${NO_COLOR} \n"
		else
			echo -e "Output is the same ${GREEN}\$$MINISHELL_OUTPUT\$${NO_COLOR}   \n"
        fi

        # Compare the exit status
        if [[ "$BASH_STATUS" != "$MINISHELL_STATUS" ]]; then
            echo "Exit status differs"
            echo -e "Bash exit status: ${VIOLET} $BASH_STATUS ${NO_COLOR} "
            echo -e "Minishell exit status: ${VIOLET}$MINISHELL_STATUS${NO_COLOR} \n"
		else
			echo -e "${GREEN}Exit status is the same${NO_COLOR} \n"
        fi
    fi
}



echo -e ${VIOLET}"Syntax errors"${NO_COLOR}
# test_command $'\n' #don't have to handle the \
test_command $'          ' #spaces 
test_command $'					' #tabs
# test_command $':' #builtin command that does nothing and return 0 not to handle 
# test_command $'!' #not part of what should be handled
test_command $'>' #bash and the actual minishell don't handle  the same way but when > is given to bash and we press enter the error message is bash: syntax error near unexpected token `newline'
test_command $'<'
test_command $'>>'
test_command $'<<'
test_command $'>>>>>'
test_command $'>>>>>>>>>>>>'
# test_command $'<<<<<<<' #doesn't have to handle <<< so it's a syntax error with <<
# test_command $'<<<<<<<<<<<<'
test_command $'> > > >'
test_command $'>> >> >> >>'
test_command $'>>>> >> >> >>'
# # test_command $'/' #not in the mandatory to handle characters
# # test_command $'//' #not in the mandatory to handle characters
# # test_command $'/.' #not in the mandatory to handle characters
# # test_command $'/./../../../../..' #not in the mandatory to handle characters
# # test_command $'/////' #not in the mandatory to handle characters
# # test_command "-" #not in the mandatory to handle characters
test_command $'|'
test_command $'| hola'
test_command $'| | |'
test_command $'||'
test_command $'||||||'
test_command $'||||||||'
test_command $'>>|><'
test_command $'&&'
test_command $'&&&&&&&&'
test_command $'hola'
test_command $''hola''
test_command $'hola'
test_command $'hola que tal'
test_command $'Makefile'
test_command $'echo'
test_command $'echo -n'
test_command $'echo Hola'
test_command $'echoHola'
test_command $'echo-nHola'
test_command $'echo "-n" Hola'
test_command $'echo -nHola'
test_command $'echo Hola -n'
test_command $'echo 				Hola'
# test_command $'echo  Hola' #works in minishell just like in bash but the difference of input says the output is not the same
# test_command $'echo "	"  | cat -e' #output is the same but differ in the testeur 
test_command $'echo 			| cat -e'
test_command $'""''echo hola""'''' que ""'' tal""'''
test_command $'echo -n -n'
test_command $'echo -n-n hola que'
test_command $'echo -p'
test_command $'echo -nnnnnn'
test_command $'echo --nnnn'
test_command $'echo --n'
test_command $'echo $'
test_command $'echo $?'
test_command $'echo $? | echo $?'
test_command $'echo $? | echo $? | echo $?'
test_command $'echo $:$= | cat -e'
test_command $'echo " $ " | cat -e'
test_command $'echo $HOME'
test_command $'echo \'$HOME\''
test_command $'echo my term is [ $TERM ]'
test_command $'echo my term is [$TERM4'
test_command $'echo $HOME9'
test_command $'echo $TERM$HOME'
test_command $'echo $HOME%'
test_command $'echo $hola'
test_command $'echo > <'
test_command $'echo | |'
test_command $'EechoE'
test_command $'.echo.'
test_command $'>echo>'
test_command $'echo *'
test_command $'echo $""'
export VAR="HOLA"
export VAR1="$VAR como estas ?"
test_command $'echo \'$VAR\'' 
test_command $'echo hey\'$VAR\'hey' 
test_command $'echo "$VAR"' 
test_command $'echo $\'VAR\'' 
test_command $'echo $"VAR"'
test_command $'echo $VAR1'
test_command $'echo "$VAR1"'
test_command $'echo \'$VAR1\''
test_command $'echo $\'VAR1\''BLUE
test_command $'echo $"VAR1"'
unset $VAR1
unset $VAR
# test_command $'echo \'$\'\'\''
test_command $'echo $"HOME"'
test_command $'echo $\'\'HOME'
test_command $'echo ""$HOME'
test_command $'echo \'\' $HOME'
test_command $'echo $"HOLA"'
test_command $' echo $\'HOLA\''
test_command $'echo $DONTEXIST Hola'
test_command $' echo \'\'hola\'\''
test_command $'echo \'\'h\'o\'la\'\''
test_command $'echo \'\'\'ho\"\'\'\'\'l"a\'\'\''
test_command $'echo hola""""""""""""'
test_command $'echo hola"\'\'\'\'\'\'\'\'\'\'"'
test_command $'echo hola\'""""""""""\''
## test_command $'echo "hola     " | cat -e'  #same output but not in the tester 
test_command $'"e"\'c\'ho \'b\'"o"nj"o"\'u\'r'
test_command $'echo "$DONTEXIST" "Makefile"'
test_command $'"$HOMEdskjhfkdshfsd"'
test_command $'$HOMEdskjhfkdshfsd'
test_command $'echo "$HOME*"'
echo -e ${VIOLET}"ENV EXPORT UNSET "${NO_COLOR}
# test_command $'export ' #not the same output the order depend of the shell, bash version, or invocations
# test_command $'export Hola  export ' #same
# test_command $'export $DONTEXIST ' #same
test_command $'export HOLA=bonjour  env '
test_command $'env'
test_command $'export | grep "HOME" '
test_command $'export ""'
test_command $'export "\'\'"'
test_command $'export $?'
test_command $'export 9HOLA='
test_command $'export HOLA9=bonjour  env'
test_command $'export _HO_LA_=bonjour  env'
test_command $'export -HOLA=bonjour'
test_command $'export --HOLA=bonjour'
test_command $'export HOLA = bonjour'
test_command $'export HOLA=bon jour  env'
test_command $'export HOLA=bonsoir  export HOLA=bonretour  export HOLA=bonjour  env'
test_command $'export HOLA=bon$jour  env'
test_command $'export HOLA=hey  echo $HOLA$HOLA$HOLA=hey$HOLA'
test_command $'export HOLA="  bonjour  hey  "  echo """$HOLA""" | cat -e'
test_command $' export HOLA="s -la"  l$HOLA'
test_command $'export HOLA="s -la"   l"$HOLA"'
test_command $'export HOLA="s -la"   l\'$HOLA\''
test_command $'export HOLA="l"  $HOLAs'
test_command $'export HOLA="l"  "$HOLA"s'
test_command $'export TE+S=T  env'
test_command $'export ""=""'
test_command $'export \'\'=\'\''
test_command $'export "="="="'
test_command $'export \'=\'=\'=\''
test_command $'export HOLA=p  export BYE=w  "$HOLA"\'$BYE\'d'
test_command $'export HOLA=p  export BYE=w  "$HOLA""$BYE"d'
test_command $'export A=1 B=2 C=3 D=4 E=5 F=6 G=7 H=8  echo "$A\'$B"\'$C"$D\'$E\'"$F\'"\'$G\'$H"'
test_command $'export HOLA=bonjour env unset HOLA env'
test_command $'unset PATH  echo $PATH'
test_command $'unset PATH  ls'
test_command $'unset ""'
test_command $'unset INEXISTANT'
test_command $'unset PWD  env | grep PWD  pwd'
test_command $'unset PWD  env | grep PWD  cd $PWD  pwd'
test_command $'unset 9HOLA'
test_command $'unset _HOLA'
test_command $'unset -HOLA'
test_command $'unset HO-LA'
test_command $'unset $PWD'
test_command $'unset "" HOLA  env | grep HOLA'
test_command $'unset ======='
test_command $'unset PATH  cat Makefile'
test_command $'unset ='
test_command $'unset echo'
test_command $'unset export'
test_command $'unset pwd'
test_command $'unset cd'
test_command $'unset unset'
test_command $'unset sudo'
echo -e ${VIOLET}"Binary files "${NO_COLOR}
test_command $'/bin/echo'
test_command $'/bin/echo hola que tal'
test_command $'/bin/env'
test_command $'/bin/cd Desktop'
test_command $'pwd'
test_command $'pwd ./hola'
test_command $'pwd hola'
test_command $'pwd -p'
test_command $'pwd -p'
test_command $'pwd --p'
test_command $'pwd pwd pwd'
test_command $'pwd ls'
test_command $'pwd ls env'
test_command $'cd'
test_command $'cd .'
test_command $'cd ./'
test_command $'cd./././.'
test_command $'cd ././././'
test_command $'cd ..'
test_command $'cd ../'
test_command $'cd ../..'
test_command $'cd ../.'
test_command $'cd .././././.'
test_command $'cd srcs'
test_command $'cd srcs objs'
test_command $'cd \'srcs\''
test_command $'cd "srcs"'
test_command $'cd /e\'tc\''
test_command $'cd \'/ect\''
test_command $'cd sr'
test_command $'cd Makefile'
test_command $'../../minishell'
test_command $'cd ../../../../../..'
test_command $'cd ../../../bin/ls'
test_command $'cd /'
test_command $'cd \'/\''
test_command $'cd ////////  pwd'
test_command $'cd /minishell'
test_command $'cd $HOME'
test_command $'cd $HOME $HOME'
test_command $'unset HOME  cd $HOME'
test_command $'cd *'
test_command $'ls hola'
test_command $'./Makefile'
test_command $'touch hola  ./hola'
test_command $'env|"wc " -l'
test_command $'env|"wc" -l'
test_command $'expr 1 + 1'
test_command $'expr $? + $?'
# test_command $'env -i ./minishell  env' #they work but not in the tester
# test_command $'env -i ./minishell  export'
# test_command $'env -i ./minishell  cd'
# test_command $'env -i ./minishell  cd ~'
# test_command $'exit' # behaviour is different run from an interactive shell and from a script
test_command $'exit exit'
test_command $'exit hola'
# test_command $'exit 42' # behaviour is different run from an interactive shell and from a script
test_command $'exit -42' # behaviour is different run from an interactive shell and from a script
test_command $'exit --0'
test_command $'exit '----666''
test_command $'exit '+666'' # behaviour is different run from an interactive shell and from a script
test_command $'exit '666'' # behaviour is different run from an interactive shell and from a script
test_command $'exit '-666'' # behaviour is different run from an interactive shell and from a script
test_command $'exit "666"' # behaviour is different run from an interactive shell and from a script
test_command $'exit '2'66'32'' # behaviour is different run from an interactive shell and from a script
test_command $'exit '666'"666"666' # behaviour is different run from an interactive shell and from a script
test_command $'exit -'666'"666"666' # behaviour is different run from an interactive shell and from a script
test_command $'exit 9223372036854775807' # behaviour is different run from an interactive shell and from a script
test_command $'exit 9223372036854775808'
test_command $'exit -9223372036854775808' # behaviour is different run from an interactive shell and from a script
test_command $'exit -9223372036854775809' 
test_command $'cat | cat | cat | ls ' #need to ctrl + D to exit 
test_command $'ls | exit'
test_command $'ls | exit 42'
test_command $'exit | ls'
test_command $'echo hola > bonjour  exit | cat -e bonjour'
test_command $'echo hola > bonjour  cat -e bonjour | exit'
test_command $'echo |echo'
test_command $'echo hola | echo que tal'
test_command $'pwd| echo hola'
test_command $'env | echo hola'
test_command $'echo oui | cat -e'
test_command $'echo oui | echo non | echo hola | grep oui'
test_command $'echo oui | echo non | echo hola | grep non'
test_command $'echo hola | cat -e | cat -e | cat -e'
test_command $'cd .. | echo "hola"'
test_command $'cd / | echo "hola"'
test_command $'cd .. | pwd'
test_command $'ifconfig | grep ":"'
test_command $'ifconfig | grep hola'
test_command $'whoami | grep $USER'
## test_command $'whoami | grep $USER > /tmp/bonjour \n cat /tmp/bonjour'
## test_command $'whoami | cat -e | cat -e > /tmp/bonjour \n cat /tmp/bonjour'
## test_command $'whereis ls | cat -e | cat -e > /tmp/bonjour \n cat /tmp/bonjour'
test_command $'ls | hola'
test_command $'ls | ls hola'
test_command $'ls | hola | ls'
test_command $'ls -la | grep "."'
test_command $'ls -la | grep "'.'"'
test_command $'echo test.c | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e|cat -e|cat -e|cat -e'
test_command $'ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|l'
test_command $'echo hola | cat | cat | cat | cat | cat | grep hola'
test_command $'echo hola ||| cat'
test_command $'ech|o hola | cat'
test_command $'cat Makefile | cat -e | cat -e'
test_command $'cat Makefile | grep srcs | cat -e'
test_command $'cat Makefile | grep srcs | grep srcs | cat -e'
test_command $'cat Makefile | grep pr | head -n 5 | cd file_not_exist'
test_command $'cat Makefile | grep pr | head -n 5 | hello'
test_command $'unset HOLA | cat -e'
test_command $'/usr/bin/time sleep 3 | sleep 3' #same output but different params of exec 
test_command $'sleep 3 | exit'
# test_command $'echo hola > a \n >>b echo que tal \n cat a | <b cat | cat > c | cat' #doesn't work with the testeur but works in the shell
test_command $'pwd && ls'
test_command $'pwd || ls'
test_command $'echo hola || echo bonjour'
test_command $'echo hola && echo bonjour'
test_command $'echo -n bonjour && echo -n hola'
test_command $'pwd && ls && echo hola'
test_command $'ls || export ""'
test_command $'ls || '
test_command $'ls && '
test_command $'ls && <'
test_command $'cat | echo || ls'
# test_command $'cat | echo && ls' #doesn't work with the testeur but works in the shell
test_command $'ls && cat | echo'
test_command $'ls || cat | echo'
test_command $'export "" && unset ""'
# test_command $'(ls)' #doesn't work with the testeur but works in the shell
# test_command $'( ( ls ) )'  #doesn't work with the testeur but works in the shell
# test_command $'ls && (ls)' #doesn't work with the testeur but works in the shell
# test_command $'(ls && pwd) > hola' #no need to handle par are only for priorities 
test_command $'> hola ls && pwd'
test_command $'> hola (ls && pwd)'
test_command $'(ls||pwd)&&(ls||pwd)'
# test_command $'(ls && pwd | wc) > hola ' #no need to handle par are only for priorities 
# test_command $'(pwd | wc) < hola' #no need to handle par are only for priorities 
# test_command $'(ls && pwd | wc) < hola'  #no need to handle par are only for priorities 
# test_command $'(ls -z || pwd | wc) < hola' #no need to handle par are only for priorities 
test_command $'ls -z && (ls) && (pwd)'
test_command $'(cd ../.. && pwd) && pwd'
test_command $'echo hola > > bonjour'
test_command $'echo hola < < bonjour'
test_command $'echo hola >>> bonjour'
test_command $'< pwd'
test_command $'cat <pwd'
test_command $'cat >>'
test_command $'cat < ls'
test_command $'cat < ls > ls'
test_command $'<a cat <b <c'
test_command $'cat << hola | rev'
test_command $'<< hola'
test_command $'<<hola'
test_command $'cat <<'
test_command $'nimp << lol << cat << koala'
test_command $'<< $hola'
test_command $'<< $"hola"$"b"'
test_command $'ls *'
test_command $'ls *.*'
test_command $'ls *.hola'
test_command $'cat M*le'
test_command $'cat Make*file'
# #require to input commands line by line
# # test_command $'echo hey > hola \n (pwd | wc) < hola'
# # test_command $'ls -z || (cd ../../..&&pwd) \n pwd'
# # test_command $'(ls && pwd | wc) >> hola \n echo hey&&(ls && pwd | wc) > hola \n cat hola'
# # test_command $'echo hola > bonjour \n cat bonjour'
# # test_command $'echo hola >> bonjour \n cat bonjour'
# # test_command $'echo hola > bonjour \n echo que tal >> bonjour \n cat < bonjour'
# # test_command $'echo hola > bonjour \n rm bonjour \n echo que tal >> bonjour \n cat < bonjour'
# # test_command $'whereis grep > Docs/bonjour \n cat Docs/bonjour'
# # test_command $'pwd>bonjour \n cat bonjour'
# # test_command $'> bonjour echo hola \n cat bonjour'
# # test_command $'nimp hola > bonjour \n ls'
# # test_command $'echo hola > hello >> hello >> hello \n echo hola >> hello \n echo hola > hello >> hello >> hello \n cat < hello'
# # test_command $'echo hola > bonjour \n echo hey > hello \n echo hola >> bonjour >> hello >> bonjour \n cat bonjour \n cat hello'
# # test_command $'cat > ls1 < ls2 \n ls'
# # test_command $'>>hola \n cat hola'
# # test_command $'echo hola               >bonjour \n cat<                     bonjour'
# # test_command $'echo hola >srcs/bonjour \n cat <srcs/bonjour'
# # test_command $'e\'c\'"h"o hola > bonjour \n cat \'bo\'"n"jour'
# # test_command $'echo hola > bonjour hey \n ls \n cat bonjour \n cat hey'
# # test_command $'echo hola > ../bonjour \n echo hey > ../hello \n rm ../bonjour ../hello \n >../bonjour >../hello <prout \n ls .. \n cat ../bonjour ../hello'
# # test_command $'rm -f bonjour \n rm bonjour > bonjour \n ls -l bonjour'
# # test_command $'<a cat <b <c \n cat a \n cat b \n cat c'
# # test_command $'mkdir dir \n ls -la > dir/bonjour \n cat dir/bonjour'