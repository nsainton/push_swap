#!/bin/zsh
#use as follows: have the scripts directory within your project folder and then run
#./scripts/test.sh number_of_vars number_of_tests
res_dir="results"
tests_dir="tests"
err_dir="errors"
if [ "$2" = "" ]
then
	echo "You must provide at least one argument for the script to work"
	echo -n "use as follows: have the scripts directory within your project folder and then run "
	echo "./scripts/test.sh number_of_vars number_of_tests"
	echo "You can provide the maximum number of operations allowed as an optional argument"
	echo "./scripts/test.sh number_of_vars number_of_tests maximum_allowed"
	exit 3
fi
if [ "$3" != "" ]
then
	maximum_allowed=$(( $3 ))
fi
make
mkdir -p $res_dir
mkdir -p $tests_dir
mkdir -p $err_dir
res_file="$res_dir/ops_$1.res"
tests_file="$tests_dir/ops_$1.tes"
err_file="$err_dir/ops_$1.err"
touch $res_file $tests_file
chmod 755 $res_file $tests_file
echo "These are the results for $1 values" > $res_file
echo "These are the tests for $1 values " > $tests_file
for (( i=0; i<$(( $2 )); i++ ))
do
	ARG="$(./scripts/randlist.py $1)"
	./push_swap $ARG | wc -l >> $res_file
	echo $ARG >> $tests_file
done
./scripts/results.py $1 $res_dir $tests_dir $err_dir $maximum_allowed
