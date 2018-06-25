#!/usr/bin/env python 
# -*- coding: utf-8 -*- 

class Node(object):
	def __init__(self,data=None):
		self.__data=data
		self.__next=None

	def __del__(self):
		print("data of {} is deleted".format(self.data))

	@property
	def data(self):
		return self.__data

	@data.setter
	def data(self,data):
		self.__data=data

	@property
	def next(self):
		return self.__next

	@next.setter
	def next(self, next):
		self.__next = next


class Linkedlist(object):
	
	def __init__(self):
		self.head=None
		self.tail=None
		self.size=0

	def is_empty(self):
		if self.size==0:
			return True
		else: 
			return False


	def append(self, data):

		#create a Node
		newnode=Node(data)

		#if it has no node 
		if self.is_empty():
			self.head=newnode
			self.tail=newnode
			#add one to size member
			self.size+=1
		#else
		else:
			self.tail.next=newnode
			self.tail=newnode
			#add one to size member
			self.size+=1


		return None


	def remove(self, target_data):
		#caution : It has four case 
		if self.is_empty():
			return None 
		# current and previous node
		prev=None 
		cur=self.head

		#if the target_data is head's data
		if  target_data == cur.data :
			data=cur.data
			# and also the tail's data 
			if cur.next == None :
				self.head=None
				self.tail=None 

			else:
				self.head=self.head.next
			
			self.size-=1
			return data


		#if the target_data is only in the tail
		while cur.next:
			#순서 중요
			prev=cur
			#update the cur and prev 
			cur=cur.next
			
			#if the updated data has the target_data
			if cur.data==target_data: 
				
				#if it is the tail 
				if cur==self.tail:
					print("sss")
					self.tail=prev

				prev.next=cur.next
				self.size-=1
				return cur.data

	


	def search_target(self, target_data, start=0):
		# output : (data,pos)

		#it starts always form zero
		pos=0
		#current node is head 
		cur=self.head

		#if pos is start 
		if pos>=start and cur.data==target_data:
			return cur.data, pos

		while cur.next :
			pos+=1
			cur = cur.next

			if pos>=start and cur.data==target_data:
				return cur.data, pos
			
		return None, None

	def search_pos(self, pos):
		# output: (data, pos)

		# current position
		cur_pos = 0
		cur = self.head

		#if pos is start 
		if cur_pos==pos:
			
			return cur.data, pos

		while cur.next :
			cur_pos+=1
			cur = cur.next
			if cur_pos==pos:
				
				return cur.data, pos
			
		return None, None


def show_list(slist):
    if slist.is_empty():
        print('The list is empty')
        return
    
    for i in range(slist.size):
        print(slist.search_pos(i))
        print("\n")


if __name__ == '__main__':
	list=Linkedlist()

	list.append(3)
	list.append(2)
	list.append(4)
	
	show_list(list)
	print("search target")
	print(list.search_target(2))
	print("remove")
	list.remove(4)
	print("show")
	show_list(list)
	print("finish")

