//
//  Graphe.cpp
//  Graphes et optimisation
//
//  Created by ZHENG Shutong on 2022/9/19.
// 
//Modified by LI Tianyi on 9/25/2022:
// implement prototype  circuit search, dijkstras
// dijkstras untested


#include "Graphe.hpp"
#define INF 0x7fffffff
#include <queue>

Graphe::Graphe(){
    maxNodeCount = 0;
    maxEdgeCount = 0;
    number_circuit = 0;
    
}
Graphe::Graphe ( int maxNodecount )
{
    maxNodeCount = maxNodeCount;
    maxEdgeCount = 0;
    number_circuit = 0;
}
Graphe::Graphe (int maxNodecount, std::vector < std::vector<Edge> > graph_initialization)
{
    maxNodeCount = maxNodeCount;
    maxEdgeCount = 0;
    graph = graph_initialization;
    number_circuit = 0;
}
Graphe::Graphe ( std::vector < std::vector<Edge> > graph_initialization )
{
    maxNodeCount = 0;
    maxEdgeCount = 0;
    graph = graph_initialization;
    number_circuit = 0;
    for(auto edges = graph.begin (); edges != graph.end (); ++edges)
    {
        maxNodeCount++;
    }
}

Graphe::~Graphe ()
{
    
}

//circuitNumber没有setter，只能通过cuountCircuit进行更新
int Graphe::getNumberCircuit()
{
    return number_circuit;
}

std::vector < std::vector<Edge> >Graphe:: getGraph ()
{
    return graph;
}

std::string Graphe::printGraph ()
{
    if (graph.size()==0)
        {
        return "Empty Graph";
        }
    else
        {
        std::string str = "";
        for (auto it = graph.begin(); it != graph.end(); it++)
            {
            str += "Node " + std::to_string(std::distance(graph.begin(), it)) + " \n";

            std::vector<Edge> temp_vec = *it;

            for (auto it2 = temp_vec.begin(); it2 != temp_vec.end(); it2++)
                {
                str += "From" + std::to_string((*it2).getFromId());
                str += " To" + std::to_string((*it2).getToId());
                str += " Weight=" + std::to_string((*it2).getWeight());
                }
            str += "\n";

            }


        return str;
        }
}


int Graphe::getMaxNodeCount(){
    return maxNodeCount;
}
void Graphe::setMaxNodeCount(int maxNodeCount1){
    this->maxNodeCount = maxNodeCount1;
    graph.resize ( maxNodeCount1 );
}

int Graphe::getMaxEdgeCount(){
    return maxEdgeCount;
}
void Graphe::setMaxEdgeCount(int maxEdgeCount){
    this->maxEdgeCount = maxEdgeCount;
}


//void Graphe::setNodes(int* idNodes, int (*toId)[3]){
//    for (int i=0 ; i< maxNodeCount; i++) {
//        Node node(idNodes[i]);
//        std::vector<Edge> edges;
//        for (int j=0; j<maxEdgeCount; j++) {
//            if (toId[j][0] == idNodes[i]) {
//                Edge e(toId[j][1],toId[j][2]);
//                edges.push_back(e);
//            }
//        }
//        node.setEdges(edges);
//
//        this->nodes.push_back(node);
//    }
//
//}


void Graphe:: CircuitSearch ()
{
   static std::vector<Edge>edgeTo(99); //记录到达当前顶点的最后一条边

   static  int n_circuit = 0;
    static std::vector<bool>visited ( 99, false );
   static  std::vector<bool>onStack ( 99, false );
    //记录遍历和访问的数组
    /*std::vector<Node>notes_temp = nodes;*/
    //默认从0点开始遍历
    std::function<void(int)> DFS = [&] (int v) {

        onStack[v] = true;
        visited[v] = true;

        for(auto it = graph[v].begin (); it != graph[v].end (); it++)
        {

                int w = (*it).getToId();
                if(!visited[w])
                {
                    edgeTo[w] = (*it);
                    DFS ( w );
                }
                else if(onStack[w])
                {
                    std::vector < std::vector<Edge> > graph_temp(maxNodeCount);
                    Edge f = (*it);
                    while(f.getFromId()!=w)
                    {
                        graph_temp[f.getFromId ()].push_back ( f );
                        f = edgeTo [ f.getFromId () ];

                    }

                    graph_temp[f.getFromId ()].push_back ( f );
                    circuit.push_back( graph_temp );

                    n_circuit++;
                    return;
                }

            }

        onStack[v] = false;
        };

    for(int v = 0; v < maxNodeCount; v++)
    {
        if(!visited[v])
        {
            DFS ( v );
        }
    }
    number_circuit = n_circuit;


  std::cout<<"search complete, circuit number is: "<<n_circuit<<std::endl;


}

