import sys

def binary(num, length=8):
    return format(num, '#0{}b'.format(length + 2))

def main(digits):
	"""docstring for main"""
	r = 2 ** digits
	for i in range(r):
		print binary(i, length=digits)[2:]

if __name__ == '__main__':
	main(int(sys.argv[1]))
