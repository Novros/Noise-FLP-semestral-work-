/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#pragma once
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * @file
 * @author  Rostislav Novak <rostislav.novak92@gmail.com>
 * @version 1.0
 *
 * @section LICENSE* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
**/

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// STL HEADERS
#include <iostream>
#include <vector>
#include <queue>

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// OWN HEADERS
#include "State.hpp"
#include "../data/GraphList.hpp"
#include "../data/PriorityQueue.hpp"

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/**
 * [Short_description]
 * [long_description]
 *
 * @author Rostislav Novak
*/
class StateFindPath: public State {
	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Variables
private:
	int findLeastPath(const GraphList & graph, const int & from, const int & to) const {
		int N = graph.getN();
		int distance[N];
		int path[N];
		PriorityQueue q;
		
		distance[from] = 0;
		path[from] = 0;
		q.push(from);
		// Inicializace
		for(int j = 0; j < N; j++) {
			if(j != from) {
				distance[j] = 9999;
				path[j] = 0;		
				q.push(j);
			}
		}

		//Dijsktra
		int v;
		while(!q.empty()) {
			v = q.pop(distance);

			std::vector<int> vector = graph.get(v);
			for (std::vector<int>::iterator i = vector.begin(); i != vector.end(); ++i)	{
				int alt = distance[v] + graph.get(v,*i);
				if(alt < distance[*i]) {
					distance[*i] = alt;
					path[*i] = v;
				}
			}
		}
		
		return distance[to];
	}

protected:

public:

	/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
	// Methods
private:

protected:

public:
	/*********************************************** Constructors ****************************************************/

	/************************************************** Others *******************************************************/
	int run(std::string line, GraphList & graph) {
		std::vector<std::string> values = parseString(line, " ");
		if(values.size() == 3) {
			return 1;
		}

		int result = findLeastPath(graph, std::stoi(values[0]),std::stoi(values[1]));
		if(result == 9999) {
			std::cout << "no path" << std::endl;
		} else {
			std::cout << result << std::endl;
		}		
		
		return 0;
	}
};

