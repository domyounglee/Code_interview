croatia=['c=','c-','dz=','d-','lj','nj','s=','z=']
check=['=','-','j']

count=0
x = input()
for i in range(len(x)):

	if x[i] in check:
		if x[i-2]+x[i-1]+x[i] in croatia:
			count-=1
			continue
		if x[i-1] + x[i] in croatia:
			continue

	count+=1
print(count)