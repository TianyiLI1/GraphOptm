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
    //�ṩ���ֳ�ʼ���������Ƽ��ĳ�ʼ��������ֻȷ�����������ʼ��ͼ��Ȼ����forѭ���ӱ�
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
    //set�������ڳ�ʼ�����ܵı�����
    void setMaxEdgeCount(int maxEdgeCount);

    Edge searchEdge(int from,int to);
    
   
    void CircuitSearch ();
    //����һ��stack���������װ�ü���ͼ���������������Ļ���
    std::vector<std::vector < std::vector<Edge> >>getCircuit();

    //����һ��һ���ӱ�
    void AddEdge (int from,int to, double cost);
    //Ҳ���������ӱߣ���double��������Ϊ������ᰲ��ǿ��ת��
    void AddEdgeByArray ( std::vector < std::vector<double> > edges );

    void ShortestPath_Dijkstras(int startID,int endID);
    //һ�����������ȴ�ʵ��

    //void setNodes(int* idNodes, int (*fromId)[3]);


};

#endif /* Graphe_hpp */
