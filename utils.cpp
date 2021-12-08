
#include "utils.h"

int random_generator(int nth_digit) {
	std::uniform_int_distribution<int> udist(0, nth_digit);

	return udist(generator);
}

void print_report(std::vector<Customer>& customers) {

}