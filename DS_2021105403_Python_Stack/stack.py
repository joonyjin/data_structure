class Stack():
    def __init__(self,size):
        self.stack = []
        self.size = size
        self.length = 0
        self.currentpos = -1
        
    def IsFull(self):
        Is_Full = False
        if self.size <= self.length:
            Is_Full = True
        return Is_Full
    
    def IsEmpty(self):
        Is_Empty = False
        if self.currentpos == -1:
            Is_Empty = True
        return Is_Empty
    
    def Push(self, input):
        if self.IsFull():
            print("It's Full!!\n")
        else:
            self.stack.append(input)
            self.length += 1
            self.currentpos += 1
    
    def Pop(self):
        if self.IsEmpty():
            print("It's Empty!!")
        else:
            self.stack.pop()
            self.currentpos -= 1
            self.length -= 1
            
    def Print(self):
        for i in range (self.length):
            print(self.stack[i])
        print('\n')
    
    def Top(self):
        return self.stack[self.length-1]

a = Stack(5)
a.Pop()
print("Current Size of a stack : " + str(a.length) + "\n")
a.Push(1)
print("Current Size of a stack : " + str(a.length) + "\n")
a.Print()
a.Push(2)
a.Push(3)
a.Push(4)
print(a.Top())
a.Push(5)
print("Current Size of a stack : " + str(a.length) + "\n")
a.Push(6)
a.Print()
a.Pop()
a.Top()
