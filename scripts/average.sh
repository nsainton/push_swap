#!/bin/zsh
ret="0"
if [ "$1" = "" ]
then
	echo "You have to provide one argument for the script to work"
	exit 3
fi
for i in {1..$1}; do arg="$(./scripts/test.sh $i | grep sorted | awk -F ' ' '{print $(NF - 1)}')";\
ret="${ret}+ ${arg}"; done
echo -n "The average number of operation needed in the worst case is : "
echo "(${ret}) / $1" | bc
