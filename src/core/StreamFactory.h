#pragma once

#include <core/Stream.h>
#include <string>
#include <memory>

class StreamFactory
{
public:
    StreamFactory() = default;
    virtual ~StreamFactory() = default;

    virtual std::unique_ptr<Stream> open(const std::string& fileName) = 0;
};