def noOverTime(N,work_lst):

	while N>0:
		work_lst[work_lst.index(max(work_lst))]-=1
		N-=1

	return sum([n**2 for n in work_lst])


print(noOverTime(4,[4,3,3]))
