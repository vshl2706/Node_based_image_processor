#ifndef BASENODE_HPP
#define BASENODE_HPP

#include <QString>
#include <QImage>
#include <vector>
#include <memory>

class BaseNode {
public:
    BaseNode(QString name);
    virtual ~BaseNode() = default;

    QString getName() const;
    
    // Each node processes and returns an image
    virtual QImage process(const std::vector<QImage> &inputs) = 0;

    int getInputCount() const;
    int getOutputCount() const;

protected:
    QString name;
    int inputCount;
    int outputCount;
};

#endif // BASENODE_HPP
