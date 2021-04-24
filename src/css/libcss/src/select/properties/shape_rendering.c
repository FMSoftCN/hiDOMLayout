/*
 * This file is part of LibCSS
 * Licensed under the MIT License,
 *		  http://www.opensource.org/licenses/mit-license.php
 * Copyright 2009 John-Mark Bell <jmb@netsurf-browser.org>
 */

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "select/propset.h"
#include "select/propget.h"
#include "utils/utils.h"

#include "select/properties/properties.h"
#include "select/properties/helpers.h"

css_error css__cascade_shape_rendering(uint32_t opv, css_style *style,
		css_select_state *state)
{
	uint16_t value = CSS_SHAPE_RENDERING_INHERIT;

	UNUSED(style);

	if (isInherit(opv) == false) {
		switch (getValue(opv)) {
            case SHAPE_RENDERING_AUTO:
                value = CSS_SHAPE_RENDERING_AUTO;
                break;
            case SHAPE_RENDERING_OPTIMIZESPEED:
                value = CSS_SHAPE_RENDERING_OPTIMIZESPEED;
                break;
            case SHAPE_RENDERING_CRISPEDGES:
                value = CSS_SHAPE_RENDERING_CRISPEDGES;
                break;
            case SHAPE_RENDERING_GEOMETRICPRECISION:
                value = CSS_SHAPE_RENDERING_GEOMETRICPRECISION;
                break;
            case SHAPE_RENDERING_DEFAULT:
                value = CSS_SHAPE_RENDERING_DEFAULT;
                break;
		}
	}

	if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
			isInherit(opv))) {
		return set_shape_rendering(state->computed, value);
	}

	return CSS_OK;
}

css_error css__set_shape_rendering_from_hint(const css_hint *hint,
		css_computed_style *style)
{
	return set_shape_rendering(style, hint->status);
}

css_error css__initial_shape_rendering(css_select_state *state)
{
	return set_shape_rendering(state->computed, CSS_SHAPE_RENDERING_AUTO);
}

css_error css__compose_shape_rendering(const css_computed_style *parent,
		const css_computed_style *child,
		css_computed_style *result)
{
	uint8_t type = get_shape_rendering(child);

	if (type == CSS_SHAPE_RENDERING_INHERIT) {
		type = get_shape_rendering(parent);
	}

	return set_shape_rendering(result, type);
}

