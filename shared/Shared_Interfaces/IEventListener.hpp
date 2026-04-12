//
// Created by user on 3/17/26.
//

#ifndef ARCADE_IEVENTLISTENER_HPP
#define ARCADE_IEVENTLISTENER_HPP
#include "IArcadeEvent.hpp"
#include "IGameState.hpp"

namespace arc {

    /**
     * @interface IEventListener
     * @brief Template interface for event listeners that handle specific event types.
     *
     * @tparam TEvent The type of event this listener handles. Must derive from IArcadeEvent.
     *
     * This interface allows for type-safe event handling. Implementations can register
     * themselves with an event dispatcher and will be notified when events of their
     * registered type occur.
     */
    template<typename TEvent>
    class   IEventListener {
    public:
        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~IEventListener() = default;

        /**
         * @brief Handle an event of type TEvent.
         * @param event reference to the event to handle
         * @return void
         */
        virtual void onEvent(TEvent& event) = 0;
    };
} // arc

#endif //ARCADE_IEVENTLISTENER_HPP