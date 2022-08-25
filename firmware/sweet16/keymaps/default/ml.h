#ifndef ML_H
#define ML_H

enum mlTypes {
    AS_IS_1SPACE,
    AS_IS_2SPACE,
    PRECEDING_BRACKETS,
    SUCCEEDING_BRACKETS
};

typedef struct mlDefinition {
    char *string;
    enum mlTypes type;
} mlDefinition;

mlDefinition ACCENT_HAT_ML = {.string = "\\hat", .type = AS_IS_2SPACE};
mlDefinition ACCENT_CHECK_ML = {.string = "\\check", .type = AS_IS_2SPACE};
mlDefinition ACCENT_TILDE_ML = {.string = "\\tilde", .type = AS_IS_2SPACE};
mlDefinition ACCENT_BAR_ML = {.string = "\\overbar", .type = AS_IS_2SPACE};
mlDefinition ACCENT_ARROW_ML = {.string = "\\vec", .type = AS_IS_2SPACE};
mlDefinition ACCENT_DOT_ML = {.string = "\\dot", .type = AS_IS_2SPACE};
mlDefinition ACCENT_2DOT_ML = {.string = "\\ddot", .type = AS_IS_2SPACE};
mlDefinition SUP_0_ML = {.string = "^0", .type = AS_IS_1SPACE};
mlDefinition SUP_1_ML = {.string = "^1", .type = AS_IS_1SPACE};
mlDefinition SUP_2_ML = {.string = "^2", .type = AS_IS_1SPACE};
mlDefinition SUP_i_ML = {.string = "^i", .type = AS_IS_1SPACE};
mlDefinition SUP_j_ML = {.string = "^j", .type = AS_IS_1SPACE};
mlDefinition SUP_n_ML = {.string = "^n", .type = AS_IS_1SPACE};
mlDefinition SUB_0_ML = {.string = "_0", .type = AS_IS_1SPACE};
mlDefinition SUB_1_ML = {.string = "_1", .type = AS_IS_1SPACE};
mlDefinition SUB_2_ML = {.string = "_2", .type = AS_IS_1SPACE};
mlDefinition SUB_i_ML = {.string = "_i", .type = AS_IS_1SPACE};
mlDefinition SUB_j_ML = {.string = "_j", .type = AS_IS_1SPACE};
mlDefinition SUB_n_ML = {.string = "_n", .type = AS_IS_1SPACE};

void bracket_next_letter(void){
    SEND_STRING("(");
    tap_code(KC_RIGHT);
    SEND_STRING(")");
};

void bracket_previous_letter(void){
    tap_code(KC_LEFT);
    SEND_STRING("(");
    tap_code(KC_RIGHT);
    SEND_STRING(")");
};

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

void send_with_preceding_brackets(char *string){
    bracket_previous_letter();
    send_string(string);
    send_2x_space();
};

void send_with_succeeding_brackets(char *string){
    tap_code(KC_LEFT);
    send_string(string);
    bracket_next_letter();
    send_space();
};

void send_ml(struct mlDefinition ml_def){
    enum mlTypes ml_type = ml_def.type;
    char *string = ml_def.string;
    switch (ml_type) {
        case AS_IS_1SPACE:
            send_as_is_1space(string);
            break;
        case AS_IS_2SPACE:
            send_as_is_2space(string);
            break;
        case PRECEDING_BRACKETS:
            send_with_preceding_brackets(string);
            break;
        case SUCCEEDING_BRACKETS:
            send_with_succeeding_brackets(string);
            break;
    };
};

void send_ml_on_keypress(struct mlDefinition ml_def, keyrecord_t *record){
    if (record->event.pressed) {
        send_ml(ml_def);
    };
};
#endif