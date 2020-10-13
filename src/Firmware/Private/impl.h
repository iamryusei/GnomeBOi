/**
 *  This header declares the internal functions needed by the GnomeBoi's framework.
 * 
 *  Your code SHOULD NOT include this header.
 *
 */

#ifndef __GNOMEBOI_FRAMEWORK_INTERNALS_H_
#define __GNOMEBOI_FRAMEWORK_INTERNALS_H_

namespace GnomeBOI_Internals
{
    namespace Runtime {
        void runStartUpAnimation();
    }

    namespace Input {
       void updateInputs();
    }

    namespace Display {
        void displayBegin();
    }

    namespace Sound {
        void updateAudioBuffers();
    }
}
#endif