#include "customer.h"
#include "utils.h"

Customer::Customer(std::string name, int rn_arrival_time, int rn_service_time) 
: rn_arrival_time(rn_arrival_time),
	rn_service_time(rn_service_time),
	name(name),
	arrival_time(0),
	depature_time(0) {

}

void create_customers(std::vector<Customer>& customers, int no_of_customers) {

	for(int i = 0; i < no_of_customers; i++) {

		std::ostringstream ostr;
		ostr << "Customer " << i;
		customers.push_back(Customer(ostr.str(), random_generator(100), random_generator(100)));
	}
}


void get_the_next_customer(std::list<Customer*>& service_queue, std::vector<Customer>& customers, int time) {

	//Pick the next customer at random
	//Check all are complete

	for(;;) {
		int next_customer = random_generator(customers.size());
		if(next_customer < customers.size() && customers[next_customer].status == NOT_SERVICED) {
			auto* selected_customer = &customers[next_customer];
			selected_customer->arrival_time = get_customers_arrival_time(selected_customer) + time;
			selected_customer->status = AWAITING_ARRIVAL;
			break;
		}

		//Break from loop if all customers area serviced or awaiting service
		int counter = 0;
		for(Customer& customer: customers) {
			if(customer.status != NOT_SERVICED) {
				counter++;
			}
		}

		if(counter > customers.size() - 1) {
			break;
		}

	}

	//Add customer with the current arrival time
	for(Customer& customer: customers) {
		if(customer.arrival_time == time)
			service_queue.push_back(&customer);
	}
}

int get_customers_arrival_time(Customer* customer) {

	for(int i = 0; i + 2 < arrival_random_interval.size(); i += 2) {
		if( customer->rn_arrival_time >= arrival_random_interval[i] && 
				customer->rn_arrival_time <= arrival_random_interval[i + 2]) {
				return arrival_times[i / 2];
		}
	}

	return 0;
}