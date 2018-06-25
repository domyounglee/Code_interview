#!/usr/bin/env python 
# -*- coding: utf-8 -*- 
def binary_search(data, target):
	#미리 정렬되있어야함. 
	data.sort()

	start=0
	end=len(data)-1
	mid = (end+start)//2

	while(end-start>=0):
		#if target return mid
		if data[mid]==target:
				return mid

		if data[mid]>target:
			end=mid-1
			mid = (end+start)//2
		else:
			start=mid+1
			mid = (end+start)//2

	return None 


if __name__ == '__main__':
	data=[i**2 for i in range(1,11)]

	target =9

	idx=binary_search(data,target)

	if idx ==None:
		print("{} 존재 안함".format(target))
	else:
		print("index, data = {} and {}".format(idx,data[idx]))


	for i in range(1,11):
		print(binary_search(data,i**2))

