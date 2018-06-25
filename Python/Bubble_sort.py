#!/usr/bin/env python 
# -*- coding: utf-8 -*- 

def Bubble_sort(data):
	#오름차순
	for i in range(len(data)-1):
		for j in range(i+1,len(data)):
			if data[i]>=data[j]:
				temp=data[i]
				data[i]=data[j]
				data[j]=temp
	return data

if __name__ == '__main__':
	data=[5,1,1,1,1,1,6]
	print(Bubble_sort(data))
