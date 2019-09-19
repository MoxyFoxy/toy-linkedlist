/*************************************************************\
 *                                                           *
 *                 Linked List Implementation                *
 *                      by Alec Sanchez                      *
 *                                                           *
 *                           NOTE:                           *
 *         This is an unoptimized toy implementation         *
 *                  for educational purposes.                *
 *         It is not recommended to use in a serious         *
 *                          project.                         *
 *                                                           *
\*************************************************************/

// Creating template to be used as generic
template <typename T>

/// <summary>
///    Node class. For info on the linked list data structure, reference https://en.wikipedia.org/wiki/Linked_list
/// </summary>
struct Node {
    T value;
    /// <value> The value of the node </value>

    Node *next;
    /// <value> The next value of the LinkedList </value>

    /// <summary>
    ///        Node constructor.
    /// </summary>
    ///
    /// <param name='value'>
    ///        The value of the generic type.
    /// </param>
    ///
    /// <param name='next'>
    ///     The next node to point to.
    /// </param>
    Node(T value, Node* next) {
        this->value = value;
        this->next = next;
    }
};