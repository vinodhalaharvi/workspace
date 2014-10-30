import sys
for line in sys.stdin.readlines():
	line = line.strip()
	one, two = line.split()
	if sys.argv[1] == "method":
		print "+ %s:%s" % (one, two)
	elif sys.argv[1] == "prop":
		print "- %s:%s" % (one, two)

