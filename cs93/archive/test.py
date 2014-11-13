import sys


for line in sys.stdin.readlines():
	line = line.strip()
	for t in line.split():
		a, b =  t.split("-")
		print "get(num, %d, %d), " % (int(b), int(a),),

