#ifndef ARRAY_TPP
# define ARRAY_TPP

template<typename T>
Array<T>::Array(void)
{
	//std::cout << "Array default contructor called" << std::endl;
	this->_array = NULL;
	this->_len = 0;
}

template<typename T>
Array<T>::~Array(void)
{
	//std::cout << "Array default destructor called" << std::endl;
	delete[] this->_array;
}

template<typename T>
Array<T>::Array(const Array& to_copy)
	:_array(new T[to_copy._len])
	,_len(to_copy._len)
{
	for (int i = 0; i < _len; i++)
		this->_array[i] = to_copy._array[i];
}

template<typename T>
Array<T>::Array(int len)
{
	if (len < 0)
		throw OutOfBoundsException();
	this->_array = new T[len]();
	this->_len = len;
}

//Array::Array&operator=(const Array& src);

/*===Member Function===*/
template<typename T>
T	&Array<T>::operator[](int i)
{
	if (i >= _len || i < 0)
		throw OutOfBoundsException();
	return (this->_array[i]);
}

template<typename T>
T const &Array<T>::operator[](int i) const
{
		if (i >= _len || i < 0)
		throw OutOfBoundsException();
	return (this->_array[i]);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}

#endif /*ARRAY_TPP*/