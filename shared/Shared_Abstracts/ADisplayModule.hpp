//
// Created by user on 3/18/26.
//

#ifndef ARCADE_ADISPLAYMODULE_HPP
#define ARCADE_ADISPLAYMODULE_HPP
#include "../Shared_Interfaces/IDisplayModule.hpp"

namespace arc {
    /**
     * @class ADisplayModule
     * @brief Abstract base class for display module implementations.
     *
     * Provides a partial implementation of IDisplayModule with common functionality
     * for all display backends (NCurses, SDL2, SFML, etc). Concrete implementations
     * should override the pure virtual methods from IDisplayModule.
     */
    class ADisplayModule: public IDisplayModule {
    protected:
        /**
         * @brief Internal mapping of sprite identifiers to file paths.
         */
        std::map<std::string, std::string> _assetsMapping;
    public:
        /**
         * @brief Get the aspect ratio of tiles for this display.
         *
         * Default implementation returns 1.0f (square tiles). Override if your
         * display has different tile aspect ratios.
         *
         * @return float tile aspect ratio (width/height)
         */
        float getTileAspectRatio() const override { return 1.0f; }
    };
} // arc

#endif //ARCADE_ADISPLAYMODULE_HPP
