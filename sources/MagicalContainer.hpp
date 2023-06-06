#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
namespace ariel
{
    // class MagicalContainer

    class MagicalContainer
    {
    private:
        std::vector<int> elements; // Dynamic array to store the elements

    public:
        std::vector<int *> primePointers;
        int size();
        void addElement(int element);
        void removeElement(int element);
        int getElement(std::size_t index) const;
        bool operator!=(const MagicalContainer &other) const
        {
            return elements != other.elements;
        }
        // AscendingIterator
        class AscendingIterator
        {
        private:
            const MagicalContainer &elements;
            typename std::vector<int>::size_type currentIndex;

        public:
            // Default constructor
            // AscendingIterator(){}

            // Copy constructor
            AscendingIterator(const MagicalContainer &cont)
                : elements(cont), currentIndex(0) {}

            // Destructor
            ~AscendingIterator() {}

            // Assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);

            // Equality comparison (operator==)
            bool operator==(const AscendingIterator &other) const;

            // Inequality comparison (operator!=)
            bool operator!=(const AscendingIterator &other) const;

            // GT comparison (operator>)
            bool operator>(const AscendingIterator &other) const;

            // LT comparison (operator<)
            bool operator<(const AscendingIterator &other) const;

            // Dereference operator (operator*)
            const int &operator*() const;

            // Pre-increment operator (operator++)
            AscendingIterator &operator++();

            // begin(): Returns the iterator pointing to the first element of the elements
            AscendingIterator begin();

            // end(): Returns the iterator pointing one position past the last element of the elements
            AscendingIterator end();
        };

        // SideCrossIterator
        class SideCrossIterator
        {
        private:
            const MagicalContainer &elements;
            typename std::vector<int>::size_type currentIndex;
            bool forward;

        public:
            SideCrossIterator(const MagicalContainer &cont)
                : elements(cont), currentIndex(0), forward(true) {}

            // // Default constructor
            // SideCrossIterator();

            // // Copy constructor
            // SideCrossIterator(const SideCrossIterator &other);

            // // Destructor
            // ~SideCrossIterator();

            // Assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);

            // Equality comparison (operator==)
            bool operator==(const SideCrossIterator &other) const;

            // Inequality comparison (operator!=)
            bool operator!=(const SideCrossIterator &other) const;

            // GT comparison (operator>)
            bool operator>(const SideCrossIterator &other) const;

            // LT comparison (operator<)
            bool operator<(const SideCrossIterator &other) const;

            // Dereference operator (operator*)
            int operator*() const;

            // Pre-increment operator (operator++)
            SideCrossIterator &operator++();

            // begin(): Returns the iterator pointing to the first element of the elements
            SideCrossIterator begin();

            // end(): Returns the iterator pointing one position past the last element of the elements
            SideCrossIterator end();
        };

        // PrimeIterator
        class PrimeIterator
        {
        private:
            const MagicalContainer &elements;
            // const MagicalContainer &primecontainer;
            typename std::vector<int>::size_type currentIndex;
            bool IsPrimeFlag = false;

        public:
            PrimeIterator(const MagicalContainer &cont)
                : elements(cont), currentIndex(0)
            {
            }

            PrimeIterator(const MagicalContainer &container, std::vector<int *>::const_iterator iterator)
                : elements(container), currentIndex(static_cast<typename std::vector<int>::size_type>(std::distance(container.primePointers.begin(), iterator)))
            {
            }

            // Default constructor
            // PrimeIterator();

            // // Copy constructor
            // PrimeIterator(const PrimeIterator &other);

            // // Destructor
            // ~PrimeIterator();

            // Assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);

            // Equality comparison (operator==)
            bool operator==(const PrimeIterator &other) const;

            // Inequality comparison (operator!=)
            bool operator!=(const PrimeIterator &other) const;

            // GT comparison (operator>)
            bool operator>(const PrimeIterator &other) const;

            // LT comparison (operator<)
            bool operator<(const PrimeIterator &other) const;

            // Dereference operator (operator*)
            int operator*() const;

            // Pre-increment operator (operator++)
            PrimeIterator &operator++();

            // begin(): Returns the iterator pointing to the first element of the elements
            PrimeIterator begin();

            // end(): Returns the iterator pointing one position past the last element of the elements
            PrimeIterator end();
        };
        bool isPrime(int num) const;
    };

}