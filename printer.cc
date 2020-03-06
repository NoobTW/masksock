#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
	while(1) {
		cout << "nice" << endl;
		this_thread::sleep_for(chrono::milliseconds(800));
	}
	return 0;
}
