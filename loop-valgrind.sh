ROOT=..
TIME_LIMIT=2.0

RED="\e[31m"
GREEN="\e[32m"
NOCOLOR="\e[0m"

if [ $# -lt 2 ]
then
	printf "${RED}Error : not enough arguments${NOCOLOR}\n"
	printf "Usage : bash loop.sh <stack size> <loop times>"
	exit 1
fi
make -C ./files/
g++ -O3 ./files/main.cpp -o ./files/better_random_test_cases
for ((i=1;i<=$2;i++));
do
./files/better_random_test_cases $@ > ./trace_loop/test_case_$i.txt
done

make -C $ROOT/

clear

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\ncheck if the variable ROOT in loop.sh is correct\n"
	exit 1
fi

declare -i total=0
declare -i count=0
declare -i max=0
declare -i min=1000000000

FLAG="${GREEN}OK${NOCOLOR}"
LEAKFLAG="${GREEN}NO LEAKS${NOCOLOR}"
for ((i=1;i<=$2;i++));
do
printf "$i	"
($ROOT/push_swap $(cat ./trace_loop/test_case_$i.txt) > ./trace_loop/output_$i.txt) & pid=$!
(sleep $TIME_LIMIT && kill -HUP $pid) 2>/dev/null & watcher=$!
if wait $pid 2>/dev/null; then
	TLEFLAG=0
else
	TLEFLAG=1
fi

if [[ "$TLEFLAG" = "0" ]];
then
	# Usando Valgrind para verificar vazamentos de memória
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet $ROOT/push_swap $(cat ./trace_loop/test_case_$i.txt) > a 2>c
	# Verificar se não houve vazamentos
	grep "0 bytes in 0 blocks" a > b
	if grep -q "definitely lost" a || grep -q "indirectly lost" a; then
		TEMPLEAK="${RED}LEAKS	${NOCOLOR}"
		LEAKFLAG="${RED}LEAKS	${NOCOLOR}"
	else
		# Nenhum vazamento detectado
		TEMPLEAK="${GREEN}NO LEAKS${NOCOLOR}"
	fi
	if [[ -s c ]]; then
		TEMPLEAK="Valgrind command not found	"
		LEAKFLAG="Valgrind command not found	"
	fi
	rm -rf a
	rm -rf b
	rm -rf c
	printf "$TEMPLEAK	"
else
printf "		"
fi

# Instruções e resultados do checker
printf "instructions amounts : "
count=$(cat ./trace_loop/output_$i.txt | wc -l)
printf "$count "
total=$((total + count))
if [ $count -gt $max ]
then
	max=count
	max_tag=$i
fi
if [ $count -lt $min ]
then
	min=count
	min_tag=$i
fi
printf "	checker result : "
if [[ "$TLEFLAG" = "1" ]]
then
	printf "${RED}TLE${NOCOLOR}\n"
	FLAG="${RED}KO${NOCOLOR}"
else
printf "${RED}"
cat ./trace_loop/output_$i.txt | ./files/checker $(cat ./trace_loop/test_case_$i.txt) > temp_result
printf "${NOCOLOR}"
temp=$(cat temp_result)
if [[ "$temp" = "OK" ]]
then
	printf "${GREEN}OK${NOCOLOR}\n"
elif [[ "$temp" = "KO" ]]
then
	printf "${RED}KO${NOCOLOR}\n"
	FLAG="${RED}KO${NOCOLOR}"
else
	FLAG="${RED}KO${NOCOLOR}"
fi
fi
done
rm -rf temp_result
average=$((total/$2))
printf "\n"
printf "stack size 		$1\n"
printf "loop time		$2\n"
printf "test result		$FLAG\n"
printf "total instructions	$total\n"
printf "maximum instructions	$max (test case $max_tag)\n"
printf "minimum instructions	$min (test case $min_tag)\n"
printf "average instructions	$average\n"
printf "memory			$LEAKFLAG\n"
echo "test_case and output are in trace_loop"
rm ./files/better_random_test_cases

