// Definitions specifically for Microsoft Office (MOF) equations editor

#ifndef MOF_H
#define MOF_H

enum mofTypes {
    AS_IS_1SPACE,
    AS_IS_2SPACE,
    MOVE_LEFT_1SPACE,
    MOVE_LEFT_2SPACE,
    SPACE_DELETE_PLACEHOLDER_LIMITS
};

typedef struct mofDefinition {
    char *string;
    enum mofTypes type;
} mofDefinition;

mofDefinition ACCENT_HAT_MOF = {.string = "\\hat", .type = AS_IS_2SPACE};
mofDefinition ACCENT_CHECK_MOF = {.string = "\\check", .type = AS_IS_2SPACE};
mofDefinition ACCENT_TILDE_MOF = {.string = "\\tilde", .type = AS_IS_2SPACE};
mofDefinition ACCENT_BAR_MOF = {.string = "\\overbar", .type = AS_IS_2SPACE};
mofDefinition ACCENT_ARROW_MOF = {.string = "\\vec", .type = AS_IS_2SPACE};
mofDefinition ACCENT_DOT_MOF = {.string = "\\dot", .type = AS_IS_2SPACE};
mofDefinition ACCENT_2DOT_MOF = {.string = "\\ddot", .type = AS_IS_2SPACE};
mofDefinition SUP_0_MOF = {.string = "^0", .type = AS_IS_1SPACE};
mofDefinition SUP_1_MOF = {.string = "^1", .type = AS_IS_1SPACE};
mofDefinition SUP_2_MOF = {.string = "^2", .type = AS_IS_1SPACE};
mofDefinition SUP_i_MOF = {.string = "^i", .type = AS_IS_1SPACE};
mofDefinition SUP_j_MOF = {.string = "^j", .type = AS_IS_1SPACE};
mofDefinition SUP_n_MOF = {.string = "^n", .type = AS_IS_1SPACE};
mofDefinition SUB_0_MOF = {.string = "_0", .type = AS_IS_1SPACE};
mofDefinition SUB_1_MOF = {.string = "_1", .type = AS_IS_1SPACE};
mofDefinition SUB_2_MOF = {.string = "_2", .type = AS_IS_1SPACE};
mofDefinition SUB_i_MOF = {.string = "_i", .type = AS_IS_1SPACE};
mofDefinition SUB_j_MOF = {.string = "_j", .type = AS_IS_1SPACE};
mofDefinition SUB_n_MOF = {.string = "_n", .type = AS_IS_1SPACE};
mofDefinition SUM_MOF = {.string = "\\sum_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
mofDefinition N_ARY_PRODUCT_MOF = {.string = "\\prod_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
mofDefinition UNION_MOF = {.string = "\\bigcup_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
mofDefinition INTERSECTION_MOF = {.string = "\\bigcap_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
mofDefinition INTEGRAL_MOF = {.string = "\\int", .type = AS_IS_2SPACE};
mofDefinition DOUBLE_INTEGRAL_MOF = {.string = "\\iint", .type = AS_IS_2SPACE};
mofDefinition TRIPLE_INTEGRAL_MOF = {.string = "\\iiint", .type = AS_IS_2SPACE};
mofDefinition LINE_INTEGRAL_MOF = {.string = "\\oint", .type = AS_IS_2SPACE};
mofDefinition SURFACE_INTEGRAL_MOF = {.string = "\\oiint", .type = AS_IS_2SPACE};
mofDefinition VOLUME_INTEGRAL_MOF = {.string = "\\oiiint", .type = AS_IS_2SPACE};
mofDefinition ROOT_MOF = {.string = "\\sqrt", .type = MOVE_LEFT_2SPACE};
mofDefinition CUBE_ROOT_MOF = {.string = "\\cbrt", .type = MOVE_LEFT_2SPACE};
mofDefinition FOURTH_ROOT_MOF = {.string = "\\qdrt", .type = MOVE_LEFT_2SPACE};
mofDefinition MATRIX_MOF = {.string = "[\\matrix(@&)]", .type = MOVE_LEFT_1SPACE};
mofDefinition FRAC_MOF = {.string = " a/b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};


void send_space(void){
    tap_code(KC_SPACE);
};

void send_2x_space(void){
    tap_code(KC_SPACE);
    tap_code(KC_SPACE);
};

void send_as_is_1space(char *string){
    send_string(string);
    send_space();
};

void send_as_is_2space(char *string){
    send_string(string);
    send_2x_space();
};

void send_with_left_mofve_1space(char *string){
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
};

void send_with_left_mofve_2space(char *string){
    send_string(string);
    send_2x_space();
    tap_code(KC_LEFT);
};

void send_with_delete_lims_1space(char *string){
    send_string(string);
    send_space();
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
    tap_code(KC_LEFT);
    tap_code(KC_BSPC);
};

void send_mof(struct mofDefinition mof_def){
    enum mofTypes mof_type = mof_def.type;
    char *string = mof_def.string;
    switch (mof_type) {
        case AS_IS_1SPACE:
            send_as_is_1space(string);
            break;
        case AS_IS_2SPACE:
            send_as_is_2space(string);
            break;
        case MOVE_LEFT_1SPACE:
            send_with_left_mofve_1space(string);
            break;
        case MOVE_LEFT_2SPACE:
            send_with_left_mofve_2space(string);
            break;
        case SPACE_DELETE_PLACEHOLDER_LIMITS:
            send_with_delete_lims_1space(string);
            break;
    };
};

void send_mof_on_keypress(struct mofDefinition mof_def, keyrecord_t *record){
    if (record->event.pressed) {
        send_mof(mof_def);
    };
};
#endif