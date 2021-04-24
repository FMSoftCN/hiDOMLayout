/*
 * Copyright (C) 2021 Beijing FMSoft Technologies Co., Ltd.
 */

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "select/propset.h"
#include "select/propget.h"
#include "utils/utils.h"

#include "select/properties/properties.h"
#include "select/properties/helpers.h"

css_error css__cascade_stop_opacity(uint32_t opv, css_style *style,
		css_select_state *state)
{
	uint16_t value = CSS_STOP_OPACITY_INHERIT;
	css_fixed opacity = 0;

	if (isInherit(opv) == false) {
		value = CSS_STOP_OPACITY_SET;

		opacity = *((css_fixed *) style->bytecode);
		advance_bytecode(style, sizeof(opacity));
	}

	if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
			isInherit(opv))) {
		return set_stop_opacity(state->computed, value, opacity);
	}

	return CSS_OK;
}

css_error css__set_stop_opacity_from_hint(const css_hint *hint,
		css_computed_style *style)
{
	return set_stop_opacity(style, hint->status, hint->data.fixed);
}

css_error css__initial_stop_opacity(css_select_state *state)
{
	return set_stop_opacity(state->computed, CSS_STOP_OPACITY_SET, INTTOFIX(1));
}

css_error css__compose_stop_opacity(const css_computed_style *parent,
		const css_computed_style *child,
		css_computed_style *result)
{
	css_fixed opacity = 0;
	uint8_t type = get_stop_opacity(child, &opacity);

	if (type == CSS_STOP_OPACITY_INHERIT) {
		type = get_stop_opacity(parent, &opacity);
	}

	return set_stop_opacity(result, type, opacity);
}

