#include<iostream>
#include"data_utils.h"
#include"sorting_algorithms.h"


int main(){
	std::cout << "Hello!\n";

	using T = SACC::T;
	SACC::RecordFactory factory;
	std::vector<T> data;

	data = factory.MakeRandom(100,1,1000);

	SACC::print_pretty(data);

	SACC::Insertion_sort(data);

	std::cout << "\n\n";

	SACC::print_pretty(data);
	

	std::cout << "\n\nAnd... That's it...";
	return 0;
}
