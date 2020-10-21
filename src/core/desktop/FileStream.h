#pragma once

#include <core/Stream.h>

#include <fstream>
#include <string>

class FileStream : public Stream
{
public:
    explicit FileStream(const std::string& path);
    ~FileStream() override;

    unsigned int size() const override;
    int read(void* target, size_t bytes) override;

private:
    std::ifstream file;
    unsigned int fileSize;
};