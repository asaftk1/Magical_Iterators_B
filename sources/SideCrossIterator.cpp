#include "MagicalContainer.hpp"

using namespace ariel;
using namespace std;
/////////////  SideCrossIterator /////////////////////////

// Assignment operator
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (elements != other.elements)
    {
        throw std::runtime_error("Cannot assign iterators pointing to different containers.");
    }
    if (this != &other)
    {
        currentIndex = other.currentIndex;
        forward = other.forward;
    }
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return currentIndex == other.currentIndex && forward == other.forward;
}

// Inequality comparison (operator!=)
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return currentIndex != other.currentIndex || forward != other.forward;
}

// GT comparison (operator>)
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return currentIndex > other.currentIndex;
}

// LT comparison (operator<)
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return currentIndex < other.currentIndex;
}

// Dereference operator (operator*)
int MagicalContainer::SideCrossIterator::operator*() const
{
    if (currentIndex > elements.elements.size())
    {
        throw std::out_of_range("Iterator out of range");
    }

    return elements.elements[currentIndex];
}

// Pre-increment operator (operator++)

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{

    if (currentIndex == elements.elements.size())
    {
        std::__throw_runtime_error("Iterator Increment Beyond End");
    }
    if (forward)
    {
        if (currentIndex >= elements.elements.size() / 2)
        {
            currentIndex = elements.elements.size();
        }
        else
        {
            currentIndex = (elements.elements.size() - currentIndex - 1);
            forward = false;
        }
    }
    else
    {
        if (currentIndex <= elements.elements.size() / 2)
        {
            currentIndex = elements.elements.size();
        }
        else
        {
            currentIndex = (elements.elements.size() - currentIndex);
        }
            forward = true;
            

    }

    return *this;
}

// begin(): Returns the iterator pointing to the first element of the elements
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(elements);
}

// end(): Returns the iterator pointing one position past the last element of the elements
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator iter(elements);
    iter.currentIndex = elements.elements.size();
    return iter;
}
