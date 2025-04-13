#include "NodeConnection.hpp"

NodeConnection::NodeConnection(std::shared_ptr<BaseNode> from,
                               std::shared_ptr<BaseNode> to,
                               int outIdx, int inIdx)
    : fromNode(from), toNode(to), outputIndex(outIdx), inputIndex(inIdx) {}
 