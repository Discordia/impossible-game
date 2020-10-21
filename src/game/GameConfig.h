#pragma once

#include <memory>
#include <string>

class StreamFactory;

class GameConfig {
public:
    GameConfig()
        : width(640), height(480), title("Game Title") {}

    void withResolution(int32_t width, int32_t height) {
        this->width = width;
        this->height = height;
    }

    void withTitle(const std::string& title) {
        this->title = title;
    }

    void withStreamFactory(std::shared_ptr<StreamFactory> streamFactory) {
        this->streamFactory = std::move(streamFactory);
    }

public:

    [[nodiscard]] int32_t getWidth() const { return width; }
    [[nodiscard]] int32_t getHeight() const { return height; }
    [[nodiscard]] std::string getTitle() const { return title; }
    [[nodiscard]] std::shared_ptr<StreamFactory> getStreamFactory() const { return streamFactory; };

private:
    int32_t width;
    int32_t height;
    std::string title;
    std::shared_ptr<StreamFactory> streamFactory;
};