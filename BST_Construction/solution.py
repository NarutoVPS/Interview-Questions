class BST:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def insert(self, data):
        currentNode = self
        while(True):
            if data >= currentNode.data:
                if currentNode.right is None:
                    currentNode.right = BST(data)
                    break
                else:
                    currentNode = currentNode.right

            else:
                if currentNode.left = None:
                    currentNode.left = BST(data)
                    break
                else:
                    currentNode = currentNode.left