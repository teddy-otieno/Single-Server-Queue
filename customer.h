#pragma once
#include <list>
#include <iostream>
#include <vector>
#include <sstream>
#include <random>

struct CustomerAccountingData {
};

enum CustomerStatus {
	IS_SERVICED,
	NOT_SERVICED,
	AWAITING_ARRIVAL,
};

struct Customer {
	int rn_arrival_time;
	int rn_service_time;
	int arrival_time;
	int service_begin = 0;
	int depature_time;

	std::string name;
	CustomerStatus status = NOT_SERVICED;

	Customer(std::string, int rn_arrival_time, int rn_service_time);
};

void create_customers(std::vector<Customer> &customers_queue, int number_of_customers);


void get_the_next_customer(std::list<Customer*>&, std::vector<Customer>&, int);

int get_customers_arrival_time(Customer*);


//Customer arrival distributions
static std::vector<int> arrival_times = {1, 2, 3, 4, 5};
static std::vector<float> arrival_prob = {0.25f, 0.40, 0.20, 0.15};
static std::vector<float> arrival_cumm_prob = {0.25, 0.65, 0.85, 1.0};
static std::vector<int> arrival_random_interval = {1, 25, 26, 65, 66, 85, 86, 0};