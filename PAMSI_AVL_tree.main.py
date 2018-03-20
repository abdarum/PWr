"""AVL Tree

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


def bst_find_min(top):
    """Function return node of least element of tree"""
    if top is None:
        raise ValueError("empty tree")
    while top.leftChild:
        top = top.leftChild
    return top

def bst_find_max(top):
    """Function return node of maximum element of tree"""
    if top is None:
        raise ValueError("empty tree")
    while top.rightChild:
        top = top.rightChild
    return top

def bst_insert(root, new_node):
    """Function insert node to tree 
    
    It return root and new created node"""
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

    return root, new_node


def bst_transplant(root, node_to_replace, transplanted_node):
    """Function transplant place node from third argument in place of node from second argument

    It return root and transplanted_node"""
    if node_to_replace.parent is None:
        root = transplanted_node
        if root:
            root.parent = None
        return root, transplanted_node
    elif node_to_replace == node_to_replace.parent.leftChild:
        node_to_replace.parent.leftChild = transplanted_node
    else:
        node_to_replace.parent.rightChild = transplanted_node
    if transplanted_node:
        transplanted_node.parent = node_to_replace
    return root, transplanted_node



def bst_delete(root, node):
    """ Function delete node called in as argument

    It return root and node that will be in place of deleted node"""
    if root is None or node is None:
        return root, None
    if node.leftChild is None:
        return bst_transplant(root, node, node.rightChild)
    elif node.rightChild is None:
        return bst_transplant(root, node, node.leftChild)
    else:      #it has left and right child
        y = bst_find_min(node.rightChild)
        if y.parent != node:
            root, _ = bst_transplant(root, y, y.rightChild)
            y.rightChild = node.rightChild
            if y.rightChild:
                y.rightChild.parent = y
        root, _ = bst_transplant(root, node, y)
        y.leftChild = node.leftChild
        y.leftChild.parent = y
        return root, y

def bst_rotate_left(root, top):
    """Function do left rotation of subtree"""
    if top.rightChild is None:
        debug("There is no right rotation")
        return root, top     #there is no rotation
    node = top.rightChild
    top.rightChild = node.leftChild
    if node.leftChild:
        node.leftChild.parent = top
    node.parent = top.parent
    if top.parent is None:
        root = node # node was root
    elif top == top.parent.leftChild:
        top.parent.leftChild = node
    else:
        top.parent.rightChild = node
    node.leftChild = top
    top.parent = node
    return root, node

def bst_rotate_right(root, top):
    """Function do right rotation of subtree"""
    if top.leftChild is None:
        debug("There is no right rotation")
        return root, top
    node = top.leftChild
    top.leftChild = node.rightChild
    if node.rightChild:
        node.rightChild.parent = top
    node.parent = top.parent
    if top.parent is None:
        root = node
    elif top == top.parent.rightChild:
        top.parent.rightChild = node
    else:
        top.parent.leftChild = node
    node.rightChild = top
    top.parent = node 
    return root, node



def return_tree_inorder(top):
    """Function return tree like a list: left_child, current_node, right_child"""
    if top is None:
        return []
    order = []
    order.extend(return_tree_inorder(top.leftChild))
    order.append(top.key)
    order.extend(return_tree_inorder(top.rightChild))
    return order

def return_tree_preorder(top):
    """Function return tree like a list: current_node, left_child, right_child"""
    if top is None:
        return []
    order = []
    order.append(top.key)
    order.extend(return_tree_inorder(top.leftChild))
    order.extend(return_tree_inorder(top.rightChild))
    return order

def return_tree_postorder(top):
    """Function return tree like a list: left_child, right_child, current_node"""
    if top is None:
        return []
    order = []
    order.extend(return_tree_inorder(top.leftChild))
    order.extend(return_tree_inorder(top.rightChild))
    order.append(top.key)
    return order

def avl_tree_rebalance(node):
    """This function rebalance AVL Tree, and it is using in function like avl_node_insert or avl_node_delete"""
    pass

def avl_node_insert():
    pass

def avl_node_delete():
    pass


def print_status_of_tree(root):
    """Test function"""
    print("\theight: "+str(bst_height(AVLTree))+", number of nods "+str(bst_count(AVLTree))+"\n"+str(return_tree_postorder(AVLTree)))



print("test drzewa")
AVLTree = AVLNode(key=5)
bst_insert(AVLTree, AVLNode(key=4))
print_status_of_tree(AVLTree)


bst_insert(AVLTree, AVLNode(key=6))
print_status_of_tree(AVLTree)


bst_insert(AVLTree, AVLNode(key=7))
print_status_of_tree(AVLTree)

bst_insert(AVLTree, AVLNode(key=3))
print_status_of_tree(AVLTree)

bst_insert(AVLTree, AVLNode(key=8))
print_status_of_tree(AVLTree)

bst_insert(AVLTree, AVLNode(key=9))
print_status_of_tree(AVLTree)


bst_insert(AVLTree, AVLNode(key=8))
print_status_of_tree(AVLTree)



print(AVLTree.rightChild.rightChild.key)
bst_rotate_left(AVLTree, AVLTree.rightChild.rightChild)
print(AVLTree.rightChild.rightChild.key)


print_status_of_tree(AVLTree)
bst_delete(AVLTree, AVLTree.rightChild)
print_status_of_tree(AVLTree)




