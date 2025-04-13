#ifndef NODECONNECTION_HPP
#define NODECONNECTION_HPP

#include <memory>

class BaseNode;

struct NodeConnection {
    std::shared_ptr<BaseNode> fromNode;
    std::shared_ptr<BaseNode> toNode;
    int outputIndex;
    int inputIndex;

    NodeConnection(std::shared_ptr<BaseNode> from,
                   std::shared_ptr<BaseNode> to,
                   int outIdx, int inIdx);
}; 

#endif // NODECONNECTION_HPP
