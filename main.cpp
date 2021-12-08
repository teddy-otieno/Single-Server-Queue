#include <list>
#include <vector>
#include <iostream>
#include "customer.h"
#include "servers.h"
#include "utils.h"

int main() {
	int time = 1;

	std::list<Customer*> service_queue;
	std::vector<Customer> customers;
	std::vector<Server> servers;

	create_customers(customers, 10);
	create_servers(servers, IS_SINGLE ? 1 : 2);

	while(time < 100) {
		//
		get_the_next_customer(service_queue, customers, time);

		//Server's logic
		for(Server& server : servers) {
			server.update(time);

			if(!server.is_busy() && service_queue.size() > 0) {
				server.handle_customer(service_queue.front(), time);
				service_queue.pop_front();
			}
		}

		std::cout << "Queue size at " << time << "\t= " << service_queue.size() << "\n";
		time++;
	}

	print_report(customers);
	return 0;
}