std::vector<std::vector < std::vector<Edge> >>Graphe:: getCircuit()
    {
    if (number_circuit==0)
        {
       std::cout<<"Empty circuit";
        return circuit;

        }
    else
        {
        return circuit;
        }

    }

void Graphe::AddEdge ( int from, int to, double cost )
{
    Edge edge_temp ( from, to, cost );
    graph[from].push_back ( edge_temp );
    
}

//用二维vector批量加边吧，数组我写不明白
void Graphe::AddEdgeByArray ( std::vector < std::vector<double> > edges )
{
    for(auto it = edges.begin(); it != edges.end(); it++)
    {
        Edge edge_temp((int)(*it)[0], (int)(*it)[1] , (*it)[2] );
        
        graph[((int)(*it)[0])].push_back ( edge_temp );
    }
}
OptimalPath Graphe::ShortestPath_Dijkstras(int startID, int endID)
    {
    OptimalPath optimalPath;
    optimalPath.start=startID;
    optimalPath.end=endID;
    optimalPath.shortestCost=INF;

    // Maintain an array of the minimum distance to each node
std::vector<double>distance(maxNodeCount,INF);

//record node for tracing back use
std::vector<int>prev(maxNodeCount);

    // Array used  track which nodes have already been visited.
std::vector<bool>visited(maxNodeCount);

// Maintain a priority queue of the next most promising node to visit.
    struct cmp_pq{
        bool operator()(Node &a,Node &b)
            {
            return a.getValue()>b.getValue();//按道理double的比较不能这么来的，要设一个小量E，然后把两个数之差的绝对值跟这个小量比，之后再改吧。。。
            }
    };
std::priority_queue<Node,std::vector<Node>,cmp_pq>pq;
Node *startNode_temp=new Node(startID,0);
pq.push(*startNode_temp);
/*delete startNode_temp;*/

    distance[startID]=0;

    //search
    while (!pq.empty())
        {
        Node node=pq.top();
        pq.pop();
        visited[node.getId()]= true;

        // We already found a better path before we got to
        // processing this node so we can ignore it.
        if (distance[node.getId()]<node.getValue())
            {
            continue;
            }
        std::vector<Edge>edges=graph[node.getId()];
        for (int i = 0; i < edges.size(); ++i)
            {
            Edge edge=edges[i];
            // We cannot get a shorter path by revisiting
            // a node we have already visited before.
            if (visited[edge.getToId()])
                {
                continue;
                }
            // Relax edge by updating minimum cost if applicable.
                double newDistance=distance[edge.getFromId()]+edge.getWeight();

            if (newDistance<distance[edge.getToId()])
                {
                prev[edge.getToId()]=edge.getFromId();
                distance[edge.getToId()]=newDistance;
                Node* node_temp=new Node(edge.getToId(),distance[edge.getToId()]);
                pq.push(*node_temp);
                /*delete node_temp;*/
                }
            }
        // Once we've visited all the nodes spanning from the end
        // node we know we can return the minimum distance value to
        // the end node because it cannot get any better after this point.
        if (node.getId()==endID)
            {
            optimalPath.shortestCost= distance[endID];
            }
        }

//retracing route
    if (endID<0||endID>=maxNodeCount)
        {
        throw std::errc::invalid_argument;
        }
    if (startID<0||startID>=maxNodeCount)
        {
        throw std::errc::invalid_argument;
        }
        std::vector<std::vector<Edge>> graph_temp;
    if (optimalPath.shortestCost==INF)
        {
        return optimalPath;
        }

    for (auto i =endID; i !=NULL ; i=prev[i])
        {
        graph_temp[prev[i]].push_back(searchEdge(prev[i],i));
        }
        optimalPath.route=graph_temp;

    //返回了一个结构体，所以用的时候也得拿结构体接
    return  optimalPath;
    }

    Edge Graphe::searchEdge(int from, int to)
        {
        std::vector<Edge> edges_temp=graph[from];
        for (auto it1 = edges_temp.begin(); it1 != edges_temp.end(); ++it1)
            {
            Edge edge_temp=*it1;
            if (edge_temp.getToId()==to)
                {
                return edge_temp;
                }
            }
        }


