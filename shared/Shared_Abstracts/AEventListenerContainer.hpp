#include "../Shared_Interfaces/IEventListenerContainer.hpp"

namespace arc {
    /**
     * @class AEventListenerContainer
     * @brief Template container for typed event listeners.
     *
     * This template class wraps a typed event listener to allow it to be stored
     * in polymorphic containers. It provides type-safe dispatch of events to the
     * contained listener.
     *
     * @tparam EventType The specific type of event this container handles
     */
    template<typename EventType>
    class AEventListenerContainer : public IEventListenerContainer {
    private:
        /**
         * @brief The wrapped event listener.
         */
        std::unique_ptr<IEventListener<EventType>> _listener;
    public:
        /**
         * @brief Construct a container with a listener.
         * @param listener unique pointer to the event listener to wrap
         */
        AEventListenerContainer(std::unique_ptr<IEventListener<EventType>> listener) : _listener(std::move(listener)) {}

        /**
         * @brief Handle an event by casting and dispatching to the contained listener.
         * @param event reference to the arcade event to handle
         * @return void
         */
        void onEvent(IArcadeEvent &event) override {
            _listener->onEvent(static_cast<EventType &>(event));
        }
    };
}
