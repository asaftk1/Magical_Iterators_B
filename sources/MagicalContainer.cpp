#include "MagicalContainer.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace ariel;
using namespace std;
int MagicalContainer::size()
{
    return elements.size();
}

// void MagicalContainer::addElement(int element)
// {
//     auto it = std::find(elements.begin(), elements.end(), element);

//     if (it != elements.end())
//     {
//         std::__throw_invalid_argument("can't insert the same element more than once");
//     }

//     elements.push_back(element);
//     if (isPrime(element))
//     {
//         primePointers.push_back(new int (elements.back()));
//         std::sort(primePointers.begin(), primePointers.end(),
//           [](int* a, int* b) {
//               return *a < *b;
//           });
//     }

//     std::sort(elements.begin(), elements.end());
// }
void MagicalContainer::addElement(int element)
{
    // Check if the element already exists in the container
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end())
    {
        std::__throw_invalid_argument("can't insert the same element more than once");
    }

    // Find the position to insert the element while maintaining sorted order
    std::vector<int>::difference_type insertIndex = 0;
    while (insertIndex < static_cast<std::vector<int>::difference_type>(elements.size()) &&
           elements[static_cast<std::vector<int>::size_type>(insertIndex)] < element)
    {
        insertIndex++;
    }

    // Insert the element at the correct position in the elements vector
    auto insertPos = elements.begin();
    //std::advance is used to move the iterator insertPos and primeInsertPos by the desired offset
    std::advance(insertPos, static_cast<std::vector<int>::difference_type>(insertIndex));
    elements.insert(insertPos, element);

    // If the element is prime, insert its pointer into the primePointers vector
    if (isPrime(element))
    {
        std::vector<int*>::difference_type primeInsertIndex = 0;
        while (primeInsertIndex < static_cast<std::vector<int*>::difference_type>(primePointers.size()) &&
               *primePointers[static_cast<std::vector<int*>::size_type>(primeInsertIndex)] < element)
        {
            primeInsertIndex++;
        }

        auto primeInsertPos = primePointers.begin();
        std::advance(primeInsertPos, static_cast<std::vector<int*>::difference_type>(primeInsertIndex));
        primePointers.insert(primeInsertPos, new int(element));
    }
}




void MagicalContainer::removeElement(int element)
{
    auto it = std::find(elements.begin(), elements.end(), element);

    if (it == elements.end())
    {
        std::__throw_runtime_error("Number is not exist");
    }
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}



