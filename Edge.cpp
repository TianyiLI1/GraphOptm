//
//  Edge.cpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
//Modified by LI Tianyi on 9/25/2022

#include "Edge.hpp"

Edge::Edge(int fromId, int toId, double weight){
    this->toId = toId;
    this->weight = weight;
    this->fromId = fromId;
}

Edge::Edge (  )
{
    this->toId = 0;
    this->weight = 0;
    this->fromId = 0;
}

Edge::~Edge ()
{
    
    
}

double Edge::getWeight(){
    return weight;
}
void Edge::setWeight(double weight){
    this->weight = weight;
}
int Edge::getToId(){
    return toId;
}
void Edge::setToId(int toId){
    this->toId = toId;
}

int Edge::getFromId ()
{
    return fromId;
}
void Edge::setFromId ( int fromId )
{
    this->fromId = fromId;
}


