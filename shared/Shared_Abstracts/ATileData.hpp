//
// Created by user on 3/18/26.
//

#ifndef ARCADE_ATILEDATA_HPP
#define ARCADE_ATILEDATA_HPP
#include <string>

#include "../Shared_Interfaces/ITileData.hpp"

namespace arc {
    /**
     * @class ATileData
     * @brief Abstract base class for tile data implementations.
     *
     * Provides a partial implementation of ITileData with common tile properties.
     * Concrete tile implementations should inherit from this class and implement
     * the interface methods or provide implementations for them.
     */
    class ATileData : public ITileData {

    public:
        /**
         * @brief Sprite name/identifier for this tile.
         *
         * References the sprite to display for this tile. Should correspond to
         * an entry in the game module's sprite map.
         */
        std::string sprite_name;

        /**
         * @brief Text content to display on this tile.
         *
         * Optional text overlay on the sprite.
         */
        std::string text;

        /**
         * @brief Color of the text displayed on this tile.
         *
         * Format depends on the display module implementation.
         */
        std::string textColor;

        /**
         * @brief Get the text content of this tile.
         * @return std::string the text content
         */
        std::string getText() override;

        /**
         * @brief Get the sprite name/identifier for this tile.
         * @return std::string the sprite identifier
         */
        std::string getSpriteName() override;

        /**
         * @brief Get the text color for this tile.
         * @return std::string the color specification
         */
        std::string getTextColor() override;

        /**
         * @brief Set the sprite name/identifier for this tile.
         * @param sprite the sprite identifier
         * @return void
         */
        void setSpriteName(std::string sprite) override;

        /**
         * @brief Set the text content for this tile.
         * @param text the text to display
         * @return void
         */
        void setText(std::string text) override;

    };
} // arc

#endif //ARCADE_ATILEDATA_HPP