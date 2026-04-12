//
// Created by user on 3/17/26.
//

#ifndef ARCADE_IGAMESTATE_HPP
#define ARCADE_IGAMESTATE_HPP
#include <map>
#include <string>
#include <vector>
#include <memory>
#include "ITileData.hpp"

namespace arc {
    /**
     * @interface IGameState
     * @brief Interface for game state objects that store game data.
     *
     * This interface defines the contract for game state implementations. It provides
     * access to the 2D grid of tile data that represents the game board or world,
     * along with dimension information.
     */
    class IGameState {
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~IGameState() = default;

        /**
         * @brief Get the complete game data as a 2D grid of tiles.
         * @return const std::vector<std::vector<std::unique_ptr<ITileData>>>& reference to the 2D tile grid
         */
        virtual const std::vector<std::vector<std::unique_ptr<ITileData>>>& getGameData() = 0;

        /**
         * @brief Get the width of the game board in tiles.
         * @return int width in tiles
         */
        virtual int width() const = 0;

        /**
         * @brief Get the height of the game board in tiles.
         * @return int height in tiles
         */
        virtual int height() const = 0;

    };
} // arc

#endif //ARCADE_IGAMESTATE_HPP
