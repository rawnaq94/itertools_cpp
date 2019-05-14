#pragma once

namespace itertools
{
    template <typename T>
    class powerset
    {//Represents all subgroups of iterable
        private:
        T bigenN;

        public:

        powerset(T _bigen) : bigenN(_bigen) 
	{
        }
        
        template <typename P>
        class iterator
        {
          private:
            P firstIndex;
            P lastIndex;

            public:
            iterator(P temp1, P temp2) : firstIndex(temp1), lastIndex(temp2) 
	    {
            }

            std::pair<decltype(*firstIndex),decltype(*lastIndex)> operator*() const 
	    {
             return  std::pair<decltype(*firstIndex),decltype(*lastIndex)> (*firstIndex , *lastIndex);
            }

            iterator<P>& operator++()
	    {
	      return *this;
	    }

            bool operator!=(iterator<P> it) const
	    {
			    return false;
            }
		
	    bool operator==(iterator<P> it) const
	    {
	      return false;
	    }

        };

        public:

        auto begin() { 
            return iterator<decltype(bigenN.begin())> (bigenN.begin(), bigenN.end()); 
        } 
        auto end()  { 
            return iterator<decltype(bigenN.begin())>(bigenN.end(), bigenN.end());
        } 

    };
}
