#include "../inc/uls.h" 

t_visible mx_visible_flags(t_flags flags) {
    switch (flags.visible)
    {
        case _H_DOTS:
            return mx_hidden_dots;

        case _W_DOTS:
            return mx_dots_absence;

        case _ALL:
            return mx_checking;
    }
}
