//
// Created by user on 3/17/26.
//

#ifndef ARCADE_AGAMEMODULE_HPP
#define ARCADE_AGAMEMODULE_HPP
#include <memory>
#include <string>
#include <vector>

#include "../../src/Dispatcher/EventDispatcher.hpp"
#include "../Shared_Interfaces/IGameModule.hpp"

namespace arc {
    /**
     * @class AGameModule
     * @brief Abstract base class for game module implementations.
     *
     * Provides a partial implementation of IGameModule with common functionality
     * shared by all game implementations. Contains the event dispatcher, sprite mapping,
     * and pending events queue. Concrete game implementations should inherit from this
     * class and implement the abstract methods from IGameModule.
     */
    class AGameModule: public IGameModule {

    protected:
        /**
         * @brief Event dispatcher for managing event listeners and dispatching events.
         */
        EventDispatcher event_dispatcher = EventDispatcher();

        /**
         * @brief Map of sprite identifiers to sprite file paths.
         *
         * Associates each sprite name/identifier with the file path where
         * the display module should load the sprite from.
         */
        std::map<std::string, std::string> sprite_map;

        /**
         * @brief Queue of events pending dispatch.
         *
         * Events are collected during update and dispatched to listeners
         * in the appropriate order.
         */
        std::vector<std::unique_ptr<IArcadeEvent>> pendingEvents;

    public:
        /**
         * @brief Default constructor.
         */
        AGameModule() = default;

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~AGameModule() = default;

    };
} // arc

#endif //ARCADE_AGAMEMODULE_HPP