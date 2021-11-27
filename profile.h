#pragma once
class Profile {
private:
	std::string displayname;
	std::string username;
	
public:
	Profile(std::string usrn, std::string dspn);
	Profile();
	std::string getUsername();
	std::string getFullName();
	void setDisplayname(std::string dspn);
};
