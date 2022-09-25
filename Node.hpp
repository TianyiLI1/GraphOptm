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
    //value���ڴ�����ܵ���Ҫ��¼��ÿ���ڵ��ϵ�ֵ������dijstras����ʱ����
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
