#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:

	std::string		_lastName;
	std::string		_firstName;
	std::string		_nickName;
	std::string		_phone;
	std::string		_secret;

public:

	// Getters
	std::string		getLastName(void)const;
	std::string		getFirstName(void)const;
	std::string		getNickName(void)const;
	std::string		getPhone(void)const;
	std::string		getSecret(void)const;

	// Setters
	void			setLastName(std::string lastName);
	void			setFirstName(std::string firstName);
	void			setNickName(std::string nickName);
	void			setPhone(std::string phone);
	void			setSecret(std::string secret);
};

#endif