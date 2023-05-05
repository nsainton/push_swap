#!/usr/bin/python3
import sys
import random
arglen = len(sys.argv)
if (arglen < 2):
	print("Please, provide a second argument")
	sys.exit(1)
number = int(sys.argv[1])
#print("This is your number : ", number)
L = list(range(number, 0, -1))
random.shuffle(L)
for num in L:
	if (num != L[-1]):
		print(num, end=' ')
	else:
		print(num, end='')
