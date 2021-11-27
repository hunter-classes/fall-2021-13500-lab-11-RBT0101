#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Testing Task A"){
	//Test with 2-parmater constructor
	Profile p1 = {"John Dewy", "JD"};
	CHECK(p1.getUsername() == "John Dewy");
	CHECK(p1.getFullName() == "JD (@John Dewy)");
	p1.setDisplayname("JDew");
	CHECK(p1.getFullName() == "JDew (@John Dewy)");
	
	//Test with default contructor
	Profile p2 = Profile();
	CHECK(p2.getUsername() == "");
	CHECK(p2.getFullName() == " (@)");
	p2.setDisplayname("Natalia");
	CHECK(p2.getFullName() == "Natalia (@)");
}

TEST_CASE("Testing Task B"){
	 //Check number of user cannot exceed max limit (20)
	 Network nw1 = {};
	 for (int i=0; i<20; i++){
	 	CHECK(nw1.addUser('u' + std::to_string(i), 'd' + std::to_string(i)) == true);
	}
	CHECK(nw1.addUser("ux", "dx") == false);
	
	//Check for duplicate username (which is not allowed)
	Network nw2 = {};
	CHECK(nw2.addUser("u0", "abc") == true);
	CHECK(nw2.addUser("u0", "efg") == false);
	
	//Checking for alphanumeric [0-9] & [a-Z] characters
	CHECK(nw2.addUser("   {}_+", "jkl") == false); 
	CHECK(nw2.addUser("  ", "jkl") == false); 
	CHECK(nw2.addUser("   ?", "jkl") == false); 
	CHECK(nw2.addUser("   =", "jkl") == false); 
	CHECK(nw2.addUser("   !~`", "jkl") == false); 
}

TEST_CASE("Testing Task C"){
	Network nw3 = {};
	nw3.addUser("a","apple");
	nw3.addUser("b", "bandage");
	nw3.addUser("c", "come on");
	
	CHECK(nw3.follow("a", "b") == true);
	CHECK(nw3.follow("a", "b") == true); //"a" is still following "b"
	CHECK(nw3.follow("a", "c") == true);
	CHECK(nw3.follow("c", "a") == true);
	CHECK(nw3.follow("c", "b") == true);
	CHECK(nw3.follow("b", "c") == true);
	CHECK(nw3.follow("b", "a") == true);	
	
	//Should equal false for members not on the list
	CHECK(nw3.follow("ab", "cd") == false);
	CHECK(nw3.follow("a", "cd") == false);
	CHECK(nw3.follow("b", "ca") == false);
}




