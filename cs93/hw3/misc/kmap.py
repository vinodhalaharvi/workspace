import numpy as np
import sys


def index(string):
	"""docstring for index"""
	ind = {
			"00" : 0, 
			"01" : 1, 
			"11" : 2, 
			"10" : 3, 
	}
	return ind[string]

if __name__ == '__main__':
	#filename = sys.argv[1]
	#file = open(filename)
	ab = ("00", "01", "11", "10", )
	cd = ("00", "01", "11", "10", )
	kmap = np.zeros((4, 4, 4))
	for line in sys.stdin.readlines():
		line = line.strip()
		inp, out = line.split("\t")
		ab = inp[0:2]
		cd = inp[2:4]
		#print ab, cd, out
		for i, c in enumerate(out):
			if c == "1":
				kmap[i][index(cd)][index(ab)] =  1
			else:
				kmap[i][index(cd)][index(ab)] =  0
				
	for i in range(len(out)):	
		print kmap[i]
		print
