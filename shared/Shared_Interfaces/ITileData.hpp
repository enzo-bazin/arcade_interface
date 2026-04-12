//
// Created by user on 3/17/26.
//

#ifndef ARCADE_ITILEDATA_HPP
#define ARCADE_ITILEDATA_HPP
#include <string>

namespace arc {
    /**
     * @interface ITileData
     * @brief Interface for tile data objects that represent a single tile in the game world.
     *
     * Each tile can have a sprite representation and optional text display. This interface
     * defines the contract for accessing and modifying tile properties such as sprite name,
     * text content, and text color.
     */
    class ITileData {
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~ITileData() = default;

        /**
         * @brief Get the sprite name/identifier for this tile.
         * @return std::string sprite identifier
         */
        virtual std::string getSpriteName() = 0;

        /**
         * @brief Get the text content displayed on this tile.
         * @return std::string text content
         */
        virtual std::string getText() = 0;

        /**
         * @brief Get the color of the text displayed on this tile.
         * @return std::string color specification (format depends on display module)
         */
        virtual std::string getTextColor() = 0;

        /**
         * @brief Set the text content to be displayed on this tile.
         * @param text the text to display
         * @return void
         */
        virtual void setText(std::string text) = 0;

        /**
         * @brief Set the sprite name/identifier for this tile.
         * @param sprite sprite identifier to use
         * @return void
         */
        virtual void setSpriteName(std::string sprite) = 0;
    };
} // arc

#endif //ARCADE_ITILEDATA_HPP
