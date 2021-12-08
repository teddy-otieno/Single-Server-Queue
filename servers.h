#pragma once

#include <sstream>
#include <string>
#include "customer.h"
#include "utils.h"

struct Server {
	Customer* current_attending_customer = nullptr;
	int priority;
	std::string name;

	Server(std::string name);
	bool is_busy();
	void handle_customer(Customer* customer, int time);
	void update(int time);

	int service_time_for_customer();


private:
	std::vector<int> service_times;
	std::vector<float> probs;
	std::vector<float> cumm_probs;
	std::vector<int> random_intervals;

	int time_takes_to_complete_service = 6;
};

static bool IS_SINGLE = true;

void create_servers(std::vector<Server>& servers, int num_of_servers);