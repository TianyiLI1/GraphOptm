//
//  Graphe.hpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//Modified by LI Tianyi on 9/25/2022:
// implement prototype  circuit search, dijkstras
// dijkstras untested

#ifndef Graphe_hpp
#define Graphe_hpp
#include "Node.hpp"
#include <string>
#include<stack>
#include <functional>
#include <vector> 
#include <iostream>

struct OptimalPath {
int start;
int end;
    std::vector < std::vector<Edge> > route;
     double shortestCost;
};

class Graphe {
    
    
private:
    int maxNodeCount;
    int maxEdgeCount;
    std::vector < std::vector<Edge> > graph;
    int number_circuit;
    std::vector<std::vector < std::vector<Edge> >> circuit;

public:
    //提供多种初始化方法。推荐的初始化方法：只确定点个数，初始化图，然后用for循环加边
    Graphe ();
    Graphe (int maxNodecount);
    Graphe ( int maxNodecount, std::vector < std::vector<Edge> > graph_initialization );
    Graphe ( std::vector < std::vector<Edge> > graph_initialization );
    ~Graphe ();
    OptimalPath ShortestPath_Dijkstras(int startID, int endID);
    int getNumberCircuit ();

    std::vector < std::vector<Edge> > getGraph ();
  
    std::string printGraph ();

    int getMaxNodeCount();
    void setMaxNodeCount(int maxNodeCount);
    int getMaxEdgeCount();
    //set方法用于初始设置总的边条数
    void setMaxEdgeCount(int maxEdgeCount);

    Edge searchEdge(int from,int to);
    
   
    void CircuitSearch ();
    //返回一个stack，里面可以装好几张图（如果检测出多个环的话）
    std::vector<std::vector < std::vector<Edge> >>getCircuit();

    //可以一条一条加边
    void AddEdge (int from,int to, double cost);
    //也可以批量加边，用double数组是因为函数里会安排强制转换
    void AddEdgeByArray ( std::vector < std::vector<double> > edges );

    void ShortestPath_Dijkstras(int startID,int endID);
    //一下三个方法等待实现

    //void setNodes(int* idNodes, int (*fromId)[3]);


};

#endif /* Graphe_hpp */
