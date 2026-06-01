#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &param_1, T &param_2)
{
	T tmp;

	tmp = param_1;
	param_1 = param_2;
	param_2 = tmp;
}

template<typename T>
T	max(const T &param_1, const T &param_2)
{
	if (param_1 > param_2)
		return (param_1);
	return (param_2);
}

template<typename T>
T	min(const T &param_1, const T &param_2)
{
	if (param_1 < param_2)
		return (param_1);
	return (param_2);
}
#endif /*WHATEVER_HPP*/