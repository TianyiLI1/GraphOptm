//
//  Node.hpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//Modified by LI Tianyi on 9/25/2022:
//for dijkstras use ,add a private data "value"

#ifndef Node_hpp
#define Node_hpp

#include "Edge.hpp"



class Node {
    
private:
    int id;
    //value用于储存可能的需要记录在每个节点上的值，比如dijstras的临时数据
    double value;
public:
    Node(int id);
    Node ( int id, double value );
    int getId();
    void setId(int id);
    
    double getValue ();
    void setValue (double value);
    void setValue ( int value );


};




#endif /* Node_hpp */
