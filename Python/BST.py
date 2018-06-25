from binary_tree import *

class BST():
	def __init__(self):
		self.root=None

	def get_root(self):
		return self.root

	def set_root(self,node):
		self.root=node

	def preorder_traversal(self,node):

		if node== None:
			return 

		print(node.data)
		self.preorder_traversal(node.lchild)
		self.preorder_traversal(node.rchild)

	def insert(self,target):

		node=Tree_node(target)


		cur = self.get_root()

		if cur==None:
			self.root = node
			return

		while True:

			parent = cur
		
			if target < cur.data:
				print('-')
				cur= cur.lchild

				if cur==None:
					parent.lchild=node
					return

			else:
				print("--")
				cur=cur.rchild

				if cur==None:
					parent.rchild=node
					return



	def search(self,target):

		cur=self.get_root()

		while cur:
			if target == cur.data:
				return cur
			if target < cur.data:
				cur=cur.lchild
			else:
				cur=cur.rchild
		return 

	def remove(self, target):
		#루트 노드의 변경 가능성이 있으므로
		#루트를 업데이트 해주어야 한다.
		self.root, removed_node = self.__remove_recursion(self.root, target)
		#삭제된 노드의 자식 노드를 None으로 만든다
		removed_node.lchild = removed_node.rchild = None

		return removed_node

	def __remove_recursion(self, cur, target):
		#if node is None 
		if cur==None:
			return None,None
		
		#if the node.data!=target
		if target<cur.data:
			cur.lchild, removed_node=self.__remove_recursion(cur.lchild,target)
		elif target>cur.data:
			cur.rchild, removed_node=self.__remove_recursion(cur.rchild,target)
		
		#if the node.data==target
		else:	
			#if leaf node 
			if cur.rchild==None and cur.lchild == None:
				removed_node=cur
				cur=None
			#if it has only one child
			elif cur.lchild==None:
				removed_node=cur
				cur=cur.rchild
			elif cur.rchild==None:
				removed_node=cur
				cur=cur.lchild
			#if it has two child
			else:
				removed_node=cur 
				swap_node=cur.lchild
				while swap_node.rchild:
					swap_node=swap_node.rchild
				#swap the data of remove node and swap_node
				cur.data, swap_node.data = swap_node.data, cur.data
				#바뀐 node 추적해서 배터내게하기 
				cur.lchild, removed_node = self.__remove_recursion(cur.lchild,target)

		return cur,removed_node

	def insert_node(self,node):
		cur = self.get_root()

		if cur==None:
			self.root = node
			return

		while True:

			parent = cur
		
			if node.data < cur.data:
				print('-')
				cur= cur.lchild

				if cur==None:
					parent.lchild=node
					return

			else:
				print("--")
				cur=cur.rchild

				if cur==None:
					parent.rchild=node
					return



if __name__ == "__main__":
    bst = BST()
    
    #insert
    bst.insert(6)
    bst.insert(3)
    bst.insert(2)
    bst.insert(4)
    bst.insert(5)
    bst.insert(8)
    bst.insert(10)
    bst.insert(9)
    bst.insert(11)
    
    
    f = lambda x: print(x, end = '  ')
    
    #전위 순회
    bst.preorder_traversal(bst.get_root())
    print()
    print(bst.search(10).data)
    """
    print("remove")
    #remove - 1 : 리프 노드일 때
    bst.remove(9)
    bst.preorder_traversal(bst.get_root())
    print()
    #remove - 2 : 자식 노드 하나일 때
    bst.remove(8)
    bst.preorder_traversal(bst.get_root())
    print()
    #remove - 3: 자식 노드 두 개일 때
    bst.remove(6)
    bst.preorder_traversal(bst.get_root())
    print()
    #search
    print("searched data : {}".format(bst.search(10).data))
	"""
	
    #이진 탐색 트리에서 6 노드를 삭제
    node = bst.remove(6)
    #반환 받은 삭제 노드의 데이터를 7로 변경
    node.data = 7
    #변경된 노드를 이진 탐색 트리에 다시 삽입한다 
    bst.insert_node(node)

    #기대 출력 값 : 5  3  2  4  8  7  10  9  11
    bst.preorder_traversal(bst.get_root())

    print()

