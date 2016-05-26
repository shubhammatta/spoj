import sys

n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]
a = map(int,raw_input().strip().split(' '))
    
new = {}
count = 0

for i in xrange(0, len(a) - 1) :
    for j in xrange(i + 1, len(a)) :
        if (a[i] + a[j]) % k == 0 :
            if a[i] not in new and a[j] not in new :
                count += 1
                new[a[i]] = 1
                new[a[j]] = 1            
print len(a) - count