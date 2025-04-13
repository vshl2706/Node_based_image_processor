#ifndef NODEGRAPH_HPP
#define NODEGRAPH_HPP

#include <vector>
#include <memory>
#include "BaseNode.hpp"
#include "NodeConnection.hpp"

class NodeGraph {
public:
    void addNode(std::shared_ptr<BaseNode> node);
    void connect(std::shared_ptr<BaseNode> from, int outIdx,
                 std::shared_ptr<BaseNode> to, int inIdx);

    QImage executeGraph(std::shared_ptr<BaseNode> outputNode);

private:
    std::vector<std::shared_ptr<BaseNode>> nodes;
    std::vector<NodeConnection> connections;
};

#endif // NODEGRAPH_HPP
