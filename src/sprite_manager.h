#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <unordered_map>
#include "sprite.h"
#include <SFML/Graphics.hpp>

using SpriteID = size_t;

class SpriteManager {
    std::unordered_map<std::string, sf::Texture> mTextures;
    std::vector<Sprite> mSprites;

public:
    sf::Texture& registerTexture(const std::string& filepath) {
        if (!mTextures.contains(filepath)) {
            mTextures[filepath] = sf::Texture(filepath);
        }
        return mTextures[filepath];
    }

    template <typename... Args>
    SpriteID createSprite(Args&&... args) {
        mSprites.push_back(Sprite(std::forward<Args...>(args...)));
        return mSprites.size() - 1;
    }

    Sprite& getSprite(SpriteID id) {
        return mSprites[id];
    }
};

#endif  // SPRITE_MANAGER_H
