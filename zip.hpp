#pragma once

namespace itertools
{
	template<typename T1, typename T2> class zip
  {//It can be assumed that they are the same length
		private:
			T1 a;
			T2 b;
	
		public:
			zip<T1,T2>(const T1 x, const T2 y) : a(x),b(y){}
		
  
			class iterator
      {
	      typename T1::iterator x1Start;
				typename T1::iterator x1Stop;
				typename T2::iterator y2Start;
				typename T2::iterator y2Stop;


			public:
				iterator(typename T1::iterator xStart, typename T1::iterator xStop, typename T2::iterator yStart, typename T2::iterator yStop):
				x1Start(xStart), x1Stop(xStop),
				y2Start(yStart), y2Stop(yStop)
			  {}
        auto operator*() const
        {
					ostringstream stream;
					stream<<*x1Start<<","<<*y2Start;
					return stream.str();
				}

				iterator& operator++()
        {
					++x1Start;
					++y2Start;
					return *this;
				}

				const iterator operator++(int)
        {
					iterator Cd(*this);
					operator++();
					return Cd;
				}

      	bool operator!=(const iterator& our) const
        {
					if(*this==our)
						return false;
					return true;
				} 
        
				bool operator==(const iterator& other) const
        {
					if(x1Start == other.x1Start)
						if(y2Start == other.y2Start)
							return  true;
					return false;
				}

		}; 
		
		typename zip<T1,T2>::iterator begin()
    {
			return zip<T1,T2>::iterator(a.begin(), a.end(), b.begin(), b.end());
		}
			
		typename zip<T1,T2>::iterator end()
    {
			return zip<T1,T2>::iterator(a.end(), a.end(), b.end(), b.end());
		}

	}; 

}
