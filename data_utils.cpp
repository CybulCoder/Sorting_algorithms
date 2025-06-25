#include"data_utils.h"

namespace SACC{

    void print(std::vector<T>& data) {
		auto cout_t = [&](const T& t) {std::cout << t << ' ';};

		std::for_each(data.begin(), data.end(), cout_t); //apllies cout_t for every iterator, probably works since c++20
	}

	void print_pretty(const std::vector<T>& data) {

		size_t i{1};

		auto cout_t = [&](const T& t) {
			std::cout << std::setw(width) << t;
			if (i % cols == 0) {
				std::cout << '\n';
				i = 0;
			}
			i++;
			};

		std::for_each(data.begin(), data.end(), cout_t);
	}

	void save_to_file(const std::vector<T>& data, std::string& file_name) {
		std::ofstream file(file_name);
		if (file.is_open()) {
			file << data;
		}
		else {
			std::cout << "\nFile cannot be opened!\n";
		}
		file.close();
	}

	void read_from_file(std::vector<T>& data_out, const std::string& file_name) {
		data_out.clear();
		std::ifstream file(file_name);
		if (file.is_open()) {
			T value;
			while (file >> value) {
				data_out.push_back(value);
			}
		}
		else {
			std::cout << "\nFile cannot be opened!\n";
		}
		file.close();
	}

	bool is_sorted(const std::vector<T>& data) {
		for (size_t i = 0; i < data.size() - 1; i++) {
			if (data[i + 1] < data[i]) {
				return false;
			}
		}
		return true;
	}

	bool is_sorted_reversed(const std::vector<T>& data) {
		for (size_t i = data.size() - 1; i > 0; i--) {
			if (data[i - 1] < data[i]) {
				return false;
			}
		}
		return true;
	}


	/*
	*	RECORD FACTORY METHODS
	*/

	std::vector<T> RecordFactory::MakeRange(size_t m, size_t M) {
		std::vector<T> data(M - m + 1);
		std::iota(data.begin(), data.end(), m); //fills with sequentially increasing values
		return data;
	}

	std::vector<T> RecordFactory::MakeRangeReversed(size_t m, size_t M) {
		std::vector<T> data(M - m + 1);
		std::iota(data.begin(), data.end(), m); //fills with sequentially increasing values
		std::reverse(data.begin(), data.end());
		return data;
	}

	std::vector<T> RecordFactory::MakeRandom(size_t N, size_t m, size_t M) {
		std::vector<T> data(N);
		std::random_device rd;
		std::default_random_engine gen(rd());
		std::uniform_int_distribution<T> distr(m, M);

		std::generate(data.begin(), data.end(), [&]() {return distr(gen);}); // assigning each element a random value
		return data;
	}

	std::vector<T> RecordFactory::MakeAlmostSorted(size_t m, size_t M, size_t swaps_num) {
		std::vector<T> data;
		data = RecordFactory::MakeRange(m, M);

		std::vector<size_t> swaps(data.size()-1);
		std::iota(swaps.begin(), swaps.end(), 0);
		
		std::random_device rd;
		std::default_random_engine gen(rd());
		std::shuffle(swaps.begin(), swaps.end(), gen);
		//swaps.resize(swaps_num);
		
		for (size_t i = 0; i < swaps_num; i++) {
			std::swap(data[swaps[i]], data[swaps[i] + 1]);
		}

		return data;
	}

} //namespace SACC

std::ostream& operator<<(std::ostream& os, const std::vector<SACC::T>& data) {
	size_t i{ 1 };

	auto cout_t = [&](const SACC::T& t) {
		os << std::setw(SACC::width) << t;
		if (i % SACC::cols == 0) {
			os << '\n';
			i = 0;
		}
		i++;
		};

	std::for_each(data.begin(), data.end(), cout_t);
	return os;
}