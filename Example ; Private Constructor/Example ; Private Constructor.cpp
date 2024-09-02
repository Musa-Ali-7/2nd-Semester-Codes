// Write a C++ program that demonstrates the use of friend classes 
//to access a private constructor. Define a class Secret with a private constructor 
//and a public method show. Declare a second class FriendClass as a friend of 
//Secret to allow it to create instances of Secret. Implement a method in 
//FriendClass that returns an instance of Secret. In the main function, create an 
//instance of FriendClass, use it to create an instance of Secret, and call the 
//show method of the Secret instance to verify that the private constructor was 
//successfully accessed.

#include<iostream>
using namespace std;

class notsecret;

class secret {
	private:
	 secret () {
		cout << "Shh! this is a secret " << endl;
	}
	public:
	void show() {
		cout << "Show method being called " << endl;
	}
	
	friend class notsecret;
};
class notsecret {
	public:
		void creatingInstences() {
			secret s1;
			s1.show();
		}
};
int main () {
	notsecret ns1; 
	ns1.creatingInstences();
	return 0;
}
