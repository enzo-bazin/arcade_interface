#ifndef ARC_SOTYPE_HPP
#define ARC_SOTYPE_HPP

namespace arc {
    /**
     * @enum SOTypeEnum
     * @brief Enumeration for shared object (SO) module types.
     *
     * Used to classify dynamic library modules in the arcade system.
     * Distinguishes between game modules and library/display modules.
     */
    enum SOTypeEnum {
        /**
         * @brief Indicates the module is a game implementation.
         */
        GAME,

        /**
         * @brief Indicates the module is a display library implementation.
         */
        LIB,
    };
}

#endif //ARC_SOTYPE_HPP