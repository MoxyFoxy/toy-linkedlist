# Toy LinkedList Implementation

Hello, everyone!
This is a toy implementation of a LinkedList. This is purely for educational purposes, so I do not recommend actually using this for a project. If you have any questions, come ask in my [Discord](https://discord.gg/hdGuA8F) server and I'd be happy to help!

## Node
  Node class. For info on the linked list data structure, reference https://en.wikipedia.org/wiki/Linked_list
  
`Members:`
- **value** - _(<T>)_ The value of the node
- **next** - _(Node*)_ The next value of the LinkedList
  
`Methods:`
  
### Node (constructor)
  Node constructor.

`Parameters:`
- **value** - _(<T>)_ The value of the generic type
- **next** - _(Node*)_ The next node to point to
  
## LinkedList
  LinkedList class. For info on the linked list data structure, reference https://en.wikipedia.org/wiki/Linked_list
  
`Members:`
- **head** - _(Node* = NULL)_ The head node of the LinkedList (the last value)
- **start** - _(Node* = NULL)_ The starting node of the LinkedList

### LinkedList (constructor)
  LinkedList constructor. Inserts an array as the default values.
  Iteratively uses the insert method `LinkedList.insert()` to insert the values into the list.
  
`Parameters:`
- **values** - _(const <T> [])_ Array of generic type T
- **size** - _(int)_ Size of the array given
  
### LinkedList (constructor)
  Default LinkedList constructor.
  
### insert
  Inserts a value into the LinkedList.
  
`Parameters:`
- **value** - _(const <T>&)_ Value of generic type T

### insert
  Inserts an array to the end of the LinkedList.
  Iteratively uses the insert method <see cref="LinkedList{T}.insert(const T& value)"/> to insert the values into the list.
  
`Parameters:`
- **values** - _(const <T> [])_ Array of generic type T
  
### get
  Returns a value at specified index.
  
`Parameters`:
- **index** - _(const int)_ The index to search for
  
`Returns:`
- _(Node*)_ Returns the pointer to the specified node. Returns NULL pointer when it's out of bounds. 

### getlast
  Returns the last node of the LinkedList.
  This isn't actually used in this toy implementation, but it'd be a cool feature to have in an actual LinkedList.

`Returns:`
- _(Node*)_ Returns the pointer to the last Node. Returns NULL pointer if the list is empty.

### remove
  Removes a value from the LinkedList.

`Parameters:`
- **value** - _(const <T>&)_ Value of generic type T
  
### removeat
  Removes the element at specified index from the LinkedList.

`Parameters:`
- **index** - _(int)_ Index to remove

### print
  Prints the LinkedList similar to how Python prints arrays.
