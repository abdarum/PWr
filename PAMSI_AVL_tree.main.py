"""AVL Tree
test

Program written for PAMSI by Kornel Stefańczyk nr 235420
5.03.2018
"""

__version__ = '0.01'

active_debbuging = True

def debug(msg):
    if active_debbuging:
        print(msg)


class Node():
    """Basic class for implementing binary trees """
    def __init__(self,key=None, parent=None, rightChild=None, leftChild=None):
        """Class initialisation  """
        self.key=key
        self.parent = parent
        self.rightChild = rightChild 
        self.leftChild = leftChild


class AVLNode(Node):
    """Class contain structure of AVL tree and methods to operate on this tree  """
    def __init__(self, key=None, parent=None, rightChild=None, leftChild=None, balance=0):
        Node.__init__(self, key, parent, rightChild, leftChild)
        self.balance = balance


def bst_count(top):
    """Counting number of nodes"""
    if top is None:
        return 0
    return bst_count(top.leftChild) + 1 + bst_count(top.rightChild) 

def bst_height(top):
    """Function return height of children nodes of "top" node """
    if top is None:
        return 0
    left = bst_height(top.leftChild)
    right = bst_height(top.rightChild)
    return 1 + max(left, right)

def bst_insert(root, new_node):
    """Function insert node to tree """
    parent = None
    node = root
    #Moving through tree to get access to last element of tree
    while node:
        parent = node
        if new_node.key < node.key:
            node = node.leftChild
        else:
            node = node.rightChild
    #If tree is not empty add node on the ond of this tree
    if parent:
        if new_node.key < parent.key:
            parent.leftChild = new_node
            debug("Added new element to tree, key= "+str(new_node.key)+" left child")
        else:
            parent.rightChild = new_node
            debug("Added new element to tree, key= "+str(new_node.key)+" right child")
    else:
        root = new_node
    new_node.parent = parent
    new_node.leftChild = None
    new_node.rightChild = None

def show_tree_inorder(top):
    """Function return tree like a list: left_child, current_node, right_child"""
    if top is None:
        return []
    order = []
    order.extend(show_tree_inorder(top.leftChild))
    order.append(top.key)
    order.extend(show_tree_inorder(top.rightChild))
    return order

def show_tree_preorder(top):
    """Function return tree like a list: current_node, left_child, right_child"""
    if top is None:
        return []
    order = []
    order.append(top.key)
    order.extend(show_tree_inorder(top.leftChild))
    order.extend(show_tree_inorder(top.rightChild))
    return order

def show_tree_postorder(top):
    """Function return tree like a list: left_child, right_child, current_node"""
    if top is None:
        return []
    order = []
    order.extend(show_tree_inorder(top.leftChild))
    order.extend(show_tree_inorder(top.rightChild))
    order.append(top.key)
    return order



print("test drzewa")
AVLTree = AVLNode(key=5)
bst_insert(AVLTree, AVLNode(key=4))
print(bst_height(AVLTree))
print(bst_count(AVLTree))
print(show_tree_preorder(AVLTree))

bst_insert(AVLTree, AVLNode(key=6))
print(bst_height(AVLTree))
print(bst_count(AVLTree))
print(show_tree_preorder(AVLTree))

bst_insert(AVLTree, AVLNode(key=7))
print(bst_height(AVLTree))
print(bst_count(AVLTree))
print(show_tree_preorder(AVLTree))

bst_insert(AVLTree, AVLNode(key=3))
print(bst_height(AVLTree))
print(bst_count(AVLTree))
print(show_tree_preorder(AVLTree))


