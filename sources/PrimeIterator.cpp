#include "MagicalContainer.hpp"
#include <math.h>
using namespace ariel;
using namespace std;
/////////////////   PrimeIterator  //////////////////////

// Assignment operator

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
     if (elements != other.elements)
    {
        throw std::runtime_error("Cannot assign iterators pointing to different containers.");
    }
    if (this != &other)
    {
        currentIndex = other.currentIndex;
    }
    return *this;
}

// Equality comparison (operator==)
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return currentIndex == other.currentIndex;
}

// Inequality comparison (operator!=)
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return currentIndex != other.currentIndex;
}

// GT comparison (operator>)
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return currentIndex > other.currentIndex;
}

// LT comparison (operator<)
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return currentIndex < other.currentIndex;
}

// Dereference operator (operator*)
int MagicalContainer::PrimeIterator::operator*() const
{
    if (currentIndex >= elements.elements.size())
    {
        throw std::out_of_range("Iterator out of range");
    }

    return *(elements.primePointers[currentIndex]) ;
}

// Pre-increment operator (operator++)
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if(currentIndex == elements.primePointers.size())
    {
        std::__throw_runtime_error("Iterator Increment Beyond End");
    }
    ++currentIndex;
    return *this;
   
}

// begin(): Returns the iterator pointing to the first element of the elements
   MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(elements, elements.primePointers.begin());
}
 

// end(): Returns the iterator pointing one position past the last element of the elements
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
     return PrimeIterator(elements, elements.primePointers.end());
}

bool MagicalContainer::isPrime(int num) const
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}
