class BST:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    # Average:- O(log(n)) time | O(1) space    Wrost:-O(n) time | O(1) space
    def insert(self, data):
        currentNode = self
        while(True):
            # if the data is greater than or equal to currentNode's data, it will be placed in the right of currentNode
            if data >= currentNode.data:
                # if the right child of currentNode is empty, place the new node there with the data
                if currentNode.right is None:
                    currentNode.right = BST(data)
                    break
                # else move to the right child of currentNode
                else:
                    currentNode = currentNode.right

            # if the data is less than currentNode's data, it will be placed in the left of currentNode
            else:
                # if the left child of currentNode is empty, place the new node there with the data
                if currentNode.left == None:
                    currentNode.left = BST(data)
                    break
                # else move to the left child of currentNode
                else:
                    currentNode = currentNode.left

    # Average:- O(log(n)) time | O(1) space    Wrost:-O(n) time | O(1) space
    def find(self, data):
        currentNode = self
        while currentNode != None:
            # if currentNode's data is equal to data, we found the node hence return True
            if currentNode.data == data:
                return True

            # if the data is less than currentNode's data, it lies in the left of currentNode, hence point currentNode to its left child
            if data < currentNode.data:
                currentNode = currentNode.left
            # if the data is greater than or equal to currentNode's data, it lies in the right of currentNode, hence point currentNode to its right child
            else:
                currentNode = currentNode.right
        # return false if not found
        return False

def inorder(root):
    if root:
        inorder(root.left)
        print(root.data)
        inorder(root.right)

