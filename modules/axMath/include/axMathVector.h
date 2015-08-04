#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>
namespace ax
{
	namespace Math
	{
		template<typename T>
		class Vector
		{
		public:
			Vector(const std::vector<T>& pt)
			{
				_vec = pt;
			}

			Vector(const Vector<T>& pt)
			{
				_vec = pt._vec;
			}

			Vector()
			{
			}

			Vector(const T& x, const T& y)
			{
				_vec.resize(2);
				_vec[0] = x;
				_vec[1] = y;
			}

			Vector(const T& x, const T& y, const T& z)
			{
				_vec.resize(3);
				_vec[0] = x;
				_vec[1] = y;
				_vec[2] = z;
			}

			T& operator [] (const int& index)
			{
				return _vec[index];
			}

			T* begin()
			{
				return &_vec[0];
			}

			T* end()
			{
				return (&_vec[_vec.size() - 1]) + 1;
			}
            
            Vector<T> operator + (const Vector<T>& vec)
            {
                Vector<T> answer;
                answer._vec.resize(_vec.size());
                
                for(int i = 0; i < _vec.size(); i++)
                {
                    answer._vec[i] = _vec[i] + vec._vec[i];
                }
                
                return answer;
            }
            
            Vector<T> operator - (const Vector<T>& vec)
            {
                Vector<T> answer;
                answer._vec.resize(_vec.size());
                
                for(int i = 0; i < _vec.size(); i++)
                {
                    answer._vec[i] = _vec[i] - vec._vec[i];
                }
                
                return answer;
            }
            
            Vector<T> operator * (const Vector<T>& vec)
            {
                Vector<T> answer;
                answer._vec.resize(_vec.size());
                
                for(int i = 0; i < _vec.size(); i++)
                {
                    answer._vec[i] = _vec[i] * vec._vec[i];
                }
                
                return answer;
            }
            
            Vector<T> operator / (const Vector<T>& vec)
            {
                Vector<T> answer;
                answer._vec.resize(_vec.size());
                
                for(int i = 0; i < _vec.size(); i++)
                {
                    answer._vec[i] = _vec[i] / vec._vec[i];
                }
                
                return answer;
            }
            
			inline int Size() const
			{
				return _vec.size();
			}

			T Dist(const Vector<T>& pt) const
			{
				assert(_vec.size() == pt.size());

                double dist = 0.0;
                
				for(int i = 0; i < _vec.size(); i++)
				{
					dist += pow(_vec[i] - pt._vec[i], 2.0);
				}

				return sqrt(dist);
			}

			std::vector<T> GetVector() const
			{
				return _vec;
			}

			void Print() const
			{
				std::cout << "(";
				for(int i = 0; i < _vec.size() - 1; i++)
				{
					std::cout << _vec[i] << ", ";
				}
				std::cout << _vec[_vec.size()-1] << ")" << std::endl;
			}

		private:
			std::vector<T> _vec;
		};
	}
}


