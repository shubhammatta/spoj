n = int(input())
while n>1 :
	if(n==3):
		print "NIE"
		break
	
	if(n%2==0):
		n/=2
	else:
		n= 3*n+3
	if(n==1):
		print "TAK"
		break
