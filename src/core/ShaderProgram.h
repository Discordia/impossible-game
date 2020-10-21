#pragma once

#include <core/StreamFactory.h>
#include <bgfx/bgfx.h>
#include <fstream>

class ShaderProgram {
public:
    explicit ShaderProgram(bgfx::ProgramHandle programHandle)
            : programHandle(programHandle) {}

    ~ShaderProgram() = default;

    static std::unique_ptr<ShaderProgram> load(
            const std::shared_ptr<StreamFactory>& streamFactory,
            const std::string& vertexShaderFile,
            const std::string& fragmentShaderFile) {
        auto vertexShaderHandle = loadShader(streamFactory, vertexShaderFile);
        auto fragmentShaderHandle = loadShader(streamFactory, fragmentShaderFile);
        return std::make_unique<ShaderProgram>(bgfx::createProgram(vertexShaderHandle, fragmentShaderHandle, true));
    }

    void submit() {
        bgfx::submit(0, programHandle);
    }

private:
    static bgfx::ShaderHandle loadShader(
            const std::shared_ptr<StreamFactory>& streamFactory,
            const std::string& name) {
        char* data = new char[2048];
        auto fileStream = streamFactory->open(name);
        fileStream->read(data, fileStream->size());

        const bgfx::Memory* mem = bgfx::copy(data,fileStream->size() + 1);
        mem->data[mem->size-1] = '\0';

        bgfx::ShaderHandle handle = bgfx::createShader(mem);
        bgfx::setName(handle, name.c_str());
        return handle;
    }

private:
    bgfx::ProgramHandle programHandle;
};