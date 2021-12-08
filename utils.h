#pragma once

#include <random>
#include "customer.h"
#include <vector>

const int seed = 723456;
static std::default_random_engine generator(seed);
int random_generator(int nth_digit);

void print_report(std::vector<Customer>&);