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

def index1(string):
	"""docstring for index"""
	ind = {
		"0" : 0, 
		"1" : 1, 
	}
	return ind[string]

if __name__ == '__main__':
	kmap = np.zeros((4, 2, 4, 4))
	for line in sys.stdin.readlines():
		line = line.strip()
		inp, out = line.split("\t")
		z = inp[0]
		ab = inp[1:3]
		cd = inp[3:5]
		#print ab, cd, out
		for i, c in enumerate(out):
			if c == "1":
				kmap[i][index1(z)][index(cd)][index(ab)] =  1
			else:
				kmap[i][index1(z)][index(cd)][index(ab)] =  0
				
	for i in range(len(out)):	
		print kmap[i]
		print
		
