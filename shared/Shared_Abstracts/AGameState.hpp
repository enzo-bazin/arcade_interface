//
// Created by user on 3/18/26.
//

#ifndef ARCADE_AGAMESTATE_HPP
#define ARCADE_AGAMESTATE_HPP
#include <memory>

#include "../Shared_Interfaces/IGameState.hpp"

namespace arc {
    /**
     * @class AGameState
     * @brief Abstract base class for game state implementations.
     *
     * Provides a partial implementation of IGameState with common state management
     * functionality. Maintains the 2D grid of tiles, dimensions, and flags for
     * module switching. Concrete game states should inherit from this class.
     */
    class AGameState: public IGameState {
    protected:
        /**
         * @brief 2D grid of tile data representing the game world.
         *
         * Each tile can contain sprite and text information for rendering.
         */
        std::vector<std::vector<std::unique_ptr<ITileData>>> _gameData;

        /**
         * @brief Width of the game board in tiles.
         */
        int _width;

        /**
         * @brief Height of the game board in tiles.
         */
        int _height;

        /**
         * @brief Name of the new game module to switch to, if requested.
         *
         * Empty string indicates no module change is requested.
         */
        std::string newGameModuleName = "";

        /**
         * @brief Name of the new display module to switch to, if requested.
         *
         * Empty string indicates no module change is requested.
         */
        std::string newDisplayModuleName = "";

        /**
         * @brief Flag indicating whether the game should close.
         */
        bool _shouldClose = false;

    public:
        /**
         * @brief Default constructor.
         */
        AGameState() = default;

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        ~AGameState() override = default;

        /**
         * @brief Initialize the game data grid with the specified dimensions.
         *
         * Must be implemented by concrete game states to set up the tile data.
         *
         * @param width width of the game board in tiles
         * @param height height of the game board in tiles
         * @return void
         */
        virtual void initializeGameData(int width, int height) = 0;

        /**
         * @brief Get and clear the pending game module change request.
         * @return std::string name of requested game module, or empty string if none
         */
        std::string getAndClearNewGameModule();

        /**
         * @brief Get and clear the pending display module change request.
         * @return std::string name of requested display module, or empty string if none
         */
        std::string getAndClearNewDisplayModule();

        /**
         * @brief Set the name of the game module to switch to.
         * @param name name of the game module
         * @return void
         */
        void setNewGameModuleName(std::string name) { newGameModuleName = name; }

        /**
         * @brief Set the name of the display module to switch to.
         * @param name name of the display module
         * @return void
         */
        void setNewDisplayModuleName(std::string name) { newDisplayModuleName = name; }

        /**
         * @brief Check if the game should close.
         * @return bool true if the game should exit, false otherwise
         */
        bool getShouldClose() const { return _shouldClose; }

        /**
         * @brief Set whether the game should close.
         * @param close true to signal the game should close
         * @return void
         */
        void setShouldClose(bool close) { _shouldClose = close; }

        /**
         * @brief Get the width of the game board.
         * @return int width in tiles
         */
        int width()  const  override { return _width; }

        /**
         * @brief Get the height of the game board.
         * @return int height in tiles
         */
        int height() const  override { return _height; }

        /**
         * @brief Get the complete game data grid.
         * @return const std::vector<std::vector<std::unique_ptr<ITileData>>>& reference to the 2D tile grid
         */
        const std::vector<std::vector<std::unique_ptr<ITileData>>>& getGameData() override { return _gameData; }
    };
} // arc

#endif //ARCADE_AGAMESTATE_HPP