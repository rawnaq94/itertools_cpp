#pragma once

namespace itertools
{
    template <typename T>
    class powerset
    {//Represents all subgroups of iterable.
	    
        private:
        T bigenN;

        public:
        powerset(T _bigen) : bigenN(_bigen) 
	{
        }
        
        template <typename X>
        class iterator
        {
          private:
            X firstIndex;
            X lastIndex;

            public:
            iterator(X iter1, X iter2) : firstIndex(iter1), lastIndex(iter2)
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

           bool operator==(iterator<X> it) const
	   {
	      return false;
	   }

           bool operator!=(iterator<X> it) const
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
