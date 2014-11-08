import sys 

i = 0 
for line in sys.stdin.readlines():
	line = line.strip()
	if i == 0: 
		header = line.split()
		i += 1
		continue
	tokens = line.split()
	print "{" +  \
		", ".join(['.%s="%s"' % (a, b) for a, b in zip(header, tokens)]) + \
		"},"
	i += 1
	
