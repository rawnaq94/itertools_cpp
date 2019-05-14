#pragma once

namespace itertools
{
    template <typename T1, typename T2>
    class product 
    {//Represents a Cartesian product of iterable.
        private:
        T1 firstIt;
        T2 socundIt;
        
        public:
        product(T1 bigen, T2 end) : firstIt(bigen), socundIt(end)
	{
        }
        
        template <typename X, typename Y>
        class iterator
        {
          private:
            X firstIndex;
            Y lastIndex;

            public:
            iterator(X iter1, Y iter2) : firstIndex(iter1), lastIndex(iter2)
	    {
            }

            std::pair<decltype(*firstIndex),decltype(*lastIndex)> operator*() const 
	    {
             return  std::pair<decltype(*firstIndex),decltype(*lastIndex)> (*firstIndex , *lastIndex);
            }

            iterator<X, Y>& operator++()
	    {
	     return *this;
            }

	    bool operator==(iterator<X,Y> it) const
	    {
	     return false;
	    }

            bool operator!=(iterator<X,Y> it) const
	    {
	     return false;
            }
        };

        public:

        auto begin()
        {
            return iterator <decltype(firstIt.begin()),decltype(socundIt.begin())> (firstIt.begin(), socundIt.begin());;
        }

        auto end()
        {
            return iterator <decltype(firstIt.end()),decltype(socundIt.end())> (firstIt.end(), socundIt_it2.end());;
        }

    };
}
