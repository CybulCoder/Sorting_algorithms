#include<stddef.h> //for size_t
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<random>

namespace SACC{
    
    using T = unsigned short; //temp type of data

    constexpr size_t width = 6;
    constexpr size_t cols =20;

    void print(std::vector<T>& data);
	void print_pretty(const std::vector<T>& data);
	void save_to_file(const std::vector<T>& data, std::string& file_name);
	void read_from_file(std::vector<T>& data_out, const std::string& file_name);
	bool is_sorted(const std::vector<T>& data);
	bool is_sorted_reversed(const std::vector<T>& data);

    class RecordFactory{
    public:
        std::vector<T> MakeRange(size_t m, size_t M);
		std::vector<T> MakeRangeReversed(size_t m, size_t M);
		std::vector<T> MakeRandom(size_t N, size_t m, size_t M);
		std::vector<T> MakeAlmostSorted(size_t m, size_t M, size_t swaps_num);
    };
} //namespace SACC

std::ostream& operator<<(std::ostream& os, const std::vector<SACC::T>& data);