//
// Created by user on 3/17/26.
//

#ifndef ARCADE_IGAMEMODULE_HPP
#define ARCADE_IGAMEMODULE_HPP
#include <map>
#include <memory>
#include <vector>

#include "../../src/Dispatcher/EventDispatcher.hpp"
#include "IGameState.hpp"

namespace arc {
    /**
     * @interface IGameModule
     * @brief Interface for game modules that implement specific games.
     *
     * This interface defines the contract for game implementations. Each game module
     * manages its own game state, sprites, events, and update logic. Game modules can
     * request switches to different games or display libraries through module change requests.
     */
    class IGameModule {
    protected:
        /**
         * @brief Add a sprite to the internal sprite map.
         * @param identifier unique identifier for the sprite in the game context
         * @param path file path to the sprite resource
         * @return void
         */
        virtual void add_sprite(std::string identifier, std::string path) = 0;
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~IGameModule() = default;

        /**
         * @brief Initialize the game module.
         *
         * Performs any setup required for the game, such as loading initial resources,
         * initializing the game state, and setting up event listeners.
         *
         * @return void
         */
        virtual void initGame() = 0;

        /**
         * @brief Get the IGameModule interface pointer.
         * @return IGameModule* pointer to this game module
         */
        virtual IGameModule *getIGameModule() = 0;

        /**
         * @brief Get the sprite map for this game.
         * @return std::map<std::string, std::string>& reference to the sprite identifier-to-path map
         */
        virtual std::map<std::string, std::string> &getSpriteMap() = 0;

        /**
         * @brief Get the event dispatcher for this game module.
         * @return EventDispatcher& reference to the event dispatcher
         */
        virtual EventDispatcher &getEventDispatcher() = 0;

        /**
         * @brief Get the current game state.
         * @return IGameState* pointer to the current game state
         */
        virtual IGameState *getGameState() = 0;

        /**
         * @brief Initialize game data for the given screen dimensions.
         * @param screenX screen width in pixels
         * @param screenY screen height in pixels
         * @return void
         */
        virtual void initGameData(int screenX, int screenY) = 0;

        /**
         * @brief Update game state based on events and elapsed time.
         * @param events reference to vector of events to process
         * @return void
         */
        virtual void update(std::vector<std::unique_ptr<IArcadeEvent>> &events) = 0;

        /**
         * @brief Get the name of the requested game module change, if any.
         * @return std::string name of new game module, or empty string if no change requested
         */
        virtual std::string getGameModuleChange() = 0;

        /**
         * @brief Get the name of the requested display module change, if any.
         * @return std::string name of new display module, or empty string if no change requested
         */
        virtual std::string getDisplayModuleChange() = 0;

        /**
         * @brief Set the aspect ratio for tiles (width/height).
         * @param ratio the tile aspect ratio
         * @return void
         */
        virtual void setTileAspectRatio(float ratio) = 0;

        /**
         * @brief Check if the game should close.
         * @return bool true if the game should exit, false otherwise
         */
        virtual bool shouldClose() = 0;
    };
} // arc

#endif //ARCADE_IGAMEMODULE_HPP