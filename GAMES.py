from fractions import Fraction
from decimal import Decimal
import math
t = int(input())
while(t>0):
	n = float(raw_input())
	new = n*100000
	print new
	k =  int(n)*100000
	new = new - k
	print new
	if(n==0):
		print 1
	else:
		
		n/=10
		
		#den =  Fraction(n,p)
		#print den.denominator
		
	t-=1