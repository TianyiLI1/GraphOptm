//
//  main.cpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//Modified by LI Tianyi on 9/25/2022



#include "Graphe.hpp"
#include <queue>

int main(int argc, const char * argv[]) {
    // insert code here...
    
   /* int nodes[3] = {0,1,2};
    std::vector < std::vector<double> > edges = {
        {0,1,2000},
        {1,2,2400},
        {2,0,3600},

    };
    Graphe graphe;
    graphe.setMaxNodeCount(3);
    graphe.AddEdgeByArray ( edges );
    std::cout << graphe.printGraph()<<std::endl << std::endl << std::endl;

    graphe.CircuitSearch ();
    std::cout <<"Circuit number is:"<< graphe.getNumberCircuit () << std::endl << std::endl << std::endl;
    auto circuit1= graphe.getCircuit();
     Graphe graph11=circuit1[0];
    std::cout <<graph11.printGraph()<<std::endl << std::endl << std::endl;*/
    struct cmp_pq{
        bool operator()(Node &a,Node &b)
            {
            return a.getValue()>b.getValue();//按道理double的比较不能这么来的，要设一个小量E，然后把两个数之差的绝对值跟这个小量比，之后再改吧。。。
            }
        };
    std::priority_queue<Node,std::vector<Node>,cmp_pq>pq;
    Node *startNode_temp=new Node(1,0);
    pq.push(*startNode_temp);
    delete startNode_temp;
Node node=pq.top();
std::cout<<node.getId()<<std::endl;

    return 0;


}
