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

#include <iostream>
#include "node.h"

// Creating template to be used as generic
template <typename T>

/// <summary>
///    LinkedList class. For info on the linked list data structure, reference https://en.wikipedia.org/wiki/Linked_list
/// </summary>
class LinkedList {
    Node<T> *head = NULL;
    /// <value> The head node of the LinkedList (the last value) </value>

    Node<T> *start = NULL;
    /// <value> The starting node of the LinkedList </value>

    public:
        /// <summary>
        ///     LinkedList constructor. Inserts an array as the default values.
        ///     Iteratively uses the insert method <see cref="LinkedList{T}.insert(const T& value)"/> to insert the values into the list.
        /// </summary>
        ///
        /// <param name='values'>
        ///     Array of generic type T.
        /// </param>
        ///
        /// <param name='size'>
        ///     Size of the array given.
        /// </param>
        LinkedList(T values [], int size) {

            // Iterate through each value of the array, inserting it
            for (int i = 0; i < size; i++) {
                this->insert(values[i]);
            }
        }

        /// <summary>
        ///     Default LinkedList constructor.
        /// </summary>
        LinkedList() {}

        /// <summary>
        ///     Inserts a value into the LinkedList.
        /// </summary>
        ///
        /// <param name='value'>
        ///     Value of generic type T.
        /// </param>
        void insert(const T& value) {
            // If you want to see the values and the head pointers as it inserts, then uncomment the next line
            //std::cout << "Value: " << value << '\n' << "Head: " << this->head << "\n\n";

            // Initializing a new node
            Node<T> *node = new Node<T>(value, NULL);

            // Making sure the start value is initialized when the first value is
            if (this->start == NULL) {
                this->start = node;
            }

            // If the head isn't NULL, make sure to set the last node's next pointer to the new node
            if (this->head != NULL) {
                this->head->next = node;
            }

            // Setting the head to the new node
            this->head = node;
        }

        /// <summary>
        ///     Inserts an array to the end of the LinkedList.
        ///     Iteratively uses the insert method <see cref="LinkedList{T}.insert(const T& value)"/> to insert the values into the list.
        /// </summary>
        ///
        /// <param name='values'>
        ///     Array of generic type T.
        /// </param>
        void insert(const T values []) {

            // Iterate through each value of the array, inserting it
            for (int i = 0; i < sizeof(values); i++) {
                this->insert(values[i]);
            }
        }

        /// <summary>
        ///     Returns a value at specified index.
        /// </summary>
        ///
        /// <param name='index'>
        ///     The index to search for.
        /// </param>
        ///
        /// <returns>
        ///     Returns the pointer to the specified node. Returns NULL pointer when it's out of bounds.
        /// </returns>
        Node<T>* get(const int index) {

            // Initializing the temp node variable and the iterator (i)
            Node<T> *node = this->start;
            int i = 0;

            // Iterate until we either reach the index we want, or reach the end of the list
            while (node != NULL) {

                // You've found the node! Now return it!
                if (i == index) {
                    return node;
                }

                // If it hasn't found the note, iterate the variables
                else {
                    node = node->next;
                    i++;
                }
            }

            // This'll return NULL if it's out of bounds or the list is empty
            return NULL;
        }

        /// <summary>
        ///     Returns the last node of the LinkedList.
        ///     This isn't actually used in this toy implementation, but it'd be a cool feature to have in an actual LinkedList.
        /// </summary>
        ///
        /// <returns>
        ///     Returns the pointer to the last Node. Returns NULL pointer if the list is empty.
        /// </returns>
        Node<T>* getlast() {

            // Initializing node variable
            Node<T> *node = this->start;

            // Iterate until we reach the end of the list, making sure the list itself is initialized
            while (node != NULL) {
                if (node->next == NULL) {
                    return node;
                }
            }

            // This'll return NULL if the list is empty
            return NULL;
        }

        /// <summary>
        ///     Removes a value from the LinkedList.
        /// </summary>
        ///
        /// <param name='value'>
        ///     Value of generic type T.
        /// </param>
        void remove(const T& value) {

            // We need to store the last node we visited for pointer swapping, hence lastnode
            Node<T> *node = this->start;
            Node<T> *lastnode;

            // Iterate until we reach the end of the list, making sure the list itself is initialized
            while (node != NULL) {

                // Dereferencing the node value to check if they're equal
                if (value == node->value) {

                    // If it's the start node, change the start to the new value
                    if (start == node) {
                        this->start = node->next;
                    }

                    // If it's the head, make sure to set the head to the new value
                    if (node == this->head) {
                        this->head = lastnode;
                    }

                    // Move the removed node's next pointer to the previous node's next pointer
                    lastnode->next = node->next;

                    // Make sure to clean up that heap memory! Then break the while loop
                    delete node;
                    break;
                }

                // If the value doesn't match, then iterate the node variables
                else {
                    lastnode = node;
                    node = node->next;
                }
            }
        }

        /// <summary>
        ///     Removes the element at specified index from the LinkedList.
        /// </summary>
        ///
        /// <param name='index'>
        ///     Index to remove.
        /// </param>
        void removeat(const int index) {

            // We need to store the last node we visited for pointer swapping, hence lastnode
            Node<T> *node = this->start;
            Node<T> *lastnode;
            int i = 0;

            // Iterate until we reach the end of the list, making sure the list itself is initialized
            while (node != NULL) {

                // You've reached your destination!
                if (i == index) {

                    // If it's the start node, change the start to the new value
                    if (this->start == node) {
                        this->start = node->next;
                    }

                    // If it's the head, make sure to set the head to the new value
                    if (node == this->head) {
                        this->head = lastnode;
                    }

                    // Move the removed node's next pointer to the previous node's next pointer
                    lastnode->next = node->next;

                    // Make sure to clean up that heap memory! Then break the while loop
                    delete node;
                    break;
                }

                // If the value doesn't match, then iterate the node variables and the iterator (i)
                else {
                    lastnode = node;
                    node = node->next;
                    i++;
                }
            }
        }

        /// <summary>
        ///     Prints the LinkedList similar to how Python prints arrays.
        /// </summary>
        void print() {
            Node<T> *node = this->start;

            std::cout << '[';

            // Iterate until you reach the end, also makes sure the list is initialized to begin with
            while (node != NULL) {
                std::cout << node->value;

                // We don't want that pesky comma at the end!
                if (node->next == NULL) {
                    break;
                }

                std::cout << ", ";
                node = node->next;
            }

            std::cout << ']';
        }
};