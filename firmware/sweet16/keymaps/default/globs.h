#ifndef GLOBS_H
#define GLOBS_H

enum modes {
    UC,
    MOF,
    LTX
};

// MODE is a global variable that sets which type of output the Matboard should emit. 
// It can be Unicode, Microsoft Office equations editor, LaTeX, etc. Clicking the mode-change button on the Mathboard
// cycles the MODE variable to its next value.
enum modes MODE = LTX;


#endif