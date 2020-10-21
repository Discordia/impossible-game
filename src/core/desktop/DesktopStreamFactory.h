#pragma once

#include <core/StreamFactory.h>
#include <core/desktop/FileStream.h>

class DesktopStreamFactory : public StreamFactory
{
public:

    explicit DesktopStreamFactory(std::string  directoryName)
        : directoryName(std::move(directoryName)) {}

    std::unique_ptr<Stream> open(const std::string& fileName) override;

private:
    std::string directoryName;
};

std::unique_ptr<Stream> DesktopStreamFactory::open(const std::string& fileName) {
    return std::unique_ptr<Stream>(new FileStream(directoryName + "/" + fileName));
}
