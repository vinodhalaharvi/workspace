import sys

for i, line in enumerate(sys.stdin.readlines()):
	line = line.strip()
	print '{"%s", &%s},' % (line, line,)
