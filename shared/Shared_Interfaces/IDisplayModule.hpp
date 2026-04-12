//
// Created by user on 3/17/26.
//

#ifndef ARCADE_IDISPLAYMODULE_HPP
#define ARCADE_IDISPLAYMODULE_HPP
#include <map>
#include <memory>
#include <vector>

#include "IArcadeEvent.hpp"
#include "IGameState.hpp"

namespace arc {
    /**
     * @interface IDisplayModule
     * @brief Interface for display modules that render game state to the screen.
     *
     * This interface defines the contract for display implementations such as
     * NCurses, SDL2, and SFML. It handles window initialization, event polling,
     * rendering, and screen dimension management.
     */
    class   IDisplayModule {
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~IDisplayModule() = default;

        /**
         * @brief Initialize the display module (loads sprites and such)
         * @param sprite_map the sprite map containing sprite identifiers mapped to file paths
         * @return void
         */
        virtual void initDisplay(std::map<std::string, std::string> sprite_map) = 0;

        /**
         * @brief Get the assets mapping for loaded sprites.
         * @return std::map<std::string, std::string> mapping of sprite identifiers to paths
         */
        virtual std::map<std::string, std::string> getAssetsMapping() = 0;

        /**
         * @brief Get window events that have occurred since last poll.
         * @return std::vector<std::unique_ptr<IArcadeEvent>> vector of events
         */
        virtual std::vector<std::unique_ptr<IArcadeEvent>> getWindowEvents() = 0;

        /**
         * @brief Display/render the current game state on the screen.
         * @param state pointer to the IGameState containing game data to render
         * @return void
         */
        virtual void display(IGameState *state) = 0;

        /**
         * @brief Poll for window events (keyboard, mouse, window close, etc).
         * @return void
         */
        virtual void pollEvents() = 0;

        /**
         * @brief Get the screen width in pixels.
         * @return int screen width
         */
        virtual int getScreenX() const = 0;

        /**
         * @brief Get the screen height in pixels.
         * @return int screen height
         */
        virtual int getScreenY() const = 0;

        /**
         * @brief Get the aspect ratio of a single tile (width/height).
         * @return float aspect ratio, typically 1.0f for square tiles
         */
        virtual float getTileAspectRatio() const = 0;

        /**
         * @brief Close the display window and clean up resources.
         * @return void
         */
        virtual void closeWindow() = 0;
    };
} // arc

#endif //ARCADE_IDISPLAYMODULE_HPP
