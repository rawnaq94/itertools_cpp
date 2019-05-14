#pragma once
 

namespace itertools {
	template<typename T> class range 
	{//Represents a range of objects.
   	public:
			range<T>(const T x, const T y) : a(x) , b(y) {}
			range<T> (const range& other) : a(other.a), b(other.b) {}
		
		private: // It can be assumed that a<b.
			T a;
			T b;
      
      
				class iterator 
        {//Running in a loop
					private:
						T _type;
						
					public:
						iterator(T member): _type(member){}					
						T operator*() const
            {
							return _type;
						}
						
						T* operator->() const
            {
							return &_type;
						}
		
        		const iterator operator++(int)
            {
							iterator _cd(*this);
							operator++();
							return _cd;
						}
            
						iterator& operator++()
            {
							++_type;
							return *this;
						}

          	bool operator!=(const iterator& othercd) const
            {
							if(_type!=othercd._type)
								return true;
							return false;
						}


						bool operator==(const iterator& othercd) const
            {
							if(_type==othercd._type)
								return true;
							return false;
						}

					
				};
        
		iterator begin()
    {
			return range<T>::iterator(a);
		}
			
		iterator end() 
    {
			return range<T>::iterator(b);
		}
	};

}
