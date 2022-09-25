//
//  Node.cpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
// Modified by LI Tianyi on 22/9/2022
//

#include "Node.hpp"

Node::Node(int id){
    this->id = id;
}
Node::Node ( int id,double Value )
{
    this->id = id;
    this->value = Value;
}

int Node::getId(){
    return id;
}
void Node::setId(int id){
    this->id = id;
}

double Node::getValue ()
{
    return value;
}
void Node::setValue ( double value )
{
    this->value = value;
}
