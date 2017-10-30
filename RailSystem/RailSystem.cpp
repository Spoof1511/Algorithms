#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "RailSystem.h"

void RailSystem::reset(void) {

    for (map<string,City*>::iterator iter=cities.begin();iter!=cities.end();iter++)
	{
		iter->second->total_distance=0;
		iter->second->total_fee=INT_MAX;
		iter->second->name="";
		iter->second->visited=false;
	}
    
}

RailSystem::RailSystem(string const &filename) {
    
    load_services(filename);
}

void RailSystem::load_services(string const &filename) {

	ifstream inf(filename.c_str());
	string from, to;
	int fee, distance;

	while ( inf.good() )
	{

		// Read in the from city, to city, the fee, and distance.
		inf >> from >> to >> fee >> distance;

		if ( inf.good() )
		{
		
			City* cityFrom=new City(from);
			City* cityTo=new City(to);
			cities.insert(std::pair(from,cityFrom));
			cities.insert(std::pair(to,cityTo));
            if (fee<0)
			{
				std::cout<<"fee cannot be negative!"<<endl;
				fee=INT_MAX;

			}
            outgoing_services[from].push_back(new Service(to,fee,distance));
		}
	}

	inf.close();
}

RailSystem::~RailSystem(void) {

    for (map<string,City*>::iterator citiesIterator=cities.begin();citiesIterator!=cities.end();citiesIterator++)
	{
		City* temp=citiesIterator->second;
		delete temp;
	}
	for (map<string,std::list<Service*>>::iterator servIt=outgoing_services.begin();servIt!=outgoing_services.end();servIt++)
	{
		std::list tempServiceList=servIt->second;
		for (int i=0;i<tempServiceList.size();i++)
		{
			Service* servTemp=tempServiceList.front();
			tempServiceList.pop_front();
			delete servTemp;

		}
	}

}

void RailSystem::output_cheapest_route(const string& from,
                const string& to, ostream& out) {

	reset();
	pair<int, int> totals = calc_route(from, to);

	if (totals.first == INT_MAX) {
		out << "There is no route from " << from << " to " << to << "\n";
	} else {
		out << "The cheapest route from " << from << " to " << to << "\n";
		out << "costs " << totals.first << " euros and spans " << totals.second
			<< " kilometers\n";
        cout << recover_route(to) << "\n\n";
	}
}

bool RailSystem::is_valid_city(const string& name) {

	return cities.count(name) == 1;
}

pair<int, int> RailSystem::calc_route(string from, string to) {
    // You can use another container
	priority_queue<City*, vector<City*>, Cheapest> candidates;
    City* initialCity=cities[from];
	initialCity->total_fee=0;
	candidates.push(initialCity);
	while (!candidates.empty())
	{
		City* temp=candidates.top();
		temp->visited=true;
		candidates.pop();
		if (temp->name==to)
			break;
	    std::list<Service*> outService=outgoing_services[temp->name];
		for (std::list<Service*>::iterator iter=outService.begin();iter!=outService.end();iter++)
		{
			Service* serv = iter;
			City* next=cities[serv->destination];
			if (!next->visited)
			{
				if((temp->total_fee+serv->fee)<(next->total_fee))
				{
					next->total_fee=temp->total_fee+serv->fee;
					next->from_city=temp->name;
					next->total_distance=temp->total_distance+serv->distance;
					candidates.push(next);
				}
			}
		}


	}

    // Return the total fee and total distance.
    // Return (INT_MAX, INT_MAX) if not path is found.
    if (cities[to]->visited) {
            return pair<int,int>(cities[to]->total_fee, cities[to]->total_distance);
    } else {
            return pair<int,int>(INT_MAX, INT_MAX);
    }

}

string RailSystem::recover_route(const string& city) {
	
    City* tempCities=cities[city];
	string str;
	while(1)
	{
		str==""? str=tempCities->name:str=tempCities->name+" to "+str;
		if(tempCities->from_city=="")
			break;
		tempCities=cities[tempCities->from_city];

	}
    return str;
}


Route RailSystem::getCheapestRoute(const string& from, const string& to){
    assert(is_valid_city(from));
    assert(is_valid_city(to));
    reset();
    pair<int, int> p =  calc_route(from,to);
    return Route(from,to,p.first,p.second);
}