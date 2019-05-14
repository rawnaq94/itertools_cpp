#pragma once

namespace itertools
{
    template <typename T1, typename T2>
    class chain 
    {//Represents a concatenation of two iterable.
	    
        private:
        T1 first;
        T2 last;
        
        public:
        chain(T1 bigen, T2 end) : first(bigen), last(end)
	{
        }

	    
        template <typename X, typename Y>
        class iterator
        {
          private:
            X firstIndex;
            Y lastIndex;

            public:
            iterator(X iter1,Y iter2) : firstIndex(iter1), lastIndex(iter2)
	    {
            }

            decltype(*firstIndex) operator*() const
	    {
	       return *firstIndex;
            }

            iterator& operator++()
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
            return iterator <decltype(first.begin()),decltype(last.begin())> (first.begin(), last.begin());;
        }

        auto end()
        {
            return iterator <decltype(first.end()),decltype(last.end())> (first.end(), last.end());;
        }
    };
}
