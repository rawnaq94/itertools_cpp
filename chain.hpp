#pragma once

namespace itertools
{
    template <typename T1, typename T2>
    class chain 
    {//Represents a concatenation of two iterable.
	    
        private:
        T1 firstIt;
        T2 lastIt;
        
        public:
        chain(T1 bigenN, T2 endD) : firstIt(bigenN), lastIt(endD)
	{
        }

        template <typename P1, typename P2>
        class iterator
        {
          private:
            P1 firstIndex;
            P2 lastIndex;

            public:
            iterator(P1 temp1, P2 temp2) : firstIndex(temp1), lastIndex(temp2)
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

	    bool operator!=(iterator<P1,P2> it) const 
	    {
	       return false;
            }
		
	    bool operator==(iterator<P1,P2> it) const
	    {
	      return false;
            }

        };

        public:

        auto begin()
        {
            return iterator <decltype(firstIt.begin()),decltype(lastIt.begin())> (firstIt.begin(), lastIt.begin());;
        }

        auto end()
        {
            return iterator <decltype(firstIt.end()),decltype(lastIt.end())> (firstIt.end(), lastIt.end());;
        }

    };
}
