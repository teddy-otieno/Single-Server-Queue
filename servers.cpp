#include <iostream>
#include "servers.h"

void create_servers(std::vector<Server>& servers, int num_of_servers) {
	for(int i = 0; i < num_of_servers; i++) {

		std::ostringstream oss;
		oss << "Server " << i;
		servers.push_back(Server(oss.str()));
	}
}

void Server::handle_customer(Customer* customer, int time) {
	if(this->is_busy())
		std::cerr << "Customer is being added while another is being worked on" << std::endl;

	this->current_attending_customer = customer;
	customer->service_begin = time;
}

bool Server::is_busy() {
	return this->current_attending_customer != nullptr;
}

Server::Server(std::string name) : name(name) { 

}

void Server::update(int time) {
	if(current_attending_customer == nullptr)
		return;

	if(IS_SINGLE) {
		if(current_attending_customer->service_begin + time_takes_to_complete_service == time) {
			current_attending_customer->status = IS_SERVICED;
			current_attending_customer->depature_time = time;
			std::cout << current_attending_customer->name << "\t serviced \t" << current_attending_customer->service_begin << std::endl;
			std::cout << current_attending_customer->name << "\t depatured \t" << time << std::endl;
			current_attending_customer = nullptr;
		}
		return;
	}

	if(service_time_for_customer() > time) {
		current_attending_customer->status = IS_SERVICED;
		current_attending_customer->depature_time = time;
		std::cout << "Customer "<< current_attending_customer->name << " arrival at" << current_attending_customer->arrival_time << std::endl;
		std::cout << "D Customer "<< current_attending_customer->name << " depatured at" << time << std::endl;
		current_attending_customer = nullptr;
	}

}

int Server::service_time_for_customer() {
	for(int i = 0; i + 2 < random_intervals.size(); i += 2) {
		if( current_attending_customer->rn_service_time >= random_intervals[i] && 
				current_attending_customer->rn_service_time <= random_intervals[i + 2]) {
				return service_times[i / 2];
		}
	}

	return 0;
}