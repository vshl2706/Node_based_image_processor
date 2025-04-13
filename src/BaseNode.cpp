#include "BaseNode.hpp"

BaseNode::BaseNode(QString name)
    : name(name), inputCount(1), outputCount(1) {}

QString BaseNode::getName() const {
    return name;
}

int BaseNode::getInputCount() const {
    return inputCount;
}

int BaseNode::getOutputCount() const {
    return outputCount;
}
