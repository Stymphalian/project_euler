#!/usr/bin/python

import sys
import time
import itertools
import string


def convertToInt(perm):
	return reduce(lambda rs,d: rs*10 +d, perm)

def checkCondition(perm):
	divisors = [2,3,5,7,11,13,17]
	for i in range(1,8):
		if( convertToInt(perm[i:i+3]) % divisors[i-1] != 0 ):
			return False

	return True
		



def main():
	t = time.clock()

	Sum=0;
	for perm in itertools.permutations([0,1,2,3,4,5,6,7,8,9]):
		if( checkCondition(perm) ):
			Sum += convertToInt(perm)

	print Sum
	print "sys ( " +  str('%.5f' % (time.clock() - t)) + " s )"


if __name__ == "__main__":
	main()
