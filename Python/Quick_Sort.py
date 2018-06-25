#!/usr/bin/env python 
# -*- coding: utf-8 -*- 
def quick_sort(data, start, end):

	#탈출조건 
	if start-end>=0:
		print("--")
		return
	#set left and right and pivot 
	left=start
	right=end

	pivot=data[(end+start)//2]

	print(pivot)
	
	while(left<=right):
	
		#move left right
		while(data[left] < pivot):
			left+=1
			print("left"+str(left))
		while(data[right] >  pivot):
			right-=1
			print("right"+str(right))


		#left와 right가 교차하지 않았다면 교환
		if (left<=right):
			
			data[left], data[right] = data[right], data[left]
			left += 1
			right -= 1


		print(data)
		#print(left,right)

	print("_________")
	quick_sort(data, start, right)
	quick_sort(data, left, end)


if __name__ == "__main__":
    data = [2, 5, 4, 1, 8, 10, 5, 3, 1, 6, 5, 7, 9, 12, 11]
    quick_sort(data, 0, len(data) - 1)
    #print(data)
