
# My-C-LinkedList

My-C-LinkedList is a mini script i made for my **Advanced Programming** University class, which is written in C and demonstrates how **linked lists** work.

## How It Works?
In order to save data in the list we need to create a **Node**. A Node is an entity
which stores our referenced **data** and a **reference** to the next Node in the memory. By doing
that, we have the ability to store data **whenever** we need to, and also **expand** our list without
having to create a new one!

# 
To achieve that in C, i used structs to create the Nodes and set the attributes
to: 
-  A **void pointer** to the value 
-  A **Node pointer** to the next Node.

For a visual representation see the [Diagram](https://imgur.com/a/PwxXhIQ).


## Functions

```c
struct Node* createNode(void) // Creates the head Node and returns a pointer to it.
void pushElement(struct Node* hNode, void* element) // Pushes a new Node at the end of the Node chain.
void popElement(struct Node* hNode) // Delete/Pop the last Node from the Node chain.
void* getElement(struct Node* hNode, int index) // Get the value attribute from a Node by it's index

void printNode__Type__(struct Node* hNode) //Prints the Node chain. 
//Replace __Type__ with one of the 3 supported types(Int,Float,Str). Eg: printNodeInt for integers.
```
- hNode: head Node.
- The printer functions **are not D.R.Y**, but they do their job for demo purposes.
  
## Authors

- [@Alexandros Vasileiou](https://www.github.com/TheVasalex)

  