#include "NodeGraph.hpp"

void NodeGraph::addNode(std::shared_ptr<BaseNode> node) {
    nodes.push_back(node);
}

void NodeGraph::connect(std::shared_ptr<BaseNode> from, int outIdx,
                        std::shared_ptr<BaseNode> to, int inIdx) {
    connections.emplace_back(from, to, outIdx, inIdx);
}

QImage NodeGraph::executeGraph(std::shared_ptr<BaseNode> outputNode) {
    // For now, just return outputNode's process method with empty input
    std::vector<QImage> inputs; // Placeholder
    return outputNode->process(inputs);
}
