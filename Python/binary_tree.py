#!/usr/bin/env python 
# -*- coding: utf-8 -*- 

class Tree_node():
	def __init__(self,data=None):
		self.__data=data
		self.__lchild=None
		self.__rchild=None

	#노드 삭제를 확인하기 위한 코드 
	def __del__(self):
		print("data of {} is deleted".format(self.data))

	@property
	def data(self):
		return self.__data

	@data.setter
	def data(self, data):
		self.__data=data

	@property
	def lchild(self):
		return self.__lchild

	@lchild.setter
	def lchild(self, node):
		self.__lchild=node

	@property
	def rchild(self):
		return self.__rchild

	@rchild.setter
	def rchild(self, node):
		self.__rchild=node


class Binary_tree():
	def __init__(self):
		self.root=None

	def get_root(self):
		return self.root

	def set_root(self,node):
		self.root=node

	def get_right_child(self,curr_node):
		return curr_node.rchild

	def set_right_child(self,curr_node,node):
		curr_node.rchild=node

	def get_left_child(self,curr_node):
		return curr_node.lchild

	def set_left_child(self,curr_node,node):
		curr_node.lchild=node

	def preorder_traversal(self,node):

		if node== None:
			return 

		print(node.data)
		self.preorder_traversal(node.lchild)
		self.preorder_traversal(node.rchild)

	def inorder_traversal(self,node):

		if node== None:
			return 
			
		self.inorder_traversal(node.lchild)
		print(node.data)
		
		self.inorder_traversal(node.rchild)

	def postorder_traversal(self,node):

		if node== None:
			return 
			
		
		self.postorder_traversal(node.lchild)
		self.postorder_traversal(node.rchild)
		print(node.data)



if __name__ == "__main__":

	#generate Binary Tree
	BTree=Binary_tree()

	#generate Treenode
	node1=Tree_node(1)

		
	node2=Tree_node(2)

	node3=Tree_node(3)

	node4=Tree_node(4)

	node5=Tree_node(5)

	node6=Tree_node(6)

	node7=Tree_node(7)

	#set as root 
	BTree.set_root(node1)

	#set root's child
	BTree.set_right_child(node1,node3)
	BTree.set_left_child(node1,node2)

	#set node2's child
	BTree.set_right_child(node2,node5)
	BTree.set_left_child(node2,node4)

	#set node3's child
	BTree.set_right_child(node3,node7)
	BTree.set_left_child(node3,node6)


	BTree.preorder_traversal(BTree.root)
	print("_________________________")
	BTree.inorder_traversal(BTree.root)
	print("_________________________")
	BTree.postorder_traversal(BTree.root)

