//
// Created by user on 3/24/26.
//

#include "../../Shared_Abstracts/AInputArcadeEvent.hpp"

#include "InputTabKeyPressedEventListener.hpp"
#include "../../Events/GameEvents/GameLibViewEvent.hpp"

namespace arc {
    class InputTabKeyPressedEvent: public AInputArcadeEvent {
    public:
        InputTabKeyPressedEvent()  = default;
        ~InputTabKeyPressedEvent() override = default;
    };
} // arc
