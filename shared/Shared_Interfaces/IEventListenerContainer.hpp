#ifndef IEVENTLISTENERCONTAINER_HPP
#define IEVENTLISTENERCONTAINER_HPP

#include "IArcadeEvent.hpp"

/**
 * @interface IEventListenerContainer
 * @brief Interface for container objects that hold event listeners.
 *
 * This interface defines the contract for containers that encapsulate
 * typed event listeners. It allows for polymorphic handling of listeners
 * without knowing their specific types.
 */
class IEventListenerContainer {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~IEventListenerContainer() = default;

    /**
     * @brief Dispatch an event to the contained listener.
     * @param event reference to the arcade event to dispatch
     * @return void
     */
    virtual void onEvent(arc::IArcadeEvent &event) = 0;
};

#endif


