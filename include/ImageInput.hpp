#ifndef IMAGEINPUTNODE_HPP
#define IMAGEINPUTNODE_HPP

#include "BaseNode.hpp"
#include <QString>
#include <QImage>

class ImageInputNode : public BaseNode {
public:
    ImageInputNode(const QString& name);

    void loadImage(const QString& path);
    QImage getImage() const;

    QImage process(const std::vector<QImage>& inputs) override;

private:
    QImage image;
    QString filePath;
}; 

#endif // IMAGEINPUTNODE_HPP
