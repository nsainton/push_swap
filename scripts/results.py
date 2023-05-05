#!/usr/bin/python3
import sys
arglen = len(sys.argv)
if (arglen < 5):
	print("Please provide as a first argument the number of values that were analysed")
	print("Please provide as a second argument the name of the results directory")
	print("Please provide as a third argument the name of the tests directory")
	print("Please provide as a fourth argument the name of the errors directory")
	print("You can provide as an optional argument the maximum number of operations that you allow for the list size you provided")
	sys.exit(1)
operations = f"/ops_{sys.argv[1]}"
res_file = f"{sys.argv[2]}" + operations + ".res"
tests_file = f"{sys.argv[3]}" + operations + ".tes"
errors_file = f"{sys.argv[4]}" + operations + ".err"
values = int(sys.argv[1])
results = open(res_file, "r")
with open(res_file, "r") as results:
	contents = results.readlines()
	#print(contents)
del contents[0]
results = list(map(int, contents))
with open(tests_file, "r") as tf:
	tests = tf.readlines()
del tests[0]
max = max(results)
print(f"This is the maximum number of operations for {sys.argv[1]} values\
 on the given list  : {max}")
print(f"This is the size of the current results list : {len(results)}")
maximum = 0
if values < 5:
	maximum = 2
elif values < 100:
	maximum = 12
elif values < 500:
	maximum = 700
else:
	maximum = 5500
if (arglen > 5):
	maximum = int(sys.argv[arglen - 1])

over = 0
f = open(errors_file, 'w', encoding="utf-8")
if f.closed:
	print(f"Error while opening {errors_file}")
for i in range(len(results)):
	if results[i] > maximum:
		over += 1
		message = f"The list [{tests[i]}] resulted in : {results[i]} operations\n" + f"These are {results[i] - maximum} operations over the maximum allowed\n"
		print(message, end='')
		if (f.closed == False):
			f.write(message)
if (f.closed == False):
	f.close()
print(f"This is the maximum number of operations allowed : {maximum}")
print(f"This is the number of values over the allowed maximum : {over}")
