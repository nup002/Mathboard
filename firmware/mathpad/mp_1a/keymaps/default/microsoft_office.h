/* Copyright 2025 Summacogni OU
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// Definitions specifically for Microsoft Office (MOF) equations editor

#ifndef MOF_H
#define MOF_H

#include QMK_KEYBOARD_H

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

static const mofDefinition ACCENT_HAT_MOF = {.string = "\\hat", .type = AS_IS_2SPACE};
static const mofDefinition ACCENT_CHECK_MOF = {.string = "\\check", .type = AS_IS_2SPACE};
static const mofDefinition ACCENT_TILDE_MOF = {.string = "\\tilde", .type = AS_IS_2SPACE};
static const mofDefinition ACCENT_BAR_MOF = {.string = "\\bar", .type = AS_IS_2SPACE};
static const mofDefinition ACCENT_ARROW_MOF = {.string = "\\vec", .type = AS_IS_2SPACE};
static const mofDefinition ACCENT_DOT_MOF = {.string = "\\dot", .type = AS_IS_2SPACE};
static const mofDefinition ACCENT_2DOT_MOF = {.string = "\\ddot", .type = AS_IS_2SPACE};
static const mofDefinition SUP_0_MOF = {.string = "^0", .type = AS_IS_1SPACE};
static const mofDefinition SUP_1_MOF = {.string = "^1", .type = AS_IS_1SPACE};
static const mofDefinition SUP_2_MOF = {.string = "^2", .type = AS_IS_1SPACE};
static const mofDefinition SUP_i_MOF = {.string = "^i", .type = AS_IS_1SPACE};
static const mofDefinition SUP_j_MOF = {.string = "^j", .type = AS_IS_1SPACE};
static const mofDefinition SUP_n_MOF = {.string = "^n", .type = AS_IS_1SPACE};
static const mofDefinition SUB_0_MOF = {.string = "_0", .type = AS_IS_1SPACE};
static const mofDefinition SUB_1_MOF = {.string = "_1", .type = AS_IS_1SPACE};
static const mofDefinition SUB_2_MOF = {.string = "_2", .type = AS_IS_1SPACE};
static const mofDefinition SUB_i_MOF = {.string = "_i", .type = AS_IS_1SPACE};
static const mofDefinition SUB_j_MOF = {.string = "_j", .type = AS_IS_1SPACE};
static const mofDefinition SUB_n_MOF = {.string = "_n", .type = AS_IS_1SPACE};
static const mofDefinition SUM_MOF = {.string = "\\sum_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition N_ARY_PRODUCT_MOF = {.string = "\\prod_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition UNION_MOF = {.string = "\\bigcup_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition INTERSECTION_MOF = {.string = "\\bigcap_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition INTEGRAL_MOF = {.string = "\\int_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition DOUBLE_INTEGRAL_MOF = {.string = "\\iint_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition TRIPLE_INTEGRAL_MOF = {.string = "\\iiint_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition LINE_INTEGRAL_MOF = {.string = "\\oint_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition SURFACE_INTEGRAL_MOF = {.string = "\\oiint_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition VOLUME_INTEGRAL_MOF = {.string = "\\oiiint_a^b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};
static const mofDefinition ROOT_MOF = {.string = "\\sqrt", .type = MOVE_LEFT_2SPACE};
static const mofDefinition CUBE_ROOT_MOF = {.string = "\\cbrt", .type = MOVE_LEFT_2SPACE};
static const mofDefinition FOURTH_ROOT_MOF = {.string = "\\qdrt", .type = MOVE_LEFT_2SPACE};
static const mofDefinition MATRIX_MOF = {.string = "[\\matrix(@&)]", .type = MOVE_LEFT_1SPACE};
static const mofDefinition FRAC_MOF = {.string = " a/b", .type = SPACE_DELETE_PLACEHOLDER_LIMITS};


void send_space(void);

void send_2x_space(void);

void send_as_is_1space(char *string);

void send_as_is_2space(char *string);

void send_with_left_move_1space(char *string);

void send_with_left_move_2space(char *string);

void send_with_delete_lims_1space(char *string);

void send_mof(struct mofDefinition mof_def);

void send_mof_on_keypress(struct mofDefinition mof_def, keyrecord_t *record);
#endif