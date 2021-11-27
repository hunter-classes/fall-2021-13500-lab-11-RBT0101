#include <iostream>
#include "profile.h"
#include "network.h"

Network::Network(){
	for (int i=0; i<20; i++){
		for (int j=0; j<20; j++){
			following[i][j] = false;
		}
	}
	
	numUsers = 0;
}

int Network::findID(std::string usern){
	for (int i=0; i<20; i++){
		std::string username = profiles[i].getUsername();
		if (usern == username){
			return i;
		}
	}
	
	return -1;
}

bool isAlphaNumeric(std::string str){
	for (int i=0; i<str.length(); i++){
		char c = str[i];
		if ((c < 48) || (c > 57 && c < 65) || (c > 90 && c < 97) || (c > 122)) return false;
	}
	
	return true;
}

bool Network::addUser(std::string usrn, std::string dspn){
	//Return false if username is non-alphanumeric or max size is exceeded
	if (!isAlphaNumeric(usrn) || numUsers >= 20) return false;
	
	//Also return false for duplicate username
	for (int i=0; i<20; i++){
		Profile p = profiles[i];
		if (p.getUsername() == usrn) return false;
	}
	
	//Add new user after above conditions pass
	for (int i=0; i<20; i++){
		Profile p = profiles[i];
		if (p.getUsername() == ""){
			profiles[i] = Profile(usrn, dspn);
			numUsers++;
			return true;
		}
	}
	
	return false;
}

bool Network::follow(std::string usrn1, std::string usrn2){
	int id1 = Network::findID(usrn1);
	int id2 = Network::findID(usrn2);
	
	if (id1 == -1 || id2 == -1) return false;
	else return following[id1][id2] = true;
}

void Network::printDot(){
	std::string output = "digraph {\n";
	for (int i=0; i<20; i++){
		if (profiles[i].getUsername() != ""){
			output += std::string("\t") + std::string("\"@") + profiles[i].getUsername() + std::string("\"\n");
		}
	}
	
	output += "\n";
	for (int i=0; i<20; i++){
		for (int j=0; j<20; j++){
			if (following[i][j] == true){
				output += std::string("\t") + std::string("\"@") + profiles[i].getUsername() + std::string("\"  -> ") + std::string("\"@" )
				+ profiles[j].getUsername() + std::string("\"\n");
			}
		}
	}
	
	output += "}";
	std::cout << output << std::endl;
}

