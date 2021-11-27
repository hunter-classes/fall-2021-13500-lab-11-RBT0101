#include <iostream>
#include "profile.h"

//Member Initializer list
Profile::Profile(std::string usrn, std::string dspn) : username(usrn), displayname(dspn) {}
Profile::Profile() : username(""), displayname("") {}

std::string Profile::getUsername(){
	return username;
}

std::string Profile::getFullName(){
	return (displayname + " (@" + username + ")");
}

void Profile::setDisplayname(std::string dspn){
	displayname = dspn;
	return;
}
