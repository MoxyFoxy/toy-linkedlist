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
#include "linkedlist.h"

int main() {
	int values [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	// Purposely used sizeof instead of a hardcoded value to demonstrate that it's the size of the array being passed
	LinkedList<int> *ll = new LinkedList<int>(values, sizeof(values) / sizeof(*values));

	std::cout << "List: ";
	ll->print();
	std::cout << '\n';

	std::cout << "Value at index 2: " << ll->get(2)->value << '\n';

	std::cout << "List after removing index 5: ";
	ll->removeat(5);
	ll->print();
	std::cout << '\n';

	std::cout << "List after removing value 9: ";
	ll->remove(9);
	ll->print();
	std::cout << '\n';

	std::cout << "Last value: " << ll->getlast()->value;
}