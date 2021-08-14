#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

class AdjancencyList{
    private:
        // Graph
        map<string, vector<string>> graph;
        // Variables
        int no_of_vectors = 0;
        vector<int> no_of_degree;
        vector<float> ranks;
        vector<float> previousRanks;
    public:
        // Methods
        // Insert edge in the graph from "from" to "to"
        void insertEdge(string from, string to){
          graph[from].push_back(to);
          if(graph.find(to)==graph.end()){
              graph[to] = {};
          }
        }
        // Calculate the out degree of each vector in the graph
        void calculateOutDegree(){
            for (auto it = graph.begin(); it != graph.end(); it++){
                no_of_degree.push_back(it->second.size());
                no_of_vectors++;
            }
        }
        // Calculate the rank of each vector in the graph
        void calculateRanks(int power_iterations){
            for (int i = 0; i < no_of_vectors; i++){
                ranks.push_back(1 / (float)no_of_vectors);
                previousRanks.push_back(1 / (float)no_of_vectors);
            }
            // In case the power iteration is bigger than 1
            for (int i = 1; i < power_iterations; i++){
                int count = 0;
                for (auto it = graph.begin(); it != graph.end(); it++){
                    float rank = 0;
                    int count2 = 0;
                    for (auto it2 = graph.begin(); it2 != graph.end(); it2++){
                        for(int k = 0; k < it2->second.size(); k++){
                            if(it->first == it2->second[k]){
                                rank = (previousRanks[count2] * (1/(float)no_of_degree[count2])) + rank;
                            }
                        }
                        count2++;
                    }
                    ranks[count] = rank;
                    count++;
                }
                if(i + 1 < power_iterations){
                    for (int index = 0; index < no_of_vectors; index++){
                        previousRanks[index] = ranks[index];
                    }
                }
            }
        }
        // Print the vectors in the graph in alphabetic ascending order
        void print(){
            int count = 0;
            for (auto it = graph.begin(); it != graph.end(); it++){
                cout << it->first << " " << fixed << setprecision(2) << ranks[count] << endl;
                count++;
            }
        }
};
int main()
{
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    AdjancencyList list;
    
    for(int i = 0; i < no_of_lines; i++){
        cin >> from;
        cin >> to;
        list.insertEdge(from, to);
    }
    list.calculateOutDegree();
    list.calculateRanks(power_iterations);
    list.print();
    return 0;
}
