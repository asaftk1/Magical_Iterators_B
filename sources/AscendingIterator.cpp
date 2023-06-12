#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;
// Assignment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
      if (elements != other.elements)
    {
        throw std::runtime_error("Cannot assign iterators pointing to different containers.");
    }
    if (this == &other)
    {
        return *this;
    }
    currentIndex = other.currentIndex;
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return currentIndex == other.currentIndex;
}

// Inequality comparison (operator!=)
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return currentIndex != other.currentIndex;
}

// GT comparison (operator>)
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return currentIndex > other.currentIndex;
}

// LT comparison (operator<)
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return currentIndex < other.currentIndex;
}

// Dereference operator (operator*)
const int &MagicalContainer::AscendingIterator::operator*() const
{
    return elements.elements[currentIndex];
}

// Pre-increment operator (operator++)
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (currentIndex == elements.elements.size())
    {
        std::__throw_runtime_error("Iterator Increment Beyond End");
    }
    if (currentIndex < elements.elements.size())
    {
        ++currentIndex; // Increment the index
    }
    return *this;
}

// begin(): Returns the iterator pointing to the first element of the elements
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(elements);
}

// end(): Returns the iterator pointing one position past the last element of the elements
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator iter(elements);
    iter.currentIndex = elements.elements.size();
    return iter;
}
