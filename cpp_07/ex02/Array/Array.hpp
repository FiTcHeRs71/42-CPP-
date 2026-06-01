#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<class T>
class Array
{
	private:
	T	*_array;
	int	_len;

	public:

	/*===Canonical Form===*/
	Array(void);
	~Array(void);
	Array(const Array& to_copy);
	Array&operator=(const Array& src);

	Array(int len);
	/*===Getters & Setters===*/
	

	/*===Member Function===*/
	T		&operator[](int i);
	T const	&operator[](int i)const;

	class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

# include "Array.tpp"

#endif