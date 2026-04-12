//
// Created by user on 3/17/26.
//

#ifndef ARCADE_IARCADEEVENT_HPP
#define ARCADE_IARCADEEVENT_HPP

namespace arc {
    /**
     * @interface IArcadeEvent
     * @brief Base interface for all Arcade events in the system.
     *
     * This is the root interface for the event hierarchy. All arcade events
     * (both input events and game events) should inherit from this interface.
     * It provides a common base for event dispatching and handling.
     */
    class IArcadeEvent {
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~IArcadeEvent() = default;
    };
} // arc

#endif //ARCADE_IARCADEEVENT_HPP